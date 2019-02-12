#include <fstream>

using namespace std;

int main() {
    int n, x, currMax, prevMax, aux;
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");

    fIn >> n >> x;
    currMax = prevMax = x;
    if (n == 1) {
        fOut << currMax << '\n';
        return 0;
    }

    fIn >> x;
    if (x > currMax) {
        currMax = x;
    }

    for (int i = 2; i < n; ++i) {
        fIn >> x;

        aux = currMax;

        if (x + prevMax > currMax) {
            currMax = x + prevMax;
        }

        prevMax = aux;
    }

    fOut << currMax << '\n';

    fIn.close();
    fOut.close();
    return 0;
}