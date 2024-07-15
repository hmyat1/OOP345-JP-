/***********************************************************************
                        Workshop - 7(Part-2)

Name : Hla Myint Myat
Email : hmyat1@myseneca.ca
Student ID : 185923216
Date : 07/14/24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

***********************************************************************/

#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H

#include <iostream>
#include <string>
#include <list>
#include <vector>


namespace seneca {

    enum BakedType 
    {
        BREAD, PASTERY
    };

    struct BakedGood 
    {
        BakedType m_type;
        std::string m_desc;
        size_t m_life;
        size_t m_stock;
        double m_price;

        friend std::ostream& operator<<(std::ostream& out, const BakedGood& b);
    };

    class Bakery 
    {
    private:
        std::vector<BakedGood> m_goods;
    public:
        Bakery() = default;
        Bakery(std::string filename);

        void showGoods(std::ostream& os) const;
        void sortBakery(const std::string& sorts);
        std::vector<BakedGood> combine(const Bakery& other);
        bool inStock(const std::string desc, const BakedType& type) const;
        std::list<BakedGood> outOfStock(const BakedType& type) const;
    };

}

#endif // SENECA_BAKERY_H