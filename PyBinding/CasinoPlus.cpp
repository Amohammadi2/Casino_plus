#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <Casino_plus.h>

namespace py = pybind11;

PYBIND11_MODULE(CasinoPlus, handle) {
	handle.doc() = "Casino plus python binding wrapper";
	// Todo: implement the library

}