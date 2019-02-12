# Identificarea numerelor prime

### check.sh:

- poate fi rulat in 2 moduri:

    - `$ ./check.sh fermat` pentru a se verifica Algoritmul lui Fermat;

    - `$ ./check.sh miller` pentru a se verifica Algoritmul Miller-Rabin;

- la fiecare rulare se compileaza toate executabilele necesare si se genereaza un nou set de teste aleatoare cu generator.cpp

- la final, se sterg toate fisierele compilate, iar testele si fisierele de output raman pentru alte inspectii.


## Algoritmul Miller-Rabin: algo.cpp + miller-rabin.cpp 

- utilizeaza exponentierea logaritmica si operatii pe biti pentru optimizari;

- se descompune fiecare numar n astfel: n = 2^k * m

- se aleg convenabil numere a, pentru care se va verifica a^m (mod n);

- daca rezultatul nu este 1 sau n - 1, se va efectua a = a^2 (mod n) de k - 1 ori, sau pana cand:

    - se obtine 1 => numar compus;

    - se obtine n - 1 => numar prim (probabil);

- daca nu se gasesc nici 1, nici n - 1, numarul n este compus.


## Algoritmul lui Fermat: algo1.cpp + fermat.cpp

- pentru fiecare numar din input, se vor genera aleator 15 numere a, pentru care se va verifica daca:

    - cmmdc(a, n) = 1;

    - a^(n - 1) = 1 (mod n);

- daca oricare dintre aceste concluzii nu este indeplinita, n este compus, altfel, este considerat prim.


### utils.cpp:

- contine implementarea exponentierii logaritmice si a functiei gcd ce calculeaza cmmdc-ul folosind algoritmul lui Stein, care inlocuieste impartirile cu shiftari.


### tester.cpp:

- citeste datele din fiecare test folosind parsare, apoi ruleaza algoritmii specificati, cronometrand si afisand timpul de executie si precizia fiecarei rulari.

- precizia se evalueaza folosind Ciurul lui Atkin optimizat pentru a retine daca un numar impar este prim sau nu pe un singur bit (numerele pare se ignora; 2 se trateaza separat);

- la final, se afiseaza rezultatele in fisierele de output, tot prin parsare.

### generator.cpp:

- creeaza 3 seturi de teste, fiecare continand 10^7 numere aleatoare:

    - testele 1 - 3 contin numere mai mici decat 2^27;

    - testele 4 - 6 contin numere mai mici decat 2^30 - 1;

    - testele 7 - 9 contin numere intre 2^30 - 1 si 2^31 - 1;

- ruland checkerul se observa ca dimensiunile datelor sunt suficiente pentru a evidentia modificarea timpilor de executie ai algoritmilor;

- testul 0 contine primele 33 de numere Carmichael, al caror rol este acela de a evidentia diferentele de precizie dintre algoritmii Fermat si Miller-Rabin (testul este irelevant din punctul de vedere al timpului de executie).


### input_parser.cpp + output_parser.cpp:

- parsere pentru fisierele de input, respectiv output, folosite pentru a scadea timpul de rulare al checkerului.

