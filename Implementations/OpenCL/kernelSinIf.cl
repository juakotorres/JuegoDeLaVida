void kernel simple_add(global int* A, global int* C,  int W, int H){

    const int k = get_global_id(0);

    const int i = k / H;
    const int j = k % H;

    int sum = 0;

    const int left = (i + W - 1)%W;
    const int right = (i + 1)%W;
    const int down = (j + 1)%H;
    const int up = (j + H - 1)%H;

    // left
    sum += A[right*H + j];
    // right
    sum += A[left*H + j];
    // up
    sum += A[i*H + up];
    // down
    sum += A[i*H + down];
    // upright
    sum += A[right*H + up];
    // downright
    sum += A[right*H + down];
    // upleft
    sum += A[left*H + up];
    // downleft
    sum += A[left*H + down];

    int value = A[k];

    C[k] = (value == 1 && (sum == 2 || sum == 3)) || (value == 0 && (sum == 3 || sum == 6) );
}