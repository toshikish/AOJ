#include <iostream>
#include <stack>
using namespace std;
static const int N = 100;
static const int NOT_YET = 0;
static const int DETECTED = 1;
static const int FINISHED = 2;

int M[N][N];

int next(int u, int origin[], int n, int M[N][N]) {
    for (int v = origin[u]; v < n; v++) {
        origin[u] = v + 1;
        if (M[u][v]) return v;
    }
    return -1;
}

void dfs(int r, int n, int M[N][N], int status[], int t_detected[], int t_finished[], int &t) {
    int origin[n];
    for (int i = 0; i < n; i++) origin[i] = 0;

    stack<int> S;
    S.push(r);
    status[r] = DETECTED;
    t_detected[r] = ++t;

    while (!S.empty()) {
        int u = S.top();
        int v = next(u, origin, n, M);
        if (v != -1) {
            if (status[v] == NOT_YET) {
                status[v] = DETECTED;
                t_detected[v] = ++t;
                S.push(v);
            }
        } else {
            S.pop();
            status[u] = FINISHED;
            t_finished[u] = ++t;
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
