#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int x) {
    if (x == 2) return true;
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, n_prime, x;
    cin >> n;

    n_prime = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (isPrime(x)) n_prime++;
    }

    cout << n_prime << endl;

    return 0;
}
