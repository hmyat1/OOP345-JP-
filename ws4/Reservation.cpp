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

#include "Reservation.h"

namespace seneca {

    std::string& Reservation::trim(std::string& str)
    {
        size_t i = 0;
        size_t len = str.length();

        while (len > static_cast<size_t>(i) && str[i] == ' ')
            i++;
        if (i > 0)
            str.erase(0, i);

        len = str.length();
        i = len - 1;
        while (i >= 0 && str[i] == ' ')
        {
            i--;
        }

        if (static_cast<size_t>(i) < len - 1)
            str.erase(i + 1);

        return str;
    }


    Reservation::Reservation() : m_numOfPeople(0), m_day(0), m_hour(0) {}

    Reservation::Reservation(const std::string& res)
    {
        size_t pos1 = res.find(':'), pos2 = res.find(',');
        std::string sub = res.substr(0, pos1);
        m_reservationID = trim(sub);

        sub = res.substr(pos1 + 1, pos2 - (pos1 + 1));
        m_name = trim(sub);

        pos1 = res.find(',', pos2 + 1);
        sub = res.substr(pos2 + 1, pos1 - (pos2 + 1));
        m_email = trim(sub);

        pos2 = res.find(',', pos1 + 1);
        sub = res.substr(pos1 + 1, pos2 - (pos1 + 1));
        m_numOfPeople = stoi(trim(sub));

        pos1 = res.find(',', pos2 + 1);
        sub = res.substr(pos2 + 1, pos1 - (pos2 + 1));
        m_day = stoi(trim(sub));

        sub = res.substr(pos1 + 1);
        m_hour = stoi(trim(sub));
    }

    void Reservation::update(int day, int time) 
    {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) 
    {
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": " << std::right
            << std::setw(20) << res.m_name << "  <" << std::left << std::setw(23)
            << res.m_email + ">";

        if (res.m_hour <= 9 && res.m_hour >= 6) {
            os << "Breakfast";
        }
        else if (res.m_hour <= 15 && res.m_hour >= 11) {
            os << "Lunch";
        }
        else if (res.m_hour <= 21 && res.m_hour >= 17) {
            os << "Dinner";
        }
        else {
            os << "Drinks";
        }

        os << " on day " << res.m_day << " @ " << res.m_hour << ":00 for "
            << res.m_numOfPeople;
        if (res.m_numOfPeople == 1)
            os << " person.\n";
        else {
            os << " people.\n";
        }

        return os;
    }
}
