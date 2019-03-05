#include <iostream>
using namespace std;
static const int NIL = -1;
static const int NO = 0;
static const int YES = 1;

int n;
int A[20];
int S[21][2001];

bool solve(int i, int m) {
    if (S[i][m] != NIL) return S[i][m];

    if (m == 0) return S[i][m] = YES;
    if (i >= n) return S[i][m] = NO;
    return S[i][m] = solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 2001; j++) {
            S[i][j] = NIL;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int q;
    cin >> q;
    int m[q];

    for (int i = 0; i < q; i++) {
        cin >> m[i];
        if (solve(0, m[i])) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
