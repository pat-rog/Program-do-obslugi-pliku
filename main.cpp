#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//Deklaracje funkcji:
void menu(char name[100], int licznik);
void start();
void show_dic(char name[100]);
void show_file(char name[100]);
void comparison_size(char name[100], int licznik);
void licznik_plikow(char name[100], int &licznik);
void comparison_change(char name[100], int licznik);
void files(char name[100], int licznik);



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
           // break;
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
//Menu
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
            menu(name,licznik);
            break;
        }
        case 2:
        {
            show_file(name);
            menu(name,licznik);
            break;
        }
        case 3:
        {
            comparison_size(name,licznik);
            menu(name,licznik);
            break;
        }
        case 4:
        {
            comparison_change(name,licznik);
            menu(name,licznik);
            break;
        }
        case 5:
        {
            files(name,licznik);
            menu(name,licznik);
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
                                cout << line_4;
                                //scout << atoi(line_4.c_str()) << endl;
                                value[licznik_2] = atoi(line_4.c_str());

                                cout << value[licznik_2] << endl;
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
    string *tab3 = new string[licznik]; //tablica do zapisania rozmiaru plików
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
                                //cout << line_4 << endl;
                                //cout << line_4.size() << endl;
                                //Wpisanie wartości do tablicy
                                tab3[licznik_2] = line_4;
                                //Obliczanie obiegów pętli
                                licznik_2 = licznik_2 + 1;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                                line_3 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                                line_4 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
        
        //cout << (int)"231220172039";
        int ile, value2, date2, time2;
        //cin >> ile;
        int *tab2 = new int[ile];
        string date1, time1, value;
        cout << "Data i czas modyfikacji: (uwaga! Podaj najpierw datę, np. 02.01.2018, a następnie czas, np. 10:21" << endl;
        cout << "data: " ;
        cin >> date1;
        cout << endl;
        cout << "czas: " ;
        cin >> time1;
        cout << endl;
        int *date_choosen = new int[licznik];
        //Wyznaczenie liczby określającej datę
        date1.erase(2,1);
        date1.erase(4,1);
        date1.erase(8,2);
        //Wyznaczenie liczby określającej godzinę
        time1.erase(2,1);
        //Wyznaczanie końcowej wartości wprowadzonego pliku
        value = date1 + time1;
        /////////////////////////////////////////////////////
        int *tab4 = new int[licznik];
        string linia1; //zmienna pomocnicza
        int linia2;
        //
        //Petla testowa
        for(int a=0; a<licznik; a++)
        {
            //
            cout << "Warość z tablicy: " << tab3[a] << endl;
            linia1 = tab3[a];
            cout << "Wartosc ze zmiennej: " << linia1 << endl;
            linia2 = atoi(linia1.c_str());
            cout << "Wartość po konwersji: " << linia2 << endl;
            //cout << endl;
            //cout << atoi(linia1.c_str());
            //cout << tab3[a] << endl;
            //linia = tab3[a];
            //tab4[a] = atoi(linia.c_str());
        }
        //cout << "Sprawdzanie czy poza pętlą działa" << endl;
       // linia2 = stoi(linia1);
        //cout << linia2;
        for(int b=0; b<licznik; b++)
        {
            cout << "test" <<  tab4[b] << endl;
        }
        
        int polecenie;
        int licznik_3 = 0;
        cout << "Wybierz właściwe polecenie 1 - 3" << endl;
        cout << "1. Wyświetl pliki o czasie modyfikacji wcześniejszym niż ten podany z klawiatury" << endl;
        cout << "2. Wyświetl pliki o czasie modyfikacji późniejszym niż ten podany z klawiatury" << endl;
        cout << "3. Wyświetl pliki o czasie modyfikacji takim samym jak ten podany z klawiatury" << endl;
        cin >> polecenie;
        /*
        switch(polecenie)
        {
            case 1:
            {
                cout << "ok##";
                //Pętla wyszukująca numery plików wcześniejszych niż ten podany z klawiatury
                for(int x=0; x<licznik; x++)
                {
                     cout << "ok#";
                    if(tab3[x]<value2)
                    {
                        cout << "ok";
                        date_choosen[x] = licznik_3;
                    }
                    licznik_3 = licznik_3 + 1;
                }
                break;
            }
            case 2:
            {
                cout << "ok##";
                //Pętla wyszukująca numery plików późniejszych niż ten podany z klawiatury
                for(int y=0; y<licznik; y++)
                {
                    cout << "ok#";
                    if(tab3[y]>value2)
                    {
                        cout << "ok";
                        date_choosen[y] = licznik_3;
                    }
                    licznik_3 = licznik_3 + 1;
                }
                break;
            }
            case 3:
            {
                cout << "ok##";
                //Pętla wyszukująca numery plików takich samych jak te podane z klawiatury
                for(int z=0; z<licznik; z++)
                {
                    cout << "ok#";
                    if(tab3[z]==value2)
                    {
                        cout << "ok";
                        date_choosen[z] = licznik_3;
                    }
                    licznik_3 = licznik_3 + 1;
                }
                break;
            }
            default:
            {
                break;
            }
        }
        
        int l; //zmienna pomocniczna
        for(int ab=0; ab<licznik; ab++)
        {
            l = date_choosen[ab];
            cout << tab1[l] << endl;
        }
       // for(int x=0; x<licznik; x++)
        //{
        //    if(value==tab3[x])

//
      //  }
        

        //Pobiera od użytkownika numery plików
        //for(int k=0; k<ile; k++)
        //{
          //  cout << "Numer wybranego pliku: ";
           // cin >> tab2[k];
        //}

        /*
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
        //cout << "Wybrane pliki w kolejności od ostaniej modyfikacji" << endl;
        for(int d=0; d<ile; d++)
        {
            for(int e=0; e<licznik; e++)
            {
                if(date_choosen[d]==tab3[e])
                {
                  // cout << tab1[e] << endl;
                }
            }
        }
        */
        delete[] tab1;
        delete[] tab2;
        delete[] tab3;
        delete[] tab4;
        delete[] date_choosen;

    }
    else
    {
        start();
    }
}
//Wypisz pliki, które nazwę zaczynają frazą podaną z klawiatury
void files(char name[100], int licznik)
{
    licznik_plikow(name,licznik);
    int licznik_2 = 0;
    fstream file;
    string line_1, line_2, line_3, line_4, line_5, line_6, line_7;
    string *tab1 = new string[licznik];  //nazwy plików
    string *tab3 = new string[licznik];
    string *tab4 = new string[licznik];
    string *tab5 = new string[licznik];
    string *tab6 = new string[licznik];
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
                            line_3 = line_2;
                            line_3.erase(0, 21);
                            line_3.erase(5);
                            if(line_3.erase(5) == "     ")
                            {
                                //Pobieranie nazwy pliku
                                line_2.erase(0,36);
                                tab1[licznik_2] = line_2;
                                //Opracowanie fraz
                                line_4 = line_2;
                                line_5 = line_2;
                                line_6 = line_2;
                                line_7 = line_2;
                                line_4.erase(1);
                                tab3[licznik_2] = line_4;
                                line_5.erase(2);
                                tab4[licznik_2] = line_5;
                                line_6.erase(3);
                                tab5[licznik_2] = line_6;
                                line_7.erase(4);
                                tab6[licznik_2] = line_7;
                                licznik_2 = licznik_2 + 1;
                                line_2 = ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
                                line_4 = "";
                                line_5 = "";
                                line_6 = "";
                                line_7 = "";
                            }
                        }
                    }
                } 
            }
            line_1= ""; //uwzględnia fakt, ze zawartosc pliku większa od przeznaczonego miejsca na program
        }
        file.close();
        //Podanie liczby plików
        cout << "Ilość plików, które chcesz wypisać: ";
        int ile;
        cin >> ile;
        //Podanie ilości znaków
        int choice;
        cout << "Wybierz z ilu pierwszych znaków nazwy pliku ma składać się podana fraza: " << endl;
        cout << "Wybierz 1, jeśli fraza zawiera pierwszy znak z nazwy pliku" << endl;
        cout << "Wybierz 2, jeśli fraza zawiera dwa pierwsze znaki z nazwy pliku" << endl;
        cout << "Wybierz 3, jeśli fraza zawiera trzy pierwsze znaki z nazwy pliku" << endl;
        cout << "Wybierz 4, jeśli fraza zawiera cztery pierwsze znaki z nazwy pliku" << endl;
        cin >> choice;
        string *fraza = new string[ile]; 
        for(int j=0; j<ile; j++)
        {
            cout << "Fraza: ";
            cin >> fraza[j];
        }
        switch(choice)
        {
            case 1:
            {
                for(int a=0; a<ile; a++)
                {
                    for(int b=0; b<licznik_2; b++)
                    {
                        if(fraza[a]==tab3[b])
                        {
                            cout << tab1[b] << endl;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                for(int a=0; a<ile; a++)
                {
                    for(int b=0; b<licznik_2; b++)
                    {
                        if(fraza[a]==tab4[b])
                        {
                            cout << tab1[b] << endl;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                for(int a=0; a<ile; a++)
                {
                    for(int b=0; b<licznik_2; b++)
                    {
                        if(fraza[a]==tab5[b])
                        {
                            cout << tab1[b] << endl;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                for(int a=0; a<ile; a++)
                {
                    for(int b=0; b<licznik_2; b++)
                    {
                        if(fraza[a]==tab6[b])
                        {
                            cout << tab1[b] << endl;
                        }
                    }
                }
                break;
            }
            default:
            {
                files(name,licznik);
            }

        }
        delete[] tab1;
        delete[] tab3;
        delete[] tab4;
        delete[] tab5;
        delete[] tab6;
        delete[] fraza;
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