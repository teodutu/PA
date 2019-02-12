#include <fstream>

using namespace std;

ifstream fIn("ssm.in");
ofstream fOut("ssm.out");

int main() {
    int n, x, currSum = -1, bestSum = 0x80000000, currStart, bestStart, end;

    fIn >> n;

    for (int i = 1; i <= n; ++i) {
        fIn >> x;

        if (currSum < 0) {
            currStart = i;
            currSum = x;
        } else {
            currSum += x;
        }

        if (bestSum < currSum) {
            bestSum = currSum;
            bestStart = currStart;
            end = i;
        }
    }

    fOut << bestSum << ' ' << bestStart << ' ' << end << '\n';
    return 0;
}