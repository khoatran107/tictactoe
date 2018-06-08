#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char motO[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char luot = 'X';

void reset();
int end();
bool isMine(char a, char b);
bool isYours(char a, char b);
char Winner();
int Attack();
void Draw();
void DanhO();
void Doicho();
void PlayWithComputer();
void PlayWithHuman();
/*===============================================================*/
int main()
{

    int chon = 0;
    do{
          cout << "====TRO=CHOI=TIC=TAC=TOE====" << endl;
          cout << "1. Choi voi nguoi ke ben. " << endl;
          cout << "2. Choi voi may tinh. " << endl;
          cout << "3. Thoat. " << endl;
          cout << "Chon : " ;
          cin >> chon;
          if (chon == 1) PlayWithHuman();
          else if (chon == 2) PlayWithComputer();
          else break;
    }while(true);
    return 0;
}
/*===============================================================*/
void Draw()
{
    #ifdef linux
    system("clear");
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
/*===============================================================*/
void Doicho()
{
    if (luot == 'X'){
        luot = 'O';
    }
    else if (luot == 'O') luot = 'X';
}
/*===============================================================*/
void Danh()
{
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = luot;
}
/*================================================================*/
int end(){

    if ((motO[0]==motO[4]) && (motO[4]==motO[8])) {
        return 1;
    }
    if ((motO[2]==motO[4]) && (motO[4]==motO[6])) {
        return 1;
    }
    for (int i = 0; i <=6 ; i=i+3)
    {
        if ((motO[i] == motO[i+1]) && (motO[i+1] == motO[i+2]))
        {
            return 1;
        }
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        if ((motO[i]==motO[i+3]) && (motO[i+3] == motO[i+6]))
        {
            return 1;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (motO[i] != 'X' && motO[i] != 'O')
        {
            return 0;
        }
    }
    return 2;
}
/*==================================================================*/
char Winner()
{
    if ((motO[0]==motO[4]) && (motO[4]==motO[8])) {
        return motO[0];
    }
    if ((motO[2]==motO[4]) && (motO[4]==motO[6])) {
        return motO[2];
    }
    for (int i = 0; i <=6 ; i=i+3)
    {
        if ((motO[i] == motO[i+1]) && (motO[i+1] == motO[i+2]))
        {
            return motO[i];
        }
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        if ((motO[i]==motO[i+3]) && (motO[i+3] == motO[i+6]))
        {
            return motO[i];
        }
    }
    return 'X';
}
/*===================================================================*/
void PlayWithHuman()
{

    reset();
    while (end() == 0){

        Draw();
        Danh();
        Doicho();
    }
    if (end() == 1)
    cout << Winner() << " chien thang !!!"<< endl;
}
/*===============================================================*/
bool isMine(char a, char b, char c)
{
    if (( b == 'O') && (a == 'O') && (c!= 'X') && (c!='O')) return true;
    else
    return false;
}
/*===============================================================*/
bool isYours(char a, char b, char c)
{
    if ((b == 'X') && (a == 'X') && (c!= 'X') && (c!='O')) return true;
    else
    return false;
}
/*===============================================================*/

int Attack()
{
    for (int i = 0; i < 3; i++)
    {
        if (isMine(motO[i],motO[i+3],motO[i+6])) return (i+6);
        else if (isMine(motO[i+3],motO[i+6],motO[i])) return (i);
        else if (isMine(motO[i+6],motO[i],motO[i+3])) return (i+3);

        else if (isMine(motO[i*3],motO[i*3+1],motO[i*3+2])) return i*3+2;
        else if (isMine(motO[i*3+1],motO[i*3+2],motO[i*3])) return i*3;
        else if (isMine(motO[i*3],motO[i*3+2],motO[i*3+1])) return i*3+1;

    }
    if (isMine(motO[0],motO[4],motO[8])) return 8;
    else if (isMine(motO[4],motO[8],motO[0])) return 0;
    else if (isMine(motO[0],motO[8],motO[4])) return 4;
    else if (isMine(motO[2],motO[4],motO[6])) return 6;
    else if (isMine(motO[4],motO[6],motO[2])) return 2;
    else if (isMine(motO[6],motO[2],motO[4])) return 4;
    else
    for (int i = 0; i < 3; i++)
      {
          if (isYours(motO[i],motO[i+3],motO[i+6])) return (i+6);
          else if (isYours(motO[i+3],motO[i+6],motO[i])) return (i);
          else if (isYours(motO[i+6],motO[i],motO[i+3])) return (i+3);

          else if (isYours(motO[i*3],motO[i*3+1],motO[i*3+2])) return i*3+2;
          else if (isYours(motO[i*3+1],motO[i*3+2],motO[i*3])) return i*3;
          else if (isYours(motO[i*3],motO[i*3+2],motO[i*3+1])) return i*3+1;

      }

    if (isYours(motO[0],motO[4],motO[8])) return 8;
    else if (isYours(motO[4],motO[8],motO[0])) return 0;
    else if (isYours(motO[0],motO[8],motO[4])) return 4;
    else if (isYours(motO[2],motO[4],motO[6])) return 6;
    else if (isYours(motO[4],motO[6],motO[2])) return 2;
    else if (isYours(motO[6],motO[2],motO[4])) return 4;
        else
    for (int i = 0; i < 9; i++)
      {
        if ((motO[i] != 'X') && (motO[i] != 'O')) return i;
      }
    return 0;
}
/*===============================================================*/
void PlayWithComputer()
{
    reset();
    Draw();
    do {
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = 'X';
    DanhO();
    Draw();
    }while (end() == 0);
    if (end() == 1)
    cout << Winner() << " chien thang !!!" << endl;
}

void DanhO()
{
    int o = Attack();
    motO[o] = 'O';
}
/*===============================================================*/
void reset()
{
    for (int i = 0; i < 9; i++)
    {
        motO[i] = static_cast<char>(49+i);
    }
}
