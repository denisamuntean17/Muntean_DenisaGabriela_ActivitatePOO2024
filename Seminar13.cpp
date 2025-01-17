#include <iostream>
#include <map>
#include <list>
using namespace std;

class Cofetarie {
protected:
	string denumire;
	string nume;
public:
	Cofetarie() {
		this->denumire = "Cofetarie";
	}

	Cofetarie(string denumire) {
		this->denumire = denumire;
	}

	virtual string getDenumire()
	{
		return denumire;
	}
};

class CofetarieOnline :public Cofetarie {
	string sufix;
public:

	CofetarieOnline(string nume, string sufix) :Cofetarie(nume) {
		this->sufix = sufix;
	}

	string getDenumire() {
		return denumire + " " + sufix;
	}


};


int main() {
	/ Cofetarie cof = new Cofetarie();
	cout << cof->getDenumire();
	return 322; */

		map<int, float> valori;
	valori.insert(pair<int, float>(7, 75.8));
	valori.insert(pair<int, float>(23, 102.6));
	valori.insert(pair<int, float>(3, 32.3));
	valori.insert(pair<int, float>(23, 23));//nu il va mai afisa pt ca este deja 23


	valori[12] = 45.5;//ne creaza o noua cheie pt ca nu e 12
	cout << valori[12];

	map<int, float>::iterator it;
	it = valori.begin();

	while (it != valori.end()) {
		cout << it->first << "=>" << it->second << endl;//first-cheia, second-valoarea
		it++;
	}

	list<Cofetarie*> cofetarii;
	cofetarii.push_back(new Cofetarie("Ana Pan"));
	cofetarii.push_back(new CofetarieOnline("Delicii", "Dorobanti"));
	cofetarii.push_front(new Cofetarie("Dulcinela"));

	for (list<Cofetarie*>::iterator i = cofetarii.begin(); i != cofetarii.end(); i++) {
		cout << (*i)->getDenumire() << endl;
	}

	return 322;
}