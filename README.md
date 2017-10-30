# JuegoDeLaVida
El juego de la vida programado para comparar rendimiento entre CPU y GPU.

Se debe instalar las siguientes bibliotecas:

- Qt5
- OpenCL (mínimo para intel)
- CUDA
- cmake
- g++
- nvcc

Este proyecto fue instalado en un pc con sistema operativo archlinux y un paquete necesario fue:

- ocl-icd

Para ejecutar el proyecto:

Estar en el directorio raiz del proyecto.
Crear carpeta build.
Ir a build
Ejecutar "cmake .."
Ejecutar "make"
Ejecutar "cd .."
Finalmente se corre el programa con "./build/JuegoDeLaDavi".