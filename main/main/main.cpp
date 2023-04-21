#include "navi.h"
#include "navi.cpp"

using namespace std;


int main(int argc, char* argv[])
{
    list<flota> flota = {};
    list<kierowca> kierowcy = {};
    string st1 = "flota.txt"; //??
    string st2 = "kierowcy.txt";

    for (int i = 1; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
        if (strcmp(argv[i - 1], "-k") == 0) st1 += argv[i];
        if (strcmp(argv[i - 1], "-p") == 0) st2 += argv[i];
    }
    if (st1 == "") {
        cout << "podaj plik z kierowcami: " << endl << ">>";
        cin >> st1;
    }
    if (st2 == "")
    {
        cout << "podaj plik z pojazdami: " << endl << ">>";
        cin >> st2;
    }




    int x;
    do
    {
        system("cls");
        string s(100, '*');
        cout << s << endl;

        cout << right << setw(10) << "POJAZDY" << endl << endl;

        cout << "1. Wypisz z pliku pojazdy" << endl;
        cout << "   2. Polacz sie z baza pojazdy" << endl;
        cout << "      3. Pokaz aktualna liste pojazdow" << endl << endl;

        cout << right << setw(10) << "KIEROWCY" << endl << endl;

        cout << "4. Wypisz z pliku kierowcow" << endl;
        cout << "   5. Polacz sie z baza kierowcow" << endl;
        cout << "      6. Pokaz aktualna liste kierowcow" << endl << endl;

        cout << right << setw(10) << "OPCJE" << endl << endl;

        cout << "7. Dodaj pojazd" << endl;
        cout << "8. Usun pojazd" << endl;
        cout << "9. Dodaj kierowce" << endl;
        cout << "10. Usun kierowce" << endl << endl;
        cout << "11. Sortuj liste pojazdow" << endl;
        cout << "12. Sortuj liste kierowcow" << endl << endl;
        cout << "13. Zapisz aktualny stan listy pojazdow" << endl;
        cout << "14. Zapisz aktualny stan listy kierowcow" << endl << endl;
        cout << "15. Szukaj pojazd" << endl;
        cout << "16. Szukaj kierowcy" << endl;
        cout << "17. Raport" << endl;
        cout << endl << "q ---> Wyjscie" << endl;
        cout << s << endl;
        cout << endl << "---> ";


        cin >> x;
        switch (x)
        {

        case 1:
            wypisz_plik_pojazdy("flota.txt");
            break;
        case 2:
            t_lista_pojazdow("flota.txt", flota);
            break;
        case 3:
            pokaz_pojazdy_lista(flota);
            break;
        case 4:
            wypisz_plik_kierowcy("kierowcy.txt");
            break;
        case 5:
            t_lista_kierowców("kierowcy.txt", kierowcy);
            break;
        case 6:
            pokaz_liste_kierowcow(kierowcy);
            break;
        case 7:
            dodaj_pojazd(flota);
            break;
        case 8:
            usun_pojazd(flota);
            break;
        case 9:
            dodaj_kierowce(kierowcy);
            break;
        case 10:
            usun_kierowce(kierowcy);
            break;
        case 11:
            sortuj_pojazdy(flota);
            break;
        case 12:
            sortuj_kierowcow(kierowcy);
            break;
        case 13:
            zapisz_liste_pojazdow(flota);
            break;
        case 14:
            zapisz_liste_kierowcow(kierowcy);
            break;
        case 15:
            szukanie_pojazdu(flota);
            break;
        case 16:
            szukanie_kierowcy(kierowcy);
            break;
        case 17:
            raport(flota, kierowcy);
            break;
        default: return 0;

        }
    } while (x != 'q' && x > 0 && x < 18);
    zapisz_liste_pojazdow(flota);
    zapisz_liste_kierowcow(kierowcy);
    return 0;
}

