#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char motO[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char luot = 'X';
char quanthang = ' ';

void Draw()
{
    #ifdef linux
    system("tput clear");
    #endif
    #ifdef _WIN32
    system("cls");
    #endif
    for (int i = 0; i < 9 ; i++)
    {
        cout << motO[i] << " ";
        if (((i + 1) % 3 == 0) && ((i + 1) > 0)) cout << endl;
    }
}

void Doicho()
{
    if (luot == 'X'){
        luot = 'O';
    }
    else if (luot == 'O') luot = 'X';
}

void Danh()
{
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = luot;
}
bool Win(){

    if ((motO[0]==motO[4]) && (motO[4]==motO[8])) {
        return true;
        quanthang = motO[0];
    }
    if ((motO[2]==motO[4]) && (motO[4]==motO[6])) {
        return true;
        quanthang = motO[2];
    }
    for (int i = 0; i <=6 ; i=i+3)
    {
        if ((motO[i] == motO[i+1]) && (motO[i+1] == motO[i+2]))
        {
            return true;
            quanthang = motO[i];
        }
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        if ((motO[i]==motO[i+3]) && (motO[i+3] == motO[i+6]))
        {
            return true;
            quanthang = motO[i];
        }
    }
    return false;
}

void PlayWithHuman()
{
        while (!Win()){

        Draw();
        Danh();
        Doicho();
    }
    cout << quanthang << "chien thang !!!"<< endl;
}

bool isMine(char a, char b)
{
    if ((a == b) && (a == 'O')) return true;
    return false;
}

bool isYours(char a, char b)
{
    if ((a == b) && (a == 'X')) return true;
    return false;
}


int Attack()
{
    for (int i = 0 ; i < 3; i++)
      {
        if (isMine(motO[i],motO[i+3])) return (i+6);
        else if (isMine(motO[i*3],motO[(i*3)+1])) return ((i*3)+2);
        else if (isMine(motO[i],motO[i+6])) return (i+3);
        else if (isMine(motO[i*3],motO[i*3+2])) return ((i*3)+1);
      }
    if (isMine(motO[0],motO[4])) return 8;
    else if (isMine(motO[4],motO[8])) return 0;
    else if (isMine(motO[0],motO[8])) return 4;
    else if (isMine(motO[2],motO[4])) return 6;
    else if (isMine(motO[4],motO[6])) return 2;
    else if (isMine(motO[6],motO[2])) return 4;
    else
    for (int i = 0 ; i < 3; i++)
      {
        if (isYours(motO[i],motO[i+3])) return (i+6);
        else if (isYours(motO[i*3],motO[(i*3)+1])) return ((i*3)+2);
        else if (isYours(motO[i],motO[i+6])) return (i+3);
        else if (isYours(motO[i*3],motO[i*3+2])) return ((i*3)+1);
      }
    if (isYours(motO[0],motO[4])) return 8;
    else if (isYours(motO[4],motO[8])) return 0;
    else if (isYours(motO[0],motO[8])) return 4;
    else if (isYours(motO[2],motO[4])) return 6;
    else if (isYours(motO[4],motO[6])) return 2;
    else if (isYours(motO[6],motO[2])) return 4;
    else
    for (int i = 0; i < 9; i++)
      {
        if (motO[i] != 'X' && motO[i] != 'O') return i;
      }

}

void PlayWithComputer()
{
    do {

    Draw();
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = 'X';

    int i = Attack();
    motO[i] = 'O';
    }while (!Win());
}

int main()
{
    PlayWithComputer();
    return 0;
}
