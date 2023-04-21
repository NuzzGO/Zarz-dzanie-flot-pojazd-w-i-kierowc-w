#include "navi.h"


bool sortuj_pojazdy_typ(const flota& flota_1, const flota& flota_2)
{
    return (flota_1.typ < flota_2.typ || (flota_1.typ == flota_2.typ) && flota_1.marka < flota_2.marka);
}
bool sortuj_pojazdy_marka(const flota& flota_1, const flota& flota_2)
{
    return (flota_1.marka < flota_2.marka || (flota_1.marka == flota_2.marka) && flota_1.model < flota_2.model);
}
bool sortuj_pojazdy_model(const flota& flota_1, const flota& flota_2)
{
    return (flota_1.model < flota_2.model || (flota_1.model == flota_2.model) && flota_1.kat_poj < flota_2.kat_poj);
}
bool sortuj_pojazdy_kat(const flota& flota_1, const flota& flota_2)
{
    return (flota_1.kat_poj < flota_2.kat_poj || (flota_1.kat_poj == flota_2.kat_poj) && flota_1.typ < flota_2.typ);
}
bool sortuj_kierowcy_imie(const kierowca& kierowcy, const kierowca& kierowcy2)
{
    return (kierowcy.imie < kierowcy2.imie || (kierowcy.imie == kierowcy2.imie) && kierowcy.nazwisko < kierowcy2.nazwisko);
}
bool sortuj_kierowcy_nazwisko(const kierowca& kierowcy, const kierowca& kierowcy2)
{
    return (kierowcy.nazwisko < kierowcy2.nazwisko || (kierowcy.nazwisko == kierowcy2.nazwisko) && kierowcy.kat < kierowcy2.kat);
}
bool sortuj_kierowcy_kat(const kierowca& kierowcy, const kierowca& kierowcy2)
{
    return (kierowcy.kat < kierowcy2.kat || (kierowcy.kat == kierowcy2.kat) && kierowcy.nazwisko < kierowcy2.nazwisko);
}


void wypisz_plik_pojazdy(string nazwa_pliku)
{
    cout << "|" << setw(10) << "TYP" << "|" << setw(20) << "MARKA" << "|" << setw(20) << "MODEL" << "|" << setw(20) << "KATEGORIA SAMOCHODU" << "|" << endl;
    ifstream plik(nazwa_pliku);
    if (!plik.good())
    {
        cout << "Nie otworzono pliku z flot¹ pojazdów" << endl;
        return;
    }
    while (!plik.eof())
    {
        string linia, typ, marka, model, kat_poj;
        plik >> ws;
        getline(plik, linia, ' '); typ = linia;
        getline(plik, linia, ' '); marka = linia;
        getline(plik, linia, ' '); model = linia;
        getline(plik, linia); kat_poj = linia;
        cout << left << "|" << setw(10) << typ << "|" << setw(20) << marka << "|" << setw(20) << model << "|" << setw(20) << kat_poj << "|" << endl;
    }

    plik.close();
    system("pause");
}

void t_lista_pojazdow(string nazwa_pliku, list<flota>& flota)
{


    ifstream plik(nazwa_pliku);
    if (!plik.good())
    {
        cout << "Nie otworzono pliku z flot¹ pojazdów" << endl;
        return;
    }
    while (!plik.eof())
    {
        string linia, typ, marka, model, kat_poj;
        plik >> ws;
        getline(plik, linia, ' '); typ = linia;
        if (linia == "") return;
        getline(plik, linia, ' '); marka = linia;
        getline(plik, linia, ' '); model = linia;
        getline(plik, linia); kat_poj = linia;


        flota.push_back({ typ,marka,model,kat_poj });
    }
    plik.close();

}

void pokaz_pojazdy_lista(list<flota> flota)
{
    cout << "|" << setw(10) << "TYP" << "|" << setw(20) << "MARKA" << "|" << setw(20) << "MODEL" << "|" << setw(20) << "KATEGORIA SAMOCHODU" << "|" << endl;

    for (auto it = flota.begin(); it != flota.end(); it++)
    {

        cout << left << "|" << setw(10) << it->typ << "|" << setw(20) << it->marka << "|" << setw(20) << it->model << "|" << setw(20) << it->kat_poj << "|" << endl;

    }
    cout << endl;
    system("pause");
}
void wypisz_plik_kierowcy(string nazwa_pliku)
{
    cout << "|" << setw(10) << "IMIE" << "|" << setw(20) << "NAZWISKO" << "|" << setw(20) << "KATEGORIA SAMOCHODU" << "|" << endl;
    ifstream plik(nazwa_pliku);
    if (!plik.good())
    {
        cout << "Nie otworzono pliku z flot¹ pojazdów" << endl;
        return;
    }
    while (!plik.eof())
    {
        string linia, imie, nazwisko, kat_poj;
        plik >> ws;
        getline(plik, linia, ' '); imie = linia;
        getline(plik, linia, ' '); nazwisko = linia;
        getline(plik, linia); kat_poj = linia;
        cout << left << "|" << setw(10) << imie << "|" << setw(20) << nazwisko << "|" << setw(20) << kat_poj << "|" << endl;
    }

    plik.close();
    system("pause");
}
void t_lista_kierowców(string nazwa_pliku, list<kierowca>& kierowcy)
{
    ifstream plik(nazwa_pliku);
    if (!plik.good())
    {
        cout << "Nie otworzono pliku z flot¹ pojazdów" << endl;
        return;
    }
    while (!plik.eof())
    {
        string linia, imie, nazwisko, kat_poj;
        plik >> ws;
        getline(plik, linia, ' '); imie = linia;
        if (linia == "") return;
        getline(plik, linia, ' '); nazwisko = linia;
        getline(plik, linia); kat_poj = linia;

        kierowcy.push_back({ imie,nazwisko,kat_poj });
    }

    plik.close();

}

void pokaz_liste_kierowcow(list<kierowca> kierowcy)
{
    cout << "|" << setw(10) << "IMIE" << "|" << setw(20) << "NAZWISKO" << "|" << setw(20) << "KATEGORIA SAMOCHODU" << "|" << endl;

    for (auto it = kierowcy.begin(); it != kierowcy.end(); it++)
    {
        cout << left << "|" << setw(10) << it->imie << "|" << setw(20) << it->nazwisko << "|" << setw(20) << it->kat << "|" << endl;
    }
    cout << endl;
    system("pause");
}

void dodaj_pojazd(list<flota>& flota)
{
    system("cls");
    string typ, marka, model, kat, s1, s2, s3;

    cout << "Dodajesz pojazd:" << endl;
    cout << "Podaj Typ (osobowy,motocykl,ciezarowy): ";  cin >> typ;
    transform(typ.begin(), typ.end(), typ.begin(), ::tolower);

    cout << "Podaj Marke (np. BMW): "; cin >> marka;
    transform(++marka.begin(), marka.end(), ++marka.begin(), ::tolower);
    transform(marka.begin(), marka.begin(), marka.begin(), ::toupper);

    cout << "Podaj Model (np. E90): "; cin >> model;
    transform(++model.begin(), model.end(), ++model.begin(), ::tolower);
    transform(model.begin(), model.begin(), model.begin(), ::toupper);

    cout << "Podaj Kategorie prawa jazdy (np. B): "; cin >> kat;
    transform(kat.begin(), kat.end(), kat.begin(), ::toupper);

    flota.push_back({ typ,marka,model,kat });
    system("pause");
}
void usun_pojazd(list<flota>& flota_)
{
    string szukana[4];
    bool a = false;
    pokaz_pojazdy_lista(flota_);
    cout << endl;

    cout << "Podaj typ,marke,model,kategorie samochodu aby usunac pojazd: " << endl;

    cout << endl << "Podaj Typ: ";
    cin >> szukana[0];
    transform(szukana[0].begin(), szukana[0].begin(), szukana[0].begin(), ::toupper);
    transform(++szukana[0].begin(), szukana[0].end(), ++szukana[0].begin(), ::tolower);

    cout << endl << "Podaj Marke: ";
    cin >> szukana[1];
    transform(szukana[1].begin(), szukana[1].begin(), szukana[1].begin(), ::toupper);
    transform(++szukana[1].begin(), szukana[1].end(), ++szukana[1].begin(), ::tolower);

    cout << endl << "Podaj Model: ";
    cin >> szukana[2];
    transform(szukana[2].begin(), szukana[2].begin(), szukana[2].begin(), ::toupper);
    transform(++szukana[2].begin(), szukana[2].end(), ++szukana[2].begin(), ::tolower);

    cout << endl << "Podaj Kategorie samochodu: ";
    cin >> szukana[3];
    transform(szukana[3].begin(), szukana[3].begin(), szukana[3].begin(), ::toupper);
    transform(++szukana[3].begin(), szukana[3].end(), ++szukana[3].begin(), ::tolower);


    for (auto it = flota_.begin(); it != flota_.end(); it++)
    {

        if ((it->typ) == szukana[0] && it->marka == szukana[1] && it->model == szukana[2] && it->kat_poj == szukana[3])
        {
            flota_.erase(it);
            cout << "Usunieto pojazd: " << szukana[0] << " " << szukana[1] << " " << szukana[2] << endl;
            a = true;
            break;
        }

    }
    if (a == false) cout << endl << "Nie znaleziono pojazdu" << endl << endl;
    system("pause");


}
void dodaj_kierowce(list<kierowca>& kierowcy)
{
    system("cls");
    string imie, nazwisko, kat;
    cout << "Dodajesz kierowce:" << endl;
    cout << "Podaj Imie: ";  cin >> imie;
    transform(imie.begin(), imie.end(), imie.begin(), ::toupper);
    transform(++imie.begin(), imie.end(), ++imie.begin(), ::tolower);

    cout << "Podaj Nazwisko: "; cin >> nazwisko;
    transform(nazwisko.begin(), nazwisko.end(), nazwisko.begin(), ::toupper);
    transform(++nazwisko.begin(), nazwisko.end(), ++nazwisko.begin(), ::tolower);

    cout << "Podaj Kategorie prawa jazdy (np. B): "; cin >> kat;
    transform(kat.begin(), kat.end(), kat.begin(), ::toupper);

    kierowcy.push_back({ imie,nazwisko,kat });
    cout << "Dodano kierowce: " << imie << " " << nazwisko << " " << kat << endl;
    system("pause");
}
void usun_kierowce(list<kierowca>& kierowcy)
{
    string szukana[3];
    bool a = false;
    pokaz_liste_kierowcow(kierowcy);

    cout << "Podaj Imie: ";
    cin >> szukana[0];
    transform(szukana[0].begin(), szukana[0].end(), szukana[0].begin(), ::toupper);
    transform(++szukana[0].begin(), szukana[0].end(), ++szukana[0].begin(), ::tolower);

    cout << "Podaj Nazwisko: ";
    cin >> szukana[1];
    transform(szukana[1].begin(), szukana[1].end(), szukana[1].begin(), ::toupper);
    transform(++szukana[1].begin(), szukana[1].end(), ++szukana[1].begin(), ::tolower);

    cout << "Podaj Kategorie: ";
    cin >> szukana[2];
    transform(szukana[2].begin(), szukana[2].end(), szukana[2].begin(), ::toupper);


    for (auto it = kierowcy.begin(); it != kierowcy.end(); it++)
    {

        if (it->imie == szukana[0] && it->nazwisko == szukana[1] && it->kat == szukana[2])
        {
            kierowcy.erase(it);
            cout << "Usunieto kierowce: " << szukana[0] << " " << szukana[1] << " " << szukana[2] << endl;
            cout << "" << endl;
            a = true;
            break;
        }

    }
    if (a == false) cout << "Nie znaleziono kierowcy" << endl;
    system("pause");

}
void sortuj_pojazdy(list<flota>& flota_)
{
    char x;
    cout << "1. Sortuj pojazdy po typie samochodu " << endl;
    cout << "2. Sortuj pojazdy po marce samochodu " << endl;
    cout << "3. Sortuj pojazdy po modelu samochodu " << endl;
    cout << "4. Sortuj pojazdy po kategorii samochodu " << endl;
    cout << "q. Wyjscie " << endl;
    cin >> x;

    switch (x)
    {
    case '1':
        flota_.sort(sortuj_pojazdy_typ);
        break;
    case '2':
        flota_.sort(sortuj_pojazdy_marka);
        break;
    case '3':
        flota_.sort(sortuj_pojazdy_model);
        break;
    case '4':
        flota_.sort(sortuj_pojazdy_kat);
        break;
    default:
        break;
    }

}
void sortuj_kierowcow(list<kierowca>& kierowcy_)
{
    char x;
    cout << "1. Sortuj kierowcow po imie kierowcy " << endl;
    cout << "2. Sortuj kierowcow po nazwisko kierowcy " << endl;
    cout << "3. Sortuj kierowcow po kategorii kierowcy " << endl;
    cout << "q. Wyjscie " << endl;
    cin >> x;

    switch (x)
    {
    case '1':
        kierowcy_.sort(sortuj_kierowcy_imie);
        break;
    case '2':
        kierowcy_.sort(sortuj_kierowcy_nazwisko);
        break;
    case '3':
        kierowcy_.sort(sortuj_kierowcy_kat);
        break;
    default:
        break;
    }
}
void zapisz_liste_pojazdow(list<flota>& flota_)
{
    ofstream plik("flota.txt");
    for (auto it = flota_.begin(); it != flota_.end(); it++)
    {
        plik << it->typ << " " << it->marka << " " << it->model << " " << it->kat_poj << endl;
    }

    plik.close();
}
void zapisz_liste_kierowcow(list<kierowca>& kierowcy_)
{
    ofstream plik("kierowcy.txt");
    for (auto it = kierowcy_.begin(); it != kierowcy_.end(); it++)
    {
        plik << it->imie << " " << it->nazwisko << " " << it->kat << endl;
    }

    plik.close();
}
void raport(list<flota> flota_, list<kierowca> kierowcy_)
{
    for (auto it = flota_.begin(); it != flota_.end(); it++)
    {
        cout <<it->typ << " " << it->marka << " " << it->model << " " << it->kat_poj <<endl<<endl;
        for (auto a = kierowcy_.begin(); a != kierowcy_.end(); a++)
        {
            int ile = a->kat.length();
            for (int i = 0; i < ile; i++)
            {
                string s, ss;
                s = it->kat_poj;
                ss = a->kat;
                if (s.find(ss[i]) != string::npos)  cout <<"--> "<< a->imie << " " << a->nazwisko << " " << a->kat << endl;
            }


        }
        cout << endl;
    }

    system("pause");
}

void szukanie_pojazdu(list<flota> flota_)
{
    cout << "1. Szukaj po typie: " << endl;
    cout << "2. Szukaj po marce: " << endl;
    cout << "3. Szukaj po modelu: " << endl;
    cout << "4. Szukaj po kategorii: " << endl;
    cout << "q -> Wyjscie " << endl;
    cout << "-> ";
    char x;
    cin >> x;
    cout << endl;

    string s, ss;

    switch (x)
    {

    case '1':

        cout << "Podaj Typ(osobowy, ciezarowy, motocykl): ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (auto it = flota_.begin(); it != flota_.end(); it++)
        {
            ss = it->typ;
            if (s.find(ss) != string::npos)  cout << it->marka << " " << it->model << " " << it->kat_poj << endl;
        }

        system("pause");
        break;
    case '2':
        cout << "Podaj marke: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        transform(++s.begin(), s.end(), ++s.begin(), ::tolower);
        for (auto it = flota_.begin(); it != flota_.end(); it++)
        {
            ss = it->marka;
            if (s.find(ss) != string::npos)  cout << it->marka << " " << it->model << " " << it->kat_poj << endl;
        }

        system("pause");
        break;
    case '3':
        cout << "Podaj model: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        transform(++s.begin(), s.end(), ++s.begin(), ::tolower);
        for (auto it = flota_.begin(); it != flota_.end(); it++)
        {
            ss = it->model;
            if (s.find(ss) != string::npos)  cout << it->marka << " " << it->model << " " << it->kat_poj << endl;
        }

        system("pause");
        break;
    case '4':
        cout << "Podaj kategorie: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (auto it = flota_.begin(); it != flota_.end(); it++)
        {
            int ile = it->kat_poj.length();
            for (int i = 0; i < ile; i++)
            {
                ss = it->kat_poj;
                if (s.find(ss[i]) != string::npos)   cout << it->marka << " " << it->model << " " << it->kat_poj << endl;
            }


        }

        system("pause");
        break;
    default:
        break;
    }
}
void szukanie_kierowcy(list<kierowca> kierowcy_)
{
    cout << "1. Szukaj po imieniu: " << endl;
    cout << "2. Szukaj po nazwisku: " << endl;
    cout << "3. Szukaj po kategorii: " << endl;
    cout << "q -> Wyjscie " << endl;
    cout << "-> ";
    char x;
    cin >> x;
    cout << endl;

    string s, ss;

    switch (x)
    {

    case '1':

        cout << "Podaj imie: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        transform(++s.begin(), s.end(), ++s.begin(), ::tolower);
        for (auto it = kierowcy_.begin(); it != kierowcy_.end(); it++)
        {
            ss = it->imie;
            if (s.find(ss) != string::npos)  cout << it->imie << " " << it->nazwisko << " " << it->kat << endl;
        }

        system("pause");
        break;
    case '2':
        cout << "Podaj nazwisko: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        transform(++s.begin(), s.end(), ++s.begin(), ::tolower);
        for (auto it = kierowcy_.begin(); it != kierowcy_.end(); it++)
        {
            ss = it->nazwisko;
            if (s.find(ss) != string::npos)  cout << it->imie << " " << it->nazwisko << " " << it->kat << endl;
        }

        system("pause");
        break;

    case '3':
        cout << "Podaj kategorie: ";
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (auto it = kierowcy_.begin(); it != kierowcy_.end(); it++)
        {
            int ile = it->kat.length();
            for (int i = 0; i < ile; i++)
            {
                ss = it->kat;
                if (s.find(ss[i]) != string::npos)  cout << it->imie << " " << it->nazwisko << " " << it->kat << endl;
            }


        }

        system("pause");
        break;
    default:
        break;
    }
}