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

	bool checkQueen(int row, int col, vector<int>& sol) {
        for (int i = 1; i < row; ++i) {
            if (sol[i] == col) {
                return false;
            }

            if (col - sol[i]  == row -  i) {
                return false;
            }

            if (sol[i] - col == row -  i) {
                return false;
            }
        }

        return true;
	}

	bool generateQueens(int step, vector<int>& sol) {
	    if (step > n) {
            return true;
	    }

	    for (int i = 1; i <= n; ++i) {
	        if (checkQueen(step, i, sol)) {
                sol[step] = i;

                if (generateQueens(step + 1, sol)) {
                    return true;
                }
	        }
	    }

        return false;
	}

	vector<int> get_result() {
		vector<int> sol(n + 1, 0);

        generateQueens(1, sol);

		return sol;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i != n ? ' ' : '\n');
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
