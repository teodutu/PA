# Lab2 - greedy

## Rucsac continuu

- clasica;

- se sorteaza obiectele dupa raportul `pret/masa` si se aleg obiecte pana se umple sacul (ultimul
obiect se poate taia);

- Complexitate temporala: `O(nlogn)`;

- Complexitate spatiala: `O(n)`.

## Benzinarii intre 2 localitati

- se face o alimentare doar daca nu se poate ajunge pana la urmatoarea benzinarie;

- Complexitate temporala: `O(n)`;

- Complexitate spatiala: `O(n)` (se poate si `O(1)` caci este nevoie doar de ultimele 2 distante`).

## Teme ACS

- se sorteaza temele descrescator dupa numarul de puncte al acestora;

- se incearca sa se puna fiecare tema cat mai aproape de deadlineul sau pentru a lasa timp pentru
temele care au deadlineuri inainte;

- Complexitate temporala: `O(n * MaxDeadline)`;

- Complexitate spatiala: `O(n)`.

## Bonus

### My Points

- se sorteaza intervalele crescator dupa capatul stang;

- se aleg intervale pana se va depasi fiecare punct;

- Complexitate temporala: `O(nlogn)`;

- Complexitate spatiala: `O(n)`.

### Dishonest Sellers

- se sorteaza descrescator obiectele dupa diferenta dintre al doilea si primul pret;

- se aleg obiecte pana in momentul in care diferenta scade sub 0 (nu mai merita luat un obiect) si se
iau cel putin `k` obiecte;

- Complexitate temporala: `O(nlogn)`;

- Complexitate spatiala: `O(n)`.

### Max Sum

- se sorteaza crescator numerele;

- primelor k negative (daca exista) li se modifica semnul si apoi se calculeaza suma noului vector;

- Complexitate temporala: `O(nlogn)`;

- Complexitate spatiala: `O(n)`.
