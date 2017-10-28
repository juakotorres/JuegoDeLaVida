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
    if (A[right * H + j])
        sum++;
    // right
    if (A[left * H + j])
        sum++;
    // up
    if (A[i * H + up])
        sum++;
    // down
    if (A[i * H + down])
        sum++;
    // upright
    if (A[right * H + up])
        sum++;
    // downright
    if (A[right * H + down])
        sum++;
    // upleft
    if (A[left * H + up])
        sum++;
    // downleft
    if (A[left * H + down])
        sum++;

    int value = A[k];
    int result = 0;
    if ( (value == 1 && (sum == 2 || sum == 3)) || (value == 0 && (sum == 3 || sum == 6) ) ){
        result = 1;
    }

    C[k] = result;
}