/*/////////////////////////////////////////////////////////////////////////
                       Milestone - 1
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Utilities.h"

using namespace std;
using namespace seneca;

namespace seneca
{
    char Utilities::m_delimiter{};
    size_t Utilities::getFieldWidth() const { return m_widthField; }
    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth;}
  
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        size_t idxOfDelimiter = str.find(getDelimiter(), next_pos);

        if (idxOfDelimiter == next_pos)
        {
            more = false;
            throw std::string("Failed to find the delimiter");
        }

        std::string extracted = str.substr(next_pos, idxOfDelimiter - next_pos);


        size_t first_not_space = extracted.find_first_not_of(" \t");
        size_t last_not_space = extracted.find_last_not_of(" \t");

        if (first_not_space != std::string::npos && last_not_space != std::string::npos)
        {
            extracted = extracted.substr(first_not_space, last_not_space - first_not_space + 1);
        }
        else
        {
            extracted.clear();
        }

        next_pos = idxOfDelimiter + 1;

        setFieldWidth(std::max(m_widthField, extracted.size()));

        more = idxOfDelimiter != std::string::npos;

        return extracted;
    }
    

    void Utilities::setDelimiter(char newDelimiter){ m_delimiter = newDelimiter; }

    char Utilities::getDelimiter(){ return m_delimiter;}
} // namespace sdds
