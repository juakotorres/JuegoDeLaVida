//
// Created by juaki on 10/15/17.
//

#include "parallelCuda.h"
extern void run(int* a, int W, int H);

void cuda::runIteration(Matrix *grid) {
    run(grid->getMatrix(), grid->getWidth(), grid->getHeight());
}
