#include "dummySolver.hpp"

std::string DummySolver::getProblemName(std::string problemToken) {
    if(problemToken == "-l") {
        return "Lid Driven Cavity";
    }

    if(problemToken == "-psf") {
        return "Plane Shear Flow";
    }

    if(problemToken == "-fs") {
        return "Flow Over Step";
    }

    return "Invalid Problem";
}
