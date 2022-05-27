
#include "Helper.h"

namespace sdds {
	void trim(std::string& str) {
		if (!str.empty())
		{
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}
	}

	bool isInteger(std::string& str) {
		bool res = true;
		for (size_t i = 0u; i < str.size() && res; i++) {
			if (!isdigit(str[i])) {
				res = false;
			}
		}

		return res;
	}
}