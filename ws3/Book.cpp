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
#include "Book.h"

namespace seneca {
    Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
        : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

    bool Book::isValid() const {
        return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
    }

    double Book::avgPagesPerChapter() const {
        return static_cast<double>(m_numPages) / m_numChapters;
    }

    std::ostream& Book::print(std::ostream& os) const {
        if (isValid()) {
            os << std::setw(56) << std::right 
               << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages)
               << " | " << std::setw(15) << std::left 
               << "(" + std::to_string(avgPagesPerChapter()) + ")";
        } else {
            os << "| Invalid book data";
        }
        return os;
    }

    bool Book::operator<(const Book& other) const {
        return avgPagesPerChapter() < other.avgPagesPerChapter();
    }

    bool Book::operator>(const Book& other) const {
        return avgPagesPerChapter() > other.avgPagesPerChapter();
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        return bk.print(os);
    }
}
