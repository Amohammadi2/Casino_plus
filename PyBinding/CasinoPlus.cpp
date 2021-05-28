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
	
	rand.AddItem(a, distro_a);
	rand.AddItem(b, distro_b);

	return rand.GetRandomItem();
}

template<typename Type, typename Handle>
void define_CRGClass(Handle handle, char* name) {
	py::class_<CasinoRandomGenerator<Type>>(handle, name)
		.def(py::init<>())
		.def("add_item", &CasinoRandomGenerator<Type>::AddItem)
		.def("get_random_item", &CasinoRandomGenerator<Type>::GetRandomItem); 
}

PYBIND11_MODULE(CasinoPlus, handle) {
	handle.doc() = "Casino plus python binding wrapper";
	handle.def("rand", &func);
	
	define_CRGClass<int>(handle, "i_CasinoRandomGenerator");
	define_CRGClass<std::string>(handle, "s_CasinoRandomGenerator");
	//define_CRGClass<std::string>(handle, "s_");
}