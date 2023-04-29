#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand(int mod) {
    int t = rand() % mod;
    t = (1LL*t*RAND_MAX + rand()) % mod;
    return t;
}

int main() {
    int n;
    scanf("%d", &n);

    srand(time(NULL));
    int num = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (myrand(i + 1) == 0)
            num = x;
        printf("%d\n", num);
    }

    return 0;
}