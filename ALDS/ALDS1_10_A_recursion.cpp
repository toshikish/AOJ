#include <iostream>
using namespace std;
static const int N = 50;
static const int NOT_SOLVED = -1;

int dp[N];

int fib(int n) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != NOT_SOLVED) return dp[n];
    return fib(n - 2) + fib(n - 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < N; i++) dp[i] = 0;

    cout << fib(n) << endl;

    return 0;
}
