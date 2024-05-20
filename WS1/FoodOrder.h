/*
*****************************************************************************
                              FoodOrder.h
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Date: 19.5.24
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>

// Global Variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace SENECA {
    class FoodOrder {
    private:
        char* customerName;
        char* foodDescription;
        double foodPrice;
        bool dailySpecial;

        // Initializes all attributes to safe empty state
        void setEmpty();

        // Frees all the dynamically allocated memory
        void deallocate();

    public:
        FoodOrder();
        ~FoodOrder();
        FoodOrder(const FoodOrder& foodOrder);
        FoodOrder& operator=(const FoodOrder& foodOrder);

        // Reads a line in the text file and stores data in class
        std::istream& read(std::istream& is);

        // Displays data
        void display() const;
    };
}

#endif // SENECA_FOODORDER_H
