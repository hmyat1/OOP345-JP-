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


#include "Movie.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace seneca {
    Movie::Movie() : m_year(0) {}

    const std::string& Movie::title() const {
        return m_title;
    }

    Movie::Movie(const std::string& strMovie) {
        std::istringstream stream(strMovie);
        std::string token;

        std::getline(stream, m_title, ',');
        std::getline(stream, token, ',');
        m_year = std::stoi(token);
        std::getline(stream, m_description);

        auto trim = [](std::string& s) {
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r") + 1);
            };

        trim(m_title);
        trim(m_description);
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::setw(40) << std::right << movie.m_title << " | "
            << std::setw(4) << std::right << movie.m_year << " | "
            << movie.m_description << "\n";
        return os;
    }
}
