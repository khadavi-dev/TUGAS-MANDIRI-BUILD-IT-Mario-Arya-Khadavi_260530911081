#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    // urutkan supaya x <= y <= z
    long long arr[3] = {a, b, c};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (arr[j] > arr[j+1]) {
                long long tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    long long x = arr[0], y = arr[1], z = arr[2];
    long long dHigh = z - y;
    long long dLow  = y - x;
    long long rounds = dHigh < dLow ? dHigh : dLow;

    printf("%lld\n", rounds);    
    return 0;
}
