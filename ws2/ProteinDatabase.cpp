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

#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>

namespace seneca {
    ProteinDatabase::ProteinDatabase() : sequences(nullptr), numSequences(0) {}

    ProteinDatabase::ProteinDatabase(const std::string& filename) : sequences(nullptr), numSequences(0) {
        std::ifstream file(filename);
        if (!file) {
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line[0] == '>') {
                ++numSequences;
            }
        }

        file.clear();
        file.seekg(0);

        sequences = new std::string[numSequences];
        size_t index = 0;
        std::string sequence;

        while (std::getline(file, line)) {
            if (line[0] == '>') {
                if (!sequence.empty()) {
                    sequences[index++] = sequence;
                    sequence.clear();
                }
            }
            else {
                sequence += line;
            }
        }

        if (!sequence.empty()) {
            sequences[index] = sequence;
        }
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) : sequences(nullptr), numSequences(other.numSequences) {
        if (numSequences > 0) {
            sequences = new std::string[numSequences];
            for (size_t i = 0; i < numSequences; ++i) {
                sequences[i] = other.sequences[i];
            }
        }
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept : sequences(other.sequences), numSequences(other.numSequences) {
        other.sequences = nullptr;
        other.numSequences = 0;
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &other) {
            delete[] sequences;
            numSequences = other.numSequences;
            sequences = new std::string[numSequences];
            for (size_t i = 0; i < numSequences; ++i) {
                sequences[i] = other.sequences[i];
            }
        }
        return *this;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
        if (this != &other) {
            delete[] sequences;
            sequences = other.sequences;
            numSequences = other.numSequences;
            other.sequences = nullptr;
            other.numSequences = 0;
        }
        return *this;
    }

    ProteinDatabase::~ProteinDatabase() {
        delete[] sequences;
    }

    size_t ProteinDatabase::size() const {
        return numSequences;
    }

    std::string ProteinDatabase::operator[](size_t index) const {
        if (index >= numSequences) {
            return "";
        }
        return sequences[index];
    }
}
