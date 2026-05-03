/* Napisz funkcję wyliczającą kolejne wyrażenia ciągu Fibonacciego:
 * a. w wersji rekurencyjnej (czyli funkcja wywołuje samą siebie)
 * b. w wersji z jedną pętlą for.
 * Niech przykładowy program wygląda tak:
 *
 * int main(){
 *  unsigned long long k = 50;
 *
 *  for(unsigned long long i=1; i<=k; ++i){
 *      cout << fib_a(i) << endl;
 *      }
 *
 *  (...)
 *  }
 *
 * Zbadaj jak wygląda czas wykonania tych obliczeń w obu podejściach. Do
 * tego celu możesz wykorzystać bibliotekę chrono. Obserwacje
 * co do czasu obliczeń zapisz w komentarzu na końcu programu.
 *
 * Input programu: brak, tak jak w przykladzie liczba wyrazow ciagu Fibonacciego
 * do obliczenia powinna być zdefiniowana w programie i powinna wynosic 50.
 * Output programu: 50 pierwszych wyrazow ciągu Fibonnaciego, obliczone metodą rekurencyjną,
 * oddzielone spacjami, nowa linia, 50 pierwszych wyrazow ciągu Fibonnaciego obliczone metodą
 * z pętlą for, nowa linia. UWAGA: po ostatnich wyrazach ciągu nie powinno być spacji!
 */

 #include <iostream>
 #include <chrono>
 using namespace std;

 unsigned long long fibonaccirek(int k)
 {
    if(k <= 0)
        return 0;
    if(k == 1)
        return 1;

    return fibonaccirek(k - 1) + fibonaccirek(k - 2);
 }

 unsigned long long fibonaccifor(int k)
 {
    if (k <= 0)
        return 0;

    if (k == 1)
        return 1;
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long wynik = 1;

    for(int i = 2; i <= k; i++)
    {
        wynik = a + b;
        a = b;
        b = wynik;
    }

    return wynik;
 }

 int main()
 {
    unsigned long long k = 50;

    auto start_rek = chrono::high_resolution_clock::now();

    for(int i = 1; i <=k; ++i)
    {
        cout << fibonaccirek(i);
        if(i < k)
            cout<<" ";
    }

    auto end_rek = chrono::high_resolution_clock::now();
    chrono::duration<double> czas_rek = end_rek - start_rek;

    cout << endl;

    auto start_for = chrono::high_resolution_clock::now();

    for(int i = 1; i <=k; ++i)
    {
        cout << fibonaccifor(i);
        if(i < k)
            cout<<" ";
    }

    auto end_for = chrono::high_resolution_clock::now();
    chrono::duration<double> czas_for = end_for - start_for;

    //cout << "\nCzas wykonania rekurencji: " << czas_rek.count() << " s"<<endl;
    //cout << "Czas wykonania petli for:  " << czas_for.count() << " s"<<endl;;

    /*
    Czas wykonania rekurencji: 116.787 s
    Czas wykonania petli for:  1.1333e-05 s

    Rekurencyjnie fukncja wykonuje sie duzo wolniej
    */

    return 0;
 }