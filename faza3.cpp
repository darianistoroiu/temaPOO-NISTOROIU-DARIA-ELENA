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
		this->oreMuncaColegi = nullptr;
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
	void operator=(const Inginer& copie) {
		this->specializare = copie.specializare;
		this->aniExperienta = copie.aniExperienta;
		this->nrColegi = copie.nrColegi;
		if (this->numeInginer != nullptr) {
			delete[] this->numeInginer;
			this->numeInginer = nullptr;
		}

		if (copie.numeInginer != nullptr)
		{
			this->numeInginer = new char[strlen(copie.numeInginer) + 1];
			strcpy_s(this->numeInginer, strlen(copie.numeInginer) + 1, copie.numeInginer);
		}
		else
			this->numeInginer = nullptr;

		if (this->oreMuncaColegi != nullptr) {
			delete[] this->oreMuncaColegi;
			this->oreMuncaColegi = nullptr;
		}
		if (copie.oreMuncaColegi != nullptr) {
			this->oreMuncaColegi = new float[copie.nrColegi];
			for (int i = 0; i < copie.nrColegi; i++) {
				this->oreMuncaColegi[i] = copie.oreMuncaColegi[i];
			}
		}
		else
			this->oreMuncaColegi = nullptr;
	}
	void operator+=(int aniDeAdaugatLaExperienta) {
		this->aniExperienta += aniDeAdaugatLaExperienta;
	}
	friend Inginer operator+=(int aniDeAdaugatLaExperienta, Inginer& i) {
		i.aniExperienta += aniDeAdaugatLaExperienta;
		return i;
	}
	Inginer operator++(int) { //postincrementare
		Inginer copie = *this;
		this->aniExperienta++;
		return copie;
	}
	Inginer operator++() { //preincrementare
		this->aniExperienta++;
		return *this;
	}
	float operator()(int pozitie) {
		return this->getOreMuncaColeg(pozitie);
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
		cout << this->getIdProiect() << ". Proiectul ";
		if (this->getNumeProiect() != nullptr)
		{
			cout << '"'<<this->getNumeProiect()<<'"';
		}
		else
			cout << "necunoscut";
		cout << " s-a lansat in anul " << this->getAnLansare() << ". La acest proiect au lucrat " << this->getNrColab() << " colaboratori.";
	}
	void operator= (const Proiect& copie){
		this->anLansare = copie.anLansare;
		this->nrColab = copie.nrColab;
		if (this->numeProiect != nullptr){
			delete[]this->numeProiect;
			this->numeProiect=nullptr;
		}
		if (copie.numeProiect != nullptr)
		{
			this->numeProiect = new char[strlen(copie.numeProiect) + 1];
			strcpy_s(this->numeProiect, strlen(copie.numeProiect) + 1, copie.numeProiect);
		}
		else
			this->numeProiect = nullptr;
	}
	bool operator <(const Proiect& p) {
		return this->nrColab < p.nrColab;
	}
	bool operator!() {
		return this->anLansare != 0;
	}
	bool operator==(const Proiect& p) {
		return this->anLansare == p.anLansare;
	}
	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->numeProiect))
			return this->numeProiect[index];
		else
			throw "Indexul furnizat nu se afla in interval!";
	}
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
	void operator=(const Utilaj& copie) {
		this->domeniu = copie.domeniu;
		this->combustibil = copie.combustibil;
		this->greutate = copie.greutate;
		if (this->numeUtilaj != nullptr) {
			delete[] this->numeUtilaj;
			this->numeUtilaj = nullptr;
		}
		if (copie.numeUtilaj != nullptr)
		{
			this->numeUtilaj = new char[strlen(copie.numeUtilaj) + 1];
			strcpy_s(this->numeUtilaj, strlen(copie.numeUtilaj) + 1, copie.numeUtilaj);
		}
		else
			this->numeUtilaj = nullptr;
	}
	~Utilaj() {
		if (this->numeUtilaj != nullptr)
			delete[] this->numeUtilaj;
	}

	friend void operator>>(istream& in, Utilaj& u);

	friend void operator<<(ostream& out, Utilaj& u) {
		cout << endl << "Id utilaj: " << u.idUtilaj;
		
		if (u.numeUtilaj != nullptr)
		{
			cout << endl << "Utilajul ";
			cout << u.numeUtilaj;
		}
		else {
			cout << endl << "Nume nespecificat. ";
		}
		cout << " folosit pentru " << u.domeniu << ", are o greutate de " << u.greutate << " tone, combustibilul fiind ";
		if (u.combustibil == 2) {
			cout << "DIESEL";
		}
		else if (u.combustibil == 3) {
			cout << "ELECTRIC";
		}
		else {
			cout<<"BENZINA";
		}
		cout << ".";
	}
	float operator()(const Utilaj* utilaje, int numarUtilaje)  {
		if (numarUtilaje <= 0)
			throw "Numar utilaje invalid!";
		float suma = 0;
		for (int i = 0;i < numarUtilaje;i++) {
			suma += utilaje[i].greutate;
		}
		return suma / numarUtilaje;
	}
};

void operator>>(istream& in, Utilaj& u) {
	cout << endl << "Nume utilaj: ";
	if (u.numeUtilaj != nullptr) {
		delete[] u.numeUtilaj;
		u.numeUtilaj = nullptr;
	}
	char buffer[20];
	in >> buffer;
	u.numeUtilaj = new char[strlen(buffer) + 1];
	strcpy_s(u.numeUtilaj, strlen(buffer) + 1, buffer);
	cout << endl << "Domeniu: "; in>>u.domeniu;
	int combustibil;
	cout << endl << "Combustibil(1=BENZINA, 2=DIESEL, 3=ELECTRIC): "; in >> combustibil;
	cout << endl << "Greutate: "; in >> u.greutate;
}

int Utilaj::nrUtilaje = 0;





void main()
{
	float* vector = new float[3] {1.5, 5, 3.5};
	Inginer ing("Popescu", "constructor", 5, 3, vector);
	cout << endl; ing.afisareInginer();
	Inginer ing2=ing;
	5 += ing2;
	cout << endl; ing2.afisareInginer();
	Inginer ing3(ing);
	cout << endl; ing3.afisareInginer();
	Inginer ing4default; 
	ing4default += 4;
	cout << endl; ing4default.afisareInginer();
	Inginer ing6=ing++; cout << endl; ing6.afisareInginer();
	++ing; cout << endl; ing.afisareInginer();
	cout << endl << "Colegul al treilea al primului inginer lucreaza " << ing(2) << " ore pe zi";



	cout << endl;

	Proiect p1("Restaurarea bisericii", 2027, 5);
	cout << endl; p1.afisareProiect();
	Proiect p2(p1);
	cout << endl << "Id proiect bazat pe constructorul de copiere:" << p2.getIdProiect();
	Proiect p3default;
	cout << endl << "Id proiect bazat pe constructorul default:" << p3default.getIdProiect();
	Proiect p4 = p3default;
	cout << endl; p4.afisareProiect();
	if (p2 < p3default)
		cout<<endl<< "Al doilea proiect are mai putini colaboratori decat proiectul al treilea.";
	else
		cout <<endl<< "Al treilea proiect are mai putini colaboratori decat al doilea proiect.";
	if (!p3default)
		cout << endl << "Proiectul a fost demarat!";
	else
		cout << endl << "Proiectul nu a fost demarat!";

	cout << endl << "Litera de pe pozitia 3 din numele proiectului este: " << p1[2];
	if (p1==p2)
		cout << endl<<"Cele doua proiecte au fost demarate in acelasi an.";
	else
		cout << endl<<"Cele doua proiecte au fost demarate in ani diferiti.";


	cout << endl;

	Utilaj u1("Macara", "excavare", DIESEL, 2000);
	cout << endl; u1.afisareUtilaj();
	Utilaj u2default;
	cout << endl; u2default.afisareUtilaj();
	Utilaj u3(u1);
	cout << endl; u3.afisareUtilaj();
	Utilaj u4 = u1;
	cout << endl; u4.afisareUtilaj();
	cin >> u1;
	cout << endl<< u1;
	Utilaj utilaje[4] = { u1,u2default,u3,u4 };
	float medie = u1(utilaje, 4);
	cout << endl << "Greutatea medie a utilajelor este: " << medie << " tone.";


	
	cout << endl;


	
}

