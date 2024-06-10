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


#include "Restaurant.h"

namespace seneca {

    Restaurant::Restaurant() 
    {
        m_res = nullptr;
        m_size = 0;
    }

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) 
    {
        m_res = new Reservation * [cnt];
        for (unsigned int i = 0; i < cnt; i++) 
        {
            m_res[i] = new Reservation;
            *m_res[i] = *reservations[i];
        }
        m_size = cnt;
    }

    Restaurant::Restaurant(const Restaurant& rest) 
    {
        m_size = 0;
        m_res = nullptr;
        this->operator=(rest);
    }

    Restaurant& Restaurant::operator=(const Restaurant& rest) 
    {
        if (this != &rest) 
        {
            while (m_size) 
            {
                delete m_res[--m_size];
            }
            delete[] m_res;
            m_size = rest.size();
            m_res = new Reservation * [m_size];
            for (unsigned int i{ 0 }; i < m_size; i++) 
            {
                m_res[i] = new Reservation;
                *m_res[i] = *rest.m_res[i];
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& rest) 
    {
        m_size = 0;
        m_res = nullptr;
        *this = std::move(rest);
    }


    Restaurant& Restaurant::operator=(Restaurant&& rest) 
    {
        if (this != &rest) 
        {
            while (m_size) 
            {
                delete m_res[--m_size];
            }
            delete[] m_res;
            m_size = rest.size();
            m_res = rest.m_res;
            rest.m_size = 0;
            rest.m_res = nullptr;
        }
        return *this;
    }

    Restaurant::~Restaurant() 
    {
        while (m_size) 
        {
            delete m_res[--m_size];
        }
        delete[] m_res;
        m_res = nullptr;
    }

    size_t Restaurant::size() const 
    {
        return m_size;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& rest) 
    {
        static unsigned int callCnt{};
        callCnt++;
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant (" << callCnt << ")" << std::endl;
        os << "--------------------------" << std::endl;
        if (rest.m_res != nullptr) 
        {
            for (unsigned int i = 0; i < rest.m_size; i++) 
            {
                os << *rest.m_res[i];
            }
        }
        else 
        {
            os << "This restaurant is empty!" << std::endl;
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}