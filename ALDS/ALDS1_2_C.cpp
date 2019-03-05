#include <iostream>
using namespace std;

struct Card {
    char suit;
    int value;
};

void printCards(Card A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

void bubbleSort(Card A[], int N) {
    for (int i = 0; i <= N - 1; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j].value < A[j - 1].value) {
                swap(A[j], A[j - 1]);
            }
        }
    }
    printCards(A, N);
}

void selectionSort(Card A[], int N) {
    for (int i = 0; i <= N - 1; i++) {
        int min_j = i;
        for (int j = i; j <= N - 1; j++) {
            if (A[j].value < A[min_j].value) min_j = j;
        }
        swap(A[i], A[min_j]);
    }
    printCards(A, N);
}

bool isStable(Card in[], Card out[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    if (
                        in[i].value == in[j].value
                        && in[i].suit == out[l].suit && in[i].value == out[l].value
                        && in[j].suit == out[k].suit && in[j].value == out[k].value
                    )
                        return false;
                }
            }
        }
    }
    return true;
}

void printStability(Card in[], Card out[], int N) {
    if (isStable(in, out, N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
}

int main() {
    int N;
    cin >> N;
    Card A[N], A1[N], A2[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i].suit >> A[i].value;
        A1[i] = A2[i] = A[i];
    }

    bubbleSort(A1, N);
    printStability(A, A1, N);

    selectionSort(A2, N);
    printStability(A, A2, N);

    return 0;
}
