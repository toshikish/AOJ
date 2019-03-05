#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    string command;
    list<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command[0] == 'i') {
            cin >> x;
            v.push_front(x);
        } else if (command[6] == 'L') {
            v.pop_back();
        } else if (command[6] == 'F') {
            v.pop_front();
        } else if (command[0] == 'd') {
            cin >> x;
            for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
                if (*it == x) {
                    v.erase(it);
                    break;
                }
            }
        }
    }

    int i = 0;
    for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (i++) cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}
