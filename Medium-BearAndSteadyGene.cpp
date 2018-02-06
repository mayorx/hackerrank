#include <iostream>
#include <string>

using namespace std;

#define MAXN 500005

int F[4][MAXN];

int mapping(int c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'T': return 2;
        case 'G': return 3;
    }
    return -1;
}

bool test(string s, int sublen, int n) {
//    cout << s << " " << sublen << " " << n << endl;
    for (int i = 0; i <= s.length() - sublen; i++) {
        int k = i + sublen;
        //s[i+1 .. k]
        bool flag = true;
        for (int j = 0; j < 4 && flag; j++)
            if (F[j][n] + F[j][i] - F[j][k] > n / 4) flag = false;
        if (flag) return true;
    }
    return false;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
//    cout << "input finished" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) F[j][i+1] = F[j][i];
        F[mapping(s[i])][i+1]++;
    }

//    cout << "mapping finished" << endl;

    int low = 0, high = n, medium;
    while (low < high) {
        medium = (low + high) / 2;
        if (test(s, medium, n)) {
            high = medium;
        } else {
            low = medium + 1;
        }
    }

    cout << low << endl;
    return 0;
}