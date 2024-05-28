/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 2 
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>

namespace seneca {
    class ProteinDatabase {
    private:
        std::string* sequences;
        size_t numSequences;
    public:
        ProteinDatabase();
        ProteinDatabase(const std::string& filename);
        ProteinDatabase(const ProteinDatabase& other);
        ProteinDatabase(ProteinDatabase&& other) noexcept;
        ProteinDatabase& operator=(const ProteinDatabase& other);
        ProteinDatabase& operator=(ProteinDatabase&& other) noexcept;
        ~ProteinDatabase();
        size_t size() const;
        std::string operator[](size_t index) const;
    };
}

#endif
