#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
    vector<vector<int>> positions;
    vector<int> newPos;

    void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	bool AC3(int row, vector<int>& sol) {
        int len = sol.size() - 1;

        for (int i = row; i <= n; ++i) {
            newPos.clear();

            for (int j = 1; j <= n; ++j) {
                if (checkQueen(row, j, sol)) {
                    newPos.emplace_back(j);
                }
            }

            if (newPos.empty()) {
                return false;
            }

            positions[i] = newPos;
        }

        return true;
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

        if (!AC3(step, sol)) {
            return false;
	    }

	    for (int p : positions[step]) {
            sol[step] = p;

            if (generateQueens(step + 1, sol)) {
                return true;
            }
	    }

        return false;
	}

	vector<int> get_result() {
		vector<int> sol(n + 1, 0);
		positions.resize(n + 1);

		for (int i = 0; i <= n; ++i) {
		    for (int j = 1; j <= n; ++j) {
		        positions[i].emplace_back(j);
		    }
		}

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

