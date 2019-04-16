#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("p1.in");
    ofstream out("p1.out");

    int n;
    int64_t diff = 0;
    int* v;

    in >> n;
    v = new int[n];

    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }

    // la orice mutare, fiecare jucator va alege cel mai mare numar disponibil,
    // deci se vor alege in ordine elementele din vectorul sortat descrescator
    sort(v, v + n, [](int v1, int v2) {
        return v1 > v2;
    });

    // primul jucator alege pozitiile pare, iar celalalt pe cele de pe pozitii impare
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            diff -= v[i];
        } else {
            diff += v[i];
        }
    }

    out << diff << '\n';

    // se elibereaza memoria si se inchid fisierele
    delete[] v;

    in.close();
    out.close();

    return 0;
}