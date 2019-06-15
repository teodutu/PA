# Lab4 - Programare Dinamica

- prea multe basini si nimic din care chiar sa inveti ceva

## Dinamica vs Mate

- spoiler: mate ftw;

- implementata legit la [bonus](https://github.com/teodutu/PA/tree/master/Laburi/Lab4/bonus/azerah).

- complexitate temporala: prea mare

- complexitate spatiala: prea mare

## In cate moduri poti paranteza o expresie booleana cu & | ^ astfel incat sa fie satisfacuta

- simalara cu [PODM](https://infoarena.ro/problema/podm);

- se ia un operator si se verifica parantezarea inainte si dupa el;

- complexitate temporala: `Theta(Numar_T/F^3)`;

- complexitate spatiala: `Theta(Numar_T/F^2)`.

## Bonus

### Dinamica vs Mate 2.0

- rezolvarea cu mate; 

- daca nu exista numere impare, atunci toate submultimile nevide ale vectorului dat sunt solutii, deci
`2^n - 1` solutii;

- daca exista si numere impare, atunci jumatate dintre submultimile de numere impare au un cardinal
par, iar acestea pot fi combinate in orice mod cu submultimile de numere impare;

- fie `i` = numarul de numere impare si `p` cel de numere pare;

- submultimile de numere pare sunt in numar de 2^p iar cele admisibile de numere impare in numar de
2^(i - 1);

- deci in total, in acest caz, avem 2^(i + p - 1) - 1 submultimi, adica 2^n - 1.

- [infoarena - azerath](https://www.infoarena.ro/problema/Azerah);

- complexitate temporala: `Theta(logn)`;

- complexitate spatiala: `Theta(1)`.

### PA Country

- `m[i][j][k]` reprezinta numarul de moduri in care se poate ajunge la pozitia `(i, j)` in `k` pasi;

- complexitate temporala: `Theta(n * m * p)`;

- complexitate spatiala: `Theta(n * m)`.
