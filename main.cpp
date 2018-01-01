#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//Deklaracje funkcji:
void menu(char name[100], int licznik);
void start();
//void check(char name[100], int &amount_of_line);
void show_dic(char name[100]);
void show_file(char name[100]);
void comparison_size(char name[100], int licznik);
void licznik_plikow(char name[100], int &licznik);
void comparison_change(char name[100], int licznik);



//Definicje funkcji:
void start()
{
    int licznik = 0;
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
                menu(name, licznik);
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
void menu(char name[100], int licznik)
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
            comparison_size(name,licznik);
            break;
        }
        case 4:
        {
            comparison_change(name,licznik);
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
            menu(name,licznik);
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
void licznik_plikow(char name[100], int &licznik)
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
                                licznik = licznik + 1;
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
//Porównaj wielkość wybranych plikówc
void comparison_size(char name[100], int licznik)
{
    licznik_plikow(name,licznik);
    int licznik_2 = 0;
    fstream file;
    string line_1, line_2, line_3, line_4;
    string *tab1 = new string[licznik];
    int *value = new int[licznik];
    file.open(name, ios::in | ios::out);
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
                            line_4 = line_2;
                            line_3 = line_2;
                            line_3.erase(0, 21);
                            line_3.erase(5);
                            if(line_3.erase(5) == "     ")
                            {
                                line_2.erase(0,36);
                                line_4.erase(0,19);
                                line_4.erase(17);
                                //scout << atoi(line_4.c_str()) << endl;
                                value[licznik_2] = atoi(line_4.c_str());
                                tab1[licznik_2] = line_2;
                                licznik_2 = licznik_2 + 1;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
        cout << "Lista plików: " << endl;
        //Przydziela numery plikom
        for(int j=0; j<licznik; j++)
        {
          cout << j << "." << tab1[j] << endl;
        }
        cout << "Ilość plików, które chcesz porównać: ";
        int ile;
        cin >> ile;
        int *tab2 = new int[ile];
        //Pobiera od użytkownika numery plików
        for(int k=0; k<ile; k++)
        {
            cout << "Numer wybranego pliku: ";
            cin >> tab2[k];
        }
        int l; //zmienna pomocnicza
        int *value_choosen = new int[ile];
        int rozmiar;
        rozmiar = ile - 1; // zmienna do algorytmu bąbelkowego
        for(int m=0; m<ile; m++)
        {
            l = tab2[m];
            value_choosen[m] = value[l];
        }
        //algorytm sortujący wielkości wybranych plików od najmniejszej
        int bufor;
        for(int a=0; a<rozmiar; a++)
        {
            for(int b=0; b<rozmiar; b++)
            {
                if(value_choosen[b]>value_choosen[b+1])
                {
                    bufor = value_choosen[b+1];
                    value_choosen[b+1] = value_choosen[b];
                    value_choosen[b] = bufor;
                }
            }
        }
        cout << "Wybrane pliki w kolejności od najmniejszego" << endl;
        for(int d=0; d<ile; d++)
        {
            for(int e=0; e<licznik; e++)
            {
                if(value_choosen[d]==value[e])
                {
                    cout << tab1[e] << endl;
                }
            }
        }
        delete[] tab1;
        delete[] tab2;
        delete[] value;
        delete[] value_choosen;
    }
    else
    {
        start();
    }
}
//Porównaj datę i czas modyfikacji wybranych plików
void comparison_change(char name[100], int licznik)
{
    licznik_plikow(name,licznik);
    int licznik_2 = 0;
    fstream file;
    string line_1, line_2, line_3, line_4;
    string *tab1 = new string[licznik];  //nazwy plików
    int *tab3 = new int[licznik];
    file.open(name, ios::in | ios::out);
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
                            line_4 = line_2;
                            line_3 = line_2;
                            line_3.erase(0, 21);
                            line_3.erase(5);
                            if(line_3.erase(5) == "     ")
                            {
                                //Pobieranie nazwy pliku
                                line_2.erase(0,36);
                                tab1[licznik_2] = line_2;
                                //Pobieranie daty i godziny
                                line_4.erase(2,1);
                                line_4.erase(4,1);
                                line_4.erase(8,2);
                                line_4.erase(10,1);
                                line_4.erase(12);
                                tab3[licznik_2] = atoi(line_4.c_str());
                                licznik_2 = licznik_2 + 1;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
        cout << "Lista plików: " << endl;
        //Przydziela numery plikom
        for(int j=0; j<licznik; j++)
        {
          cout << j << "." << tab1[j] << endl;
        }
        cout << "Ilość plików, które chcesz porównać: ";
        int ile;
        cin >> ile;
        int *tab2 = new int[ile];
        //Pobiera od użytkownika numery plików
        for(int k=0; k<ile; k++)
        {
            cout << "Numer wybranego pliku: ";
            cin >> tab2[k];
        }
        int l; //zmienna pomocnicza
        int rozmiar;
        rozmiar = ile - 1; // zmienna do algorytmu bąbelkowego
        int *date_choosen = new int[ile];
        for(int m=0; m<ile; m++)
        {
            l = tab2[m];
            date_choosen[m] = tab3[l];
        }
        //algorytm sortujący wielkości wybranych plików od najmniejszej
        int bufor;
        for(int a=0; a<rozmiar; a++)
        {
            for(int b=0; b<rozmiar; b++)
            {
                if(date_choosen[b]<date_choosen[b+1])
                {
                    bufor = date_choosen[b+1];
                    date_choosen[b+1] = date_choosen[b];
                    date_choosen[b] = bufor;
                }
                //else if(date_choosen[b]==date_choosen[b+1])
                //{
                    //brak zmian
                //}
            }
        }
        cout << "Wybrane pliki w kolejności od ostaniej modyfikacji" << endl;
        for(int d=0; d<ile; d++)
        {
            for(int e=0; e<licznik; e++)
            {
                if(date_choosen[d]==tab3[e])
                {
                   cout << tab1[e] << endl;
                }
            }
        }
        delete[] tab1;
        delete[] tab2;
        delete[] tab3;
        delete[] date_choosen;
    }
    else
    {
        start();
    }
}
int main()
{
    start();
    return 0;
}