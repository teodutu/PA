#include <fstream>

using namespace std;

#define NMAX 100

__attribute__((always_inline)) bool isOnMap(int r, int c, int rows, int cols) {
    // functia verifica daca pozitia (r, c) este sau nu in harta
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

int findArea(int r, int c, int rows, int cols, int maxDiff, int zone, int marked[][NMAX],
             int map[][NMAX], int start) {
    if (!isOnMap(r, c, rows, cols) || marked[r][c] == zone || map[r][c] - start > maxDiff
        || map[r][c] < start) {
        // noua pozitie la care s-a ajuns nu respecta constrangerile problemei
        return 0;
    }

    marked[r][c] = zone;

    // aria de la pozitia (r, c) este 1 + arie_dreapta + arie_sus + arie_stanga + arie_jos
    return 1 + findArea(r, c + 1, rows, cols, maxDiff, zone, marked, map, start)
             + findArea(r - 1, c, rows, cols, maxDiff, zone, marked, map, start)
             + findArea(r, c - 1, rows, cols, maxDiff, zone, marked, map, start)
             + findArea(r + 1, c, rows, cols, maxDiff, zone, marked, map, start);
}

int main() {
    // se deschid fisierele
    ifstream fIn("p2.in");
    ofstream fOut("p2.out");

    int rows, cols, maxDiff, maxArea = 0, crtArea, zone = 0;
    int map[NMAX][NMAX], marked[NMAX][NMAX] = {0};

    // se citesc variabilele si harta
    fIn >> rows >> cols >> maxDiff;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fIn >> map[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // se calculeaza suprafata maxima a zonei care ar avea drept valoare minima pe cea
            // de la pozitia (i, j)
            crtArea = findArea(i, j ,rows, cols, maxDiff, ++zone, marked, map, map[i][j]);

            if (crtArea > maxArea) {
                maxArea = crtArea;
            }
        }
    }

    fOut << maxArea << '\n';

    // se inchid fisierele
    fIn.close();
    fOut.close();

    return 0;
}