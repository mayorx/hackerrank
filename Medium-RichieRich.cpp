#include <string>
#include <iostream>

using namespace std;

int main() {
    int n, k, m = 0;
    string s;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) m++;
    }

    if (m > k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if (s[i] == s[j]) { // match
                if (s[i] != '9' && k-2 >= m) {
                    s[i] = '9'; s[j] = '9'; k-= 2;
                }
            } else {
                char c = max(s[i], s[j]);
                if (c == '9') {
                    s[i] = '9';
                    s[j] = '9';
                    k -= 1;
                    m -= 1;
                } else {
                    if (k - 2 >= m - 1) {
                        s[i] = '9';
                        s[j] = '9';
                        k -= 2;
                        m -= 1;
                    } else {
                        s[i] = c;
                        s[j] = c;
                        k -= 1;
                        m -= 1;
                    }
                }
            }
        }
        if (n % 2 == 1 && k >= 1) {
            s[(n+1)/2] = '9';
        }
        cout << s << endl;
    }
    return 0;
}