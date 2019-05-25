# Tema 2 PA

## Precizari generale

- valorile si variabilele folosite in *README* au aceleasi semnificatii precum cele din enunt.

## p1

### Idee

- cel mai simplu este sa  se construiasca un arbore ce respecta distantele date;

- de aceea, se va tine un hash de la un nivel (o distanta fata de radacina) la un vector de noduri
de pe acel nivel;

- daca un nivel lipseste sau daca sunt mai multe noduri pe acelasi nivel, se afiseaza `-1` si se
incheie programul;

- apoi, se va construi graful ce va contine `N - 1` muchii (deci mai putine decat `10^6`) si in care
ultimul nod ca numar de pe un nivel va fi parintele nodurilor de pe nivelul urmator;

### Complexitate

- se considera ca hashuirea folosind unordered_map se face in timp `O(1)`;

- **temporala**: parcurgerea distantelor `(Theta(N))` + parcurgerea elementelor si a vectorilor din hash
`(Theta(N))` = `Theta(N)`;

- **spatiala**: vectorul de distante `(Theta(N))` + hash-ul ce contine un nod o singura data `(Theta(N))` =
`Theta(N)`.

## p2

### Idee

- se va considera, ca fiecare element din harta este, pe rand, minimul dintr-o regiune;

- astfel, din fiecare element al hartii se va face un `fill/DFS` care va returna aria zonei care
contine celula de start si ale carei celule sunt cu maximum `K` mai mari decat cea de start.

## Complexitate

- **temporala**: un `fill/DFS` potential cat toata harta din fiecare celula = `O(N^2 * M^2)`;

- **spatiala**: se retin matricea din fisier si cea in care se marcheaza daca o celula a fost vizitata =
`Theta(N * M)`.

## p3

### Idee

- distantele catre un nod se vor considera impreuna cu muchia prin care s-a ajuns la acest nod,
deoarece o muchie dezavantajoasa la un anumit moment se poate dovedi utila la urmatorul pas, daca
aceasta ar introduce, per total, penalizari mai mici decat celelalte;

- pentru ca avem nevoie sa scadem treptat costurile acestor perechi nod-muchie, se va folosi
*algoritmul Bellman-Ford*;

- costurile vor fi reprezentate sub forma unei matrice in care `costs[i][j]` reprezinta cel mai mic
 cost obtinut pentru nodul `i`, cu muchia de intrare in acesta de tip `j`;

- la final, costul minim pana la nodul `N` va fi minimul dintre costurile aferente tuturor tipurilor
de muchii, adica `min(costs[N][i]), i = 1 : T`.

### Complexitate

- nodurile vizitate cu Bellman-Ford sunt acum in numar de `N * T`, deci complexitatile vor fi:

- **temporala:** complexitatea *algoritmului Bellman-Ford*, pentru noul numar de noduri, adica `O(N * T * M)`;

- **spatiala**: se foloseste o lista de adiacenta (`O(M)`), o matrice de costuri (`O(N * T)`) si una de
penalizari `O(T^2)` => complexitatea `O(M + N * T + T^2)`.

## p4

### Idee

- intrucat `T <= 7`, se vor genera toate submultimile de tipuri de muchii, iar apoi se va rula
algoritmul Dijkstra pe fiecare submultime, solutia problemei fiind minimul costurilor obtinunte in
cadrul acestor `2^7 - 1` rulari;

- fie `t1`, `t2`, ..., `tp` muchiile necesare pentru a obtine un cost minim de la nodul 1 la `N`;

- generarea tuturor submultimilor tipurilor de muchii face sa se genereze si submultimea ce contine
fix `t1`, `t2`, ..., `tp` cautate, deci nu trebuie pusa problema vreunei memorari a muchiei de intrare
intr-un nod, ca in cazul problemei anterioare;

- la finalul unei rulari a *algoritmului lui Dijkstra*, se vor adauga la costurile obtinute in mod
obsinuit prin acest algoritm, penalizarile aferente tipurilor de muchii din submultimea curenta.

### Complexitate

- **temporala**: se ruleaza *algoritmul Dijkstra* de `P(T) - 1= 2^7 - 1` ori (nu se ruleaza pentru multimea
vida de muchii), deci `O(T * NlogN)`;

- **spatiala**: se retin lista de adiacenta (`O(N^2)`), un vector de costuri (`Theta(N)`) si unul de
penalizari (`Theta(N)`) `=> O(N^2)`.
