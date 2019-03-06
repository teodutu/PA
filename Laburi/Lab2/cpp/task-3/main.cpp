#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Homework {
	int deadline;
	int score;

	Homework(int _deadline, int _score) : deadline(_deadline), score(_score) {}
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<Homework> hws;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		for (int i = 0, deadline, score; i < n; i++) {
			fin >> deadline >> score;
			hws.emplace_back(deadline, score);
		}
		fin.close();
	}

	int get_result() {
	    int maxScore = 0, time = 0;
	    int maxDeadline = 0;

        for (Homework& hw : hws) {
            if (maxDeadline < hw.deadline) {
                maxDeadline = hw.deadline;
            }
        }

        bool tasks[maxDeadline + 1];
        memset(tasks, 0, maxDeadline + 1);

		sort(hws.begin(), hws.end(), [](Homework& h1, Homework& h2) {
		    return h1.score > h2.score;
		});

		for (Homework& hw : hws) {
		    if (!tasks[hw.deadline]) {
                tasks[hw.deadline] = true;
                maxScore += hw.score;
		    } else {
		        for (int i = hw.deadline - 1; i; --i) {
		            if (!tasks[i]) {
                        maxScore += hw.score;
                        tasks[i] = true;
                        break;
		            }
		        }
		    }
		}

		return maxScore;
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