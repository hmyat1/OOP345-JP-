/*/////////////////////////////////////////////////////////////////////////
                       Milestone - 3
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
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

using namespace std;
using namespace seneca;

namespace seneca
{
    size_t Station::m_widthField{};
    size_t Station::id_generator = 1; 

    Station::Station(const std::string &record)
    {
        try
        {
            m_id = id_generator++;

            Utilities utility;
            size_t npos = 0;
            bool more;

            m_name = utility.extractToken(record, npos, more);
            m_serialNumber = std::stoi(utility.extractToken(record, npos, more));
            m_inStock_items = std::stoi(utility.extractToken(record, npos, more));

            m_widthField = std::max(utility.getFieldWidth(), m_widthField);

            m_description = utility.extractToken(record, npos, more);
        }
        catch (const std::string &err) {std::cout << err; }
    }
    //getting the name
    const std::string &Station::getItemName() const{ return m_name;}

    //getting the serial number
    size_t Station::getNextSerialNumber(){ return m_serialNumber++; }

    //getting the quantity
    size_t Station::getQuantity() const{return m_inStock_items;}

    //updating
    void Station::updateQuantity()
    {if (m_inStock_items > 0){ m_inStock_items--;} }

    void Station::display(std::ostream &os, bool full) const
    {
        os << std::setfill('0') << std::setw(3) << std::right << m_id;
        os << " | " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
        os << " | " << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << " | ";

        if (full)
        {
            os << std::setfill(' ') << setw(4) << std::right << m_inStock_items
               << " | " << std::left << m_description << std::endl;
        }
        else
        {
            os << std::endl;
        }
    }
} 
