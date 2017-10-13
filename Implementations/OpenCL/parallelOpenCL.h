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

#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>

class opencl : public implementations {

public:
    void runIteration(Matrix *grid);
};


#endif //JUEGODELADAVI_OPENCL_H
