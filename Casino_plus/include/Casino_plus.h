// Casino_plus.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

template <class Item_Type>
class CasinoRandomGenerator {
public:

	CasinoRandomGenerator();

	void add_item(const Item_Type& new_item, int probabilty_chance);
	template <class ... Items>
	void add_items(Item_Type first, Items ... rest);
	Item_Type get_random_item();

#ifndef G_UNITTEST // expose private members when testing
private:
#endif
	std::vector<std::pair<Item_Type, int>> m_rand_items;
	int m_total_probabilities = 0;
	std::default_random_engine m_engine;

};
