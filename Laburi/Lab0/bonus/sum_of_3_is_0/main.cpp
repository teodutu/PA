#include <fstream>
#include <unordered_set>

using namespace std;

int v[1000000];
unordered_set<int> set;

int main() {
    bool found_nums = false;
    int n, sum, y;
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");

    fIn >> n;
    for (int i = 0; i < n; ++i) {
        fIn >> v[i];
    }

    for (int i = 0; i < n && !found_nums; ++i) {
        sum = -v[i];

        for (int j = i + 1; j < n; ++j) {
            if (set.find(sum - v[j]) != set.end()) {
                fOut << v[i] << ' ' << v[j] << ' ' << sum - v[j] << '\n';
                found_nums = true;
                break;
            }

            set.insert(v[j]);
        }
    }

    if (!found_nums) {
        fOut << "Numbers not found\n";
    }

    fIn.close();
    fOut.close();
    return 0;
}