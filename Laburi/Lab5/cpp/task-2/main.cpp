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
	int n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

    void BKT(int crtPos, vector<vector<int> >& all, vector<int>& sol) {
        all.emplace_back(sol);

        if (crtPos == n) {
            return;
        }

        for (int i = (crtPos > 0 ? sol[crtPos - 1] + 1 : 1); i <= n; ++i) {
            sol.emplace_back(i);
            BKT(crtPos + 1, all, sol);
            sol.pop_back();
        }
    }

	vector<vector<int> > get_result() {
		vector<vector<int> > all;
		vector<int> crtArr;

		BKT(0, all, crtArr);

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
