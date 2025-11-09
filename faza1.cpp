#include<iostream>

using namespace std;

// domeniu Elena Nistoroiu => constructii

class Inginer {
public:
	const int idInginer; //variabila constanta
	static int nrIngineri;
	char* numeInginer;
	string specializare;
	int aniExperienta;
	int nrColegi;
	float* oreMuncaColegi;
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
		cout << this->idInginer << ". Inginerul ";
		if (this->numeInginer != nullptr)
		{
			cout << this->numeInginer;
		}
		cout << " cu specializarea " << this->specializare << " si " << this->aniExperienta << " ani de experienta";
		cout << " are o echipa formata din " << this->nrColegi << " colegi";
		if (this->nrColegi > 0)
		{
			cout << ", avand urmatoarele ore de lucru zilic: ";
			for (int i = 0;i < nrColegi;i++)
				cout << this->oreMuncaColegi[i] << " ";
		}

	}
	~Inginer() {
		if (this->numeInginer != nullptr)
			delete[] this->numeInginer;
		if (this->oreMuncaColegi != nullptr)
			delete[] this->oreMuncaColegi;
	}


};

int Inginer::nrIngineri = 0;

class Proiect {
public:
	const int idProiect; //variabila constanta
	static int nrProiecte;
	char* numeProiect;
	int anLansare;
	int nrColab;
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
		cout << this->idProiect << ". Proiectul-";
		if (this->numeProiect != nullptr)
		{
			cout << this->numeProiect;
		}
		cout << " s-a lansat in anul " << this->anLansare << ". La acest proiect au lucrat " << this->nrColab << " oameni.";
	}

	~Proiect() {
		if (this->numeProiect != nullptr)
			delete[] this->numeProiect;
	}

};

int Proiect::nrProiecte = 0;

enum Combustibil { BENZINA = 1, DIESEL = 2, ELECTRIC = 3 };

class Utilaj {
public:
	const int idUtilaj;
	static int nrUtilaje;
	char* numeUtilaj;
	string domeniu;
	Combustibil combustibil;
	float greutate;
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
		cout << this->idUtilaj << ". Utilajul ";
		if (this->numeUtilaj != nullptr)
		{
			cout << this->numeUtilaj;
		}
		cout << " folosit pentru " << this->domeniu << ", are o greutate de " << this->greutate << " tone, combustibilul fiind ";
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

	Proiect p1("Restaurarea bisericii", 2025, 3);
	cout << endl; p1.afisareProiect();
	Proiect p2(p1);
	cout << endl << "Id proiect bazat pe constructorul de copiere:" << p2.idProiect;
	Proiect p3default;
	cout << endl << "Id proiect bazat pe constructorul default:" << p3default.idProiect;

	cout << endl;

	Utilaj u1("Macara", "excavare", DIESEL, 2000);
	cout << endl; u1.afisareUtilaj();
	Utilaj u2default;
	cout << endl; u2default.afisareUtilaj();
	Utilaj u3(u1);
	cout << endl; u3.afisareUtilaj();
}

