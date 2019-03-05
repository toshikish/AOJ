#include <iostream>
#include <vector>
#include <stack>
using namespace std;
static const int NIL = -1;

void dfs(int r, int n, vector<int> G[], int con_id, int connection[]) {
    stack<int> S;
    S.push(r);
    connection[r] = con_id;

    while (!S.empty()) {
        int u = S.top();
        S.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (connection[v] == NIL) {
                connection[v] = con_id;
                S.push(v);
            }
        }
    }
}

int main() {
    int n, s, t, m, q;
    cin >> n >> m;
    vector<int> G[n];

    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    int id = 1;
    int connection[n];
    for (int i = 0; i < n; i++) connection[i] = NIL;
    for (int u = 0; u < n; u++) {
        if (connection[u] == NIL) dfs(u, n, G, id++, connection);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> s >> t;
        if (connection[s] == connection[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
