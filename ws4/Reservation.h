/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 4
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iomanip>
#include <ostream>
#include <string>

namespace seneca {
    class Reservation 
    {
        std::string m_reservationID;
        std::string m_name;
        std::string m_email;
        int m_numOfPeople;
        int m_day;
        int m_hour;

    public:
        Reservation();
        std::string& trim(std::string& str);
        Reservation(const std::string& res);
        void update(int day, int time);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // SENECA_RESERVATION_H
