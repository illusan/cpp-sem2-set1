/* Zmodyfikuj poprzedni program z zadania 4 tak, żeby korzystał z wyliczonych wcześniej
 * wartości (nie powtarzał ich wyliczania) do wyznaczenia następnych. Na przykład,
 * żeby pytał, który element ciągu ma wyliczyć i jeśli już wcześniej wyliczył niższe
 * wartości, to miał je zapamiętane i wykorzystał. Można tutaj wykorzystać prostą tablicę lub kontener.
 *
 * Input programu: 5 liczb oznaczających wybrane wyrazy ciagu Fibonnaciego, podane w sekwencji
 * parametr, zatwierdzenie, parametr, zatwierdzenie, itd...
 * Output programu w przypadku podania prawidłowych parametrow: nowa linia, żądane wyrazy ciągu oddzielone spacjami, nowa linia, return 0.
 * Jak w zad. 4, po ostatnim wyrazie ciągu nie powinno być spacji.
 * Output programu w przypagku podania nieprawidłowych parametrow (np. przynajmniej jedna z liczb ujemna
 * lub niecałkowita): "\nPODANO NIEPRAWIDLOWE NUMERY WYRAZOW CIAGU FIBONACCIEGO", return 1.
 */

 #include <iostream>
 #include <vector> 
 using namespace std;

static vector<unsigned long long> tablica = {0,1};

 unsigned long long fibnoacci(int k)
 {
    unsigned long long a = tablica[tablica.size() - 2];
    unsigned long long b = tablica[tablica.size() - 1];
    unsigned long long wynik = 1;

    if(k < tablica.size())
    {
        return tablica[k];
    }

    for(int i = tablica.size(); i <= k; i++)
    {
        wynik = a + b;
        a = b;
        b = wynik;
        tablica.push_back(wynik);
    }

    return tablica[k];
 }

 int main()
 {
    int input[5];

    cout << "Podaj 5 liczb: "<<endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> input[i];
        if(input[i] < 0)
        {
            cout << "\nPODANO NIEPRAWIDLOWE NUMERY WYRAZOW CIAGU FIBONACCIEGO";
            return 1;
        }
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << fibnoacci(input[i]);
        if (i < 4)
        {
            cout <<" ";
        }
    }

    cout << endl;

    return 0;
 }