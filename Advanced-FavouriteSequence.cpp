#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

map <int, int> degree;
map <int, vector <int> > nextedge;
set <int> nodes;
vector <int> heap(1);
int heapsize(0);


void heapDown(int i) {
    if (i * 2 > heapsize) return;
    int j = 2 * i;
    if (j + 1 <= heapsize && heap[j + 1] < heap[j]) j = j + 1;
    if (heap[i] > heap[j]) {
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
}

void heapInsert(int x) {
    heap.push_back(x);
    heapsize++;
    int i = heapsize / 2;
    while (i) {
        heapDown(i);
        i = i / 2;
    }
}

int heapPop() {
    int x = heap[1];
    heap[1] = heap[heapsize]; heapsize--;
    heap.pop_back();
    int i = 1, j = 2 * i;
    while (j <= heapsize) {
        if (j + 1 <= heapsize && heap[j + 1] < heap[j]) j = j + 1;
        if (heap[i] > heap[j]) {
            int tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
        }

        i = j;
        j = 2 * i;
    }
    return x;
}

void addNode(int x) {
    nodes.insert(x);
}

void addEdge(int x, int y) {
    degree[y]++;
    nextedge[x].push_back(y);
}

void topoSort() {
    vector <int> sortedList(0);
    for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        int x = *it;
        if (degree[x] == 0) heapInsert(x);
    }

    while (heapsize) {
        int x = heapPop();
        sortedList.push_back(x);
        for (int i = 0; i < nextedge[x].size(); i++) {
            int y = nextedge[x][i];
            degree[y] -= 1;
            if (degree[y] == 0) heapInsert(y);
        }
    }

    for (int i = 0; i < sortedList.size(); i++) {
        if (i != 0) {
            printf(" %d", sortedList[i]);
        } else {
            printf("%d", sortedList[i]);
        }
    }
    cout << endl;


}

int main() {
    int n;
    cin >> n;

//    clock_t st, mid, ed;
//    st = clock();
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        vector <int> lists(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &lists[i]);
            addNode(lists[i]);
            if (i != 0) addEdge(lists[i-1], lists[i]);
        }
    }
//    mid = clock();
    topoSort();
//    ed = clock();
//    cout << (double)(mid - st) / CLOCKS_PER_SEC << endl;
//    cout << (double)(ed - mid) / CLOCKS_PER_SEC << endl;

    return 0;
}