//
// Created by juaki on 10/15/17.
//

#ifndef JUEGODELADAVI_PARALLELCUDA_H
#define JUEGODELADAVI_PARALLELCUDA_H


#include "../implementations.h"

class cuda : public implementations{

public:
    void runIteration(Matrix *grid);
};


#endif //JUEGODELADAVI_PARALLELCUDA_H
