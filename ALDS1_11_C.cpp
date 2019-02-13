#include <iostream>
#include <queue>
using namespace std;
static const int N = 100;
static const int NAV = -1;

int M[N][N];

void bfs(int s, int n, int M[N][N], int d[]) {
    queue<int> Q;
    for (int i = 0; i < n; i++) d[i] = NAV;
    d[s] = 0;
    Q.push(s);

    int u;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int v = 0; v < n; v++) {
            if (M[u][v] != 0 && d[v] == NAV) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main() {
    int n, u, k, v;
    cin >> n;

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

    int d[n];
    bfs(0, n, M, d);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << endl;
    }

    return 0;
}
