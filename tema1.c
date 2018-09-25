//Gavan Adrian George - 314CA


#include <stdio.h>
#include <math.h>

//Functii definite
int IsPrim(int);
int IsMagic(int);
double intensitate(double, double, double, double, double);
double unghi(double, double, double, double, double, double);

int main()									
{												
	/* ind = se retine indicele copacului ideal
	indX, indY = se retin coordonatele copacului ideal	
	k = indicele copacului
	nr = numarul care va fi verificat pentru a se stabili daca e numar magic sau nu
	lightX, lightY = coordonatele sursei de lumina
	X,Y = coordonatele X, Y ale unui copac
	c1X, c1Y, c2X, c2Y, c3X, c3Y = variabilele in care se vor retine coordonatele a 3 copaci alaturati
	lightSourceIntensity = intensitatea sursei de lumina
	I = intensitatea din varful copacului verificat
	Lt = retinem intensitatea din varful copacului ideal
	bonus = retinem unghiul */

	int n, lightX, lightY, X, Y, c1X, c1Y, c2X, c2Y, c3X, c3Y, k, nr, ind, indX, indY;
	double lightSourceIntensity, I, Lt, bonus;
	//Citirea coordonatelor sursei, intensitatea acesteia si numarul de copaci	
	scanf("%d%d%lf", &lightX, &lightY, &lightSourceIntensity);
	scanf("%d", &n);									
	//Se dau valori mari variabilelor indX si indY (1001 pentru ca se stie ca n nu poate fi mai mare decat 1000)	
	indX = 1001;
	indY = 1001;
	ind = 0;								
	bonus = 0;										
	//Se ia pe rand fiecare copac si se citesc coordonatele	
	for(k = 0; k <= n-1; k++){
		scanf("%d%d", &X, &Y);
		//initializare primul copac(indice 0)												
		if(k == 0){ 
			c1X = X;
			c1Y = Y;
		}
		//initializare al doilea copac(indice 1)										
		if(k == 1){									
			c2X = X;
			c2Y = Y;
		}
		//initializare al treilea copac(indice 2) si verificare daca copacul 2 este ideal
		if(k == 2){
			c3X = X;
			c3Y = Y;
			I = intensitate(lightX, lightY, c2X, c2Y, lightSourceIntensity);
			nr = (((int)I) % 10) * 1000 + (c1Y % 10) * 100 + (c2Y % 10) * 10 + (c3Y % 10 );
			//Daca copacul 2 (indice 1) este magic, se memoreaza detaliile lui
			if(IsMagic(nr) == 1){
				ind = k - 1;
				indX = c2X;
				indY = c2Y;
				Lt = I;
				bonus = unghi(c1X, c1Y, c2X, c2Y, c3X, c3Y);
			}
			
		}
		//Se verifica si restul copacilor pana la n-1
		if(k >= 3){
			//Copacii 2 si 3 devin copacii 1 si 2, iar apoi salvam in c3X si c3Y coordonatele copacului urmator
			c1X = c2X;
			c1Y = c2Y;
			c2X = c3X;
			c2Y = c3Y;
			c3X = X;
			c3Y = Y;
			I = intensitate(lightX, lightY, c2X, c2Y, lightSourceIntensity);
			nr = (((int)I) % 10) * 1000 + (c1Y % 10) * 100 + (c2Y % 10) * 10 + (c3Y % 10);
			//Daca noul copac este ideal se compara cu cel salvat anterior si se alege cel mai potrivit dintre cei 2
			//Se compara inaltimile celor 2 copaci si daca este cazul coordonatele X ale acestora			
			//Se salveaza noile coordonate
			if(IsMagic(nr) == 1){
				if(c2Y < indY){
					ind = k - 1;
					indY = c2Y;
					indX = c2X;
					Lt = I;	
					bonus = unghi(c1X, c1Y, c2X, c2Y, c3X, c3Y);
				}
				if(c2Y == indY){
					if(c2X < indX){
						ind = k - 1;						
						indX = c2X;
						indY = c2Y;
						Lt = I;
						bonus = unghi(c1X, c1Y, c2X, c2Y, c3X, c3Y);
					}
				}
			}
		}
			
	}
	//Se verifica daca a fost gasit un copac ideal
	//Daca indicele a ramas neschimbat (0) inseamna ca nu a fost gasit niciun copac ideal
	if (ind == 0){
		printf("There is no place for you in DwarfLand!\n");
	}else{	
		printf("%d %.4lf\n", ind, Lt);
		if(bonus > 90){
			printf("%.4lf IT CAN BE EXTENDED\n", bonus);
		}else{
			printf("%.4lf IT CAN NOT BE EXTENDED\n", bonus);
		}
	}
	return 0;	
}

//Functie ce verifica daca un numar este prim sau nu
int IsPrim(int n){
	int i, k;
	k = 0;
	if(n < 2){
		return 0;
	}else{
		for(i = 2; i <= n / 2; i++){
			if(n % i == 0){
				k = k + 1;
			}
		}	
		if(k == 0){
			return 1;   //returneaza 1 daca este prim
		}else{
			return 0;   //returneaza 0 daca nu este prim
		}
	}
}

//Functie de verificare daca un numar este magic sau nu
int IsMagic(int n){
	int d, nr, ep, i;
	d = 1000;
	nr = 0;	
	ep = 0;   //ep = retine 1 daca numarul e prim si 0 daca nu e prim
	for(i = 1; i <= 4; i++){
		nr = n / d;
		if(nr == 0){
			d = d / 10;
		}else{
			if(IsPrim(nr) == 1){
				d = d / 10;
				ep = 1;
			}
			else{
				ep = 0;
				break;
			}

		}
	}
	if (ep == 1){
		return 1;  //returneaza 1 daca e magic
	}else{
		return 0;  //returneaza 0 daca nu e magic
	}
}

//Functie ce determina intensitatea in varful copacului verificat
//p0X, p0Y = coordonatele sursei de lumina
//pX, pY = coordonatele copacului verificat
//Ip0 = intensitatea sursei de lumina
double intensitate(double p0X, double p0Y, double pX, double pY, double Ip0){
	double d = 0, Ip; //d = patratul distantei dintre varf si sursa luminii	
	d = (p0X - pX) * (p0X - pX) + (p0Y - pY) * (p0Y - pY); 
	Ip = 1 / d * Ip0; //formula pentru intensitatea intr-un punct la distanta d fata de sursa	
	return Ip;
}

//Functie ce determina unghiul format de copacul ideal si vecinii sai
//c1X, c1Y, c2X, c2Y, c3X, c3Y = coordonatele a 3 copaci alaturati
double unghi(double c1X, double c1Y, double c2X, double c2Y, double c3X, double c3Y){
	double d1 = 0, d2 = 0, d3 = 0, cosunghi = 0, unghiGrade = 0, PI = 3.14159265;	
	d1 = (c3X - c1X) * (c3X - c1X) + (c3Y - c1Y) * (c3Y - c1Y); //Patratul distantei dintre copac 1 si 3
	d2 = (c1X - c2X) * (c1X - c2X) + (c1Y - c2Y) * (c1Y - c2Y); //Patratul distantei dintre copac 1 si 2
	d3 = (c2X - c3X) * (c2X - c3X) + (c2Y - c3Y) * (c2Y - c3Y); //patratul distantei dintre copac 2 si 3
	cosunghi = (d2 + d3 - d1) / (2 * sqrt(d2) * sqrt(d3)); //Valoarea cosinusului unghiului in radiani (Tr. cosinusului)
	unghiGrade = acos(cosunghi) * 180 / PI; //Determinarea unghiului in grade
	return unghiGrade;
}
	

