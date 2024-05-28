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

#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <chrono>
#include <string>

namespace seneca {
    struct Task {
        std::string taskName;
        std::string timeUnit;
        std::chrono::nanoseconds duration;
    };

    class TimedTask {
        Task tasks[10];
        int numRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* taskName);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& task);
    };
}

#endif
