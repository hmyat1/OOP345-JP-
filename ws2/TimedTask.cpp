/*/////////////////////////////////////////////////////////////////////////
                       Workshop - 2 
Full Name  :Hla Myint Myat 
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.
 /////////////////////////////////////////////////////////////////////////*/

#include "TimedTask.h"
#include <chrono>
#include <iomanip>

namespace seneca {
    TimedTask::TimedTask() : numRecords(0) {}

    void TimedTask::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* taskName) {
        if (numRecords < 10) {
            tasks[numRecords].taskName = taskName;
            tasks[numRecords].timeUnit = "nanoseconds";
            tasks[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            numRecords++;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedTask& task) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < task.numRecords; ++i) {
            os << std::setw(21) << std::left << task.tasks[i].taskName
                << std::setw(13) << std::right << task.tasks[i].duration.count()
                << ' ' << task.tasks[i].timeUnit << '\n';
        }
        os << "--------------------------\n";
        return os;
    }
}
