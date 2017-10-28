/**
 * Clase que representa el modelo del juego
 */

#include "model.h"
#include "../Examples/Waifu.h"
#include "../Examples/Replicator.h"
#include "../Examples/Lines.h"
#include "../Examples/RandomExample.h"

model::model() {

    // Se inicializan las implementaciones.
    implementationcpu = new cpu();
    implementationopencl = new opencl();
    implementationcuda = new cuda();

    // se inicializan los ejemplos y se guardan en un arreglo.
    examples[0] = new Lines();
    examples[1] = new Replicator();
    examples[2] = new Waifu();
    examples[3] = new RandomExample(1920, 1080);

    currentImplementation = 0;
    currentExample = 0;
}

/**
 * Retorna el ejemplo seleccionado.
 */
Matrix *model::getGrid() {
    return examples[currentExample]->getExample();
}

/**
 * Corre una iteración del modelo.
 */
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

/**
 * Setea el ejemplo a correr.
 */
void model::setCurrentExample(std::string name) {
    if (name.compare("Lines") == 0)
        currentExample = 0;
    else if (name.compare("Replicator") == 0)
        currentExample = 1;
    else if (name.compare("Random") == 0)
        currentExample = 3;
    else {
        currentExample = 2;
    }
}

/**
 * Setea la implementación que se usará.
 */
void model::setCurrentImplementation(std::string name) {

    if (name.compare("CPU") == 0)
        currentImplementation = 0;
    else if (name.compare("CUDA") == 0)
        currentImplementation = 1;
    else
        currentImplementation = 2;
}

std::string model::getImplementation() {
    if (currentImplementation == 0)
        return "CPU";
    else if (currentImplementation == 1)
        return "CUDA";
    else {
        return "OpenCL";
    }
}
