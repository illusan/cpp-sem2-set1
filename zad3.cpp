/* Napisz program, który wczytuje zdanie, a potem sprawdza, czy jest palindromem
 * (tzn. czytane wspak brzmi tak samo). Przykład: Kobyla ma maly bok. Oczywiście
 * trzeba tu ignorować spacje oraz nie zwracać uwagi na wielkość liter
 * (można wykorzystać funkcje z języka C: toupper, tolower). Tak jak w poprzednim
 * zadaniu założ, że podane zdanie nie może zwierać znakow diakrytycznych.
 *
 * Input programu: zdanie, zatwierdzenie.
 * Output programu, w przypadku kiedy zdanie jest palindromem: "\nPODANE ZDANIE TO PALINDROM`"
 * Output programu, w przypadku kiedy zdania są rozne: "\nPODANE ZDANIE TO NIE PALINDROM"
 * Za output programu uznaje się ostatnią wypisaną przez niego linijkę. Program może posiadać
 * inne, wcześniejsze wypisy, nie będą one testowane.
 */

 #include <iostream>
 #include <cctype>
 using namespace std;

 bool palindrom(string tekst)
 {
    bool wynik = true;
    string zdanie = "";
    string nowytekst = "";

    for (int i = 0; i < tekst.length(); i++)
    {
        if(tekst[i] != ' ')
        {
            nowytekst += tolower(tekst[i]);
        }
    }
    
    for(int i = nowytekst.length() -1; i >=0; i--)
    {
        zdanie += nowytekst[i];
    }

    if(zdanie == nowytekst)
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
    string tekst = "";
    cout << "Podaj zdanie: " <<endl;
    getline(cin, tekst);

    if(palindrom(tekst) == true)
    {
        cout << "\nPODANE ZDANIE TO PALINDROM" << endl;
    }
    else
    {
        cout << "\nPODANE ZDANIE TO NIE PALINDROM" << endl;
    }
    
    return 0;
 }