//
// Created by juaki on 10/12/17.
//

#include "GosperGliderGun.h"

GosperGliderGun::GosperGliderGun() {

    this->example = new Matrix(38, 38);

    example->setValue(3, 37 - 1, 1);
    example->setValue(4, 37 - 1, 1);
    example->setValue(3, 37 - 2, 1);
    example->setValue(4, 37 - 2, 1);

    example->setValue(1, 37 - 13, 1);
    example->setValue(2, 37 - 13, 1);
    example->setValue(6, 37 - 13, 1);
    example->setValue(7, 37 - 13, 1);

    example->setValue(2, 37 - 15, 1);
    example->setValue(6, 37 - 15, 1);

    example->setValue(3, 37 - 16, 1);
    example->setValue(4, 37 - 16, 1);
    example->setValue(5, 37 - 16, 1);
    example->setValue(3, 37 - 17, 1);
    example->setValue(4, 37 - 17, 1);
    example->setValue(5, 37 - 17, 1);

    example->setValue(6, 37 - 20, 1);
    example->setValue(5, 37 - 21, 1);
    example->setValue(6, 37 - 21, 1);
    example->setValue(7, 37 - 21, 1);
    example->setValue(4, 37 - 22, 1);
    example->setValue(8, 37 - 22, 1);
    example->setValue(6, 37 - 23, 1);
    example->setValue(9, 37 - 24, 1);
    example->setValue(3, 37 - 24, 1);
    example->setValue(9, 37 - 25, 1);
    example->setValue(3, 37 - 25, 1);
    example->setValue(4, 37 - 26, 1);
    example->setValue(8, 37 - 26, 1);
    example->setValue(5, 37 - 27, 1);
    example->setValue(6, 37 - 27, 1);
    example->setValue(7, 37 - 27, 1);

    example->setValue(5, 1, 1);
    example->setValue(6, 1, 1);
    example->setValue(5, 2, 1);
    example->setValue(6, 2, 1);
}