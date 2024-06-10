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

#include "ConfirmationSender.h"

namespace seneca {

    ConfirmationSender::ConfirmationSender() : m_reservations(nullptr), m_count(0) {}

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) : m_reservations(nullptr), m_count(0) 
    {
        *this = other;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) 
    {
        if (this != &other) 
        {
            delete[] m_reservations;
            m_count = other.m_count;
            m_reservations = new const Reservation * [m_count];
            for (size_t i = 0; i < m_count; ++i) 
            {
                m_reservations[i] = other.m_reservations[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) : m_reservations(nullptr), m_count(0) 
    {
        *this = std::move(other);
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) 
    {
        if (this != &other) 
        {
            delete[] m_reservations;
            m_reservations = other.m_reservations;
            m_count = other.m_count;
            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() 
    {
        delete[] m_reservations;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) 
    {
        bool alreadyExists = false;
        for (size_t i = 0; i < m_count; ++i) 
        {
            if (m_reservations[i] == &res) 
            {
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) 
        {
            const Reservation** temp = new const Reservation * [m_count + 1];
            for (size_t i = 0; i < m_count; ++i) 
            {
                temp[i] = m_reservations[i];
            }
            temp[m_count] = &res;
            delete[] m_reservations;
            m_reservations = temp;
            ++m_count;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) 
    {
        bool found = false;
        for (size_t i = 0; i < m_count; ++i) 
        {
            if (m_reservations[i] == &res) 
            {
                found = true;
                for (size_t j = i; j < m_count - 1; ++j) 
                {
                    m_reservations[j] = m_reservations[j + 1];
                }
                --m_count;
                break;
            }
        }
        if (found) 
        {
            const Reservation** temp = new const Reservation * [m_count];
            for (size_t i = 0; i < m_count; ++i) 
            {
                temp[i] = m_reservations[i];
            }
            delete[] m_reservations;
            m_reservations = temp;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) 
    {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (sender.m_count == 0) 
        {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < sender.m_count; ++i) 
            {
                os << *sender.m_reservations[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }
}
