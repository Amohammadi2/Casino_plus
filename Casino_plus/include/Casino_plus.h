// Casino_plus.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#ifndef A_STRANGE_NAME_THAT_THIS_FILE_HOLD_IT_AGURUYGDGEYUXEN_0X738697368
#define A_STRANGE_NAME_THAT_THIS_FILE_HOLD_IT_AGURUYGDGEYUXEN_0X738697368

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

#ifdef PY_MODULE_IMPL
// when compiling for python module, include this headers as well
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
#endif

template <class Item_Type>
class CasinoRandomGenerator {
public:
	// constructs a new generator
	CasinoRandomGenerator();

	// adds a single item to the generator
	// params:
	//     - new_item {Item_Type} the new item you want to add
	//     - probability_chance: {int} how likely is this item to appear
	void add_item(const Item_Type& new_item, int probabilty_chance);

	// can add multiple items in row
	// params:
	//     - items {std::pair<Item_Type, int>[]} new items you want to add
	//     - len {size_t} the length of the `items` array
	void add_items(std::pair<Item_Type, int> items[], size_t len);

	// get a random item from the generator
	// returns: {Item_Type}
	Item_Type get_random_item();

#ifdef PY_MODULE_IMPL
	// adds sequencial items to the generator
	// side note: only available in python module
	void add_sequence(std::vector<std::pair<Item_Type, int>> items);
#endif

#ifndef G_UNITTEST // expose private members when testing
private:
#endif
	// items available
	std::vector<std::pair<Item_Type, int>> m_rand_items;
	// total probabilities of items, needed for performance reasons
	int m_total_probabilities = 0;
	std::default_random_engine m_engine;

};
#endif
