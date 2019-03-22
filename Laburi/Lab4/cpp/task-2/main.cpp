#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int kMod = 1e9 + 7;

int t[1000][1000], f[1000][1000];
string boolean, op;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	string expr;

	void read_input() {
		ifstream fin("in");
		fin >> n >> expr;
		expr = " " + expr; // adaugare caracter fictiv - indexare de la 1
		fin.close();
	}

	int get_result() {
		/*
		Calculati numarul de parantezari ale expresiei date astfel incat
		rezultatul sa dea true si returnati restul impartirii numarului
		la 10^9 + 7.
		*/

		int j;

		for (char c : expr) {
		    if (c == 'T' || c == 'F') {
		        boolean += c;
		    } else if (c != ' '){
		        op += c;
		    }
		}

		int m = boolean.size();

        for (int i = 0 ; i < m; ++i) {
            if (boolean[i] == 'T') {
                t[i][i] = 1;
                f[i][i] = 0;
            } else {
                f[i][i] = 1;
                t[i][i] = 0;
            }
        }

		for (int p = 1; p < m; ++p) {
            for (int i = 0; i < m; ++i) {
                j = i + p;
                if (j < m) {
                    for (int k = i; k < j; ++k) {
                        switch (op[k]) {
                            case '&':
                                t[i][j] = (t[i][j] + 1LL * t[i][k] * t[k + 1][j]) % kMod;

                                f[i][j] = (f[i][j] + 1LL * t[i][k] * f[k + 1][j]) % kMod;
                                f[i][j] = (f[i][j] + 1LL * f[i][k] * t[k + 1][j]) % kMod;
                                f[i][j] = (f[i][j] + 1LL * f[i][k] * f[k + 1][j]) % kMod;
                                break;

                            case '|':
                                t[i][j] = (t[i][j] + 1LL * f[i][k] * t[k + 1][j]) % kMod;
                                t[i][j] = (t[i][j] + 1LL * t[i][k] * t[k + 1][j]) % kMod;
                                t[i][j] = (t[i][j] + 1LL * t[i][k] * f[k + 1][j]) % kMod;

                                f[i][j] = (f[i][j] + 1LL * f[i][k] * f[k + 1][j]) % kMod;
                                break;

                            case '^':
                                t[i][j] = (t[i][j] + 1LL * t[i][k] * f[k + 1][j]) % kMod;
                                t[i][j] = (t[i][j] + 1LL * f[i][k] * t[k + 1][j]) % kMod;

                                f[i][j] = (f[i][j] + 1LL * f[i][k] * f[k + 1][j]) % kMod;
                                f[i][j] = (f[i][j] + 1LL * t[i][k] * t[k + 1][j]) % kMod;
                                break;
                        }
                    }
                }
            }
		}

		return t[0][m - 1];
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
