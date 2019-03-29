#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, k;

	void read_input() {
		ifstream fin("in");
		fin >> n >> k;
		fin.close();
	}

	void BKT(int crtPos, vector<vector<int> >& all, vector<int>& sol, vector<bool>& used) {
        if (crtPos == k) {
            all.emplace_back(sol);
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                used[i] = true;
                sol.emplace_back(i);

                BKT(crtPos + 1, all, sol, used);

                used[i] = false;
                sol.pop_back();
            }
        }
	}

	vector<vector<int> > get_result() {
		vector<vector<int> > all;
        vector<int> crtArr;
        vector<bool> used(n, false);

        BKT(0, all, crtArr,used);

		return all;
	}

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j] <<
					(j + 1 != result[i].size() ? ' ' : '\n');
			}
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
