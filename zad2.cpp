/* Napisz program, który zapyta o dwa ciągi znaków oraz je porówna, nie zwracając uwagi na
 * wielkość liter (tzn. żeby traktował literę A i a jako takie same). Do tego zadania
 * wykorzystaj dowolny kontener (np. std::string) lub tablice.
 * Założ, że podany ciąg znaków nie może zawierać znaków diakrytycznych, czyli np. ą, ę, ł, itp.
 *
 * Input programu: pierwszy ciag znakow, zatwierdzenie, drugi ciag znakow, zatwierdzenie
 * Output programu w przypadku gdy ciągi znakow są takie same: "\nPODANE CIAGI ZNAKOW IDENTYCZNE"
 * Output programu w przypadku gdy ciagi znakow sa rozne: PODANE "\nCIAGI ZNAKOW ROZNE"
 * Za output programu uznaje się ostatnią wypisaną przez niego linijkę. Program może posiadać
 * inne, wcześniejsze wypisy, nie będą one testowane.
 */

 #include <iostream>
 #include <string>
 #include <cctype>
 using namespace std;

 bool porownaj(string ciag_a, string ciag_b)
 {
    bool wynik = true;

    string kontener_a = "";
    string kontener_b = "";

    int dlugosc = 0;

    if(ciag_a.length() < ciag_b.length())
    {
        return 0;
    }
    else if (ciag_b.length() < ciag_a.length())
    {
        return 0;
    }
    else
    {
        dlugosc = ciag_a.length();
    }

    for(int i = 0; i < dlugosc; i++)
    {
        kontener_a += tolower(ciag_a[i]);
        kontener_b += tolower(ciag_b[i]);
    }

    if(kontener_a == kontener_b)
    {
        wynik = true;
    }
    else
    {
        wynik = false;
    }

    return wynik;
 }

 int main()
 {
    string ciag_a = "";
    string ciag_b = "";

    cout << "Podaj pierwszy ciag: " << endl;
    getline(cin, ciag_a);
    cout << "Podaj drugi ciag: " << endl;
    getline(cin, ciag_b);

    if(porownaj(ciag_a, ciag_b) == true)
    {
        cout << "\nPODANE CIAGI ZNAKOW IDENTYCZNE";
    }
    else
    {
        cout << "\nCIAGI ZNAKOW ROZNE";
    }

    return 0;
 }