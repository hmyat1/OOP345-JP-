/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 3
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <limits>
#include "Book.h"

namespace seneca {

    template <typename T, unsigned C>
    class Collection {
        public :
        static T m_smallestItem;
        static T m_largestItem;
        T m_items[C];
        unsigned m_size;

        void setSmallestItem(const T& item) {
            if (item < m_smallestItem) {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T& item) {
            if (item > m_largestItem) {
                m_largestItem = item;
            }
        }

    protected:
        virtual T& operator[](unsigned index) { return m_items[index]; }

        virtual void incrSize() {
            ++m_size;
        }

    public:
        Collection() : m_size(0) {}

        static T getSmallestItem() { return m_smallestItem; }
        static T getLargestItem() { return m_largestItem; }
        unsigned size() const { return m_size; }
        unsigned capacity() const { return C; }

        virtual bool operator+=(const T& item) {
            if (m_size < C) {
                m_items[m_size++] = item;
                setSmallestItem(item);
                setLargestItem(item);
                return true;
            }
            return false;
        }

        virtual void print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < m_size; ++i) {
                os << m_items[i];
                if (i < m_size - 1) {
                    os << ",";
                }
            }
            os << "]\n";
        }
    };

    // Define the static members outside the class template
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = std::numeric_limits<T>::max();

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = std::numeric_limits<T>::lowest();

    // Template specializations for Book type
    template <>
    seneca::Book Collection<seneca::Book, 72>::m_smallestItem = seneca::Book("", 1, 10000);

    template <>
    seneca::Book Collection<seneca::Book, 72>::m_largestItem = seneca::Book("", 10000, 1);

     // Template specializations for Book type
    template <>
    seneca::Book Collection<seneca::Book, 10>::m_smallestItem = seneca::Book("", 1, 10000);

    template <>
    seneca::Book Collection<seneca::Book, 10>::m_largestItem = seneca::Book("", 10000, 1);   

    // Template specialization for printing Book objects
    template <>
    void Collection<seneca::Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| ";
            m_items[i].print(os);
            os << " |\n";
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

    template <>
    void Collection<seneca::Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| ";
            m_items[i].print(os);
            os << " |\n";
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

} // namespace seneca

#endif // SENECA_COLLECTION_H
