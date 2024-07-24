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

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace seneca
{

	class LineManager
	{
		// the collection of workstations for the current assembly line.
		std::vector<Workstation*> m_activeLine;
		//the total number of CustomerOrder objects
		size_t m_cntCustomerOrder{ 0u };

		//points to the first active station on the current line
		Workstation* m_firstStation{ nullptr };
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif //SENECA_LineManager_H
