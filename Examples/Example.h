//
// Created by juaki on 10/12/17.
//

#ifndef JUEGODELADAVI_EXAMPLE_H
#define JUEGODELADAVI_EXAMPLE_H


#include "../Utils/Matrix.h"
#include <fstream>
#include <iostream>

class Example {
public:
    Matrix *getExample();

protected:
    void processMatrix(std::string file);
    Matrix *example;
};


#endif //JUEGODELADAVI_EXAMPLE_H
