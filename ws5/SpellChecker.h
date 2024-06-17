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


#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace seneca {
    class SpellChecker {
        std::string m_badWords[6]; // An array with 6 misspelled words
        std::string m_goodWords[6]; // An array with the correct spelling of those 6 words
        size_t m_replacements[6] = { 0 };

    public:
        // Receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words
        SpellChecker(const char* filename);
        // This operator searches text and replaces any misspelled word with the correct version
        void operator()(std::string& text);
        // Inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance
        void showStatistics(std::ostream& out) const;
    };
}
#endif 
