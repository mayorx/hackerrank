#include <iostream>

using namespace std;

int main() {
    string s, t;
    int n, m, k = 0, steps;
    cin >> s >> t;
    cin >> steps;
    n = s.length(); m = t.length();
    for (int i = 0; i < min(n, m); i++) {
        if (s[i] != t[i]) break;
        k = i + 1;
        // s[0..(k-1)] == t[0..(k-1)]
    }
    if (steps >= n + m || (steps >= n - k + m - k && steps % 2 == (n + m) % 2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}