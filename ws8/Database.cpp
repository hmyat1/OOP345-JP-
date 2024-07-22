/***********************************************************************
                        Workshop - 8

Name : Hla Myint Myat
Email : hmyat1@myseneca.ca
Student ID : 185923216

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

***********************************************************************/

#include "Database.h"
#include <iomanip>
#include <algorithm>

namespace seneca {
    template<typename T>
    std::shared_ptr<Database<T>> Database<T>::instance = nullptr;

    template<typename T>
    Database<T>::Database(const std::string& filename) : filename(filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("File could not be opened");
        }

        std::cout << "[" << this <<"] ";
        std::cout << "Database(const std::string&)" << std::endl;

        std::string key;
        T value;
        while (file >> key >> value) {
            if (numEntries >= capacity) {
                break;
            }
            std::replace(key.begin(), key.end(), '_', ' ');
            encryptDecrypt(value);
            keys[numEntries] = key;
            values[numEntries] = value;
            numEntries++;
        }
    }

    template<typename T>
    std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& filename) {
        if (!instance) {
            instance = std::shared_ptr<Database<T>>(new Database<T>(filename));
        }
        return instance;
    }

    template<typename T>
    Err_Status Database<T>::GetValue(const std::string& key, T& value) const {
        for (int i = 0; i < numEntries; ++i) {
            if (keys[i] == key) {
                value = values[i];
                return Err_Status::Err_Success;
            }
        }
        return Err_Status::Err_NotFound;
    }

    template<typename T>
    Err_Status Database<T>::SetValue(const std::string& key, const T& value) {
        if (numEntries >= capacity) {
            return Err_Status::Err_OutOfMemory;
        }
        keys[numEntries] = key;
        values[numEntries] = value;
        numEntries++;
        return Err_Status::Err_Success;
    }


    template<typename T>
    Database<T>::~Database() {
    std::cout << "[" << this << "] ";
    std::cout << "~Database()" << std::endl;

    // Open the backup file in binary mode if dealing with non-text data
    std::ofstream backupFile(filename + ".bkp.txt", std::ios::out | std::ios::binary);
    if (!backupFile) {
        std::cerr << "Error opening backup file for writing." << std::endl;
        return;
    }

    for (int i = 0; i < numEntries; ++i) {
        T encryptedValue = values[i];
        encryptDecrypt(encryptedValue);
        // For string, use .c_str() to convert to const char*
        // For other types, ensure they have operator<< defined
        backupFile << std::left << std::setw(25) << keys[i] << " -> " << encryptedValue << std::endl;
    }

    backupFile.close(); // Always close the file when done
}

template<>
void Database<std::string>::encryptDecrypt(std::string& toEncrypt) {
    const char secret[] = "secret encryption key";
    size_t secret_len = sizeof(secret) - 1; // Exclude null terminator

   
    for (char& c : toEncrypt) {
        for (size_t j = 0; j < secret_len; ++j) {
            c = c ^ secret[j];
        }
       
    }
   
}

     template<>
void Database<long long>::encryptDecrypt(long long& value) {
    const char secret[] = "super secret encryption key";
    size_t secret_len = sizeof(secret) - 1; // Exclude null terminator

    // Reinterpret the long long value as a sequence of bytes
    char* data = reinterpret_cast<char*>(&value);

    // XOR each byte of the long long value with each character in the secret
    for (size_t i = 0; i < sizeof(long long); ++i) {
        for (size_t j = 0; j < secret_len; ++j) {
            data[i] ^= secret[j];
        }
    }
}
   
    // Explicit template instantiation
    template class Database<std::string>;
    template class Database<long long>;
}
