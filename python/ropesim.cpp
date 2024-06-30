#include <pybind11/pybind11.h>
#include "ropesim_bits/rope.hpp"

namespace py = pybind11;

void init_rope(py::module &);

PYBIND11_MODULE(ropesim, m) {
    // Optional docstring
    m.doc() = "Rope simulation library";
    
    init_rope(m);
}