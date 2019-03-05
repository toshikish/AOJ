#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int S[n];
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int q;
    cin >> q;
    int T[q];
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    int c = 0;
    for (int i = 0; i < q; i++) {
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == T[i]) {
                c++;
                break;
            } else if (T[i] < S[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    cout << c << endl;

    return 0;
}
