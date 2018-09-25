Nume: Gavan Adrian George

Grupa: 314CA

Informatii generale:
====================

Acest program rezolva problema gasirii unui copac ideal pentru construirea casei
piticilor din DwarfLand.
Acest program calculeaza, de asemenea, conform cerintei bonus, daca se poate 
construi o gradina suspendata ca extensie in copacul ideal.

Prezentarea implementarii:
==========================

Pentru aceasta implementare au fost definite urmatoarele functii: 
1. Functie ce verifica daca un numar este prim sau nu.
 int IsPrim(int n);
2. Functie de verificare daca un numar este magic sau nu.
 int IsMagic(int n);
3. Functie ce determina intensitatea in varful copacului verificat.
 float intensitate(float p0X, float p0Y, float pX, float pY, float Ip0);
4. Functie ce determina unghiul format de copacul ideal si vecinii sai.
 float unghi(float c1X, float c1Y, float c2X, float c2Y, float c3X, float c3Y);

Algoritm:
- Se citesc coordonatele sursei de lumina si intensitatea acesteia.
- Se citeste numarul de copaci.
- Se citesc coordonatele primilor 3 copaci cu indicii 0, 1, 2, rezultand copacii c1, c2, c3.
- Se verifica daca copacul cu indicele 1 este copac ideal.
- Daca este copac ideal se memoreaza coordonatele, indicele, intensitatea si unghiul format de
acesta cu copacii vecini. Daca nu, se trece mai departe.
- Mutam coordonatele copacului c2 in c1,  c3 in c2 si atribuim coordonatele copacului nou citit 
variabilelor copacului c3.
- Se verifica daca noul copac c2 din noua secventa de copaci c1, c2, c3 este copac ideal. 
- Daca este copac ideal verificam daca noul copac ideal are inaltimea mai mica decat vechiul 
copac ideal (in cazul in care exista un copac ideal anterior). Daca da, atunci se retin 
datele noului copac ideal.
- Daca inaltimile sunt egale, se compara coordonatele X ale celor 2 copaci ideali. Daca cel 
nou are coordonata X mai mica, se retin datele acestuia.
- Daca inaltimea primului copac ideal este mai mica, nu se modifica informatiile retinute.
- Procesul se repeta pana la citirea ultimului copac, cu verificarea penultimului copac.
- Daca nu se gaseste niciun copac ideal, indicele copacului ideal va ramane neschimbat, la 
valoarea initiala 0. Daca indicele este egal cu 0, se va afisa mesajul: 
“There is no place for you in DwarfLand!”.
- Daca exista un copac ideal, se va afisa indicele acestuia, intensitatea in varful copacului si 
masura unghiului format de copacul ideal cu copacii alaturati (in grade).
- Daca unghiul este obtuz, va aparea mesajul “IT CAN BE EXTENDED”.
- In caz contrat, se va afisa “IT CAN NOT BE EXTENDED”. 

Conditii impuse de tema:
======================

2 < n < 100;
Coordonatele X ale copacilor sunt in ordine crescatoare.
Toate coordonatele din plan sunt numere intregi din intervalul [0, 1000].
lightSourceIntensity este un numar real mai mic decat 2^24.
Unghiul masurat are o valoare intre 0 si 180 de grade.
Afisarea intensitatii luminii si a unghiului măsurat se va face folosind o precizie de 4 zecimale.
In implementarea temei nu este permisa folosirea vectorilor.

