
#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include <vector>
#include <iostream>
#include "Resource.h"
#include <algorithm>
#include <stdexcept>
#include <iomanip>
namespace seneca {
	class Directory:public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(std::string name);
		~Directory();
		void update_parent_path(const std::string& path);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource*);
		Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
		Directory(const Directory& src) = delete;
		Directory& operator=(const Directory& src) = delete;
		void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const;
	};
}
#endif // !SENECA_DIRECTORY_H

