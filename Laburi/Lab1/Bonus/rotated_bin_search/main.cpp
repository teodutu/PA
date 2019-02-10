#include <fstream>

using namespace std;

int v[1000000];

int findRotationPos(int v[], int len) {
    int start = 0, end = len - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (v[mid] > v[mid + 1]) {
            return mid;
        }

        if (v[start] > v[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return 0;
}

int binSearch(int v[], int len, int target) {
    int i, step;

    for (step = 1; step < len; step <<= 1);
    for (i = 0; step; step >>= 1) {
        if (i + step < len && v[i + step] <= target) {
            i += step;
        }
    }

    return i;
}

int main() {
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");

    int n, pos, x;

    fIn >> n >> x;

    for (int i = 0; i < n; ++i) {
        fIn >> v[i];
    }

    pos = findRotationPos(v, n);

    if (x >= v[0]) {
        pos = binSearch(v, pos + 1, x);
    } else {
        pos += binSearch(v + pos + 1, n - pos - 1, x) + 1;
    }

    fOut << pos << "\n";

    fIn.close();
    fOut.close();
    return 0;
}