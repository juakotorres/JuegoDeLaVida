//
// Created by juaki on 10/10/17.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix::Matrix(int width, int height) {
    this->valores = new int[height*width];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            valores[i*height + j] = (rand() % static_cast<int>(2));
        }
    }

    this->width = width;
    this->height = height;
}

Matrix::Matrix(int size) {
    Matrix(size, size);
}

void Matrix::setValue(int i, int j, int value) {
    valores[i*height + j] = value;
}

int Matrix::getValue(int i, int j) {
    return valores[i*height + j];
}

int Matrix::getHeight(){
    return this->height;
}

int Matrix::getWidth(){
    return this->width;
}

Matrix::~Matrix() {
    delete(valores);
}

int *Matrix::getMatrix() {
    return valores;
}