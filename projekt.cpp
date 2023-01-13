#include <iostream>
#include <string>

using namespace std;

char gracz = '8';
char klawisz;
char temp = '$';

char labirynt[10][20];

int zycia = 5;
int gracz_x(0);
int gracz_y(0);


bool sciana(char kierunek); // sprawdza czy jest sciana po wpisaniu ruchu zwraca  true jak jest sciana
void pozycja_startowa(); // startowa pozycja_startowa gracza
void ruchy(); // ruchy gracza
void wypisanie(); // wypisuje caly labirynt na ekran
bool czy_Wygrana(); //sprwdza czy gracz dotarl do konca labiryntu
void reguly(); // wypisuje zasady gry
void menu_Koncowe(); // wybor po zakonczeniu gry1
bool zero_zycia(); // zwraca true kiedy zycia spadna do zera
void restart_gry(); // wybor labiryntu
void gra(); // cala gra poza funkcja main





int main()
{

   gra();

    return 0;
}

void gra()
{
    reguly();
    restart_gry();
    pozycja_startowa();
    do
    {
        wypisanie();
        cin >> klawisz;
        ruchy();



    } while (czy_Wygrana() == false);


}

void reguly()
{
 
    cout << "                   Witam w grze " << endl;
    cout << "                   __________" << endl;
    cout << "                   |LABIRYNT| " << endl;
    cout << "                   ----------\n" << endl;
    cout << "Twoim celem jest dotarcie do wyjscia oznaczonego znakiem '@'\n " << endl;
    cout << "Masz 5 zyc (HP) za kazde wejscie w sciane oznaczana '#' tracisz jedno\n" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|                   Sterowanie:                   |" << endl;
    cout << "|               (g) by isc w gore                 |" << endl;
    cout << "|               (d) by isc w dol                  |" << endl;
    cout << "|               (l) by isc w lewo                 |" << endl;
    cout << "|               (p) by isc w prawo                |" << endl;
    cout << "|           Powrot do menu glownego (m)           |" << endl;
    cout << "|              Zakoncz program (n)                |" << endl;
    cout << "---------------------------------------------------\n\n" << endl;
}

void ruchy()
{
    switch (klawisz)
    {
    case 'g':
        if (sciana('g') == true) {
            zero_zycia();
            break;
        }
        labirynt[gracz_y][gracz_x] = temp;
        gracz_y--;
        temp = labirynt[gracz_y][gracz_x];

        czy_Wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'd':
        if (sciana('d') == true) {
            zero_zycia();
            break;
        }
        labirynt[gracz_y][gracz_x] = temp;
        gracz_y++;
        temp = labirynt[gracz_y][gracz_x];

        czy_Wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'l':
        if (sciana('l') == true) {
            zero_zycia();
            break;
        }
        labirynt[gracz_y][gracz_x] = temp;
        gracz_x--;
        temp = labirynt[gracz_y][gracz_x];
        czy_Wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'p':
        if (sciana('p') == true) {
            zero_zycia();
            break;
        }
        labirynt[gracz_y][gracz_x] = temp;
        gracz_x++;
        temp = labirynt[gracz_y][gracz_x];
        czy_Wygrana();
        labirynt[gracz_y][gracz_x] = gracz;
        break;

    case 'm':
        gra();
        break;

    default:
    cout << "Aby sie poruszac, uzywaj klawiszy  (g)  (d)  (l)  (p)" << endl;
        break;
    }

}

void wypisanie()
{
    for (int y = 0; y <= sizeof(labirynt) / sizeof(labirynt[0]) - 1; y++)
    {
        for (int x = 0; x <= sizeof(labirynt[0]) - 1; x++)
        {
            cout << labirynt[y][x];
        }
        cout << endl;
    }
}

void pozycja_startowa()
{
    for (int y = 0; y <= sizeof(labirynt[0]) - 1; y++)
    {
        for (int x = 0; x <= sizeof(labirynt[0]) - 1; x++)
        {
            if (labirynt[y][x] == '$')
            {
                labirynt[y][x] = gracz;
                gracz_x = x;
                gracz_y = y;
                break;
            }
        }
    }
}

bool czy_Wygrana()
{

    if (labirynt[gracz_y][gracz_x] == '@')
    {
        wypisanie();
        cout << "Gratulacje, udalo ci sie pokonac labirynt!\n\n" << endl;
        menu_Koncowe();
        return true;
    }
    return false;
}


bool sciana(char kierunek)
{

    //temp = labirynt[gracz_y][gracz_x];

    switch (kierunek)
    {
    case 'g':
        if (labirynt[gracz_y - 1][gracz_x] == '#')
        {
            zycia -= 1;
            cout << "Zostalo ci " << zycia << "Hp\n" << endl;


            return true;
        }
        return false;
        break;

    case 'd':
        if (labirynt[gracz_y + 1][gracz_x] == '#')
        {
            zycia -= 1;
            cout << "Zostalo ci " << zycia << "Hp\n" << endl;


            return true;
        }
        return false;
        break;

    case 'l':
        if (labirynt[gracz_y][gracz_x - 1] == '#')
        {
            zycia -= 1;
            cout << "Zostalo ci " << zycia << "Hp\n" << endl;


            return true;
        }
        return false;
        break;

    case 'p':
        if (labirynt[gracz_y][gracz_x + 1] == '#')
        {
            zycia -= 1;
            cout << "Zostalo ci " << zycia << "Hp\n" << endl;


            return true;
        }
        return false;
        break;

    default:
        break;
    }


    return true;
}


void menu_Koncowe()
{
    char TN;
    cout << "Powrot do menu startowego (T) " << endl;
    cout << "Zakoncz program (N) " << endl;
    cin >> TN;
    cout << "---------------------\n" << endl;

    switch (TN)
    {
    case 't':
    case 'T':
        
        gra();
        cout << "---------------------\n" << endl;


    case 'n':
    case 'N':

        exit(0);
        break;

    default:
        menu_Koncowe();
        break;
    }
}

bool zero_zycia()
{
    if (zycia < 1)
    {
        cout << "Przegrales, koniec gry\n " << endl;
        menu_Koncowe();
        return true;
    }
    return false;
}

void restart_gry()
{
    char ktory_labirynt;

    char labirynt_startowy[10][20] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','$',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#','#','#','#','#','#',' ','#','#',' ','#','#','#',' ','#'},
        {'#',' ','#','#',' ','#',' ','#',' ','#','#',' ','#',' ',' ','#',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ','#','#','#',' ','#'},
        {'#',' ','#','#','#','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#',' ','#',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };
    

    char labirynt_startowy2[10][20] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','#'},
        {'#',' ','#','#','#',' ',' ','#',' ','$',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ','#','#',' ','#'},
        {'#','#',' ','#','#','#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };

    char labirynt_startowy3[10][20] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#'},
        {'#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#'},
        {'@',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#','$','#'},
        {'#',' ','#','#','#',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#'},
        {'#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };


    zycia = 5;
    temp = '$';

    cout << "Wybierz jeden z 3 labiryntow, wciskajac '1', '2' lub '3':";
    cin >> ktory_labirynt;
    cout << "---------------------\n" << endl;
    
    switch(ktory_labirynt)
    {
    case '1':
    cout << "Pokonaj labirynt nr 1! " << endl;
    cout << "---------------------\n" << endl;
        for (int y = 0; y < sizeof(labirynt) / sizeof(labirynt[0]); y++)
        {
            for (int x = 0; x < sizeof(labirynt[0]); x++)
            {
                labirynt[y][x] = labirynt_startowy[y][x];
            }
        }
        break;
    case '2':
     cout << "Pokonaj labirynt nr 2! " << endl;
    cout << "---------------------\n" << endl;
        for (int y = 0; y < sizeof(labirynt) / sizeof(labirynt[0]); y++)
        {
            for (int x = 0; x < sizeof(labirynt[0]); x++)
            {
                labirynt[y][x] = labirynt_startowy2[y][x];
            }
        }
        break;
    case '3':
     cout << "Pokonaj labirynt nr 3! " << endl;
    cout << "---------------------\n" << endl;
        for (int y = 0; y < sizeof(labirynt) / sizeof(labirynt[0]);  y++)
        {
            for (int x = 0; x < sizeof(labirynt[0]); x++)
            {
                labirynt[y][x] = labirynt_startowy3[y][x];
            }
        }
        break;
    default:
        restart_gry();

        break;
    } 
     

}

