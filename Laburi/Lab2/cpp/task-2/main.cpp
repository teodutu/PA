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
	int n, m;
	vector<int> dist;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 0, d; i < n; i++) {
			fin >> d;
			dist.push_back(d);
		}
		fin.close();
	}

	int get_result() {
		int stops = 0, currMax = m, len = dist.size();

		for (int i = 1; i < len; ++i) {
			if (currMax < dist[i]) {
				currMax = dist[i - 1] + m;
				++stops;
			}
		}

		return stops;
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