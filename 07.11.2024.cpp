#include<iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}
	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < m.nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}
	Masina operator=(const Masina& m) {
		if (this != &m) {
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[m.nrRoti];
			for (int i = 0; i < m.nrRoti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}


	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	Masina operator+(const Masina& m) const{
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(Masina m) {
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+=(float adaosPret)  {
		this->pret += adaosPret;
		return *this;
	}	
	
	Masina operator+(float adaosPret)const {
		Masina temp = *this;
		temp.pret += adaosPret;
		return temp;
	}

	friend Masina operator+(float adaosPret, Masina m) {
		Masina temp = m;
		temp.pret += adaosPret;
		return temp;
	}

	explicit operator float(){
		return calculeazaPretTotal();

	}
	
	string& operator[](int index) { //se pune & pentru a trimite prin referinta; ca sa si modificam cum am facut in main cu Mankook
		if (index >= 0 && index < this->nrRoti)
			return this->producatori[index];
		//else return "N/A";
		else throw "Indexul este inafara limitelor.";
		//throw
		//try
		//catch
	}

	explicit operator int() { //explicit -> va putea fi folosit daca celalalt operator ii spune sa o faca intr-un mod explicit
		return this->nrRoti;
	}

	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getProducatori() {
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "NU a fost gasit.";
		}
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (Masina::TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}

	bool operator<(Masina m) {
		return this->pret < m.pret;
	}

	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Marca: ";
		input >> m.marca;
		cout << "Nr roti: ";
		input >> m.nrRoti;		
		if (m.producatori != NULL) 
			delete[] m.producatori;
		if (m.nrRoti > 0) {
			m.producatori = new string(m.nrRoti);
			cout << "Producatori: ";
			for (int i = 0; i < m.nrRoti; i++) {
				input >> m.producatori[i];
			}
		}
		else m.producatori = NULL;
		cout << "Pret: ";
		input >> m.pret;
		return input;
	}

	friend ostream& operator<<(ostream& output, Masina m);

};

int Masina::TVA = 19;

ostream& operator<<(ostream& output, Masina m) {
	output << "Marca:" << m.marca << endl;
	output << "Nr roti:" << m.nrRoti << ": ";
	if (m.producatori != NULL) {
		for (int i = 0; i < m.nrRoti; i++) {
			output << m.producatori[i] << ", ";
		}
	}
	output << endl;
	output << "Pret:" << m.pret << endl;
	output << "TVA:" << m.TVA << endl;
	output << "An fabricatie:" << m.anFabricatie << endl;
	return output;

	
}

int main() {
	Masina m1;
	Masina m2(4, "BMW", 45000, 2021);
	
	float pretMasina =(float) m2;
	m1 = m2;
	cout << pretMasina << endl;
	int nrRoti = (int)m2;
	cout << nrRoti << endl;
	cout <<(int) m2<<endl;

	cout << m2[1]<<endl;
	try {
		cout << m2[1]<<endl;
		/*cout << m2[-4] << endl; //creeaza exceptie
		cout << "ceva"; //nu mai poate fi afisata, deoarece atunci cand e aruncata acea exceptie sare peste restul 
		*/
		m2[1] = "Mankook";
		cout << m2[1] << endl;

	}
	catch (int ex) {
		
	}
	catch (float ex) {

	}
	catch (const char* exceptie) {
		cout << exceptie;
	}
	catch (...) { //aici intra orice ar fi

	}

	cout << m2<<endl;
	cin >> m2;
	cout << endl << m2 << endl;

	if (m2 > m1) {

	}


}