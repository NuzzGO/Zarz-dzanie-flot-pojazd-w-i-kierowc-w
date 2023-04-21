#ifndef navi_h
#define navi_h
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct flota
{
    string typ;
    string marka;
    string model;
    string kat_poj;

};

struct kierowca
{

    string imie;
    string nazwisko;
    string kat;

};

bool sortuj_pojazdy_typ(const flota& flota_1, const flota& flota_2);
bool sortuj_pojazdy_marka(const flota& flota_1, const flota& flota_2);
bool sortuj_pojazdy_model(const flota& flota_1, const flota& flota_2);
bool sortuj_pojazdy_kat(const flota& flota_1, const flota& flota_2);
bool sortuj_kierowcy_imie(const kierowca& kierowcy, const kierowca& kierowcy2);
bool sortuj_kierowcy_nazwisko(const kierowca& kierowcy, const kierowca& kierowcy2);
bool sortuj_kierowcy_kat(const kierowca& kierowcy, const kierowca& kierowcy2);
void wypisz_plik_pojazdy(string nazwa_pliku);
void t_lista_pojazdow(string nazwa_pliku, list<flota>& flota);
void pokaz_pojazdy_lista(list<flota> flota);
void wypisz_plik_kierowcy(string nazwa_pliku);
void t_lista_kierowców(string nazwa_pliku, list<kierowca>& kierowcy);

void pokaz_liste_kierowcow(list<kierowca> kierowcy);
void dodaj_pojazd(list<flota>& flota);
void usun_pojazd(list<flota>& flota_);
void dodaj_kierowce(list<kierowca>& kierowcy);
void usun_kierowce(list<kierowca>& kierowcy);

void sortuj_pojazdy(list<flota>& flota_);
void sortuj_kierowcow(list<kierowca>& kierowcy_);

void zapisz_liste_pojazdow(list<flota>& flota_);
void zapisz_liste_kierowcow(list<kierowca>& kierowcy_);

void raport(list<flota> flota_, list<kierowca> kierowcy_);

void szukanie_pojazdu(list<flota> flota_);
void szukanie_kierowcy(list<kierowca> kierowcy_);



#endif
