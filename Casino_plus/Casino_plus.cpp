﻿// Casino_plus.cpp : Defines the entry point for the application.
//

#include "Casino_plus.h"

template <class Item_Type>
void CasinoRandomGenerator<Item_Type>::AddItem
(const Item_Type& new_item, int probabilty_chance) {
	m_rand_items.push_back({ new_item, probabilty_chance });
	m_total_probabilities += probabilty_chance;
}

template <class Item_Type>
Item_Type CasinoRandomGenerator<Item_Type>::GetRandomItem() {
	std::uniform_int_distribution<int> distribution(1, m_total_probabilities);
	int rand_num = distribution(m_engine);
	for (const auto& item : m_rand_items) {
		rand_num -= item.second;
		if (rand_num <= 0) {
			return item.first;
		}
	}
}

template <class Item_Type>
CasinoRandomGenerator<Item_Type>::CasinoRandomGenerator()
 : m_engine((unsigned int) time(0)) {}

// test
int main() {
	CasinoRandomGenerator<std::string> name_rand;

	name_rand.AddItem("Ashkan Mohammadi", 5);
	name_rand.AddItem("Ilia Mohammadi", 2);
	name_rand.AddItem("Arshia Mohammadi", 3);

	for (int i = 0; i < 10; i++) {
		std::cout << name_rand.GetRandomItem() << std::endl;
	}

	return 0;
}