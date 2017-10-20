//
// Created by juaki on 10/15/17.
//

#include "model.h"
#include "../Examples/Waifu.h"
#include "../Examples/Replicator.h"
#include "../Examples/Lines.h"

model::model() {
    implementationcpu = new cpu();
    implementationopencl = new opencl();
    implementationcuda = new cuda();

    examples[0] = new Lines();
    examples[1] = new Replicator();
    examples[2] = new Waifu();

    currentImplementation = 0;
    currentExample = 0;
}

Matrix *model::getGrid() {
    return examples[currentExample]->getExample();
}

void model::runIteration() {
    switch(currentImplementation){
        case 0:
            implementationcpu->runIteration(getGrid());
            break;
        case 2:
            implementationopencl->runIteration(getGrid());
            break;
        case 1:
            implementationcuda->runIteration(getGrid());
            break;

    }

}

void model::setCurrentExample(std::string name) {
    if (name.compare("Lines") == 0)
        currentExample = 0;
    else if (name.compare("Replicator") == 0)
        currentExample = 1;
    else {
        currentExample = 2;
    }
}

void model::setCurrentImplementation(std::string name) {

    if (name.compare("CPU") == 0)
        currentImplementation = 0;
    else if (name.compare("CUDA") == 0)
        currentImplementation = 1;
    else
        currentImplementation = 2;
}
