#include <iostream>
using namespace std;

int main() {
    int n, u, k, v;
    cin >> n;

    int M[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}
