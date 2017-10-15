//
// Created by juaki on 10/15/17.
//

#ifndef JUEGODELADAVI_MODEL_H
#define JUEGODELADAVI_MODEL_H


#include "../Utils/Matrix.h"
#include "../Implementations/CPU/cpu.h"
#include "../Implementations/OpenCL/parallelOpenCL.h"
#include "../Implementations/CUDA/parallelCuda.h"
#include "../Examples/Example.h"

class model {
public:
    model();
    void runIteration();
    Matrix *getGrid();
    void setCurrentExample(std::string name);
    void setCurrentImplementation(std::string name);

private:
    cpu *implementationcpu;
    opencl *implementationopencl;
    cuda *implementationcuda;

    int currentImplementation;
    int currentExample;

    Example *examples[3];

};


#endif //JUEGODELADAVI_MODEL_H
