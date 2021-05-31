#define PY_MODULE_IMPL

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <Casino_plus.h>
#include "../Casino_plus/Casino_plus_py.cpp"
#include <iostream>
#include <string>
#include <cstring>

namespace py = pybind11;
using str = std::string;

// Todo: remove this test function and export all
//       instantiations of CasinoRandomGenerator
int func(unsigned long int length , int arr[][2])
{
	CasinoRandomGenerator<int> rand;

	for(int i=0; i < length; i++)
		rand.add_item(arr[i][0] , arr[i][1]);


	return rand.get_random_item();
}

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
	handle.def("rand", &func);

	define_CRGClass<int>(handle, "i_CasinoRandomGenerator");
	define_CRGClass<float>(handle, "f_CasinoRandomGenerator");
	define_CRGClass<double>(handle, "d_CasinoRandomGenerator");
	define_CRGClass<char>(handle, "cs_CasinoRandomGenerator");
	define_CRGClass<str>(handle, "s_CasinoRandomGenerator");
	//define_CRGClass<std::string>(handle, "s_");
}
