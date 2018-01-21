#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tasknum;
    cin >> tasknum;
    while (tasknum--) {
        int n;
        cin >> n;
        vector < vector<int> > container(n, vector<int> (n)); // mark
        vector <int> containerSize(n, 0);
        vector <int> ballsCount(n, 0);

        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> container[i][j];
            containerSize[i] += container[i][j];
            ballsCount[j] += container[i][j];
        }
        sort(containerSize.begin(), containerSize.end());
        sort(ballsCount.begin(), ballsCount.end());
        int flag = 1;
        for (int i = 0; i < n; i++)
            if (containerSize[i] != ballsCount[i]) {
                flag = 0;
                break;
            }
        cout << (flag == 1 ? "Possible" : "Impossible") << endl;
    }

    return 0;
}
