#include <iostream>
using namespace std;
static const int N = 100;
static const int NOT_YET = 0;
static const int DETECTED = 1;
static const int FINISHED = 2;

int M[N][N];

void dfs(int u, int n, int M[N][N], int status[], int t_detected[], int t_finished[], int &t) {
    status[u] = DETECTED;
    t_detected[u] = ++t;
    for (int v = 0; v < n; v++) {
        if (M[u][v] != 0 && status[v] == NOT_YET) {
            dfs(v, n, M, status, t_detected, t_finished, t);
        }
    }
    status[u] = FINISHED;
    t_finished[u] = ++t;
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

    int status[n], t_detected[n], t_finished[n];
    for (u = 0; u < n; u++) {
        status[u] = NOT_YET;
    }
    int t = 0;

    for (u = 0; u < n; u++) {
        if (status[u] == NOT_YET) dfs(u, n, M, status, t_detected, t_finished, t);
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << t_detected[i] << " " << t_finished[i] << endl;
    }

    return 0;
}
