/**
 * Implementación en CPU del juego de la vida.
 */

#include <iostream>
#include "cpu.h"

void cpu::runIteration(Matrix *grid) {

    // guardamos variables locales.
    int width = grid->getWidth();
    int height = grid->getHeight();

    // Creamos una matriz donde dejaremos el resultado.
    Matrix gridA(width, height);

    // iteramos sobre toda la matriz.
    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){

            // variables locales para aumentar rendimiento.
            int right, left, up, down;
            int sum = 0;

            // Calculamos cuales son los indices de las casillas vecinas.
            left = (i + width - 1)%width;
            right = (i + 1)%width;
            down = (j + 1)%height;
            up = (j + height - 1)%height;

            // Por cada casilla vecina tomamos su valor y se lo sumamos a una variable acumuladora.

            // left
            sum += grid->getValue(right, j);
            // right
            sum += grid->getValue(left, j);
            // up
            sum += grid->getValue(i, up);
            // down
            sum += grid->getValue(i, down);
            // upright
            sum += grid->getValue(right, up);
            // downright
            sum += grid->getValue(right, down);
            // upleft
            sum += grid->getValue(left, up);
            // downleft
            sum += grid->getValue(left, down);

            // Tomamos el valor de la casilla.
            int value = grid->getValue(i,j);

            // Guardamos el valor según la condicion de Conway.
            gridA.setValue(i, j, (value == 1 && (sum == 2 || sum == 3)) || (value == 0 && (sum == 3 || sum == 6) ) );
        }
    }

    // Copiamos los valores a la matriz original.
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            grid->setValue(i,j, gridA.getValue(i,j));
        }
    }
}
