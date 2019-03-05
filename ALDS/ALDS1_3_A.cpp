#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int a, b;
    string s;
    stack<int> S;

    while (cin >> s) {
        if (s == "+") {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a + b);
        } else if (s == "-") {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(b - a);
        } else if (s == "*") {
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a * b);
        } else {
            S.push(stoi(s));
        }
    }

    cout << S.top() << endl;

    return 0;
}
