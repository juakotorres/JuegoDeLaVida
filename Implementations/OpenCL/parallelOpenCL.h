//
// Created by juaki on 10/13/17.
//

#ifndef JUEGODELADAVI_OPENCL_H
#define JUEGODELADAVI_OPENCL_H


#include "../../Utils/Matrix.h"
#include "../implementations.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>

#include <CL/cl.hpp>

class opencl : public implementations {

public:
    opencl();
    void runIteration(Matrix *grid);
private:
    cl::Context myContext;
    cl::Program myProgram;
    cl::Device default_device;
};


#endif //JUEGODELADAVI_OPENCL_H
