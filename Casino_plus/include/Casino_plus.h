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
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
#endif

template <class Item_Type>
class CasinoRandomGenerator {
public:

	CasinoRandomGenerator();

	void add_item(const Item_Type& new_item, int probabilty_chance);
	// Todo @critical: implement this function without variadic templates
	void add_items(std::pair<Item_Type, int> items[], size_t len);
	Item_Type get_random_item();

#ifdef PY_MODULE_IMPL
	void add_sequence(std::vector<std::pair<Item_Type, int>> items);
#endif

#ifndef G_UNITTEST // expose private members when testing
private:
#endif
	std::vector<std::pair<Item_Type, int>> m_rand_items;
	int m_total_probabilities = 0;
	std::default_random_engine m_engine;

};
#endif
