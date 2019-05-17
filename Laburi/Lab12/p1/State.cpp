#include "State.h"

#include <cmath>

bool State::has_same_state(const State& other) {
  return x == other.x && y == other.y;
}

int State::approx_distance(const State other) {
 	int approx_distance = 0;
	/*TODO: functie admisibila care sa estimeze costul pana la starea finala*/
	approx_distance = ABS(x - other.x) + ABS(y - other.y);
	  	
	return approx_distance;
}

State* State::create_State(int next_i, int next_j) {
  State* next = new State(*this);
  next->set_parent(this);
  next->x = next_i;
  next->y = next_j;
  next->set_distance(distance() + 1);
  return next;
}

void State::expand(std::vector<State*>& expanded) {
  const int i = x;
  const int j = y;

  /* Exista maxim 4 vecini posibili: */
  /* 1. Patratelul de deasupra spatiului alb este interschimbat. */
  if (i > 0 && matrix[i-1][j]) {
    expanded.push_back(create_State(i - 1, j));
  }

  /* 2. Patratelul de dedesubtul spatiului alb este interschimbat. */
  if (i < M - 1 && matrix[i+1][j]) {
    expanded.push_back(create_State(i + 1, j));
  }

  /* 3. Patratelul de la stanga spatiului alb este interschimbat. */
  if (j > 0 && matrix[i][j-1]) {
    expanded.push_back(create_State(i, j - 1));
  }

  /* 4. Patratelul de la dreapta spatiului alb este interschimbat. */
  if (j < N - 1 && matrix[i][j+1]) {
    expanded.push_back(create_State(i, j + 1));
  }
}

void State::print_path() {
  int moves = State::print_partial_path(this);
  std::cout << moves << " mutari" << std::endl;
}

int State::print_partial_path(State* state) {
  if (state == NULL) {
    return 0;
  }
  const int moves = print_partial_path(state->parent());
  std::cout << *state << std::endl;
  return moves + 1;
}

/* I/O operators. */
std::ostream& operator<< (std::ostream& out, const State& state) {
	std::cout << state.x << " " << state.y;
	std::cout << std::endl;
 	return out;
}

std::istream& operator>> (std::istream& in, State& state) {
  in >> state.x >> state.y;
  return in;
}

