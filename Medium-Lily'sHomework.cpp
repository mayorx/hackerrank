#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int work(vector <int> origin, vector <int> target) {
    map <int, int> next, flag;
    for (int i = 0; i < origin.size(); i++)
        next[origin[i]] = i;

//    printf("\norigin: "); for (int i = 0; i < origin.size(); i++) printf(" %d", origin[i]);
//    printf("\ntarget: "); for (int i = 0; i < target.size(); i++) printf(" %d", target[i]);
//    printf("\nnext: "); for (map <int, int>::iterator it = next.begin(); it != next.end(); it++) printf(" {%d -> %d}", it->first, it->second);
//    printf("\n");

    int ans = 0;
    for (int i = 0; i < origin.size(); i++)
        if (flag[origin[i]] != 1) {
            int cnt = 0;
            int j = origin[i];
            while (!flag[j]) {
                flag[j] = 1;
                j = target[next[j]];
                cnt++;
            }
            ans += cnt - 1;
        }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    vector <int> origin(n);
    for (int i = 0; i < n; i++) scanf("%d", &origin[i]);
    vector <int> target(origin);
    sort(target.begin(), target.end());
    int ans1 = work(origin, target);
    reverse(target.begin(), target.end());
    int ans2 = work(origin, target);

    printf("%d\n", min(ans1, ans2));

    return 0;
}