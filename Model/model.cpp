/**
 * Clase que representa el modelo del juego
 */

#include "model.h"
#include "../Examples/Waifu.h"
#include "../Examples/Replicator.h"
#include "../Examples/Lines.h"

model::model() {

    // Se inicializan las implementaciones.
    implementationcpu = new cpu();
    implementationopencl = new opencl();
    implementationcuda = new cuda();

    // se inicializan los ejemplos y se guardan en un arreglo.
    examples[0] = new Lines();
    examples[1] = new Replicator();
    examples[2] = new Waifu();

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
    implementationopencl->runIteration(getGrid());
}

/**
 * Setea el ejemplo a correr.
 */
void model::setCurrentExample(std::string name) {
    if (name.compare("Lines") == 0)
        currentExample = 0;
    else if (name.compare("Replicator") == 0)
        currentExample = 1;
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
