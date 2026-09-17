#include <stdio.h>
#include <stdlib.h>

const long long MOD = 1000000007LL;

int cmp(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *A = (long long*) malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, n, sizeof(long long), cmp);

    // total pasangan index = C(n,2)
    long long totalPairs = (long long)n * (n - 1) / 2;

    // kurangi pasangan dengan nilai sama, dihitung per kelompok nilai yang sama
    long long samePairs = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && A[j] == A[i]) j++;
        long long cnt = j - i;
        samePairs += cnt * (cnt - 1) / 2;
        i = j;
    }

    long long ans = (totalPairs - samePairs) % MOD;
    printf("%lld\n", ans);

    free(A);
    return 0;
}
