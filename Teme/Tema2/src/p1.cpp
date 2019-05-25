#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // se deschid fisierele
    ifstream fIn("p1.in");
    ofstream fOut("p1.out");

    int numNodes, crtDist, maxDist = 0, lastNode, crtNode, numZeros = 0;
    // hash distanta - vector de noduri cu acea distanta pana la nodul 1
    unordered_map<int, vector<int>> dists;
    vector<pair<int, int>> edges;

    fIn >> numNodes;

    for (int i = 1; i <= numNodes; ++i) {
        fIn >> crtDist;

        // se verifica sa nu existe 2 noduri pe nivelul 0 al arborelui de parcurgere `BFS`
        // (2 radacini)
        if (!crtDist&& ++numZeros > 1) {
            fOut << "-1\n";
            return 0;
        }

        // se adauga nodul curent la vectorul corespunzator distantei acestuia
        dists[crtDist].emplace_back(i);

        if (maxDist < crtDist) {
            maxDist = crtDist;
        }
    }

    // daca arborele `BFS` nu are radacina, acesta este invalid
    if (!numZeros) {
        fOut << "-1\n";
        return 0;
    }

    // nodul ce va fi radacina subarborelui cu distanta mai mare cu 1 decat cea pana la acest nod
    lastNode = 1;

    // se iau distantele pe rand si se creeaza un arbore corespunzator unei parcurgeri `BFS` in
    // care toate nodurile de pe un anumit nivel >= 1 sunt legate doar la ultimul nod gasit pe
    // nivelul anterior
    for (crtDist = 1; crtDist <= maxDist; ++crtDist) {
        // daca nu exista un anumit nivel, distantele date sunt invalide
        if (dists.find(crtDist) == dists.end()) {
            fOut << "-1\n";
            return 0;
        }

        // se adauga muchiile din vectorul corespunzator nivelului curent in solutie, si se retine
        // ultimul nod de pe acest nivel
        for (int nextNode : dists[crtDist]) {
            edges.emplace_back(lastNode, nextNode);
            crtNode = nextNode;
        }

        lastNode = crtNode;
    }

    // se afiseaza numarul de muchii (`N` - 1, fiind un arbore) si muchiile in sine
    fOut << edges.size() << '\n';
    for (auto& crtEdge : edges) {
        fOut << crtEdge.first << ' ' << crtEdge.second << '\n';
    }

    // se inchid fisierele
    fIn.close();
    fOut.close();

    return 0;
}