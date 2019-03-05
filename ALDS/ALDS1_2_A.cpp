#include <iostream>
using namespace std;

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void bubbleSort(int A[], int N) {
    int n_swaps = 0;
    for (int i = 0; i <= N - 1; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                n_swaps++;
            }
        }
    }
    printArray(A, N);
    cout << n_swaps << endl;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    bubbleSort(A, N);
    return 0;
}
