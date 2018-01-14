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
            cout << "Wybór: ";
            cin >> name;
            file.open(name, ios::in | ios::out);
            if(file.good() == true)
            {
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
    long long *values = new long long[licznik];
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
                                //cout << "Rozmiary" << line_4 << endl;        
                                values[licznik_2]= atoll(line_4.c_str());
                                //cout << "Rozmiary z tablicy: " << values[licznik_2] << endl;                      
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
        cout << endl;
        long long size;
        cout << "Podaj wielkość pliku: ";
        cin >> size;
        cout << endl;
        cout << "|-----------------------------------------------------------------------------|" << endl;
        cout << "| Wybierz polecenie, podając odpowiednią cyfrę:                               |" << endl;
        cout << "|-----------------------------------------------------------------------------|" << endl;
        cout << "| 1. Wypisz pliki, których wielkość jest większa od zadanej z klawiatury.     |" << endl;
        cout << "|-----------------------------------------------------------------------------|" << endl;
        cout << "| 2. Wypisz pliki, których wielkość jest mniejsza od zadanej z klawiatury.    |" << endl;
        cout << "|-----------------------------------------------------------------------------|" << endl;
        cout << "| 3. Wypisz pliki, których wielkość jest równa zadanej z klawiatury.          |" << endl;
        cout << "|-----------------------------------------------------------------------------|" << endl;
        cout << endl;
        int choice;
        cin >> choice;
        long long *values_sorted = new long long[licznik_2];
        int help = 0; //zmienna pomocnicza, aby nie było luk
        if(choice==1)
        {
            cout << "Pliki o rozmiarze większym niż zadany z klawiatury." << endl;
            cout << "Pliki wyświetlone w kolejności od pliku o najmniejszym rozmiarze rosnąco!" << endl;
            cout << endl;
            for(int i=0; i<licznik_2; i++)
            {
                if(size<values[i])
                {
                    values_sorted[help] = values[i];
                    help = help + 1;
                }
            }
            //Sortowanie tablicy
            int rozmiar = licznik_2 - 1;
            long long bufor;
            for(int a=0; a<rozmiar; a++)
            {
                for(int b=0; b<rozmiar; b++)
                {
                    if(values_sorted[b]>values_sorted[b+1])
                    {
                        bufor = values_sorted[b+1];
                        values_sorted[b+1] = values_sorted[b];
                        values_sorted[b] = bufor;
                    }
                }
            }
            //Wyświetlanie od najmniejszego
            for(int j=0; j<licznik; j++)
            {
                for(int k=0; k<licznik; k++)
                {
                    if(values_sorted[j]==values[k])
                    {
                        cout << tab1[k] << endl;
                    }
                }
            }
        }
        else if(choice==2)
        {
            cout << "Pliki o rozmiarze mniejszym niż zadany z klawiatury." << endl;
            cout << "Pliki wyświetlone w kolejności od pliku o najmniejszym rozmiarze rosnąco!" << endl;
            cout << endl;
            for(int i=0; i<licznik_2; i++)
            {
                if(size>values[i])
                {
                    values_sorted[help] = values[i];
                    help = help + 1;
                }
            }
            //Sortowanie tablicy
            int rozmiar = licznik_2 - 1;
            long long bufor;
            for(int a=0; a<rozmiar; a++)
            {
                for(int b=0; b<rozmiar; b++)
                {
                    if(values_sorted[b]>values_sorted[b+1])
                    {
                        bufor = values_sorted[b+1];
                        values_sorted[b+1] = values_sorted[b];
                        values_sorted[b] = bufor;
                    }
                }
            }
            //Wyświetlanie od najmniejszego
            for(int j=0; j<licznik; j++)
            {
                for(int k=0; k<licznik; k++)
                {
                    if(values_sorted[j]==values[k])
                    {
                        cout << tab1[k] << endl;
                    }
                }
            }
        }
        else if(choice==3)
        {
            cout << "Pliki o rozmiarze równym jak zadany z klawiatury." << endl;
            cout << "Pliki wyświetlone w kolejności od pliku o najmniejszym rozmiarze rosnąco!" << endl;
            cout << endl;
            for(int i=0; i<licznik_2; i++)
            {
                if(size==values[i])
                {
                    values_sorted[help] = values[i];
                    help = help + 1;
                }
            }
            //Wyświetlanie 
            for(int j=0; j<licznik; j++)
            {
                for(int k=0; k<licznik; k++)
                {
                    if(values_sorted[j]==values[k])
                    {
                        cout << tab1[k] << endl;
                    }
                }
            }
        }
        else
        {
            comparison_size(name, licznik);   
        }
        cout << endl;
        delete[] tab1;
        delete[] values;
        delete[] values_sorted;
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
    int *year1 = new int[licznik];
    int *month1 = new int[licznik];
    int *day1 = new int[licznik];
    int *hour1 = new int[licznik];
    int *minute1 = new int[licznik];
    string year2;
    string month2;
    string day2;
    string hour2;
    string minute2;
    
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
                                //Wpisanie wartości do tablicy
                                //Rok:
                                year2 = line_4;
                                year2.erase(0,4);
                                year2.erase(4);
                                year1[licznik_2] = atoi(year2.c_str());
                                cout << "rok: " << year1[licznik_2] << endl;
                                //Miesiąc
                                month2 = line_4;
                                month2.erase(0,2);
                                month2.erase(2);
                                month1[licznik_2] = atoi(month2.c_str());
                                cout << "miesiąc: " << month1[licznik_2] << endl;
                                //Dzień
                                day2 = line_4;
                                day2.erase(2);
                                day1[licznik_2] = atoi(day2.c_str());
                                cout << "dzień " << day1[licznik_2] << endl; 
                                //Godzina
                                hour2 = line_4;
                                hour2.erase(0,8);
                                hour2.erase(2);
                                hour1[licznik_2] = atoi(hour2.c_str());
                                cout << "godzina: " << hour1[licznik_2] << endl;
                                //Minuta
                                minute2 = line_4;
                                minute2.erase(0,10);
                                minute1[licznik_2] = atoi(minute2.c_str());
                                cout << "minuta: " << minute1[licznik_2] << endl;
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
        
        //cin >> ile;
        //int *tab2 = new int[ile];
        string date, time, value, bufor_year, bufor_month, bufor_day, bufor_hour, bufor_minute;

        int date_year, date_month, date_day; //zmienne dla wpisanego roku, miesiąca i dnia
        int time_hour, time_minute; //zmienne dla wpisanej godziny i minuty
        cout << "Data i czas modyfikacji: (uwaga! Podaj najpierw datę, np. 02.01.2018, a następnie czas, np. 10:21" << endl;
        cout << "data: " ;
        cin >> date;
        cout << endl;
        cout << "czas: " ;
        cin >> time;
        cout << endl;
        string *date_choosen = new string[licznik];
        //Wyznaczenie liczby określającej datę
        date.erase(2,1);
        date.erase(4,1);
        date.erase(8,2);
        //Rok:
        bufor_year = date;
        bufor_year.erase(0,4);
        date_year = atoi(bufor_year.c_str());
        cout << date_year << endl;
        //Miesiąc
        bufor_month = date;
        bufor_month.erase(0,2);
        bufor_month.erase(2);
        date_month = atoi(bufor_month.c_str());
        cout << date_month << endl;
        //Dzień
        bufor_day = date;
        bufor_day.erase(2);
        date_day = atoi(bufor_day.c_str());
        cout << date_day << endl;
        //Godzina
        bufor_hour = time;
        bufor_hour.erase(2);
        time_hour = atoi(bufor_hour.c_str());
        cout << time_hour << endl;
        //Minuta
        bufor_minute = time;
        bufor_minute.erase(0,3);
        time_minute = atoi(bufor_minute.c_str());
        cout << time_minute << endl;
        ///////////////////////////////////////////////////// 
        int polecenie;
        int elementy = 0;
        int indeks;
        int rozmiar;
        int l; //zmienna pomocnicza
        cout << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz właściwe polecenie 1 - 3                                                     |" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << "|1. Wyświetl pliki o czasie modyfikacji wcześniejszym niż ten podany z klawiatury     |" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << "|2. Wyświetl pliki o czasie modyfikacji późniejszym niż ten podany z klawiatury       |" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << "|3. Wyświetl pliki o czasie modyfikacji takim samym jak ten podany z klawiatury       |" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << endl;
        cout << "Wybór: ";
        cin >> polecenie;
        cout << endl;
        switch(polecenie)
        {
            case 1:
            {
                for(int i=0; i<licznik_2; i++)
                {
                    if(year1[i]<date_year)
                    {
                        cout << tab1[i] << endl;
                    }
                    else if(year1[i]==date_year)
                    {
                       if(month1[i]<date_month)
                       {
                           cout << tab1[i] << endl;
                       }
                       else if(month1[i]==date_month)
                       {
                           if(day1[i]<date_day)
                           {
                               cout << tab1[i] << endl;
                           }
                           else if(day1[i]==date_day)
                           {
                               if(hour1[i]<time_hour)
                               {
                                   cout << tab1[i] << endl;
                               }
                               else if(hour1[i]==time_hour)
                               {
                                   if(minute1[i]<time_minute)
                                   {
                                       cout << tab1[i] << endl;
                                   }
                               }
                           }
                       }
                    }
                }
                break;
            }
            case 2:
            {
                for(int i=0; i<licznik_2; i++)
                {
                    if(year1[i]>date_year)
                    {
                        cout << tab1[i] << endl;
                    }
                    else if(year1[i]==date_year)
                    {
                       if(month1[i]>date_month)
                       {
                           cout << tab1[i] << endl;
                       }
                       else if(month1[i]==date_month)
                       {
                           if(day1[i]>date_day)
                           {
                               cout << tab1[i] << endl;
                           }
                           else if(day1[i]==date_day)
                           {
                               if(hour1[i]>time_hour)
                               {
                                   cout << tab1[i] << endl;
                               }
                               else if(hour1[i]==time_hour)
                               {
                                   if(minute1[i]>time_minute)
                                   {
                                       cout << tab1[i] << endl;
                                   }
                               }
                           }
                       }
                    }
                }
                break;
            }
            case 3:
            {
                for(int i=0; i<licznik_2; i++)
                {
                    if(year1[i]==date_year)
                    {
                        if(month1[i]==date_month)
                        {
                            if(day1[i]==date_day)
                            {
                                if(hour1[i]==time_hour)
                                {
                                    if(minute1[i]==time_minute)
                                    {
                                        cout << tab1[i] << endl;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            default:
            {

            }
        }
        cout << endl;
        ////////////////////////////////////
        delete[] tab1;
        delete[] date_choosen;
        delete[] year1;
        delete[] month1;
        delete[] day1;
        delete[] hour1;
        delete[] minute1;
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
                                tab3[licznik_2] = line_4; //1 znak
                                line_5.erase(2);
                                tab4[licznik_2] = line_5; //2 znaki
                                line_6.erase(3);
                                tab5[licznik_2] = line_6; //3 znaki
                                line_7.erase(4);
                                tab6[licznik_2] = line_7; //4 znaki
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
        //Podanie frazy
        string fraza;
        cout << endl;
        cout << "Fraza ";
        cin >> fraza;
        cout << endl;
        //Podanie ilości znaków
        int choice;
        cout << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz z ilu pierwszych znaków nazwy pliku ma składać się podana fraza:  |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz 1, jeśli fraza zawiera pierwszy znak z nazwy pliku                |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz 2, jeśli fraza zawiera dwa pierwsze znaki z nazwy pliku           |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz 3, jeśli fraza zawiera trzy pierwsze znaki z nazwy pliku          |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << "|Wybierz 4, jeśli fraza zawiera cztery pierwsze znaki z nazwy pliku        |" << endl;
        cout << "|--------------------------------------------------------------------------|" << endl;
        cout << endl;
        cout << "Wybór: ";
        cin >> choice;
        cout << endl;
        if(choice==1)
        {
            for(int i=0; i<licznik_2; i++)
            {
                if(fraza==tab3[i])
                {
                    cout << tab1[i] << endl;
                }
            }
        }
        else if(choice==2)
        {
            for(int i=0; i<licznik_2; i++)
            {
                if(fraza==tab4[i])
                {
                    cout << tab1[i] << endl;
                }
            }
        }
        else if(choice==3)
        {
            for(int i=0; i<licznik_2; i++)
            {
                if(fraza==tab5[i])
                {
                    cout << tab1[i] << endl;
                }
            }
        }
        else if(choice==4)
        {
            for(int i=0; i<licznik_2; i++)
            {
                if(fraza==tab6[i])
                {
                    cout << tab1[i] << endl;
                }
            }
        }
        else
        {
            cout << "Niezgodnie z instrukcją użytkownik wpisał dane";
            files(name, licznik);
        }
        delete[] tab1;
        delete[] tab3;
        delete[] tab4;
        delete[] tab5;
        delete[] tab6;
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