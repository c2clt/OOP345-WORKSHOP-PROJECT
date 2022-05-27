#ifndef SDDS_KVP_H__
#define SDDS_KVP_H__
#include <iostream>

namespace sdds {
	template <typename K, typename V, unsigned int valSize>
	class KVP {
		K m_key{};
		V m_val[valSize]{};
	public:
		std::istream& read(std::istream& is = std::cin) {
			is >> m_key;
			for (unsigned int i = 0; i < valSize; i++) {
				std::cout << (i + 1) << "/" << valSize << ": ";
				is >> m_val[i];
				is.ignore(1000, '\n');
			}

			return is;
		}

		std::ostream& print(std::ostream& os = std::cout) const {
			os << m_key;
			for (unsigned int i = 0; i < valSize; i++) {
				os << m_val[i];
				if (i != valSize - 1) {
					os << ", ";
				}
			}

			return os << std::endl;
		}
	};

	template <typename K, typename V, unsigned int valSize>
	std::ostream& operator<< (std::ostream& os, const KVP<K, V, valSize>& kvp) {
		return kvp.print(os);
		
	}

	template <typename K, typename V, unsigned int valSize>
	std::istream& operator>> (std::istream& is, KVP<K, V, valSize>& kvp) {
		return kvp.read(is);
	}
}
#endif
