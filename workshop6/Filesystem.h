
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Directory.h"
#include "File.h"
namespace seneca {
	class Filesystem {
		Directory* m_root{};
		Directory* m_current{};
	public:
		Filesystem(const std::string& filename, const std::string& rootName = "");
		~Filesystem();
		Filesystem(const Filesystem& src) = delete;
		Filesystem& operator=(const Filesystem& src) = delete;
		Filesystem(Filesystem&& src) noexcept;
		Filesystem& operator=(Filesystem&& src) noexcept;
		Filesystem& operator+=(Resource* resource);
		Directory* change_directory(const std::string& dirName = "");
		Directory* get_current_directory() const;
	};
}
#endif // !SENECA_FILESYSTEM_H

