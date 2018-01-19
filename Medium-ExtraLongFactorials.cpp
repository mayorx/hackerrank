#include <cstdio>

using namespace std;

#define maxlength 500
#define base 10

int len;
int x[maxlength];

int main() {
    int n;
    scanf("%d", &n);

    //init
    x[0] = 1; len = 1;
    for (int i = 2; i <= n; i++) {
        // calc x * i
        for (int j = 0; j < len; j++) {
            x[j] = x[j] * i;
        }
        for (int j = 0; j < len; j++) {
            if (x[j] >= base) {
                x[j+1] += x[j] / base;
                x[j] = x[j] % base;
            }
        }
        while (x[len]) {
            x[len+1] = x[len] / base;
            x[len] = x[len] % base;
            len++;
        }
    }
    for (int j = len - 1; j >= 0; j--) {
        printf("%d", x[j]);
    }
}