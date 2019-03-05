#include <iostream>
using namespace std;

void printReversedArrayInOneLine(int A[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void printArrayInMultipleLines(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
}

int insertionSort(int A[], int n, int g) {
    int cnt = 0;
    for (int i = g; i <= n - 1; i++) {
        int v = A[i];
        int j;
        for (j = i - g; j >= 0 && A[j] > v; j -= g) {
            A[j + g] = A[j];
            cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shellSort(int A[], int G[], int m, int n) {
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--) {
        cnt += insertionSort(A, n, G[i]);
    }
    return cnt;
}

void generateGaps(int G[], int &m, int n) {
    int h = 1;
    for (m = 0; h <= n; m++) {
        G[m] = h;
        h = 3 * h + 1;
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    int G[n];
    int m;
    generateGaps(G, m, n);
    cout << m << endl;
    printReversedArrayInOneLine(G, m);

    cout << shellSort(A, G, m, n) << endl;
    printArrayInMultipleLines(A, n);

    return 0;
}
