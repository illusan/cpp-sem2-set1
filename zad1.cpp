/* Napisz program, który narysuje kwadrat o zadanym boku (liczbie x-ow) oraz pusty w środku
 * (też o zadanym boku). O parametry zapytaj w programie.
 * Przykładowy obraz dla zewnętrznego rozmiaru 10 i wewnętrznego 6:
 *
 * xxxxxxxxxx
 * xxxxxxxxxx
 * xx      xx
 * xx      xx
 * xx      xx
 * xx      xx
 * xx      xx
 * xx      xx
 * xxxxxxxxxx
 * xxxxxxxxxx
 *
 * Pamiętaj o zweryfikowaniu, czy podane parametry są poprawne (dodatnie liczby całkowite). Zwroć uwagę,
 * że wymiary kwadratow powinny być parami liczb parzystych lub nieparzystych aby kwadrat został prawidłowo
 * narysowany. W przypadku gdy jedna z podanych liczb będzie parzysta, a druga nieparzysta kwadrat byłby
 * niesymetryczny. Czy są jeszcze inne warunki do spełnienia?
 *
 * Input programu: pierwszy parametr (wymiar zewnętrzny), zatwierdzenie, drugi parametr (wymiar wewnętrzny), zatwierdzenie
 * Output programu, w przypadku podania prawidłowych parametrow: nowa linia, obrazek wypisany bez dodatkowych nowych linii i wcięć, return 0
 * Output programu, w przypadku podania nieprawidłowych parametrow: "\nPODANO NIEPRAWIDŁOWE PARAMETRY", return 1
 */


 #include <iostream>
 using namespace std;

 int main()
 {
    int x = 0;
    int y = 0;

    cout << "Podaj pierwszy parametr: "<<endl;
    cin >> x;
    cout << "Podaj drugi parametr: "<<endl;
    cin >> y;

    if(x%2 != 0 && y%2 == 0 || x%2 == 0 && y%2 != 0 || x <= 0 || y <= 0 || x <= y)
    {
        cout << "\nPODANO NIEPRAWIDŁOWE PARAMETRY";
        return 1;
    }
    else
    {
        cout << endl;

        int ramka = (x - y) / 2;

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(i >= ramka && i < x - ramka && j >= ramka && j < x - ramka)
                {
                    cout << " ";
                }
                else
                {
                    cout << "x";
                }
            }
            
            cout << endl;
        }
        return 0;
    }
    
    return 0;
 }