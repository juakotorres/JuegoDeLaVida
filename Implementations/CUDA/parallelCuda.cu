#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <device_launch_parameters.h>
#include <cuda_runtime_api.h>
#include <iostream>


// CUDA kernel. Each thread takes care of one element of c
__global__ void deviceIteration(int *c, int *a, int H, int W)
{
    // Get our global thread ID
    const int k = blockIdx.x;
    if (k < W*H) {

        const int i = k / H;
        const int j = k % H;

        int sum = 0;

        const int left = (i + W - 1) % W;
        const int right = (i + 1) % W;
        const int down = (j + 1) % H;
        const int up = (j + H - 1) % H;

        // left
        sum += a[right * H + j];
        // right
        sum += a[left * H + j];
        // up
        sum += a[i * H + up];
        // down
        sum += a[i * H + down];
        // upright
        sum += a[right * H + up];
        // downright
        sum += a[right * H + down];
        // upleft
        sum += a[left * H + up];
        // downleft
        sum += a[left * H + down];

        int value = a[k];
        int result = 0;
        if ((value == 1 && (sum == 2 || sum == 3)) || (value == 0 && (sum == 3 || sum == 6))) {
            result = 1;
        }

        c[k] = result;
    }
}


void run(int* a, int W, int H){


    //Host output vector
    int *h_c;

    // Device input vectors
    int *d_a;
    //Device output vector
    int *d_c;

    // Size, in bytes, of each vector
    size_t bytes = W*H*sizeof(int);

    // Allocate memory for each vector on host
    h_c = (int*)malloc(bytes);

    // Allocate memory for each vector on GPU
    cudaMalloc((void **) &d_a, bytes);
    cudaMalloc((void **) &d_c, bytes);

    // Copy host vectors to device
    cudaMemcpy(d_a, a, bytes, cudaMemcpyHostToDevice);

    //int blockSize, gridSize;

    // Execute the kernel
    deviceIteration<<<W*H, 1>>>(d_c, d_a, H, W);

    // Copy array back to host
    cudaMemcpy( h_c, d_c, bytes, cudaMemcpyDeviceToHost );

    // Sum up vector c and print result divided by n, this should equal 1 within error
    int i,j;
    for(i=0; i<W; i++) {
        for(j=0; j<H; j++) {
            a[i*H + j] = h_c[i*H + j];
        }
    }

    // Release device memory
    cudaFree(d_a);
    cudaFree(d_c);

    // Release host memory
    free(h_c);
}


