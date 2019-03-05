#include <cstdio>
#include <cstring>
using namespace std;
static const long M = 1046527;   // A prime number
static const int NIL = -1;

long T[M];

int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

long getKey(char str[]) {
    long sum = 0, p = 1;
    for (int i = 0; i < strlen(str); i++) {
        sum += p * getChar(str[i]);
        p *= 5;
    }
    return sum;
}

long h1(long key) {
    return key % M;
}


long h2(long key) {
    return 1 + (key % (M - 1));
}

long h(long key, int i) {
    return (h1(key) + i * h2(key)) % M;
}

int insert(long key) {
    long hash;
    for (int i = 0; ; i++) {
        hash = h(key, i);
        if (hash >= M) return 0;

        if (T[hash] == NIL) {
            T[hash] = key;
            return 1;
        }
    }
    return 0;
}

int find(long key) {
    long hash;
    for (int i = 0; ; i++) {
        hash = h(key, i);
        if (hash >= M - 1) return 0;

        if (T[hash] == key) {
            return 1;
        }
    }
    return 0;

}

int main() {
    for (int i = 0; i < M; i++) T[i] = NIL;

    int n;
    scanf("%d", &n);
    char cmd[6], str[12];
    long key;
    for (int i = 0; i < n; i++) {
        scanf("%s %s", cmd, str);
        key = getKey(str);
        if (cmd[0] == 'i') {
            insert(key);
        } else if (cmd[0] == 'f') {
            if (find(key)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}