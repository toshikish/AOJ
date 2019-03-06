#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> Parent;
    vector<int> Weight;

    DisjointSet(int n) {
        Parent = vector<int> (n, -1);
        Weight = vector<int> (n, 0);
    }

    int root(int a) {
        if (Parent[a] < 0) return a;
        return Parent[a] = root(Parent[a]);
    }

    int size(int a) {
        return -Parent[root(a)];
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    bool relate(int a, int b, int d) {
        if (same(a, b)) return false;
        int A = root(a);
        int B = root(b);

        // Merge B into A
        if (size(A) < size(B)) {
            swap(a, b);
            swap(A, B);
            d *= -1;
        }
        int diff_AB = d + Weight[a] - Weight[b];
        for (int i = 0; i < Weight.size(); i++) {
            if ((Parent[i] < 0 && i == B) || Parent[i] == B) {
                Weight[i] += diff_AB;
            }
        }
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }

    int diff(int a, int b) {
        // if (!same(a, b)) return false;
        return Weight[b] - Weight[a];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    int c, x, y, z;
    for (int i = 0; i < q; i++) {
        cin >> c >> x >> y;
        if (c == 0) {
            cin >> z;
            ds.relate(x, y, z);
        } else {
            if (ds.same(x, y)) {
                cout << ds.diff(x, y) << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }

    return 0;
}
