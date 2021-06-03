#define PY_MODULE_IMPL

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <Casino_plus.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include "../Casino_plus/Casino_plus_py.cpp"

namespace py = pybind11;
using str = std::string;


int rand_choice(std::vector<std::pair<int, int>> items)
{
	CasinoRandomGenerator<int> rand;
	
	for (const auto& item: items)
		rand.add_item(item.first, item.second);

	return rand.get_random_item();
}
// defineCRGClass = define Casino Rando Generator class
template<typename Type, typename Handle>
void define_CRGClass(Handle handle, const char* name) {
	py::class_<CasinoRandomGenerator<Type>>(handle, name)
		.def(py::init<>())
		.def("add_item", &CasinoRandomGenerator<Type>::add_item)
		.def("add_sequence", &CasinoRandomGenerator<Type>::add_sequence)
		.def("get_random_item", &CasinoRandomGenerator<Type>::get_random_item);
}



PYBIND11_MODULE(CasinoPlus, handle) {
	handle.doc() = "create uniform and non-uniform distribution";
	handle.def("rand", &rand_choice);
	
	define_CRGClass<int>(handle, "i_CasinoRandomGenerator");
	define_CRGClass<float>(handle, "f_CasinoRandomGenerator");
	define_CRGClass<double>(handle, "d_CasinoRandomGenerator");
	define_CRGClass<char>(handle, "cs_CasinoRandomGenerator");
	define_CRGClass<str>(handle, "s_CasinoRandomGenerator");
}
