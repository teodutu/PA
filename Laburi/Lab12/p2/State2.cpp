#include "State2.h"

#include <cmath>

bool State2::has_same_state(const State2& other) {
  return c_v == other.c_v && c_e == other.c_e && 
	m_v == other.m_v && m_e == other.m_e && position == other.position;
}

int State2::approx_distance() {
  	/*TODO: functie admisibila care sa estimeze costul pana la starea finala*/
    return (m_v + c_v) / 2;
}

State2* State2::create_State(int m_e, int m_v, int c_e, int c_v, int position) {
  State2* next = new State2(*this);
  next->set_parent(this);
  next->m_e = m_e;
  next->m_v = m_v;
  next->c_v = c_v;
  next->c_e = c_e;
  next->position = position;
  next->set_distance(distance() + 1);
  return next;
}

bool validState(State2 state) {
	if (state.m_e < 0 || state.c_e < 0 || state.m_v < 0 || state.c_v < 0)
		return false;

	if ((state.m_e > 0 && state.m_e < state.c_e )|| (state.m_v > 0 && state.m_v < state.c_v))
		return false;

	return true;
}

void State2::expand(std::vector<State2*>& expanded) {
  State2 *state;

  /*incerc sa mut 1 canibal + 1 misionar */
  if(position == E) {
	state = create_State(m_e - 1, m_v + 1, c_e - 1, c_v + 1, V);
	if (validState(*state))
		expanded.push_back(state);
	else
		delete state;
  }
  else {
   state = create_State(m_e + 1, m_v - 1, c_e + 1, c_v - 1, E);
	 if (validState(*state))
		expanded.push_back(state);
	else
		delete state;
  }

	/*incerc sa mut 2 canibali */
  	if(position == E) {
  		state = create_State(m_e, m_v, c_e - 2, c_v + 2, V);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;	
	}
	else {
  	state = create_State(m_e, m_v, c_e + 2, c_v - 2, E);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}

  /*incerc sa mut 2 misionari */
	if(position == E) {
  	state = create_State(m_e - 2, m_v + 2, c_e, c_v, V);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}
	else {
  	state = create_State(m_e + 2, m_v - 2, c_e, c_v, E);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}

  /*incerc sa mut 1 canibal */
	if(position == E) {
  	state = create_State(m_e, m_v, c_e - 1, c_v + 1, V);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}
	else {
  		state = create_State(m_e, m_v, c_e + 1, c_v - 1, E);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}

  /*incerc sa mut 1 misionar */
	if(position == E) {
  	state = create_State(m_e - 1, m_v + 1, c_e, c_v, V);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}
	else {
		state = create_State(m_e + 1, m_v - 1, c_e, c_v, E);
		if (validState(*state))
			expanded.push_back(state);
		else
			delete state;
	}
}

void State2::print_path() {
  int moves = State2::print_partial_path(this);
  std::cout << moves << " mutari" << std::endl;
}

int State2::print_partial_path(State2* state) {
  if (state == NULL) {
    return 0;
  }
  const int moves = print_partial_path(state->parent());
  std::cout << *state << std::endl;
  return moves + 1;
}

/* I/O operators. */
std::ostream& operator<< (std::ostream& out, const State2& state) {
	std::cout << "E: misionari: " << state.m_e << " canibali " << state.c_e 
		<<" V: misionari: " << state.m_v << " canibali " << state.c_v;
	std::cout << std::endl;
 	return out;
}

