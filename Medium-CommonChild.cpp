#include <iostream>

using namespace std;

#define MAXLENGTH 5005

int F[2][MAXLENGTH];

int f(int i, int j) {
    if (i < 0 || j < 0) return 0;
    return F[i % 2][j];
}

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        int k = i % 2;
        for (int j = 0; j < t.length(); j++) {
            F[k][j] = max(f(i, j-1), f(i-1, j));
            if (s[i] == t[j]) F[k][j] = max(F[k][j], f(i-1, j-1) + 1);
        }
    }
    cout << F[(s.length() -1) % 2][t.length() -1] << endl;
    return 0;
}