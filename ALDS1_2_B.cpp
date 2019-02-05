#include <iostream>
using namespace std;

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void selectionSort(int A[], int N) {
    int n_swaps = 0;
    for (int i = 0; i <= N - 1; i++) {
        int min_j = i;
        for (int j = i; j <= N - 1; j++) {
            if (A[j] < A[min_j]) min_j = j;
        }
        swap(A[i], A[min_j]);
        if (i != min_j) n_swaps++;
    }
    printArray(A, N);
    cout << n_swaps << endl;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    selectionSort(A, N);
}

