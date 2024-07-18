/*/////////////////////////////////////////////////////////////////////////
                       Milestone - 2
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <algorithm>
#include<string>
#include "Station.h"

namespace seneca {
	// Defining structure item here
	struct Item
	{
		std::string m_itemName = "";
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};
	//customer class
	class CustomerOrder {
		// name of customer
		std::string m_name = ""; 
		// name of product
		std::string m_product = ""; 
		// number of items in a customer's order
		size_t m_cntItem = 0u; 
		// dynamically pointer to pointer
		//This is the resource that your class must manage.
		Item** m_lstItem{ nullptr }; 

		//the maximum width of a field, used for display purposes
		static size_t m_widthField;

	public:
		//rule of 5
		//default constructor
		CustomerOrder() = default;
		CustomerOrder(const std::string& line);
		//copy semantics
		// Copy Constructor for throwing an Exception
		CustomerOrder(const CustomerOrder&); 
		// Deleting the Copy assignment
		CustomerOrder& operator=(CustomerOrder& customer) = delete; 
		//move semantics
		// Move Constructor;
		CustomerOrder(CustomerOrder&& moveCustomer)noexcept; 
		//Move assignment Operator
		CustomerOrder& operator=(CustomerOrder&& moveCustomer)noexcept;
		// Destructor
		virtual ~CustomerOrder(); 
		//returns true if all the items in the order have been filled; false otherwise
		bool isOrderFilled() const;
		//returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
		bool isItemFilled(const std::string& itemName) const;
		//this modifier fills one item in the current order that the Station specified in the first parameter handles.
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;


	};

}

#endif