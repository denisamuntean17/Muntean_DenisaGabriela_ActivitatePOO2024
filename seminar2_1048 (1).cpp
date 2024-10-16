#include<iostream>

using namespace std;

//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector

struct Tara {
	char* denumire; //pointer = un tip de data ce retine o adresa
	int nr_locuitori;
	string capitala;
	bool AreIesireLaMare;
 };

void afisareTara(Tara tara) {

}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume: " << pt->denumire << endl;
	cout << "Numar locuitori: " << pt->nr_locuitori << endl;
	cout << "Capitala: " << pt->capitala << endl;
	cout << "Are iesire la mare: " << (pt->AreIesireLaMare ? "Da" : "Nu") << endl; // ?: -operator, tine locul pentru if else
	/*if (pt->AreIesireLaMare) cout << "Da" << endl;
	else cout << "Nu" << endl;*/
	
	//operator ternar
}

Tara* citirePointerLaTara() {
	Tara* p = new Tara();
	cout << "Capitala: ";
	cin >> p->capitala;

	cout << "Denumire: ";
	char buffer[100]; //alocam spatiu in mod static, pe stiva, pt ca va fi sters in mom in care se termina functia
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);

	cout << "Numar locuitori: ";
	cin >> p->nr_locuitori;

	cout << "Are iesire la mare?(0-Nu, 1-Da) ";
	cin >> p->AreIesireLaMare;

	return p;
}

int main()
{
	Tara tara;
	tara.AreIesireLaMare = false;
	Tara* pTara;
	pTara = new Tara();
	pTara->AreIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nr_locuitori = 200;

	afisarePointerLaTara(pTara);
	
	delete[]pTara->denumire; //sterge mai multe
	delete pTara; //sterge un articol

	/*Tara* p2Tara = citirePointerLaTara();
	afisarePointerLaTara(p2Tara);*/

	Tara* vector;
	vector = new Tara[2];

	delete[]vector;

	//vector de pointeri
	int nr_pointeri = 2;
	Tara** pointeri;
	pointeri = new Tara * [nr_pointeri];
	for (int i = 0; i < nr_pointeri; i++) 
		pointeri[i] = citirePointerLaTara();

	//procesare
	for (int i = 0; i < nr_pointeri; i++)
		afisarePointerLaTara(pointeri[i]);

	//procesare
	for (int i = 0; i < nr_pointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}
	delete[]pointeri;

}
//MEMORILIC = o zona de memorie alocata, care nu a fost dezalocata si nu mai avem referinta catre ea