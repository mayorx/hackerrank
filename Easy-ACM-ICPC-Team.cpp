#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector <string> topics(n);
    for (int i = 0; i < n; i++)
        cin >> topics[i];

    int best = 0, bestCount = 0;

    for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
        int tmp = 0;
        for (int k = 0; k < m; k++) {
            if (tmp + m - k < best) break;
            if (topics[i][k] == '1' || topics[j][k] == '1') tmp++;
        }
        if (tmp > best) {
            best = tmp;
            bestCount = 1;
        } else if (tmp == best) {
            bestCount ++;
        }
    }
    cout << best << endl;
    cout << bestCount << endl;
    return 0;
}