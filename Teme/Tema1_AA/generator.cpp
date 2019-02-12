#include <fstream>
#include <random>
#include <climits>

#include "output_parser.h"

#define MAX_N 10000000

/**
 * Se vor genera fisierele de input test[1, 9].in, ce contin numere aleatoare intre diverse limite.
 */
int main() {
    char out_file_name[] = "in/test0.in";
    std::random_device rd;
    std::mt19937 mt(rd());

    // genereaza numere aleatoare distribuite uniform pe intervalul [1, 2^27 - 1]
    std::uniform_int_distribution<> small_dist(1, INT_MAX >> 4);

    //  genereaza numere aleatoare distribuite uniform pe intervalul [1, 2^30 - 1]
    std::uniform_int_distribution<> medium_dist(1, INT_MAX >> 1);

    //  genereaza numere aleatoare distribuite uniform pe intervalul [2^30 - 1, 2^31 - 1]
    std::uniform_int_distribution<> large_dist(INT_MAX >> 1, INT_MAX);

    for (int i = 1; i < 10; ++i) {
        out_file_name[7] = i + '0';

        OutputWriter writer(out_file_name);

        writer.write_int(MAX_N);
        writer.write_char('\n');

        // testele [1, 3] contin numere mici
        // testele [4, 6] contin numere de pe intreg intervalul posibil
        // testele [7, 9] contin numerele mai mari
        for (int j = 0; j < MAX_N; ++j) {
            if (i < 4) {
                writer.write_int(small_dist(mt));
            } else if (i < 7) {
                writer.write_int(medium_dist(mt));
            } else {
                writer.write_int(large_dist(mt));
            }
            writer.write_char(' ');
        }
    }

    return 0;
}
