#ifndef _State2_H_
#define _State2_H_

#include <iostream>
#include <vector>

class State2 {
 public:
  const static int E = 1;
  const static int V = 2;
  int c_v, c_e, m_v, m_e;
  int position;
  State2() : distance_(0), parent_(NULL) { }

  friend std::ostream& operator<< (std::ostream& out, const State2& state);
  
  /* Verifica data 2 noduri reprezinta aceeasi stare. */
  bool has_same_state(const State2& other);

  /* Distanta de la starea initiala. */
  int distance() const { return distance_; }
  void set_distance(int distance) { distance_ = distance; }

  /* Nodul prin care s-a ajuns in aceasta stare. */
  State2* parent() { return parent_; }
  void set_parent(State2* parent) { parent_ = parent; }

  /* Intoarce estimarea distantei dintre 2 noduri ca suma a diferentei
   * pozitiilor. */
  int approx_distance();

  /* Lista vecinilor. */
  void expand(std::vector<State2*>& expanded);

  /* Afiseaza toti parintii nodului, in ordinea parcurgerii. */
  void print_path();

 private:
   /* Creaza un nou nod din nodul curent interschimband continutul celor 2
   * pozitii. */
  State2* create_State(int m_e, int m_v, int c_e, int c_v, int position);

  /* Helper pentru afisare. Intoarce numarul de mutari. */ 
  int print_partial_path(State2* state);

  /* Distanta de la nodul sursa in explorare. */
  int distance_;

  /* Nodul parinte in explorare. NULL pentru nodul sursa. */
  State2* parent_;
};

/* I/O operators. */
std::ostream& operator<< (std::ostream& out, const State2& state);
#endif  /* _State2_H_ */
