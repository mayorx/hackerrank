#include <iostream>

using namespace std;

int main() {
    int tasknum;
    cin >> tasknum;
    while (tasknum--) {
        long long n, m, s;
        cin >> n >> m >> s;
        long long ans = 0;
        if ((n - 1) * (n - 2) / 2 + 1 >= m) {
            ans = s + m - n + 1;
        } else {
            if (-(n-2) * (m - (n - 1) * (n - 2)/2) + (n - 2) * (n - 1) / 2 < 0) {
                //average
                long long k = s / (n - 1);
                long long t = s % (n - 1);
                ans = (m - (n - 1) * (n - 2) / 2) * (s - (n - 2) * k) + (n - 2) * (n - 1) / 2 * k;
                if (t != 0) {
                    ans = min(ans,
                        (k + 1) * (m - (n - 1) * (n - 2) / 2) + (n - 1) * (n - 2) / 2 * k + (t - 1) * (2 * n - t - 2) / 2
                    );
                }
            } else {
                ans = (m - (n - 1) * (n - 2) / 2) * (s - n + 2) + (n - 2) * (n - 1) / 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}