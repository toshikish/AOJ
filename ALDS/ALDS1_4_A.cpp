#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int S[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int q;
    cin >> q;
    int T[q + 1];
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    int c = 0;
    for (int i = 0; i < q; i++) {
        int j = 0;
        S[n] = T[i];
        while (S[j] != T[i]){
            j++;
        }
        if (j != n) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
