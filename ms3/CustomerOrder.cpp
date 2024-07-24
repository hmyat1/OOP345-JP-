/*/////////////////////////////////////////////////////////////////////////
                       Milestone - 3
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include <string>
#include<algorithm>

using namespace std;

namespace seneca {

	
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& str) {
		size_t next_pos = 0;
		bool more = true;
		Utilities util{};
		size_t startCpy{};
		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);
		startCpy = next_pos;
		
		while (more) {util.extractToken(str, next_pos, more); m_cntItem++;}
		
		next_pos = startCpy;
		more = true;

		
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
		}

		
		(m_widthField < util.getFieldWidth()) ? m_widthField = util.getFieldWidth() : m_widthField;
	}


	CustomerOrder::CustomerOrder(const CustomerOrder& customer) { throw "ERROR: Cannot make copies.";}


	CustomerOrder::CustomerOrder(CustomerOrder&& moveCustomer)noexcept { *this = std::move(moveCustomer); }

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& moveCustomer)noexcept {
		if (this != &moveCustomer) {
			if (moveCustomer.m_lstItem != nullptr)
			{
				if (m_lstItem)
				{
					
					for (size_t i = 0; i < m_cntItem; i++) {

						delete m_lstItem[i];
					}
					delete[] m_lstItem;
				}
			

				m_name = moveCustomer.m_name;

				m_product = moveCustomer.m_product;

				m_cntItem = moveCustomer.m_cntItem;

				m_lstItem = moveCustomer.m_lstItem;


				moveCustomer.m_name = "";
				moveCustomer.m_product = "";
				moveCustomer.m_cntItem = 0u;
				moveCustomer.m_lstItem = nullptr;
			}

			
		}

		return *this;

	}

	CustomerOrder::~CustomerOrder() {

		// First deallocating the memory for each item and deallocating the whole memory
		for (size_t i = 0; i < m_cntItem; i++) { delete m_lstItem[i];}
		delete[] m_lstItem; // Then deleting the main pointer to pointer for the list of items by itself.
	}

	bool CustomerOrder::isOrderFilled() const {
		bool result = true;
		for (size_t i = 0u; i < m_cntItem&&result; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				result = false;
			}
		}
		return result;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool result = true;
		for (size_t i = 0; i < m_cntItem&&result; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (!m_lstItem[i]->m_isFilled) {
					result = false;
				}
				
			}
		}

		return result;

	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool filled{ false };
		for (size_t i = 0; i < m_cntItem && !filled; i++) {
			if ((m_lstItem[i]->m_itemName == station.getItemName()) && !m_lstItem[i]->m_isFilled && (station.getQuantity() > 0)) {
				// Subtracting one from the inventory
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				filled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0)) {
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}


	 void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::right << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
            os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
            os << std::endl;
        }
    }



}