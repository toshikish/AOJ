#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> Parent;

    DisjointSet(int n) {
        Parent = vector<int> (n, -1);
    }

    int root(int a) {
        if (Parent[a] < 0) return a;
        return Parent[a] = root(Parent[a]);
    }

    int size(int a) {
        return -Parent[root(a)];
    }

    bool link(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return false;

        if (size(a) < size(b)) swap(a, b);
        Parent[a] += Parent[b];
        Parent[b] = a;
        return true;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    int c, x, y;
    for (int i = 0; i < q; i++) {
        cin >> c >> x >> y;
        if (c == 0) {
            ds.link(x, y);
        } else {
            if (ds.root(x) == ds.root(y)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
