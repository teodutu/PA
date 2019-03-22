#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int kMod = 1e9 + 7;
int even[1001], odd[1001];

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<int> v;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

	int get_result() {
		/*
		Calculati numarul de subsiruri ale lui v cu suma numerelor para si
		returnati restul impartirii numarului la 10^9 + 7.
		*/

        even[0] = 1;
        odd[0] = 0;

        for (int i = 1; i <= n; ++i) {
            if (v[i] & 1) {
               odd[i] = even[i] = (1LL * even[i - 1] + odd[i - 1]) % kMod;
            } else {
                even[i] = (1LL * even[i - 1] * 2) % kMod;
                odd[i] = (1LL * odd[i - 1] * 2) % kMod;
            }
        }

        return even[n] - 1; 
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
