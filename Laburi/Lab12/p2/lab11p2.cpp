#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <set>
#include <queue>
#include <vector>

#include "State2.h"

class StateComparator {
 public:
  /* Determina algoritmul folosit. */
  enum Algorithm {
    AStar,
  };

  StateComparator(Algorithm algorithm)
      : algorithm_(algorithm) { }

  int f(State2* state) const{
    /* f(n) = g(n) + h(n) */
    /* g(n) = numarul de mutari din pozitia initiala */
    switch(algorithm_) {
      case AStar:
      return state->distance() + state->approx_distance();
    }
    return 0;
  }

  bool operator() (State2* State1, State2* State2) const {
    return f(State1) > f(State2);
  }

 private:
  const Algorithm algorithm_;
};

bool is_explored(std::vector<State2*>& closed, State2& state) {
  for (std::vector<State2*>::const_iterator it = closed.begin();
       it != closed.end();
       ++it) {
    if (state.has_same_state(**it)) {
      return true;
    }
  }
  return false;
}

void remove_state(std::vector<State2*>& closed, State2* state) {
    auto it = std::find_if(closed.begin(), closed.end(), [state](State2* s) {
        return state->has_same_state(*s);
    });

    if (it != closed.end()) {
        closed.erase(it);
    }
}

int main() {

  	State2* initial_State = new State2();
  	State2* solution_State = new State2();
  	
	initial_State->m_e = 3;
	initial_State->m_v = 0;
	initial_State->c_e = 3;
	initial_State->c_v = 0;
	initial_State->position = State2::E;

	solution_State->m_e = 0;
	solution_State->m_v = 3;
	solution_State->c_e = 0;
	solution_State->c_v = 3;
	solution_State->position = State2::V;

  	std::cout << "initial point " << *initial_State << std::endl;
  	std::cout << "final point " << *solution_State << std::endl;

	

  	/* Pentru nodurile in curs de explorare, implementate ca o coada de
   	* prioritati. */
  	std::priority_queue<State2*, std::vector<State2*>, StateComparator> open(
      	StateComparator(StateComparator::AStar));

  	/* Initial doar nodul de start este in curs de explorare. */
  	initial_State->set_distance(0);
  	initial_State->set_parent(NULL);
  	open.push(initial_State);

  	/* Pentru nodurile care au fost deja expandate. */
  	std::vector<State2*> closed;
  	std::vector<State2*> next_states;
  	State2* crt_state;

	/* Numar de pasi pana la solutie */
	int steps = 0;

	/*TODO: A* */
	closed.emplace_back(initial_State);
	open.emplace(initial_State);

    while (!open.empty()) {
        crt_state = open.top();
        open.pop();
        next_states.clear();

        if (crt_state->has_same_state(*solution_State)) {
            crt_state->print_path();
            break;
        }

        crt_state->expand(next_states);
        closed.emplace_back(crt_state);

        for (State2* next_state : next_states) {
            if (!is_explored(closed, *next_state)) {
//                closed.emplace_back(next_state);
                next_state->set_distance(crt_state->distance() + 1);
                next_state->set_parent(crt_state);
                open.emplace(next_state);
            } else if (crt_state->distance() + 1 > next_state->distance()) {
                remove_state(closed, next_state);
                next_state->set_distance(crt_state->distance() + 1);
                next_state->set_parent(crt_state);
                open.emplace(next_state);
            }
        }
    }

	std::cout << "Numarul de pasi pana la solutie: " << steps << std::endl;
  	return 0;
}
