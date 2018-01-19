#include <cstdio>
#include <iostream>

using namespace std;

#define maxk 100

int tot[maxk];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        tot[x % k]++;
    }
    int sum = 0;
    for (int i = 1; i < (k+1) / 2; i++) {
        sum += max(tot[i], tot[k - i]); // %k == i && %k == k-i
    }
    if (tot[0]) sum += 1; // % k == 0
    if (k % 2 == 0 && tot[k/2]) sum += 1; // %k == k/2
    printf("%d\n", sum);
    return 0;
}