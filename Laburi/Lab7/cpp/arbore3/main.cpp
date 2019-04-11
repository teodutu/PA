#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 1000001
#define MAXHASH 666013

struct Entry {
    int key, value;
};

vector<Entry> pathSums[MAXHASH];
vector<int> adjList[MAXN];
int values[MAXN];
int totalPaths, sum;

int getIndex(int key) {
    key %= MAXHASH;

    if (key < 0) {
        key += MAXHASH;
    }

    return key;
}

int findKey(int key) {
    int index = getIndex(key);
    int pos = 0;

    for (Entry& entry : pathSums[index]) {
        if (entry.key == key) {
            return pos;
        }

        ++pos;
    }

    return pos;
}

void DFS(int crtNode, int crtSum) {
    crtSum += values[crtNode];
    int pos = findKey(crtSum);
    int index = getIndex(crtSum);
    Entry entry;

    if (pathSums[index].empty() || pos > pathSums[index].size()) {
        entry.key = crtSum;
        entry.value = 1;
        pathSums[index].emplace_back(entry);
    } else {
        ++pathSums[index][pos].value;
    }

    index = getIndex(crtSum - sum);
    pos = findKey(crtSum - sum);

    if (!pathSums[index].empty() && pos < pathSums[index].size()) {
        totalPaths += pathSums[index][pos].value;
    }

    for (int nextNode : adjList[crtNode]) {
        DFS(nextNode, crtSum);
    }

    index = getIndex(crtSum);
    pos = findKey(crtSum);

    if (!pathSums[index].empty() && pos < pathSums[index].size()) {
        --pathSums[index][pos].value;
    }
}

int main() {
    FILE *in, *out;
    in = fopen("arbore3.in", "r");
    out = fopen("arbore3.out", "w");

    int n, x, y, len;
    Entry entry;

    fscanf(in, "%d %d", &n, &sum);

    for (int i = 1; i <= n; ++i) {
        fscanf(in, "%d %d", &x, &y);

        values[i] = y;
        adjList[x].emplace_back(i);
    }

    entry.key = 0;
    entry.value = 1;
    pathSums[0].emplace_back(entry);

    DFS(1, 0);

    fprintf(out, "%d\n", totalPaths);

    return 0;
}