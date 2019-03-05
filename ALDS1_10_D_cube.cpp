#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    double p[n + 1], q[n + 2], E[n + 2][n + 2], P[n + 2][n + 2], Q[n + 2][n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        cin >> q[i];
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = i; j <= n + 1; j++) {
            E[i][j] = 0.0;
            P[i][j] = 0.0;
            Q[i][j] = 0.0;
            for (int k = i; k <= j; k++) {
                P[i][j] += p[k];
                Q[i][j] += q[k];
            }
        }
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            E[i][j] = numeric_limits<double>::max();
            for (int k = i + 1; k <= j; k++) {
                E[i][j] = min(E[i][j], E[i][k - 1] + E[k][j] + P[i + 1][j] + Q[i][j]);
                cout << l << " " << i << " " << j << " " << k << " " << E[i][j] << endl;
            }
        }
    }

    cout << E[0][n] << endl;

    return 0;
}
