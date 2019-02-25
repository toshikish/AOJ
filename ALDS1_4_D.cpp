#include <iostream>
using namespace std;
typedef long long llong;

int n, k;
llong T[100000];

int getShippableNumOfItems(llong P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        llong sum = 0;
        while (sum + T[i] <= P) {
            sum += T[i];
            i++;
            if (i == n) return n;
        }
    }
    return i;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> T[i];

    llong left = 0;
    llong right = 100000 * 10000;
    llong mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int v = getShippableNumOfItems(mid);
        if (v >= n) right = mid;
        else left = mid;
    }

    cout << right << endl;
}