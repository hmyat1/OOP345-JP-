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
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace seneca {
    class ConfirmationSender 
    {
        const Reservation** m_reservations;
        size_t m_count;

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other);
        ConfirmationSender& operator=(ConfirmationSender&& other);
        ~ConfirmationSender();

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // SENECA_CONFIRMATIONSENDER_H
