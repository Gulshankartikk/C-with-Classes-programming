#include <stdio.h>
#include <stdlib.h>

// helper: max heapify
void heapify(int heap[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] > heap[largest])
        largest = l;

    if (r < n && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

int solve(int* A, int n1, int B) {
    if (B == 0)
        return 0;

    int sum = 0;
    int i;

    // build max heap
    for (i = n1/2 - 1; i >= 0; i--)
        heapify(A, n1, i);

    int size = n1;

    while (B && size > 0) {
        int top = A[0];
        sum += top;

        if (top > 1) {
            A[0] = top - 1;
        } else {
            A[0] = A[size-1];
            size--;
        }

        heapify(A, size, 0);
        B--;
    }

    return sum;
}

int main() {
    int A[] = {3, 1, 2};
    int n1 = sizeof(A) / sizeof(A[0]);
    int B = 3;

    int result = solve(A, n1, B);
    printf("Result = %d\n", result);

    return 0;
}