//
// Created by juaki on 10/12/17.
//

#include <iostream>
#include "cpu.h"

void cpu::runIteration(Matrix *grid) {

    int width = grid->getWidth();
    int height = grid->getHeight();

    Matrix gridA(width, height);

    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            int right, left, up, down;
            int sum = 0;

            left = (i + width - 1)%width;
            right = (i + 1)%width;
            down = (j + 1)%height;
            up = (j + height - 1)%height;

            //std::cout << "i: " << i << " j :" << j << "  " << left << right << up << down << std::endl;
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
            //printf("%d", sum);

            int value = grid->getValue(i,j);

            if ( (value == 1 && (sum == 2 || sum == 3)) || (value == 0 && (sum == 3 || sum == 6) ) ){
                gridA.setValue(i,j,1);
            } else {
                gridA.setValue(i,j,0);
            }
        }
    }

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            grid->setValue(i,j, gridA.getValue(i,j));
        }
    }
}
