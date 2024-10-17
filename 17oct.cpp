#include<iostream>
using namespace std;

class masina {
public:
	int nrRoti;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
	masina() :anFabricatie(2024) {
		this->nrRoti = 4;
		this->marca = "Dacia";
		this->pret = 5000;
		//this->anFabricatie = 2010;
	}

	masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;

	}

	void afisare() {
		cout << "Marca: " << this->marca << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Numar roti: " << this->nrRoti << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "An fabricatie: " << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (masina::TVA / 100.00));
	}

	static void modificaTVA( int noulTVA) {
		if(noulTVA>0)
			masina::TVA = noulTVA;
	}

	static float calculeazaPretTotalPentruVector(int nrMasini, masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++)
			pretTotal += vector[i].calculeazaPretTotalPentruVector();
		return pretTotal;
	}

};

int masina::TVA = 19; //asa se initializeaza atributele statice



int main() {
	masina m1;
	m1.afisare();

	masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	masina::modificaTVA(-21);

	masina* pointer = new masina(6, "Volvo", 20000, 2022);
	pointer->afisare();

	cout << "Pret total: " << pointer->calculeazaPretTotal() << endl;

	int nrMasini = 3;
	masina* vector;
	vector = new masina[nrMasini];
	for (int i = 0; i < nrMasini; i++) {
		vector[i].afisare();
	}

	cout << "Pret total flota: " << masina::calculeazaPretTotalPentruVector(nrMasini, vector) << endl;


	// -> dereferentiere + accesare
	// [] deplasare + dereferentiere
	// . accesare
	return 0;
}