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


#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"

namespace seneca {
    class Restaurant 
    {
        Reservation** m_res{};
        size_t m_size{};
    public:
        Restaurant();

        Restaurant(const Reservation* reservations[], size_t cnt);

        Restaurant(const Restaurant& rest);
        Restaurant& operator=(const Restaurant& rest);
        Restaurant(Restaurant&& rest);
        Restaurant& operator=(Restaurant&& rest);


        ~Restaurant();
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
    };
}

#endif // SENECA_RESTAURANT_H
