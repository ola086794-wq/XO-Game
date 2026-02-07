#include <iostream>

using namespace std;
char arr[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char position;
char player='x';
void show()
{
    cout<<"\n\n\t\t_____________________"<<endl;
    cout<<"\t\t|      |      |      |"<<endl;
    cout<<"\t\t|  "<<arr[0][0]<<"   |  "<<arr[0][1]<<"   |  "<<arr[0][2]<<"   | "<<endl;
    cout<<"\t\t|______|______|______|"<<endl;
    cout<<"\t\t|      |      |      |"<<endl;
    cout<<"\t\t|  "<<arr[1][0]<<"   |  "<<arr[1][1]<<"   |  "<<arr[1][2]<<"   | "<<endl;
    cout<<"\t\t|______|______|______|"<<endl;
    cout<<"\t\t|      |      |      |"<<endl;
    cout<<"\t\t|  "<<arr[2][0]<<"   |  "<<arr[2][1]<<"   |  "<<arr[2][2]<<"   | "<<endl;
    cout<<"\t\t|______|______|______|"<<endl;
}
void play()
{
    cout<<"Please Enter Position From :(1 - 9) For Player : "<<player<<endl;
    cin>>position;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
          if(position==arr[i][j])
          {
            arr[i][j]=player;
            break;
          }
        }
    }
    if(player=='x')
    {
        player='o';
    }
    else
    {
      player='x';
    }
}
char winner()
{
    int xCounter=0;
    int oCounter=0;
    int test=0;
    for(int i=0; i<3; i++)
    {

        for(int j=0; j<3; j++)
        {
            if(arr[i][j]!='x'&&arr[i][j]!='o')
            {
                test=1;
            }
            if(arr[i][j]=='x')
            {
                xCounter++;
            }
            else if(arr[i][j]=='o')
            {
                oCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if (oCounter==3)
        {
            return 'o';
        }
        xCounter=oCounter=0;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[j][i]=='x')
            {
                xCounter++;
            }
            else if(arr[j][i]=='o')
            {
                oCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if (oCounter==3)
        {
            return 'o';
        }
        xCounter=oCounter=0;
    }
    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x')
    {
        return 'x';
    }
    else if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o')
    {
        return 'o';
    }
    else if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x')
    {
        return 'x';
    }
    else if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o')
    {
        return 'o';
    }
    if(test==0)
    {
        return 'z';
    }
    return '.';
}
void resetGame()
{
    char c = '1';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[i][j] = c++;

    player = 'x';
}
int main()
{
    char again;
    do
    {
        resetGame();
        char result;
        while((result=winner())=='.')
        {
            show();
            play();
            system("cls");
        }
        show();
        if(result=='z')
            cout<<"No Winner In This Game\n";
        else
            cout<<"The Winner In This Game Is Player : " << result << "\n";

        cout<<"\nDo you want to play again? (y/n): ";
        cin>>again;
    }
    while(again=='y'||again=='Y');

    cout<<"\nThanks for playing See you soon!\n";
    return 0;
}
