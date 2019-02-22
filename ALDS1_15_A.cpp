#include <iostream>
using namespace std;

int main() {
    int coins[4] = {25, 10, 5, 1};
    long n, a, x;
    cin >> n;
    x = 0;
    for (int i = 0; i < 4; i++) {
        x += n / coins[i];
        n = n % coins[i];
    }
    cout << x << endl;

    return 0;
}
