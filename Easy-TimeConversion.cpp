#include <iostream>
#include <string>

using namespace std;


string timeConversion(string s) {
//    cout << s.find("AM") << endl;
//    cout << string::npos << endl;
    int isAM = string::npos != s.find("AM");
    int hour = (s[0] - '0') * 10 + s[1] - '0';
    if (isAM && hour == 12) {
        hour -= 12;
    } else if (!isAM && hour != 12) {
        hour += 12;
    }
    s[0] = '0' + hour / 10;
    s[1] = '0' + hour % 10;
    return s.substr(0, 8);
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}