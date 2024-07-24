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

#include "LineManager.h"
#include <fstream>
#include <algorithm>
#include "Utilities.h"
#include <string>
using namespace std;

namespace seneca
{
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        std::ifstream filename(file);

        if (!filename) {
            throw std::string("unable to open file");
        }
        size_t next_pos = 0u;
        bool more = false;
        Utilities util; // making a instance of the Utilities class
        std::string line;
        while (std::getline(filename, line)) {

            if (line.empty()==false) {

                next_pos = 0;

                std::string station = util.extractToken(line, next_pos, more);
                std::string next_station = "a";
                if (more)
                {
                    next_station = util.extractToken(line, next_pos, more);
                }

                Workstation* ws = nullptr;
                Workstation* next_ws = nullptr;
                for (auto& s_ptr : stations) {
                    if (s_ptr->getItemName() == station) {
                        ws = s_ptr;
                    }
                    if (s_ptr->getItemName() == next_station) {
                        next_ws = s_ptr;
                    }
                }
                if (ws && next_ws) {
                    ws->setNextStation(next_ws);
                    m_activeLine.push_back(ws);
                }
                else
                {
                    m_activeLine.push_back(ws);
                }
            }
        }
        filename.close(); // closing the file while reading from assembleLine.txt file

        m_firstStation = nullptr;
        for (auto& s_ptr : stations) {
            bool found = false;
            for (auto& checkStation : stations) {
                if (checkStation->getNextStation() == s_ptr) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                m_firstStation = s_ptr;
                break;
            }
        }
        if (!m_firstStation) {
            throw std::string("error");
        }

      
        m_cntCustomerOrder = g_pending.size();
    }

    // Reording the orders in the station while pushing back the stations. 
    void LineManager::reorderStations()
    {
        Workstation* forward_station = m_firstStation;
        vector<Workstation*>  ws;

        while (forward_station) {
            ws.push_back(forward_station);
            forward_station = forward_station->getNextStation();
        }

        m_activeLine = ws;

    }
    bool LineManager::run(std::ostream& os)
    {

        static size_t count = 0u;

        os << "Line Manager Iteration: " << ++count << endl;

        if (!g_pending.empty()) {
            *m_activeLine.front() += move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto i : m_activeLine)
            i->fill(os);

        for (auto i : m_activeLine)
            i->attemptToMoveOrder();

        return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();

    }

    // Using stl algorithms instead of for loop and if statment  
    void LineManager::display(std::ostream& os) const
    {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* src) {
            src->display(os);
            });

    }
}