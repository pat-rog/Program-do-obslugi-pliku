#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Deklaracje funkcji:
void menu();
void start();



//Definicje funkcji:
void start()
{
    char name[100];
    fstream file;
    cout << "|______________________________________________________________________________|" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  Program do obsługi plików z instrukcji dir w systemie operacyjnym Windows   |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  1. Podaj nazwę pliku                                                        |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  2. Wyjście z programu                                                       |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|______________________________________________________________________________|" << endl;
    int choice_1;
    cin >> choice_1;
    switch(choice_1)
    {
        case 1:
        {
            cin >> name;
            file.open(name, ios::in | ios::out);
            if(file.good() == true)
            {
                file.close();
                menu();
            }
            else
            {
                start();
            }
            break;
        }
        case 2:
        {
            break;
        }
        default:
        {
            start();
        }
    }
    cin >> name;
    file.open(name, ios::in | ios::out);
    if(file.good() == true)
    {
        file.close();
        menu();
    }
    else
    {
        start();
    }
}
void menu()
{
    cout << "|______________________________________________________________________________|" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  Program do obsługi plików z instrukcji dir w systemie operacyjnym Windows   |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  1. Wypisz wszystkie katalogi                                                |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  2. Wypisz wszystie pliki                                                    |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  3. Porównaj wielkość wybranych plików                                       |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  4. Porównaj datę i czas modyfikacji wybranych plików                        |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  5. Wypisz pliki, które nazwę zaczynają frazą podaną z klawiatury            |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  6. Powrót do wyboru pliku                                                   |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|  7. Wyjście z programu                                                       |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|______________________________________________________________________________|" << endl;
    int choice_2;
    cin >> choice_2;
    switch(choice_2)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            start();
            break;
        }
        case 7:
        {   
            cout <<"Exit";
            break;
        }
        default:
        {
            menu();
            break;
        }
    }
}
int main()
{
    start();
    //fstream plik;
    //string tab[10];
    //plik.open("plik1.txt", std::ios::in | std::ios::out);
    /*if(plik.good() == true)
    {
        string x;
        int licznik = 0;
        for(int i=0; i<10; i++)
        {
           getline(plik,x);
           licznik = licznik + 1;
           x.clear();
           cout << x;
        }
        cout << licznik << endl;
        cout << x;
        plik.close();
    }
    */
    
    //if(plik.good() == true)
    //{
        //for(int i=0; i<10; i++)
        //{
          // getline(plik, tab[i]);
           //tab[i].erase(0, 6);
       // }
        //plik.close();
    //}
    //for(int j=0; j<10; j++)
    //{
        //cout << "Tab: " << tab[j] << endl;
    //}
    return 0;
}