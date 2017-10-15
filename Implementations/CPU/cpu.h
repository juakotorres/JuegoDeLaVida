//
// Created by juaki on 10/12/17.
//

#ifndef JUEGODELADAVI_HIGHLIFECPU_H
#define JUEGODELADAVI_HIGHLIFECPU_H


#include "../../Utils/Matrix.h"
#include "../implementations.h"

class cpu : public implementations{

public:
    void runIteration(Matrix *grid);

};


#endif //JUEGODELADAVI_HIGHLIFECPU_H
