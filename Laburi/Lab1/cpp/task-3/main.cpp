#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(get_result(n, x, y));
	}

private:
	int n, x, y;

	void read_input() {
		ifstream fin("in");
		fin >> n >> x >> y;
		fin.close();
	}

    int get_result(int n, int x, int y) {
        int step = ((n - 1) << 1);
        int num = 1;
        int minL = 1, minC = 1;
        int maxL = 2 * step, maxC = 2 * step;

        while (step) {
            if (minL + step <= x && minC + step <= y) {
                minL += step;
                minC += step;
                num += 3 * step * step;
            } else if (minL + step <= x && minC + step >= y) {
                minL += step;
                maxC -= step;
                num += 2 * step * step;
            } else if (minL + step >= x && minC + step <= y) {
                maxL -= step;
                minC += step;
                num += step  * step;
            } else {
                maxL -= step;
                maxC -= step;
            }

            step >>= 1;
        }

		return num;
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
