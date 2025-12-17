#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;
const string FAJL = "imena.txt";



int Upisivanje() {
    ofstream izlaz(FAJL.c_str());
    string ime;
    int n;

    if (!izlaz) return 0;

    cout << "Koliko imena zelis unijeti? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Unesi ime " << i + 1 << ": ";
        cin >> ime;
        izlaz << ime << endl;
    }

    izlaz.close();
    return 1;
}


int Ispisivanje() {
    ifstream ulaz(FAJL.c_str());
    string ime;
    int i = 1;

    if (!ulaz) {
        cout << "Fajl ne postoji.\n";
        return 0;
    }

    cout << "Imena:\n";
    while (getline(ulaz, ime)) {
        cout << i++ << ". " << ime << endl;
    }

    ulaz.close();
    return 1;
}


int Dodavanje() {
    ofstream izlaz(FAJL.c_str(), ios::app);
    string ime;

    if (!izlaz) return 0;

    cout << "Unesi ime: ";
    cin >> ime;

    izlaz << ime << endl;
    izlaz.close();
    return 1;
}


int Brisanje() {
    string imena[MAX], trazeno;
    int n = 0;

    ifstream ulaz(FAJL.c_str());
    if (!ulaz) return 0;

    while (n < MAX && getline(ulaz, imena[n]))
        n++;

    ulaz.close();

    cout << "Unesi ime za brisanje: ";
    cin >> trazeno;

    for (int i = 0; i < n; i++) {
        if (imena[i] == trazeno) {
            for (int j = i; j < n - 1; j++)
                imena[j] = imena[j + 1];
            n--;

            ofstream izlaz(FAJL.c_str());
            for (int k = 0; k < n; k++)
                izlaz << imena[k] << endl;
            izlaz.close();

            cout << "Ime obrisano.\n";
            return 1;
        }
    }

    cout << "Ime nije pronadjeno.\n";
    return 0;
}


int Sortiranje() {
    string imena[MAX], temp;
    int n = 0;

    ifstream ulaz(FAJL.c_str());
    if (!ulaz) return 0;

    while (n < MAX && getline(ulaz, imena[n]))
        n++;

    ulaz.close();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (imena[i] > imena[j]) {
                temp = imena[i];
                imena[i] = imena[j];
                imena[j] = temp;
            }

    ofstream izlaz(FAJL.c_str());
    for (int i = 0; i < n; i++)
        izlaz << imena[i] << endl;

    izlaz.close();
    cout << "Imena su sortirana.\n";
    return 1;
}


int Pretraga() {
    ifstream ulaz(FAJL.c_str());
    string ime, trazeno;

    if (!ulaz) return 0;

    cout << "Unesi ime za pretragu: ";
    cin >> trazeno;

    while (getline(ulaz, ime)) {
        if (ime == trazeno) {
            cout << "Ime postoji.\n";
            ulaz.close();
            return 1;
        }
    }

    cout << "Ime ne postoji.\n";
    ulaz.close();
    return 0;
}


int main() {
	
	
	
	 string LOZINKA ="sifra123";
   string unesenalozinka;
   
   const int broj_pokusaja = 3;
   bool pristupdozvoljen = false;
   
   for(int i=0; i < broj_pokusaja; i++){
   	cout<<"Unesite lozinku:";
   	cin>>unesenalozinka;
   	
   	if(unesenalozinka == LOZINKA){
   		pristupdozvoljen = true;
   		break;
	   } 
	   else{
	   	cout<<"Pogresna lozinka";
	   	if(i<broj_pokusaja-1)
	   	cout<<"Pokusaj te ponovo"<<endl;
	   }
   }
   if(!pristupdozvoljen){
   cout<<"Nema vise pokusaja"<<endl;
   return 0;
   }
  

    int izbor;

    do {
        cout << "\n--- MENI ---\n";
        cout << "---1. Upisivanje---\n";
        cout << "---2. Ispisivanje---\n";
        cout << "---3. Dodavanje---\n";
        cout << "---4. Brisanje---\n";
        cout << "---5. Sortiranje---\n";
        cout << "---6. Pretrazivanje---\n";
        cout << "---0. Izlaz---\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: Upisivanje(); break;
            case 2: Ispisivanje(); break;
            case 3: Dodavanje(); break;
            case 4: Brisanje(); break;
            case 5: Sortiranje(); break;
            case 6: Pretraga(); break;
            case 0: cout << "Kraj programa.\n"; break;
            default: cout << "Pogresan izbor!\n";
        }

    } while (izbor != 0);

    return 0;
}

