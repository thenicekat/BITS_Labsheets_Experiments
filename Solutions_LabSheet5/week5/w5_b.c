#include <stdio.h>
#include <stdlib.h>

int findAlivePosition(int n){
    if(n == 1)
        return 1;
    
    int pos = findAlivePosition(n / 2);
    return n - 2 * (pos - 1) - (n % 2);
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", findAlivePosition(n));

    return 0;
}