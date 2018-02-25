#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int num = 15;
int maxx = 10000000;
int n = 100000;


int main() {
    cout << num << endl;
    srand((unsigned)time(NULL));
    while (num--) {
        int n = 100000;
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << rand() % n + maxx - n << " ";
        cout << endl;
    }
    return 0;
}