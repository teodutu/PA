#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(get_result());
	}

private:
	int n, x;
	vector<int> v;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		for (int i = 0, e; i < n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin >> x;
		fin.close();
	}

	int find_first() {
		int step, i;

		for (step = 1; step <= n; step <<= 1);
		for (i = 0; step; step >>= 1) {
		    if (i + step < n && v[i + step] < x) {
		        i += step;
		    }
		}

		if (v[i] != x) {
		    ++i;
		}

        return (v[i] == x ? i : -1);
	}

	int find_last() {
        int step, i;

        for (step = 1; step <= n; step <<= 1);
        for (i = 0; step; step >>= 1) {
            if (i + step < n && v[i + step] <= x) {
                i += step;
            }
        }

        return (v[i] == x ? i : -1);
	}

	int get_result() {
		int firstFound = find_first();
		if (firstFound == -1) {
            return 0;
		}

		return find_last() - firstFound + 1;
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
