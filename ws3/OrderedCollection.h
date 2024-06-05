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
#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"
#include <algorithm>

namespace seneca {

    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item) override {
            if (this->size() < this->capacity()) {
                unsigned pos = 0;
                while (pos < this->size() && this->operator[](pos) < item) {
                    ++pos;
                }
                for (unsigned i = this->size(); i > pos; --i) {
                    this->operator[](i) = this->operator[](i - 1);
                }
                this->operator[](pos) = item;
                this->incrSize();
                // Update smallest and largest items
                updateSmallestAndLargest(item);
                return true;
            }
            return false;
        }

    private:
        void updateSmallestAndLargest(const T& item) {
            if (item < this->getSmallestItem()) {
                Collection<T, 72>::m_smallestItem = item;
            }
            if (item > this->getLargestItem()) {
                Collection<T, 72>::m_largestItem = item;
            }
        }
    };

} // namespace seneca

#endif // SENECA_ORDERED_COLLECTION_H
