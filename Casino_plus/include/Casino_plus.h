// Casino_plus.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <ctime>
#include <string>

template <class Item_Type>
class CasinoRandomGenerator {
private:
	std::vector<std::pair<Item_Type, int>> m_rand_items;
	int m_total_probabilities = 0;
	std::default_random_engine m_engine;

public:
	CasinoRandomGenerator();

	void AddItem(const Item_Type& new_item, int probabilty_chance);
	Item_Type GetRandomItem();
};
