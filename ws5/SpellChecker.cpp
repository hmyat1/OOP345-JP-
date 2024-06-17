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


#include "SpellChecker.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace seneca {
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            throw "Bad file name!";
        }

        std::string line;
        for (int i = 0; i < 6 && std::getline(file, line); ++i) {
            std::istringstream iss(line);
            iss >> m_badWords[i] >> m_goodWords[i];
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < 6; ++i) {
            size_t pos;
            while ((pos = text.find(m_badWords[i])) != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                ++m_replacements[i];
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        for (size_t i = 0; i < 6; ++i) {
            out << std::setw(15) << std::right << m_badWords[i] << ": "
                << m_replacements[i] << " replacements" << std::endl;
        }
    }
}
