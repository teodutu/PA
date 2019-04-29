#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/blob/master/Laburi/Lab11/cpp/task-1/main.cpp

const int kNmax = 1005;

class Task {
public:
	void solve() {
		read_input();
		print_output(get_result());
	}

private:
	int n;
	int m;
	vector<int> adj[kNmax];
    int C[kNmax][kNmax];
    bool marked[kNmax];
    int parent[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;

		memset(C, 0, sizeof(C));

		for (int i = 1, x, y, z; i <= m; i++) {
			fin >> x >> y >> z;
			adj[x].push_back(y);
			adj[y].push_back(x);
			C[x][y] += z;
		}

		fin.close();
	}

    inline bool BFS() {
        queue<int> q;
        int currNode;

        memset(marked, 0, sizeof(marked));

        q.push(1);
        marked[1] = true;

        while (!q.empty()) {
            currNode = q.front();
            q.pop();

            if (currNode != n) {
                for (int nextNode : adj[currNode]) {
                    if (!marked[nextNode] && C[currNode][nextNode]) {
                        marked[nextNode] = true;
                        parent[nextNode] = currNode;
                        q.push(nextNode);
                    }
                }
            }
        }

        return marked[n];
    }

	int get_result() {
		int maxFlow = 0;
		int crtFlow;

        while (BFS()) {
            for (int currNode : adj[n]) {
                if (marked[currNode]) {
                    crtFlow = INT_MAX;
                    parent[n] = currNode;

                    for (int crtNode = n; crtNode != 1; crtNode = parent[crtNode]) {
                        crtFlow = min(crtFlow, C[parent[crtNode]][crtNode]);
                    }

                    if (crtFlow) {
                        for (int crtNode = n; crtNode != 1; crtNode = parent[crtNode]) {
                            C[parent[crtNode]][crtNode] -= crtFlow;
                            C[crtNode][parent[crtNode]] += crtFlow;
                        }

                        maxFlow += crtFlow;
                    }
                }
            }
        }

		return maxFlow;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
