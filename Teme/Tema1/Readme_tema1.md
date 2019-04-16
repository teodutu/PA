# Tema 1 - PA

## p1:

### Idee:

- a juca optim inseama ca fiecare jucator sa ia cea mai mare moneda posibila,
caci altfel, aceasta va fi luata de adversar, rezultand intr-un avantaj pentru
acesta din urma;

- asadar, daca la fiecare pas fiecare jucator ia moneda cea mai mare disponibila
acest lucru se poate simula parcurgand vectorul monedelor sortat descrescator de
la dreapta la stanga si alegand prima moneda la fiecare pas pentru fiecare
jucator;

- diferenta va fi sumaPozitiiPare (alese de primul jucator, caci vectorul este
indexat de la 0) - sumaPozitiiImpare (alese de al doilea jucator).

### Complexitate:

- timp: sortare (`Theta(nlogn)`) + parcurgere (`Theta(n)`) + citire (`Theta(n)`) =>
`(Theta(nlogn)`);

- spatiu: se folosese doar vectorul de monede cu n elemente => Theta(n) memorie.


## p2:

### Idee:

- se va construi solutia incremental, in functie de k;

- astfel, pentru fiecare i din intervalul `[0, k]` se va cauta diferenta maxima
daca jocul s-ar desfasura intre pozitiile `[0, j]` cu i eliminari si cu
`j <- [0, n - 1]`;

- de aceea este nevoie initial de o matrice `bestDiff[k + 1][n]`;

- pentru 0 eliminari, jocul este identic cu cel de la p1, deci se va sorta
vectorul de monede si se va copia in matrice;

- acum, pentru fiecare pozitie `(i, j)` din `bestDiff`, exista 2 optiuni:
	- fie eliminam elementul j din vector si, deci avem diferenta de la pozitia
	`(i - 1, j - 1)`;

	- fie presupunem ca deja s-au facut cele i eliminari in intervalul `[0, j - 1]`
	si avem de adunat/scazut la/din suma de pe pozitia (i, j - 1) elementul `v[j]`
	in functie de paritatea pozitiei pe care se afla dupa i eliminari, paritate
	ce este data de pozitia sa, `j - 1`, deci de `(-1)^(j - i)`, caci primul jucator
	incepe de pe pozitia 0;

- se alege maximul dintre aceste 2 variane;

- la final, rezultatul se afla pe pozitia `(k, n - 1)` din matrice, ce
corespunde eliminarii a `k` numere din cele n totale;

- ar fi nevoie de `Theta(n^2)` memorie, dar se observa ca la fiecare pas i se
foloseste doar linia de deasupra, `i - 1`, deci sunt necesare doar 2 linii in
"matrice", ceea ce se obtine prin copierea liniei corespunzatoare lui i peste
cea ce ii corespunde lui `i - 1` dupa fiecare parcurgere;

- astfel, complexitatea temporala ramane aceeasi, iar cea de memorie scade;

### Complexitate:

- timp: sortare (`Theta(nlogn)`) + parcurgere "matrice" (`Theta(n^2)`) => `Theta(n^2)`;

- spatiu: vectorul de monede (`Theta(n)`) + matricea redusa la 2 linii si n
coloane (`Theta(n)`) => `Theta(n)`;


## p3:

### Idee:

- solutia se construieste pornind de la diferentele maxime obtinute in jocuri
cu o singura moneda, pentru fiecare moneda;

- apoi se va creste numarul de monede din joc cu 1 pana se ajunge la n;

- jocul cu monedele  `[i..j]` este fie cel cu monedele `[i + 1, j]` la care
se adauga moneda `i`, fie cel cu monedele `[i, j - 1]` la care se adauga moneda `j`;

- la fiecare extindere a jocului cu o moneda, jucatorul care va face prima
mutare va fi diferit de cel ce a facut prima mutare in cadrul jocurilor ce pot
compune jocul curent;

- practic fiecare supradiagonala a matricei folosite reprezinta mutarea unui
jucator;

- de aceea, din elementele i sau j se scad cele mai bune diferente obtinute
pentru jocurile `[i + 1, j]`, respectiv `[i, j - 1]`, cumva similar cu ideea
algoritmului negamax in care castigul unui jucator reprezinta pierderea
celuilalt;

- dintre cele 2 variante de a alege o moneda, se alege cea in care diferenta de
mai sus este maxima.

Complexitate:

- timp: parcurgere matrice (`Theta(n^2)`) => `Theta(n^2)`;

- memorie: vectorul de monede (`Theta(n)`) + matrice (`Theta(n^2)`) => `Theta(n^2)`.


## p4:

### Definitii:

- daca `(a, n) = 1`, atunci exista `b` astfel incat `a * b = 1 (mod n)`, `b` este
**inversul modular** al lui `a` fata de `n`;

- din *Teorema lui Euler*: `a^fi(n) = 1(mod n)`, unde *fi* = functia lui euler =
numarul de numere mai mici decat `n` cu care acesta este prim;

- `a^fi(n) = 1(mod n) => a^(fi(n) - 1) * a = 1(mod n)`, deci `a^(fi(n) - 1)` este
inversul modular al lui `a`;

- daca `n = prim, fi(n) = n - 1`, deci inversul modular al lui `a` este `a^(n - 2)`,
care se poate calcula in timp `logn`, folosind exponentiere logaritmica;

- fie `C_n^k` combinari de `n` luate cate `k`;

- acestea se vor calcula folosind inversul modular, deoarece este cerut
rezultatul `% 1000000007`, care este prim;

- `C_n^k = n! * (k!)^(-1) * (n - k)!^(-1)`, iar `(k!)^(-1)` si `(n - k)!^(-1)` sunt
inversele modulare ale lui `k!`, respectiv `(n - k)!` fata de `1000000007`; 

### Idee:

- problema se va desparti intre `n` par si impar;

- cazul `n` impar se va reduce la cel par, asa ca initial se analizeaza acesta din
urma;

#### Cazul par:

- cum n este par, se pot grupa monedele concecutive din vectorul sortat 2 cate 2
si se pastreaza diferentele:

	- `k = v1 - v2 + v3 - v4 + ... + vn-1 - vn`

	- `k = (v1 - v2) + (v3 - v4) + ... + (vn-1 - vn)`

	- `k = d1 + d2 + ... + dn/2`

- aceste diferente sunt toate pozitive, deoarece `v` este sortat descrescator;

- acum ramane sa determinam in cate moduri se poate obtine suma `k` din `n/2` numere
nu neaparat distincte:

	- `k = 1 + 1 + ... + 1 (de k ori)`

- problema se reduce la numarul de moduri distincte in care se poate paranteza
acesta suma;

- sunt `k` termeni de 1, deci `k - 1` locuri in care putem pune paranteze si `n/2`
termeni ce trebuie formati, deci trebuie sa alegem `n/2 - 1` locuri dintre cele
`k - 1`, asadar rezultatul este `C_{k-1}^{n/2 - 1}` (1);

- acum mai trebuie sa aflam pentru fiecare partitionare a lui `k`, in cate moduri
o putem obtine din elementele lui `v`;

- se observa ca `v1 = (v1 - v2) + (v2 - v3) + ... + (vn-1 - vn) + (vn - 0)`

	- `v1 = d1 + (v2 - v3) + d2 + (v4 - v5) + ... + dn/2 + (vn - 0)`

- fie `v2k - v2k+1 = dk' si vn - 0 = dn/2'` asadar, identitatea de mai sus se
poate scrie ca:

	- `v1 = (d1 + d2 + ... + dn) + (d1' + d2' + ... + dn/2')`
	
	- `v1 = k + (d1' + d2' + ... + dn/2')`
	
	- `v1 - k = d1' + d2' + ... + dn/2'`, unde v1 este cea mai mare moneda

- acum problema este aceeasi ca cea de dinainte: sa partitionam `v1 - k` in suma
de `n/2` termeni, pentru orice `k <= v1 <= v`;

- prin urmare, pentru fiecare suma `i`, cu `0 <= i <= v - k` va trebui sa
partitionam `i` in suma de `n/2` numere, deci vor fi `C_{i-1}^{n/2 - 1}` moduri;

- este evident ca pentru `i` in intervalul `[0, n/2 - 1]`, combinarile de mai sus nu
au sens, asa ca se vor calcula doar pentru `n/2 <= i <= v - k`;

- asadar, tinand seama si ca orice prmutare a unui vector de monede este valida,
din (1) si (2), rezultatul final va fi:
`n! * C_{k-1}^{n/2 - 1} * sum(n/2..v-k)(C_{i-1}^{n/2 - 1})`

#### Cazul impar:

- acest caz se reduce la cel par considerand ca fiecare moneda da la 1 la `v` va
fi cea mai mica din vector;

- daca avem valoarea minima din vector i, vom putea reduce intervalul de valori
ale monedelor de la `[i + 1, v]` la `[1, v - i]`, deoarece aceasta mutare nu
afecteaza diferentele posibile care se pot obtine;

- asadar, pentru fiecare moneda minima i ramane de rezolvat problema pentru
`(n - 1, k - i, v - i)`, unde `n - 1` este par.

### Precizari:

- pentru o complexitate temporala mai buna, se va precalcula suma de combinari
din formula finala, pentru a putea accesa rezultatele din aceasta pentru cazul
impar in `Theta(1)` dupa precalculare;

Complexitate:

- timp `n` par: citire (`Theta(1)`) + precalculare factorial (`Theta(v)`) +
			  precalculare sume combinari (`Theta((v - k)log(MOD))`) +
			  calculare combinari (`Theta(log(MOD))`)
			  => `Theta(v)`

- timp `n` impar: la fel ca la n par, dar calcularea sumei aditionale se face in `Theta(vlog(MOD))`, deci complexitatea ramane `Theta(v)`

- spatiu: se folosesc vectori unidimensionali, deci `Theta(v)`
