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


#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>
#include <string>

namespace seneca {
    class Movie {
        std::string m_title;
        size_t m_year;
        std::string m_description;

    public:
        // Default Constructor
        Movie();
        // A query that returns the title of the movie
        const std::string& title() const;
        // Receives the movie through a reference to a string. 
        // This constructor extracts the information about the movie from the string and stores the tokens in the attributes
        Movie(const std::string& strMovie);

        // This function calls the overloaded operator() on instance spellChecker, passing to it the movie title and description.
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }

        // Insertion operator to insert the content of a movie object into an ostream object, in the following format
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };
}
#endif
