/**
 * Clase que representa el mundo del juego.
 *
 * Es una matriz que es mapeada a un arreglo de una dimensión.
 */

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Constructor de la clase. Genera la matriz de tamaño width*height rellena de ceros.
 *
 */
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

/**
 * Constructor para una matriz cuadrada.
 */
Matrix::Matrix(int size) {
    Matrix(size, size);
}

/**
 * Setea el valor en la fila i columna j de la matriz con el valor dado.
 */
void Matrix::setValue(int i, int j, int value) {
    valores[i*height + j] = value;
}

/**
 * Retorna el valor en la fila i columna j.
 */
int Matrix::getValue(int i, int j) {
    return valores[i*height + j];
}

/**
 * Entrega el alto de la matriz.
 */
int Matrix::getHeight(){
    return this->height;
}

/**
 * Entrega el ancho de la matriz.
 */
int Matrix::getWidth(){
    return this->width;
}

Matrix::~Matrix() {
    delete(valores);
}

/**
 * Retorna el arreglo de una dimensión que representa a la matriz.
 */
int *Matrix::getMatrix() {
    return valores;
}