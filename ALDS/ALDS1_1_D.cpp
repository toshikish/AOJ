#include <iostream>
using namespace std;

int main() {
    int n, a_min, diff, diff_max;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    diff_max = -2e9;
    a_min = a[0];
    for (int i = 1; i < n; i++) {
        diff = a[i] - a_min;
        if (diff > diff_max) {
            diff_max = diff;
        }
        if (a[i] < a_min) {
            a_min = a[i];
        }
    }
    cout << diff_max << endl;
    return 0;
}
