#include <utility>
#include <vector>
#include "include/Casino_plus.h"
#include <iostream>

#ifdef PY_MODULE_IMPL
template<class Item_Type>
void CasinoRandomGenerator<Item_Type>::add_sequence(std::vector<std::pair<Item_Type, int>> items) {
	for (const auto& item : items) {
		add_item(item.first, item.second);
	}
}
#endif
