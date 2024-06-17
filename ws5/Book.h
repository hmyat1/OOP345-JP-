/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 5
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_description;

    public:
        // Default Constructor
        Book();
        // This constructor extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes.
        Book(const std::string& strBook);
        // A query that returns the title of the book
        const std::string& title() const;
        // A query that returns the publication country
        const std::string& country() const;
        // A query that returns the publication year
        const size_t& year() const;
        // A function that returns the price by reference, allowing the client code to update the price
        double& price();

        // This function calls the overloaded operator() on the instance spellChecker, passing to it the book description.
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        }
        // Insertion operator to insert the content of a book object into an ostream object
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
    };
}
#endif 
