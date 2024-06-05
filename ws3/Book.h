/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 3
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

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca {
    class Book {
        std::string m_title;
        unsigned m_numChapters;
        unsigned m_numPages;
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        bool isValid() const;
        double avgPagesPerChapter() const;
        std::ostream& print(std::ostream& os) const;
        bool operator<(const Book& other) const;
        bool operator>(const Book& other) const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // SENECA_BOOK_H
