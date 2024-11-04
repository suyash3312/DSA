void check(int A[], int& i, int min, int max, int size){
    if(*i >= size){
        return;
    }
    if(A[i] >= min && A[*i] <= max){
        int rootVal = A[(i)++];
        check(A, i, min, rootVal, size);
        check(A, i, rootVal, max, size);
    }
}
int solve(int A[], int n1) {
    int i = 0;
    check(A, i, INT_MIN, INT_MAX, n1);
    return i == n1 ? 1 : 0;
}
