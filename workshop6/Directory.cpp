

#include "Directory.h"
namespace seneca {
	Directory::Directory(std::string name) {
		m_name = name;
		if (!m_name.empty() && m_name.back() != '/') {
			m_name += '/';
		}
			
	}
	Directory::~Directory() {
		for (Resource* resource : m_contents) {
			delete resource;
		}
		m_contents.clear();
	}
	void Directory::update_parent_path(const std::string& path) {
		m_parent_path = path;
		for (Resource* resource : m_contents) {
			resource->update_parent_path(m_parent_path + m_name);
		}
	}
	NodeType Directory::type() const {
		return NodeType::DIR;
	}
	std::string Directory::path() const {
		return m_parent_path + m_name;
	}
	std::string Directory::name() const {
		return m_name;
	}
	int Directory::count() const {
		return static_cast<int>(m_contents.size());
	}
	size_t Directory::size() const {
		size_t totalSize = 0u;
		for (Resource* resource : m_contents) {
			totalSize += resource->size();
		}
		return totalSize;
	}
	Directory& Directory::operator+=(Resource* resource) {
		for (Resource* existing : m_contents) {
			if (existing->name() == resource->name()) {
				throw "This resource already exists";
			}
		}
		m_contents.push_back(resource);
		resource->update_parent_path(m_parent_path + m_name);
		return *this;
	}
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
		for (Resource* resource : m_contents) {
			if (resource->name() == name) {
				return resource;
			}
		}

		if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end()) {
			for (Resource* resource : m_contents) {
				if (resource->type() == NodeType::DIR) {
					Directory* subDirectory = dynamic_cast<Directory*>(resource);
					if (subDirectory) {
						Resource* found = subDirectory->find(name, flags);
						if (found) {
							return found;
						}
					}
				}
			}
		}

		return nullptr;
	}
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags) {
		auto it = std::find_if(m_contents.begin(), m_contents.end(), [&](Resource* resource) {
			return resource->name() == name;
			});
		if (it != m_contents.end()) {
			if ((*it)->type() == NodeType::DIR) {
	
				if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end()) {
					delete* it;
					m_contents.erase(it);
				}
				else {
					throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
				}
			}
			else {
				delete* it;
				m_contents.erase(it);
			}
		}
		else {
			throw std::string(name + " does not exist in " + m_name);
		}
	}
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const {
		bool isLong = false;
		for (FormatFlags flag : flags) {
			if (flag == seneca::FormatFlags::LONG) {
				isLong = true;
			}
		}
		os << "Total size: " << size() << " bytes" << std::endl;
		for (size_t i = 0; i < m_contents.size(); i++) {
			if (isLong) {
				if (m_contents[i]->type() == seneca::NodeType::DIR) {
					os << "D | ";
					os << std::left << std::setw(15) << m_contents[i]->name() << " | ";
					os << std::right << std::setw(2) << m_contents[i]->count() << " |";
					os << std::right << std::setw(5) << m_contents[i]->size() << " bytes | ";

				}
				else {
					os << "F | ";
					os << std::left << std::setw(15) << m_contents[i]->name() << " | ";
					os << std::setw(2) << "   |";
					os << std::right << std::setw(5) << m_contents[i]->size() << " bytes | ";

				}
			}
			else {
				if (m_contents[i]->type() == seneca::NodeType::DIR) {
					os << "D | ";
					os << std::left << std::setw(15) << m_contents[i]->name() << " |";
				}
				else{
					os << "F | ";
					os << std::left << std::setw(15) << m_contents[i]->name() << " |";
				}
			}
			os << std::endl;
			os.unsetf(std::ios::left);
			os.unsetf(std::ios::right);
		}
	}





}

