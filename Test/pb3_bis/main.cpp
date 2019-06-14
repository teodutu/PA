#include <cstdio>
#include <cstring>
#include <cctype>

#define NMAX 102

using namespace std;

bool haveChar[NMAX][NMAX];
char s1[NMAX], s2[NMAX];

bool checkUpper (int i, int j) {
    return s1[i] == s2[j] || tolower(s2[j]) == s1[i];
}

int main() {
    int n, len1, len2;

    scanf("%d", &n);

    for (int k = 1; k <= n; ++k) {
        scanf("%s", s1);
        scanf("%s", s2);

        memset(haveChar, false, sizeof(haveChar));
        haveChar[0][0] = true;

        len1 = strlen(s1);
        len2 = strlen(s2);

        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (haveChar[i][j]) {
                    if (islower(s1[i])) {
                        haveChar[i + 1][j] = true;
                    }

                    if (j < len2 && checkUpper(i, j)) {
                        haveChar[i + 1][j + 1] = true;
                    }
                }
            }
        }

        if (haveChar[len1][len2]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
