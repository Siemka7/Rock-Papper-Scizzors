#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

int cash, x;




int ChooseYourHand(){ // Pasirenki handa po to kai pabetinai (logiska), bet poto pasirinkus handa vel meta i kiek nori betint ir tada vel grazina prie hando ir t.t...

    cout<<"[1] Rock"<<endl;
    cout<<"[2] Papper"<<endl;
    cout<<"[3] Scissors"<<endl;
    cout<<"Choose your hand: ";
    cin>>x;

    while(x!=1 && x!=2 && x!=3){

        cout<<"Choose a hand from the given above: ";
        cin>>x;
}

return x;
}




int RandomNumber(){
    srand(time(0));
    int a=rand()%3;
    return a;
}

int Balance(int bet){
   cash-=bet;
   return cash;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartGame()
{



int bet, x, h, k;
cout<<"How much would you like to bet? "<<endl;
cin>>bet;

while(bet<=0 || bet>cash){
cout<<"You can't bet less than 1 Dollaro or more than you have: "<<endl;
cin>>bet;
}

cout<<"Your bet is: "<<bet<<" Dollaros"<<endl;
cout<<endl;

cash=Balance(bet);
cout<<"Remaining balance: "<<cash<<" Dollaros"<<endl;
cout<<endl;

int a=RandomNumber();

x=ChooseYourHand();

if(x==a){
    cash+=bet;
    cout<<"You tied"<<endl;
    cout<<endl;

   if(a==1){

        cout<<"Your oponent picked - Papper"<<endl;

    }
    if(a==2){
        cout<<"Your oponent picked - Scissors"<<endl;
    }
    if(a==3){

        cout<<"Your oponent picked - Rock"<<endl;
    }

    cout<<"Balance: "<<cash<<" Dollaros"<<endl;
    cout<<"Press [1] to play again"<<endl;
    cout<<"Press [6] back to start"<<endl;
    cin>>h;

        while(h!=1 && h!=6){
        h=0;
        cout<<"You have to pick one of the given options"<<endl;
        cin>>h;
}

       if(h==1){
           StartGame();
}

       if(h==6){
           return; //sugrazina i StartGame() pradzia, o ne i int Main()
       }
}




else if(x==1 && a==2 || x==2 && a==3 || x==3 && a==1){


    if(a==1){

        cout<<"Your oponent picked - Rock"<<endl;

    }
    if(a==2){
        cout<<"Your oponent picked - Paper"<<endl;
    }
    if(a==3){

        cout<<"Your oponent picked - Scizzors"<<endl;
    }

    cout<<"You loose"<<endl;
    cout<<endl;

    cout<<"Remaining balance: "<<cash<<" Dollaros"<<endl;

    cout<<"Press [1] to play again"<<endl;
    cout<<"Press [6] back to start"<<endl;
    cin>>h;

        while(h!=1 && h!=6){
        cout<<"You have to pick one of the given options"<<endl;
        cin>>h;
}

       if(h==1){
           StartGame();
}

       if(h==6){
           return;
       }

}

else if(x==1 && a==3 || x==2 && a==1 || x==3 && a==2){

    cash+=bet*2;

    if(a==1){

        cout<<"Your oponent picked - Papper"<<endl;

    }
    if(a==2){
        cout<<"Your oponent picked - Scissors"<<endl;
    }
    if(a==3){

        cout<<"Your oponent picked - Rock"<<endl;
    }

    cout<<"You win"<<endl;
    cout<<endl;

    cout<<"Remaining balance: "<<cash<<" Dollaros"<<endl;

    cout<<"Press [1] to play again"<<endl;
    cout<<"Press [6] back to start"<<endl;
    cin>>h;

        while(h!=1 && h!=6){

        cout<<"You have to pick one of the given options: "<<endl;
        cin>>h;
}

       if(h==1){
           StartGame();
}

       if(h==6){
           return;
       }

}
}

//Start Game funkcija ^

int main(){

ifstream infile("cash.txt");

infile>>cash;

infile.close();

ofstream outfile("cash.txt");

int o;
for(int i=-1; i<0; i--){


cout<<"BALANCE: "<<cash<<" Dollaros"<<endl;
cout<<"Press [1] to Start the game"<<endl;
cout<<"Press [9] to End the game"<<endl;
cin>>o;

if(o==9){
    outfile<<cash;
    outfile.close();
    return 1;
}

while(o!=1){
        cout<<"You have to PRESS [1] or [9]"<<endl;
        cin>>o;
        if(o==9){
            outfile<<cash;
            outfile.close();
            return 1;
        }

}

StartGame();

outfile<<cash;
}

outfile.close();
return 0;
}
