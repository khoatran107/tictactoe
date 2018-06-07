#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char motO[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char luot = 'X';
char quanthang = ' ';

void Draw()
{
    system("cls");
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
    // if ((motO[0]==motO[1]) && (motO[1]==motO[2])) return true;
    // if ((motO[3]==motO[4]) && (motO[4]==motO[5])) return true;
    // if ((motO[6]==motO[7]) && (motO[8]==motO[7])) return true;
    // if ((motO[0]==motO[3]) && (motO[3]==motO[6])) return true;
    // if ((motO[1]==motO[4]) && (motO[4]==motO[7])) return true;
    // if ((motO[2]==motO[5]) && (motO[5]==motO[8])) return true;
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

void PlayWithComputer()
{
    Draw();
    Danh();

}

int main()
{
    PlayWithHuman();
    system("pause");
    return 0;
}
