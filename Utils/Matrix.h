//
// Created by juaki on 10/10/17.
//

#ifndef JUEGODELADAVI_MATRIX_H
#define JUEGODELADAVI_MATRIX_H


class Matrix {

public:
    Matrix(int width, int height);
    Matrix(int size);

    void setValue(int i, int j, int value);
    int getValue(int i, int j);
    int getHeight();
    int getWidth();
    int *getMatrix();

    ~Matrix();

    void randomMatrix();

private:
    int height,width;
    int* valores;
};


#endif //JUEGODELADAVI_MATRIX_H
