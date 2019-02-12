#include <cassert>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-3;

int main(int argc, char *argv[]) {
  if (argc != 3) return 1;

  FILE* ref = fopen(argv[1], "r");
  assert(ref);

  FILE* out = fopen(argv[2], "r");
  assert(out);

  double x, y;
  assert(fscanf(ref, "%lf", &x) == 1);
  assert(fscanf(out, "%lf", &y) == 1);

  assert(fabs(x - y) <= eps);
  return 0;
}
