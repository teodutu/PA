#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Object {
	int weight;
	int price;

	Object(int _weight, int _price) : weight(_weight), price(_price) {}
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, w;
	vector<Object> objs;

	void read_input() {
		ifstream fin("in");
		fin >> n >> w;
		for (int i = 0, weight, price; i < n; i++) {
			fin >> weight >> price;
			objs.emplace_back(weight, price);
		}
		fin.close();
	}

	double get_result() {
		sort(objs.begin(), objs.end(), [](Object& o1, Object& o2) {
            return (double)o1.price / o1.weight > (double)o2.price / o2.weight;
		});

		double maxPrice = 0;

		for (Object& obj : objs) {
		    if (!w) {
                break;
		    }

		    if (w < obj.weight) {
		        maxPrice += (double)w / obj.weight * obj.price;
                break;
		    }

		    w -= obj.weight;
            maxPrice += obj.price;
		}

		return maxPrice;
	}

	void print_output(double result) {
		ofstream fout("out");
		fout << setprecision(4) << fixed << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}