#include <iostream>
#include <algorithm>
using namespace std;
static const int INFTY = (1 << 21);

int main() {
    int n;
    cin >> n;
    double p[n + 1], q[n + 2], E[n + 1][n + 1], P[n + 1][n + 1], Q[n + 2][n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        cin >> q[i];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            E[i][j] = INFTY;
            for (int k = i; k <= j - 1; k++) {
                E[i][j] = min(E[i][j], E[i][k] + E[k + 1][j] + P[i + 1][j] + Q[i][j]);
            }
        }
    }

    cout << E[0][n] << endl;

    return 0;
}
