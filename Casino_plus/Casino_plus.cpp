#include "include/Casino_plus.h"

template <class Item_Type>
void CasinoRandomGenerator<Item_Type>::add_item
(const Item_Type& new_item, int probabilty_chance) {
	m_rand_items.push_back({ new_item, probabilty_chance });
	m_total_probabilities += probabilty_chance;
}

template <class Item_Type>
Item_Type CasinoRandomGenerator<Item_Type>::get_random_item() {
	std::uniform_int_distribution<int> distribution(1, m_total_probabilities);
	int rand_num = distribution(m_engine);
	for (const auto& item : m_rand_items) {
		rand_num -= item.second;
		if (rand_num <= 0) {
			return item.first;
		}
	}
	return 0;
}

template <class Item_Type>
template <class ... Items>
void CasinoRandomGenerator<Item_Type>::add_items(Item_Type first, Items ...) {
	m_rand_items.push_back(first);
	add_items(...);
}

template <class Item_Type>
CasinoRandomGenerator<Item_Type>::CasinoRandomGenerator()
 : m_engine((unsigned int) time(0)) {}


#pragma region [CasinoRandomGenerator] template instantiation

// instantiate basic types
template class CasinoRandomGenerator<int>;
template class CasinoRandomGenerator<float>;
template class CasinoRandomGenerator<double>;
template class CasinoRandomGenerator<char>;
template class CasinoRandomGenerator<bool>;
template class CasinoRandomGenerator<std::string>;

#pragma endregion