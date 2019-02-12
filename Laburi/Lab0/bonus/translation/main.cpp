#include <fstream>

using namespace std;

int makeNum(char c1, char c2) {
    return (c1 - '0') * 10 + c2 - '0';
}

int main() {
    int prevTranslations = 1, currTranslations = 1, aux;
    char prevChar, currChar;

    FILE *pInFile = fopen("input.txt", "r");
    ofstream fOut("output.txt");

    fscanf(pInFile, "%c%c", &prevChar, &currChar);

    if (currChar == '\n') {
        fOut << 1 << '\n';
        return 0;
    }

    if (makeNum(prevChar, currChar) <= 26) {
        currTranslations = 2;
    }

    while (true) {
        prevChar = currChar;
        fscanf(pInFile, "%c", &currChar);

        if (currChar == '\n') {
            break;
        }

        aux = currTranslations;
        currTranslations = (makeNum(prevChar, currChar) <= 26 ? prevTranslations + currTranslations
                                                              : currTranslations);
        prevTranslations = aux;
    }

    fOut << currTranslations << '\n';

    fclose(pInFile);
    fOut.close();
    return 0;
}