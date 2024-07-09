
#include "Filesystem.h"
namespace seneca {
    Filesystem::Filesystem(const std::string& fileName, const std::string& rootName) {

        std::ifstream inputFile(fileName);
        if (inputFile) {
            m_root = new Directory(rootName);
            m_current = m_root;
            std::string line;
            while (getline(inputFile, line)) {
                std::string filePath, contents;
                size_t delimiterPos = line.find("|");
                size_t pos1 = line.find_first_not_of(" ");
                size_t pos2 = line.find_last_not_of(" ", delimiterPos - 1);
                filePath = line.substr(pos1, pos2 - pos1 + 1);
                line.erase(0, delimiterPos + 1);
                pos1 = line.find_first_not_of(" ");
                line.erase(0, pos1);
                pos2 = line.find_last_not_of(" ");
                contents = line.substr(0, pos2 + 1);
                size_t pos = 0;
                std::vector<seneca::OpFlags> oflags;
                oflags.push_back(seneca::OpFlags::RECURSIVE);
                Directory* rootDirectory = m_root;
                while ((pos = filePath.find("/")) != std::string::npos) {
                    if (!(m_root->find(filePath.substr(0, pos + 1), oflags))) {
                        Directory* dir = new Directory(filePath.substr(0, pos + 1));
                        *rootDirectory += dir;
                        rootDirectory = dir;
                    }
                    else {
                        rootDirectory = dynamic_cast<Directory*>(m_root->find(filePath.substr(0, pos + 1), oflags));
                    }
                    filePath = filePath.substr(pos + 1);
                }

                if (delimiterPos != std::string::npos) {
                    if (!(m_root->find(filePath))) {
                        File* file = new File(filePath, contents);
                        *rootDirectory += file;
                    }
                }
            }
            
        }
        else {
            throw std::invalid_argument("File not found: " + fileName);
        }

    }

    Filesystem::~Filesystem() {
        delete m_root;
    }
    Filesystem::Filesystem(Filesystem&& src) noexcept {
        *this = std::move(src);
    }
    Filesystem& Filesystem::operator=(Filesystem&& src) noexcept {
        if (this != &src) {
            delete m_root;
            m_root = src.m_root;
            m_current = src.m_current;
            src.m_root = nullptr;
            src.m_current = nullptr;
        }
        return *this;
    }
    Filesystem& Filesystem::operator+=(Resource* resource) {
        if (resource) {
            m_current->operator+=(resource);
        }
        return *this;
    }
    Directory* Filesystem::change_directory(const std::string& dirName) {
        if (dirName.empty()) {
            m_current = m_root;
            return m_current;
        }
        std::string cleanDirName = dirName;
        cleanDirName.erase(0, cleanDirName.find_first_not_of(' '));
        cleanDirName.erase(cleanDirName.find_last_not_of(' ') + 1);
        Resource* resource = m_current->find(cleanDirName);
        if (resource && resource->type() == NodeType::DIR) {
            m_current = dynamic_cast<Directory*>(resource);
            return m_current;
        }
        else {
            throw std::invalid_argument("Cannot change directory! " + dirName + " not found!");
        }
    }
    Directory* Filesystem::get_current_directory() const {
        return m_current;
    }
}