//
// Created by juaki on 10/12/17.
//

#include "Example.h"

Matrix *Example::getExample() {
    return example;
}

void Example::processMatrix(std::string file) {
    std::ifstream f(file, std::ios::in);
    int m, n;
    f >> m >> n;

    this->example = new Matrix(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int valor;
            f >> valor;
            example->setValue(i, j, valor);
        }
    }
}

