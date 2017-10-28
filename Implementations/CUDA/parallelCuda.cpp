/**
 * Implementación paralela en GPU CUDA.
 */

#include "parallelCuda.h"
// Aquí declaramos el método que se usará en el .cu
extern void run(int* a, int W, int H);

void cuda::runIteration(Matrix *grid) {
    run(grid->getMatrix(), grid->getWidth(), grid->getHeight());
}
