#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<windows.h>

using namespace std;


int main() {

              //----------------------------FUNCTION # 1 STARTS---------------------//

string welcome = "Welcome to Conway's game of life, one of the most infamous cellular automations ever created.";
string rule0 = "The Rules of this game are simple. Enter the number of rows and columns you want, and the computer will create a random grid of Alive and dead cells, in accordance with your grid boundaries.";
string ruleZ = "After this, you must enter the number of generations you wish to simulate. The state of each cell in the next generation";
string ruleX = "is determined by a few simple rules :--";
string rule1 = "1. Any live cell with two or three live neighbours survives.";
string rule2 = "2. Any dead cell with three live neighbours becomes a live cell.";
string rule3 = "3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.";
cout <<welcome<<endl<<endl<<rule0<<endl<<endl<<ruleZ<<ruleX<<endl<<rule1<<endl<<rule2<<endl<<rule3<<endl<<endl<<endl<<endl;
 cout <<"To begin please follow the on-screen instructions"<<endl<<endl<<endl<<endl<<endl<<endl;
 int rm2 = 100 , cm2 = 100;

    while (( rm2 > 25) || (cm2 > 25) || (rm2 == 0) || (cm2 == 0) ) {

    cout << "Please enter your desired number of rows (Between 1 and 25)"<<endl;    // limit is 25, otherwise formating is distubed
    cin >> rm2;
    cout << "Please enter your desired number of columns (Between 1 and 25)"<<endl;
    cin >>cm2;
    if ((rm2 == 0) || (cm2 == 0) || (rm2 > 25) || (cm2 > 25))
    {
        cout <<"Your number of rows and/or columns is invalid. Please enter a valid number between 1 and 25"<<endl<<endl<<endl<<endl;
    }
    }


int rows = rm2 + 2;
int columns = cm2 + 2;
int a2rows  = rows;
char state[columns][rows];
     cout <<"Great! Below is your computer generated initial template for the game of life:-"<<endl;
     cout <<endl<<endl;
    char  test[rows][columns] ;







int r , c;

    srand(time(0));

    for (r=0; r<rows; ++r){
     for (c = 0; c < columns; ++c){

        if (   (r == 0) || (r == (rows - 1) ) || (c == 0) || (c == (columns - 1) ) ){


        test [r][c] = ' ';
    }
    }
     }
                                                                    //enables compiler to give new output
    for ( r = 1; r < (rows - 1) ; ++r)
    {
    for ( c = 1; c < (columns - 1) ; ++c){



      {
          int ran_v = (rand () % 2 + 0);
      if (ran_v == 1)
     {
          test [r][c] = 'A';
      }
      else
      {
          test [r][c] = ' ';
      }

      }
    }
    }

    for (r = 1; r < (rows - 1); ++r){
    for (c = 1; c < (columns - 1); ++c){

        cout << " ["<< test[r][c]<<"]";
    }
     cout<<endl;

    }

cout <<endl<<endl<<endl<<endl<<endl;


int generations = 200;

while ((generations == 0) || (generations > 50) ) {

    cout<< "Please enter your desired number of generations between 1 and 50 (Once you click enter, the game will begin)"<<endl<<endl<<endl;
cin >> generations;
   if ((generations == 0) || (generations > 50) ) {
        cout <<"Your number of generations is invalid. Please enter a valid number of generations between 1 and 50"<<endl<<endl<<endl<<endl;
    }
    }

cout <<endl<<endl;
int gen;
int count = 0;
int neighbors;
int m , n;
for ( gen = 0; gen< generations; gen++){
 cout << "Generation number "<< gen + 1 << " is " <<endl<<endl<<endl;

 for (r=0; r<rows; ++r){
     for (c = 0; c < columns; ++c){

        if (   (r == 0) || (r == (rows - 1) ) || (c == 0) || (c == (columns - 1) ) ){


        state [r][c] = ' ';
    }
    }
     }
for (r = 1; r <= (rows - 2); ++r){//////////////////////
for (c = 1; c <= (columns - 2); ++c){ /////////////////////



for (m = (r - 1); m <= (r + 1); ++m){///222222222
for (n = (c - 1); n <= (c + 1); ++n){///22222222222

if (test[m][n] == 'A'){//////////3

    count++;

}///////////////////////////3

}///22
}////2
if (test[r][c] == 'A'){

    neighbors = (count - 1);
}

else if (test[r][c] == ' ') {

    neighbors = count;
}


if (test[r][c] == 'A'){

    if (  (neighbors == 2 ) || (neighbors == 3) ){

        state [r][c] = 'A';
    }
    else {

    state[r][c] = ' ';
    }


}

else if (test [r][c] == ' '){

    if (neighbors == 3) {

        state [r][c] = 'A';
    }

    else {
        state[r][c] = ' ';
    }


}

count =0;
neighbors =0;

cout <<" ["<<state[r][c]<<"]";
}/////////////////////////
cout <<endl;
}///////////////////////

for (r = 0; r < rows; r++){
for (c = 0; c < columns; c++){
test[r][c] = state[r][c];
}
}
Sleep(500);
system ("cls");

 cout <<endl<<endl;
}

cout << "THE  FINAL GENERATION IS    "<<endl<<endl<<endl;
for (r = 1; r <= (rows - 2); ++r){
for (c = 1; c <= (columns - 2); ++c){

cout << " ["<< state[r][c]<<"]";
}
cout <<endl;
}


cout<<endl<<endl<<endl;

cout <<"Thank you for playing the game of life! Hope to see you again soon!"<<endl;

return 0;
}



////Sleep(1000);

////system("cls");

































