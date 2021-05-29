#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <Casino_plus.h>
#include <iostream>
#include <string>
#include <cstring>

namespace py = pybind11;
using str = std::string;

// Todo: remove this test function and export all
//       instantiations of CasinoRandomGenerator
int func(int a, int distro_a, int b, int distro_b)
{
	CasinoRandomGenerator<int> rand;
	
	rand.add_item(a, distro_a);
	rand.add_item(b, distro_b);

	return rand.get_random_item();
}

template<typename Type, typename Handle>
void define_CRGClass(Handle handle, char* name) {
	py::class_<CasinoRandomGenerator<Type>>(handle, name)
		.def(py::init<>())
		.def("add_item", &CasinoRandomGenerator<Type>::add_item)
		.def("get_random_item", &CasinoRandomGenerator<Type>::get_random_item); 
}

PYBIND11_MODULE(CasinoPlus, handle) {
	handle.doc() = "Casino plus python binding wrapper";
	handle.def("rand", &func);
	
	define_CRGClass<int>(handle, "i_CasinoRandomGenerator");
	define_CRGClass<float>(handle, "f_CasinoRandomGenerator");
	define_CRGClass<double>(handle, "d_CasinoRandomGenerator");
	define_CRGClass<char>(handle, "cs_CasinoRandomGenerator");
	define_CRGClass<std::string>(handle, "s_CasinoRandomGenerator");
	//define_CRGClass<std::string>(handle, "s_");
}