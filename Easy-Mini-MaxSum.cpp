#include <cstdio>

using namespace std;

#define n 5

int main() {
    long long sum = 0, minx = 1000000000, maxx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        if (x < minx) minx = x;
        if (x > maxx) maxx = x;
    }
    printf("%lld %lld\n", sum - maxx, sum - minx);
    return 0;
}