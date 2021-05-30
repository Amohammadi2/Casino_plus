// Casino_plus.h : Include file for standard system include files,
// or project specific include files.

#pragma once

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
	//template <class ... Items>
	//void add_items(Item_Type first, int second, Items ... rest);
	Item_Type get_random_item();

#ifdef PY_MODULE_IMPL
	void add_sequence(py::args args);
#endif

#ifndef G_UNITTEST // expose private members when testing
private:
#endif
	std::vector<std::pair<Item_Type, int>> m_rand_items;
	int m_total_probabilities = 0;
	std::default_random_engine m_engine;

};
