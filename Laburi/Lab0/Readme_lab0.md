# Lab0 - probleme de interviu

- [probleme luate din slideurile lui Traian](https://www.slideshare.net/TraianRebedea/importana-algoritmilor-pentru-problemele-de-la-interviuri)

## Se cauta elementul maxim intr-un vector sortat si rotit cu un numar necunoscut de  pozitii la dreapta - rotated_bin_search

- se va cauta binar numarul de pozitii cu care sirul a fost rotit;

- in functie de acest numar, se va cauta binar numarul dorit fie la dreapta pozitiei rotirii, fie in
stanga;

- Complexitate temporala: `O(logn)`;

- Complexitate spatiala: `O(n)`.

## Suma maxima dintr-un vector cu o constrangere: daca se ia v[i], nu se iau v[i - 1] si v[i + 1]

- e destul sa se tina sumele maxime posibile pentru ultimele 2 pozitii, iar noua suma maxima se va
calcula pe baza acestor maxime, dupa care, acestea din urma se vor actualiza la fiecare pas.

- Complexitate temporala: `O(n)`;

- Complexitate spatiala: `O(1)`.

## Se cauta 3 numere cu suma 0 intr-un vector de intregi

- pentru fiecare numar se cauta printre numerele de dupa acesta din vector 2 numere cu suma egala cu
primul numar `* (-1)`;

- pentru a cauta cel de-al 3-lea numar se foloseste un `unordered_set` pentru a face interogari in
`O(1)`;

- Complexitate temporala: `O(n^2)`;

- Complexitate spatiala: `O(n)`.

## Codificand caracterele a-z cu numarul lor de ordine din alfabet, sa se afle numarul de interpretari al unei codificari

- orice 2 cifre din codificare care impreuna formeaza un numar `<= 26` va mari numarul de interpretari;

- pe de o parte, cele 2 cifre pot fi considerate separat, pe de alta parte, pot fi considerate impreuna;

- asadar, este nevoie de ultimele 2 numere de translatie;

- se verifica daca ultimele 2 cifre parcurse formeaza un numar `<= 26`, caz in care noul numar de
translatii este suma ultimelor 2 numere;

- altfel, se pastreaza numarul precedent de translatii;

- Complexitate temporala: `O(n)`;

- Complexitate spatiala: `O(1)`.
