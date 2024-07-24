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

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca
{
	// holds the orders to be placed onto the assembly line at the first station.
	extern std::deque<CustomerOrder> g_pending;

	//holds the orders that have been removed from the last station and have been completely filled.
	extern std::deque<CustomerOrder> g_completed;

	//holds the orders that have been removed from the last station and could not be filled completely.
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		// a pointer to the next Workstation on the assembly line.
		Workstation* m_pNextStation = nullptr;
	public:
		// one argument constructor with const reference to string with Station as a paramatarized constructor
		Workstation(const std::string& src) : Station(src) {}; 

//this modifier fills the order at the front of the queue if there are CustomerOrders in the queue; otherwise, does nothing.
		void fill(std::ostream& os);

		// attempts to move the order order at the front of the queue to the next station in the assembly line:
		bool attemptToMoveOrder();

		// setter function to set the next station
		void setNextStation(Workstation* station); 

		// function to get the next station
		Workstation* getNextStation() const; 

		// display function
		void display(std::ostream& os) const; 
		Workstation& operator+=(CustomerOrder&& newOrder); 

		// Deleting any copy or moving operations
		Workstation(const Workstation&) = delete; 
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};
}

#endif // SENECA_WORKSTATION_H

