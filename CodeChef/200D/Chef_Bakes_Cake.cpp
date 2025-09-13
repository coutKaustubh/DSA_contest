#include <stdio.h>

int main() {
    long long n, x, y;
    if (scanf("%lld %lld %lld", &n, &x, &y) != 3) return 0;
    long long k = y / x;
    if (k < 1) k = 1;
    long long ans = (n + k - 1) / k;
    printf("%lld", ans);
    return 0;
}
