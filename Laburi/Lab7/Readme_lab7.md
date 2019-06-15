# Lab7 - BFS si DFS

- probleme in principiu simple;

- probleme ceva mai interesante la bonus.

## BFS chior

- nimic interesant, folosit ca sa determine distanta intre noduri...

## Sortare topologica

- cu *algoritmul lui Kahn*.

## Bonus - Lee

- cam penal...

## Extra

### muzeu

- [infoarena](https://infoarena.ro/problema/muzeu);

- facuta mai demult, codu' nu e pe git.

### arbore3 + Pokemon GO Away

- [infoarena](https://infoarena.ro/problema/arbore3)

- [Test PA 2017](https://www.hackerrank.com/contests/test-practic-pa-2017-v2-meeseeks/challenges/test-2-pokemon-go-away-grea)

- dinamica pe arbore, cu elementele retinute intr-un *hash*;

- hash-ul retine numarul de aparitii al unei anumite sume pe un lant dintr-un arbore

- se adauga in hash fiecare noua suma obtinuat prin *DFS* prin arbore si se verifica gasirea unei sume
ce o completeaza pe cea curenta pana la suma dorita;

- cand se trece pe un alt lant, se elimina suma nodului curent din *hash*;

- complexitate temporala: `Theta(n + m)`;

- complexitate spatiala: `Theta(n + m)`.

### berarii2

- [infoarena](https://infoarena.ro/problema/berarii2);

- BFS din mai multe noduri de start (berariile) pana se goloste coada;

- complexitate temporala: `Theta(n + m)`;

- complexitate spatiala: `Theta(n + m)`.

### insule

- [infoarena](https://infoarena.ro/problema/insule);

- se face *Fill* pentru a determina insulele si *Lee* din vecinii oricarei insule *R* catre o insula *G*;

- complexitate temporala: `Theta(n + m)`;

- complexitate spatiala: `Theta(n + m)`.
