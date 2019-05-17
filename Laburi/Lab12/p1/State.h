#ifndef _State_H_
#define _State_H_

#include <iostream>
#include <vector>

#define ABS(a) ((a) < 0 ? (-(a)) : (a))

class State {
 public:
  static int N, M;
  static int **matrix;
  int x, y;
  State() : distance_(0), parent_(NULL) { }

  friend std::ostream& operator<< (std::ostream& out, const State& state);
  friend std::istream& operator>> (std::istream& in, State& state);

  /* Verifica daca 2 noduri reprezinta aceeasi stare. */
  bool has_same_state(const State& other);

  /* Distanta de la starea initiala. */
  int distance() const { return distance_; }
  void set_distance(int distance) { distance_ = distance; }

  /* Nodul prin care s-a ajuns in aceasta stare. */
  State* parent() { return parent_; }
  void set_parent(State* parent) { parent_ = parent; }

  /* Intoarce estimarea distantei dintre 2 noduri ca suma a diferentei
   * pozitiilor. */
  int approx_distance(const State other);

  /* Lista vecinilor. */
  void expand(std::vector<State*>& expanded);

  /* Afiseaza toti parintii nodului, in ordinea parcurgerii. */
  void print_path();

 private:
   /* Creaza un nou nod din nodul curent interschimband continutul celor 2
   * pozitii. */
  State* create_State(int next_i, int next_j);

  /* Helper pentru afisare. Intoarce numarul de mutari. */ 
  int print_partial_path(State* state);

  /* Distanta de la nodul sursa in explorare. */
  int distance_;

  /* Nodul parinte in explorare. NULL pentru nodul sursa. */
  State* parent_;
};

/* I/O operators. */
std::ostream& operator<< (std::ostream& out, const State& state);
std::istream& operator>> (std::istream& in, State& state);
#endif  /* _State_H_ */
