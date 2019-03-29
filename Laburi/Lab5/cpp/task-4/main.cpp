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
	string caractere;
	vector<int> freq;

	void read_input() {
		ifstream fin("in");
		fin >> n >> k;
		fin >> caractere;
		caractere = " " + caractere; // Adaugare element fictiv -
									 // indexare de la 1.
		freq.push_back(-1); // Adaugare element fictiv - indexare de la 1.
		for (int i = 1, f; i <= n; i++) {
			fin >> f;
			freq.push_back(f);
		}
		fin.close();
	}

	bool checkChar(vector<char> sol) {
	    int len = sol.size();
	    int f = 0;

	    for (int i = len - 2; i > -1 && sol[i] == sol[i + 1]; --i) {
            if (++f == k) {
                return false;
            }
	    }

        return true;
	}

    void BKT(int crtPos, int len, vector<vector<char> >& all, vector<char>& sol) {
        if (crtPos > len) {
            all.emplace_back(sol);
            return;
        }

        int numChars = caractere.size();

        for (int i = 1; i < numChars; ++i) {
            if (freq[i]) {
                sol.emplace_back(caractere[i]);
                --freq[i];

                if (checkChar(sol)) {
                    BKT(crtPos + 1, len, all, sol);
                }

                sol.pop_back();
                ++freq[i];
            }
        }
    }

	vector<vector<char> > get_result() {
		vector<vector<char> > all;
        vector<char> sol;
		int len = 0;

		for (int f : freq) {
		    len += f;
		}

		BKT(0, len, all, sol);

		return all;
	}

	void print_output(vector<vector<char> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j];
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
