#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i <= N - 1; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                cnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

