#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include "../cpp/include/ropesim_bits/rope.hpp"

void init_rope(py::module &m) {
    py::class_ <simlogic::particle>(m, "particle")
        .def(py::init())
        .def_readwrite("x", &simlogic::particle::x)
        .def_readwrite("y", &simlogic::particle::y)
        .def_readwrite("xp", &simlogic::particle::xp)
        .def_readwrite("yp", &simlogic::particle::yp)
        .def_readwrite("fixed", &simlogic::particle::fixed);




    py::class_<simlogic::rope>(m, "rope")
        .def(py::init<float, float, float, float, unsigned int>(), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"), py::arg("nparticles"))
        .def("step", &simlogic::rope::step)
        .def("verletintegration", &simlogic::rope::verletintegration)
        .def("enforceconstraints", &simlogic::rope::enforceconstraints)
        .def_readwrite("_particles", &simlogic::rope::_particles)
        .def_readwrite("_desireddistance", &simlogic::rope::_desireddistance);


    m.attr("gravity") = simlogic::gravity;
    m.attr("max_iterations") = simlogic::max_iterations;
    m.attr("dt") = simlogic::dt;
}
