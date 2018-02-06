#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CHARNUM 26

int isValid(string s) {
    vector <int> cnt(CHARNUM, 0);

//    for (int i = 0; i < CHARNUM; i++)
//        cout << i << " " << cnt[i] << endl;

    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - 'a']++;

//    for (int i = 0; i < CHARNUM; i++)
//        cout << i << " " << cnt[i] << endl;

    int max = 0, maxCount = 0, min = 10000000, minCount = 0;
    for (int i = 0; i < CHARNUM; i++)
        if (cnt[i] != 0) {
            if (cnt[i] > max) {
                max = cnt[i];
                maxCount = 1;
            } else if (cnt[i] == max) maxCount++;

            if (cnt[i] < min) {
                min = cnt[i];
                minCount = 1;
            } else if (cnt[i] == min) minCount++;
        }

    return (max == min || (max == min + 1 && maxCount == 1) || (max * maxCount + 1 == s.length()));
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}