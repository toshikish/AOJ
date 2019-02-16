#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int c[m + 1][n + 1];
    c[0][0] = 0;
    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 1; j <= n; j++) c[0][j] = 0;

    int max_len = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
            max_len = max(max_len, c[i][j]);
        }
    }

    return max_len;
}

int main() {
    int n;
    cin >> n;
    string s1, s2;
    int max_len[n];
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        max_len[i] = lcs(s1, s2);
    }

    for (int i = 0; i < n; i++) {
        cout << max_len[i] << endl;
    }

    return 0;
}
