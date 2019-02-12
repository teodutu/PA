#include <fstream>
#define NMAX 100000

using namespace std;

ifstream fIn("input.txt");
ofstream fOut("output.txt");

int v[NMAX];

int main() {
    int n, left = 0, right, mid;

    fIn >> n;
    right = n;

    for (int i = 0; i < n; ++i) {
        fIn >> v[i];
    }

    while (left <= right) {
        mid = (left + right) / 2;

        if (v[mid] > v[mid + 1] && v[mid - 1] < v[mid]) {
            break;
        } else if (v[mid] < v[mid + 1]) {
            left = mid + 1;
        } else if (v[mid - 1] > v[mid]) {
            right = mid - 1;
        }
    }

    fOut << mid << '\n';

    fIn.close();
    fOut.close();
    return 0;
}