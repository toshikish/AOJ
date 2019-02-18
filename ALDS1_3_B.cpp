#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class Process {
public:
    string name;
    int time;
};

int main() {
    int n, q, t = 0;
    cin >> n >> q;
    string name[n];
    int time[n];
    queue<Process> P;
    Process p;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> time[i];
        p.name = name[i];
        p.time = time[i];
        P.push(p);
    }

    while (!P.empty()) {
        p = P.front();
        if (p.time > q) {
            t += q;
            p.time -= q;
            P.pop();
            P.push(p);
        } else {
            t += p.time;
            P.pop();
            cout << p.name << " " << t << endl;
        }
    }

    return 0;
}
