#include <iostream>
#include <string>
using namespace std;

bool match(string T, string P) {
    for (int i = 0; i < T.length(); i++) {
        if (T[i] != P[i]) return false;
    }
    return true;
}

int main() {
    string T, P;
    cin >> T >> P;
    int lt, lp;
    lt = T.length();
    lp = P.length();

    for (int i = 0; i < lt - lp + 1; i++) {
        if (match(T.substr(i, lp), P)) cout << i << endl;
    }

    return 0;
}
