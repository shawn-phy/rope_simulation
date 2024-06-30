#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include "../cpp/include/ropesim_bits/rope.hpp"

void init_rope(py::module &m) {
    py::class_<simlogic::rope>(m, "rope")
        .def(py::init<float, float, float, float, unsigned int>(), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"), py::arg("nparticles"))
        .def("step", &simlogic::rope::step);
}
