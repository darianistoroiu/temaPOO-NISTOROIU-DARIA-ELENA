#include<iostream>

using namespace std;

// domeniu Elena Nistoroiu => constructii

class Inginer {
private:
	const int idInginer; //variabila constanta
	static int nrIngineri;
	char* numeInginer;
	string specializare;
	int aniExperienta;
	int nrColegi;
	float* oreMuncaColegi;

public:
	int getIdInginer() {
		return this->idInginer;
	}
	char* getNumeInginer() {
		return this->numeInginer;
	}
	void setNumeInginer(const char* numeInginer) {
		if (strlen(numeInginer) > 0) {
			if (this->numeInginer != nullptr) {
				delete[]this->numeInginer;
			}
			this->numeInginer = new char[strlen(numeInginer) + 1];
			strcpy_s(this->numeInginer, strlen(numeInginer) + 1, numeInginer);
		}
	}
	string getSpecializare() {
		return this->specializare;
	}
	void setSpecializare(string specializare) {
		if (specializare.length() > 0)
			this->specializare = specializare;
	}
	int getAniExperienta() {
		return this->aniExperienta;
	}
	int getNrColegi() {
		return this->nrColegi;
	}
	float* getOreMuncaColegi() {
		return this->oreMuncaColegi;
	}
	void setOreMuncaColegi(float* oreMuncaColegi, int nrColegi) {
		if (nrColegi > 0) {
			this->nrColegi = nrColegi;
			if (this->oreMuncaColegi != nullptr) {
				delete[]this->oreMuncaColegi;
			}
			this->oreMuncaColegi = new float[nrColegi];
			for (int i = 0;i < nrColegi;i++)
				this->oreMuncaColegi[i] = oreMuncaColegi[i];
		}

	}
	float getOreMuncaColeg(int pozitie) {
		if (pozitie >= 0 && pozitie <= nrColegi) {
			return this->oreMuncaColegi[pozitie];
		}
	}

	static int getNrIngineri() {
		return nrIngineri;
	}
	void setNrIngineri(int numarIngineri) {
		nrIngineri = numarIngineri;
	}

	Inginer(const char* numeInginer, string specializare, int aniExperienta, int nrColegi, const float* oreMuncaColegi) :idInginer(++nrIngineri) {
		this->specializare = specializare;
		this->aniExperienta = aniExperienta;
		this->nrColegi = nrColegi;
		this->numeInginer = new char[strlen(numeInginer) + 1];
		strcpy_s(this->numeInginer, strlen(numeInginer) + 1, numeInginer);
		this->oreMuncaColegi = new float[nrColegi];
		for (int i = 0; i < nrColegi; i++) {
			this->oreMuncaColegi[i] = oreMuncaColegi[i];
		}
	}
	Inginer() :idInginer(++nrIngineri) {
		this->numeInginer = nullptr;
		this->specializare = "necunoscuta";
		this->aniExperienta = 0;
		this->nrColegi = 0;
	}
	Inginer(const Inginer& copie) : idInginer(++nrIngineri) {
		this->specializare = copie.specializare;
		this->aniExperienta = copie.aniExperienta;
		this->nrColegi = copie.nrColegi;
		if (copie.numeInginer != nullptr)
		{
			this->numeInginer = new char[strlen(copie.numeInginer) + 1];
			strcpy_s(this->numeInginer, strlen(copie.numeInginer) + 1, copie.numeInginer);
		}
		else
			this->numeInginer = nullptr;
		if (copie.oreMuncaColegi != nullptr) {
			this->oreMuncaColegi = new float[copie.nrColegi];
			for (int i = 0; i < copie.nrColegi; i++) {
				this->oreMuncaColegi[i] = copie.oreMuncaColegi[i];
			}
		}
		else
			this->oreMuncaColegi = nullptr;
	};
	void afisareInginer() {
		cout << this->getIdInginer() << ". Inginerul ";
		if (this->getNumeInginer() != nullptr)
		{
			cout << this->getNumeInginer();
		}
		cout << " cu specializarea " << this->getSpecializare() << " si " << this->getAniExperienta() << " ani de experienta";
		cout << " are o echipa formata din " << this->getNrColegi() << " colegi";
		if (this->getNrColegi() > 0)
		{
			cout << ", avand urmatoarele ore de lucru zilic: ";
			for (int i = 0;i < getNrColegi();i++)
				cout << this->getOreMuncaColeg(i) << " ";
		}

	}
	class Proiect;// declarare anticipata a clasei proiect- pt ca fac functia friend inainte ca aceasta clasa sa fie definita
	friend void afisareDateSantier(Inginer i,Proiect p);
	friend void totalOameniLucrare(Inginer i, Proiect p);

	~Inginer() {
		if (this->numeInginer != nullptr)
			delete[] this->numeInginer;
		if (this->oreMuncaColegi != nullptr)
			delete[] this->oreMuncaColegi;
	}


};


int Inginer::nrIngineri = 0;

class Proiect {
private:
	const int idProiect; //variabila constanta
	static int nrProiecte;
	char* numeProiect;
	int anLansare;
	int nrColab;
public:
	int getIdProiect() {
		return this->idProiect;
	}
	char* getNumeProiect() {
		return this->numeProiect;
	}
	void setNumeProiect(const char* numeProiect) {
		if (strlen(numeProiect) > 0) {
			delete[]this->numeProiect;
		}
		this->numeProiect = new char[strlen(numeProiect) + 1];
		strcpy_s(this->numeProiect, strlen(numeProiect) + 1, numeProiect);
	}
	int getAnLansare() {
		return this->anLansare;
	}
	int getNrColab() {
		return this->nrColab;
	}
	static int getNrProeicte() {
		return nrProiecte;
	}
	void setNrProiecte(int numarProiecte) {
		nrProiecte = numarProiecte;
	}


	Proiect(const char* numeProiect, int anLansare, int nrColab) :idProiect(++nrProiecte) {
		this->anLansare = anLansare;
		this->nrColab = nrColab;
		this->numeProiect = new char[strlen(numeProiect) + 1];
		strcpy_s(this->numeProiect, strlen(numeProiect) + 1, numeProiect);
	}
	Proiect() :idProiect(++nrProiecte) {
		this->numeProiect = nullptr;
		this->anLansare = 0;
		this->nrColab = 0;
	}
	Proiect(const Proiect& copie) : idProiect(++nrProiecte) {
		this->anLansare = copie.anLansare;
		this->nrColab = copie.nrColab;
		if (copie.numeProiect != nullptr)
		{
			this->numeProiect = new char[strlen(copie.numeProiect) + 1];
			strcpy_s(this->numeProiect, strlen(copie.numeProiect) + 1, copie.numeProiect);
		}
		else
			this->numeProiect = nullptr;
	}
	void afisareProiect() {
		cout << this->getIdProiect() << ". Proiectul-";
		if (this->getNumeProiect() != nullptr)
		{
			cout << this->getNumeProiect();
		}
		cout << " s-a lansat in anul " << this->getAnLansare() << ". La acest proiect au lucrat " << this->getNrColab() << " colaboratori.";
	}

	friend void afisareDateSantier(Inginer i,Proiect p);
	friend void totalOameniLucrare(Inginer i, Proiect p);

	~Proiect() {
		if (this->numeProiect != nullptr)
			delete[] this->numeProiect;
	}



};

int Proiect::nrProiecte = 0;

enum Combustibil { BENZINA = 1, DIESEL = 2, ELECTRIC = 3 };

class Utilaj {
private:
	const int idUtilaj;
	static int nrUtilaje;
	char* numeUtilaj;
	string domeniu;
	Combustibil combustibil;
	float greutate;
public:
	int getIdUtilaj() {
		return this->idUtilaj;
	}
	static int getNrUtilaje() {
		return nrUtilaje;
	}
	void setNrUtilaje(int numarUtilaje) {
		nrUtilaje = numarUtilaje;
	}
	char* getNumeUtilaj() {
		return this->numeUtilaj;
	}
	void setNumeUtilaj(const char* numeUtilaj) {
		if (strlen(numeUtilaj) > 0) {
			if (this->numeUtilaj != nullptr) {
				delete[]this->numeUtilaj;
			}
			this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
			strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
			
		}
	}
	string getDomeniu() {
		return this->domeniu;
	}
	void setDomeniu(string domeniu) {
		if (domeniu.length() > 0)
			this->domeniu = domeniu;
	}
	Combustibil getCombustibil() {
		return this->combustibil;
	}
	void setCombustibil(Combustibil combustibil) {
		if (combustibil == 1 || combustibil == 2 || combustibil == 3) {
			this->combustibil = combustibil;
		}
	}
	float getGreutate() {
		return this->greutate;
	}
	Utilaj(const char* numeUtilaj, string domeniu, Combustibil combustibil, float greutate) :idUtilaj(++nrUtilaje) {
		this->domeniu = domeniu;
		this->combustibil = combustibil;
		this->greutate = greutate;
		this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
		strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
	}
	Utilaj() :idUtilaj(++nrUtilaje) {
		this->numeUtilaj = nullptr;
		this->domeniu = "constructii";
		this->combustibil = BENZINA;
		this->greutate = 0;
	}
	Utilaj(const Utilaj& copie) : idUtilaj(++nrUtilaje) {
		this->domeniu = copie.domeniu;
		this->combustibil = copie.combustibil;
		this->greutate = copie.greutate;
		if (copie.numeUtilaj != nullptr)
		{
			this->numeUtilaj = new char[strlen(copie.numeUtilaj) + 1];
			strcpy_s(this->numeUtilaj, strlen(copie.numeUtilaj) + 1, copie.numeUtilaj);
		}
		else
			this->numeUtilaj = nullptr;
	}
	void afisareUtilaj() {
		cout << this->getIdUtilaj() << ". Utilajul ";
		if (this->getNumeUtilaj() != nullptr)
		{
			cout << this->getNumeUtilaj();
		}
		cout << " folosit pentru " << this->getDomeniu() << ", are o greutate de " << this->getGreutate() << " tone, combustibilul fiind ";
		if (this->combustibil == 1) {
			cout << "BENZINA";
		}
		else if (this->combustibil == 2) {
			cout << "DIESEL";
		}
		else {
			"ELECTRIC";
		}

		cout << ".";

	}
	~Utilaj() {
		if (this->numeUtilaj != nullptr)
			delete[] this->numeUtilaj;
	}


};

int Utilaj::nrUtilaje = 0;

void afisareDateSantier(Inginer i,Proiect p) {
	cout << "Proiectul " << p.getNumeProiect() << " este realizat in colaborare cu inginerul " << i.getNumeInginer() << ".";
}

void totalOameniLucrare(Inginer i, Proiect p) {
	int total = 0;
	total = p.getNrColab() * i.getNrColegi();
	cout << "Pentru a realiza proiectul " << p.getNumeProiect() << " a fost nevoie de o echipa de " << total << " oameni.";
}

void domeniiUtilajeFolosite(Proiect p, int contor, Utilaj* utilaje) {
	cout << "Pentru a realiza proiectul " << p.getNumeProiect() << " a fost nevoie de " << contor << " utilaje folosite pentru:";
	for (int i = 0;i <contor;i++)
		cout << utilaje[i].getDomeniu() << " ";
}



void main()
{
	float* vector = new float[3] {1.5, 5, 3.5};
	Inginer ing("Popescu", "constructor", 5, 3, vector);
	cout << endl; ing.afisareInginer();
	Inginer ing2default;
	cout << endl; ing2default.afisareInginer();
	Inginer ing3(ing);
	cout << endl; ing3.afisareInginer();


	cout << endl;

	Proiect p1("Restaurarea bisericii", 2027, 5);
	cout << endl; p1.afisareProiect();
	Proiect p2(p1);
	cout << endl << "Id proiect bazat pe constructorul de copiere:" << p2.getIdProiect();
	Proiect p3default;
	cout << endl << "Id proiect bazat pe constructorul default:" << p3default.getIdProiect();

	cout << endl;

	Utilaj u1("Macara", "excavare", DIESEL, 2000);
	cout << endl; u1.afisareUtilaj();
	Utilaj u2default;
	cout << endl; u2default.afisareUtilaj();
	Utilaj u3(u1);
	cout << endl; u3.afisareUtilaj();

;
	cout << endl;
	Utilaj utilaje[3] = {u1,u2default,u3};
	domeniiUtilajeFolosite(p1,3, utilaje);

	cout << endl;
	afisareDateSantier(ing, p1);

	cout << endl;
	totalOameniLucrare(ing, p1);
}

