#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define eps 0.000001

int main() {
    string s;
    cin >> s;
    int L = s.length();
    int row, col;
    row = (int)(sqrt(L) + eps);
    col = row;
    if (row * col < L) col += 1;
    if (row * col < L) row += 1;

    for (int i = 0; i < col; i++) {
        int flag = L % col != 0 && i >= L % col ? 1 : 0;
        for (int j = 0; j < row - flag; j++) {
            cout << s[j * col + i];
        }
        if (i == col - 1) {
            cout << endl;
        } else cout << " ";
    }
    return 0;
}