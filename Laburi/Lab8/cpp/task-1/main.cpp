#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/Laburi/Lab8/cpp/task-1/main.cpp

const int kNmax = 100005;

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
	vector<int> adjt[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
		fin.close();
	}

	void DFS(int crtNode, int& time, vector<int>& disc, vector<int>& firstAccessible, stack<int>& s,
             vector<vector<int>>& sol, vector<bool>& isInStack) {
	    disc[crtNode] = time;
	    firstAccessible[crtNode] = time++;
	    s.push(crtNode);
	    isInStack[crtNode] = true;

	    for (int nextNode : adj[crtNode]) {
	        if (!disc[nextNode]) {
	            DFS(nextNode, time, disc, firstAccessible, s, sol, isInStack);
	            firstAccessible[crtNode] = min(firstAccessible[nextNode], firstAccessible[crtNode]);
	        } else if (isInStack[nextNode]) {
                firstAccessible[crtNode] = min(disc[nextNode], firstAccessible[crtNode]);
	        }
	    }

	    if (disc[crtNode] == firstAccessible[crtNode]) {
            vector<int> crtSol;
            int x;

            do {
                x = s.top();
                s.pop();
                crtSol.emplace_back(x);
                isInStack[x] = false;
            } while (crtNode != x);

            sol.emplace_back(crtSol);
	    }
	}

	vector<vector<int>> get_result() {
		/*
		TODO: Gasiti componentele tare conexe ale grafului orientat cu
		n noduri, stocat in adj. Rezultatul se va returna sub forma
		unui vector, ale carui elemente sunt componentele tare conexe
		detectate. Nodurile si componentele tare conexe pot fi puse in orice
		ordine in vector.
		
		Atentie: graful transpus este stocat in adjt.
		*/
		vector<vector<int>> sol;
		vector<int> disc(n + 1), firstAccessible(n + 1);
		vector<bool> isInStack(n + 1);
		stack<int> s;
		int startTime = 1;

		for (int i = 1; i <= n; ++i) {
		    if (!disc[i]) {
		        DFS(i, startTime, disc, firstAccessible, s, sol, isInStack);
		    }
		}

		return sol;
	}

	void print_output(vector<vector<int>> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				fout << nod << ' ';
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
