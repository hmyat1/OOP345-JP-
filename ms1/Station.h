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
 
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>

namespace seneca
{
    class Station
        //instance variables
    {
        //the id of the station (integer)
        int m_id;
        //the name of the item handled by the station (string)
        std::string m_name;
        //the description of the station (string)
        std::string m_description;
        //the next serial number to be assigned to an item at this station (non-negative integer)
        unsigned m_serialNumber;
        //the number of items currently in stock (non-negative integer)
        unsigned m_inStock_items;

        //class variables
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string &record);  
        // returns the name of the current Station object
        const std::string &getItemName() const; 
        //// returns the next serial number to be used on the assembly line and increments m_serialNumber
        size_t getNextSerialNumber();    
        // returns the remaining quantity of items in the Station object
        size_t getQuantity() const; 
        // subtracts 1 from the available quantity; should not drop below 0.
        void updateQuantity();       
        // inserts information about the current object into stream os.
        void display(std::ostream &os, bool full) const; 
    };

} // namespace seneca

#endif