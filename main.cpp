#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Deklaracje funkcji:
void menu(char name[100]);
void start();
//void check(char name[100], int &amount_of_line);
void show_dic(char name[100]);
void show_file(char name[100]);



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
                //check(name);
                file.close();
                menu(name);
            }
            else
            {
                cout << "Nie ma pliku o takiej nazwie!" << endl;
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
}
void menu(char name[100])
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
            show_dic(name);
            break;
        }
        case 2:
        {
            show_file(name);
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
            menu(name);
            break;
        }
    }
}
/*void check(char name[100], int &amount_of_line)
{
    amount_of_line = 0;
    string line;
    fstream file;
    file.open(name, ios::in | ios::out);
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, line);
            line = "";
            amount_of_line = amount_of_line + 1;
        }
        amount_of_line = amount_of_line - 1;
        cout << "linijka: " << line << endl; // It won't be forever! "It's only for test"
        cout << "Liczba linijek: " << amount_of_line << endl; // It won't be forever! "It's only for test"
        file.seekg(0);
        file.close();
    }
    else
    {
        start(amount_of_line);
    }
}
*/
//Wypisz wszystkie katalogi
void show_dic(char name[100])
{
    fstream file;
    string line_1, line_2, line_3;
    file.open(name, ios::in | ios::out);;
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, line_1);
            if(line_1.size()!=1 && line_1.size()!=0)
            {
                if(line_1.erase(13) == " Directory of") //|| line == "Directory of")
                {
                    while(!file.eof())
                    {   
                        getline(file, line_2);
                        if(line_2.size()!=1 && line_2.size()!=0)
                        {
                            line_3 = line_2;
                            line_3.erase(0, 21);
                            line_3.erase(5);
                            if(line_3.erase(5) == "<DIR>")
                            {
                                line_2.erase(0,36);
                                cout << line_2 << endl;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
    }
    else
    {
        start();
    }
}
//Wypisz wszystkie pliki
void show_file(char name[100])
{
    fstream file;
    string line_1, line_2, line_3;
    file.open(name, ios::in | ios::out);;
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, line_1);
            if(line_1.size()!=1 && line_1.size()!=0)
            {
                if(line_1.erase(13) == " Directory of") //|| line == "Directory of")
                {
                    while(!file.eof())
                    {   
                        getline(file, line_2);
                        if(line_2.size()!=1 && line_2.size()!=0)
                        {
                            line_3 = line_2;
                            line_3.erase(0, 21);
                            line_3.erase(5);
                            if(line_3.erase(5) == "     ")
                            {
                                line_2.erase(0,36);
                                cout << line_2 << endl;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
    }
    else
    {
        start();
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