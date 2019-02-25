#include <cstdio>
#include <cstring>
using namespace std;
static const int M = 244140625;

int T[M];

int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

int getKey(char str[]) {
    int sum = 0, p = 1;
    for (int i = 0; i < strlen(str); i++) {
        sum += p * getChar(str[i]);
        p *= 5;
    }
    return sum;
}

int main() {
    // When this line was added, memory limit exceeded.
    // for (int i = 0; i < M; i++) T[i] = 0;

    int n;
    scanf("%d", &n);
    char cmd[6], str[12];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %s", cmd, str);
        key = getKey(str);
        if (cmd[0] == 'i') {
            T[key] = 1;
        } else if (cmd[0] == 'f') {
            if (T[key]) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}