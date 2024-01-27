#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;

const int genlim = 50;
int rows = 10;
int columns = 20;

char gen1[25][25] ;
char gen2[25][25] ;

int customgridrows();
int customgridcolumns();
void grid(int r, int c);

int main()
{
//instructions of game of life
    cout << "_______   Welcome to the game of life!   _______" << endl << endl;
    cout << "1. A live cell with fewer than two live neighbors dies." << endl;
    cout << "2. A live cell with more than three live neighbors also dies." << endl;
    cout << "3. A live cell with exactly two or three live neighbors lives." << endl;
    cout << "4. A dead cell with exactly three live neighbors becomes alive." << endl << endl;
    cout << "Project Members: Javeria Rehman | Alishbah Khalid | Umer Nadeem." << endl;

    char gridchoice;

//input of rows and columns
    cout << "\nWould you like to make your custom grid for the game of life? (Enter y/n): ";
    cin >> gridchoice;
    if (gridchoice == 'y')
    {
        cout << "Enter grid size in the range 1x1 to 10x40: " << endl;
        
        rows = customgridrows();
        if (rows > 10)
        {
            cout << endl << "Your input should be in the range 1 to 10" << endl;
            cout << "Program terminated. Please start again." << endl;
        }
        else
        {
        columns = customgridcolumns();
        if (columns > 40)
        {
            cout << endl << "Your input should be in the range 1 to 40" << endl;
            cout << "Program terminated. Please start again." << endl;
        }

        else
        {
            cout << endl << "Grid size: " << rows << "x" << columns << endl;
            cout << endl;

            grid(rows, columns);  //calling grid function to build the required sized grid
            cout << endl << endl;
            cout << endl;
        }//grid column size condition else ends
        }//grid row size condition else ends

    }
    

//Initial Grid output
    int rowss = rows;
    int columnss = columns;
    

//Choice for computer generated grid or a user entered grid
    char statechoice = 'n';
    int v, h;
    char  choiceenterstate = 'y';
    cout << "Would you like to Enter the state of the cells yourself or would you like the computer to generate a random grid for you?" << endl;
    cout << "If you want to enter the state yourself ENTER y. Otherwise enter n: ";
    cin >> statechoice;
    cout <<endl;

    if (statechoice == 'y')
    {
        for(int i=0; i<rowss; i++)
        {
            for(int j=0; j<columnss; j++)
            {
                gen1[i][j] = ' ';
            }
        }
        //
        int inputCells,cCol, cRow;
        cout << "Enter the number of cells you want to mark 'alive': ";
        cin >> inputCells;

        if (inputCells > rows*columns)
        {
            cout << endl << "Your input should be in the range 1 and " << rows*columns <<"." << endl;
            cout << "Program terminated. Please start again." << endl;
        }

        else
        {
            cout << "Start entering the coordinates of those cells one-by-one" << endl;
            cout << "(The coordinates should be according to the size of the grid i.e. " << rows << "x" << columns << endl << endl;
            
            for(int i=0; i<inputCells; i++)
            {
                cout << "Cell number " << i+1 << ":" << endl;
                cout << "Row number: ";
                cin >> cRow;
                if ( cRow < 0 || cRow >= rows) //condition for wrong row number
                {
                    cout << "Your row index should be in the range 0-" << rows-1;
                    cout << "Program terminated. Start again" << endl << endl;
                }
                else
                {
                    cout << "Column number: ";
                    cin >> cCol;
                    if ( cCol < 0 || cCol >= columns)   //condition for wrong column number
                    {
                        cout << "Your col index should be in the range 0-" << columns-1;
                        cout << "Program terminated. Start again" << endl << endl;
                    }
                    else
                    {
                        gen1[cRow][cCol] = '@';
                        cout << endl << endl;
                    }
                    cout << endl << endl << endl;
                }///
            }
        }
    }
    else
    {
        int r , c;
        srand(time(0));
        for (r=0; r<rowss; ++r)
        {
            for (c = 0; c < columnss; ++c)
            {
                if ((r == 0) || (r == (rowss - 1) ) || (c == 0) || (c == (columnss - 1)))
                {
                    gen1 [r][c] = ' ';
                }
            }
        }
                                                                    //enables compiler to give new output
        for ( r = 1; r < (rowss - 1) ; ++r)
        {
            for ( c = 1; c < (columnss - 1) ; ++c)
            {
                {
                int ran_v = (rand () % 2 + 0);
                if (ran_v == 1)
                {
                    gen1 [r][c] = '@';
                }
                else
                {
                    gen1 [r][c] = ' ';
                }
                }
            }
        }

        for(int j=0; j<rowss; j++)  //j = rows
        {
            cout << "   ";
            for(int i=0; i<columnss; i++)  //i = columns
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            cout << " " << j << " ";
            for(int i=0; i<columnss; i++)
            {
                cout << "| " << gen1[j][i] << " ";   //quadruple character
            }
            cout << "|" << endl;
        }
        cout << "   ";
        for(int i=0; i<columnss; i++)
        {
            cout << "+---";
        }
        cout << "+";
    }

    cout << endl << endl << endl;
//number of generations either input by user or set to 50
    int generations = 50;
    char genchoice = 'n';
    cout << "Do you want to enter the number of generations yourself? Enter y." << endl;
    cout << "Otherwise the number of generations will be set to 50: ";
    cin >> genchoice;
    cout << endl;

    if (genchoice == 'y')
    {
        cout<< "Please enter your desired number of generations between 1 and 50 (Once you click enter, the game will begin) : ";
        cin >> generations;
        cout << endl;
    }
    else
    {
        generations;
    }

//generation change
int gen;
int count = 0;
int neighbors;
int m , n;

    for ( gen = 0; gen< generations; gen++)
    {
    cout << "Generation number "<< gen + 1 << " is " <<endl<<endl<<endl;

     for (int r=0; r<rowss; ++r)
    {
        for (int c = 0; c < columnss; ++c)
        {
            if (   (r == 0) || (r == (rowss - 1) ) || (c == 0) || (c == (columnss - 1) ) )
            {
            gen2 [r][c] = ' ';
            }
        }
    }
    for (int r = 1; r <= (rowss - 2); ++r)
    {
        for (int c = 1; c <= (columnss - 2); ++c)
        {
            for (m = (r - 1); m <= (r + 1); ++m)
            {
                for (n = (c - 1); n <= (c + 1); ++n)
                {
                    if (gen1[m][n] == '@')
                    {
                    count++;
                    }
                }
            }
            if (gen1[r][c] == '@')
            {
                neighbors = (count - 1);
            }
            else if (gen1[r][c] == ' ')
            {
                neighbors = count;
            }
            if (gen1[r][c] == '@')
            {
                if (  (neighbors == 2 ) || (neighbors == 3) )
                {
                    gen2 [r][c] = '@';
                }
                else
                {
                    gen2[r][c] = ' ';
                }
            }
            else if (gen1 [r][c] == ' ')
            {
                if (neighbors == 3)
                {
                    gen2 [r][c] = '@';
                }
                else
                {
                    gen2[r][c] = ' ';
                }
            }
        count =0;
        neighbors =0;

        }
    }

    {
    cout << "   ";
    for(int i=0; i<columnss; i++)
    {
        if (i>9)
        {
            cout << " " << i << " ";
        }
        else
        {
            cout << "  " << i << " ";
        }
    }
    cout << endl;

    for(int j=0; j<rowss; j++)  //j = rows
    {
        cout << "   ";
        for(int i=0; i<columnss; i++)  //i = columns
        {
            cout << "+---";
        }
        cout << "+";
        cout << endl;
        cout << " " << j << " ";
        for(int i=0; i<columnss; i++)
        {
            cout << "| " << gen2[j][i] << " ";   //quadruple character
        }
        cout << "|" << endl;
    }
    cout << "   ";
    for(int i=0; i<columnss; i++)
    {
        cout << "+---";
    }
    cout << "+";
    }

    for (int r = 0; r < rowss ; r++)
    {
        for (int c = 0; c < columnss ; c++)
        {
        gen1[r][c] = gen2[r][c];
        }
    }
    Sleep(500);
    system ("cls");
    cout <<endl<<endl;
    }

    cout << "The Program has successfully come to an end!! :) :)";
    cout << endl;
    return 0;
}

int customgridrows()
{
    int r;
    cout << "Rows: ";
    cin >> r;
    return r;
}

int customgridcolumns()
{
    int c;
    cout << "Columns: ";
    cin >> c;
    return c;
}

void grid(int r, int c)
{
    char array[r][c];

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            array[i][j] = ' ';
        }
    }

    cout << "   ";
    for(int i=0; i<c; i++)
    {
        if (i>9)
        {
            cout << " " << i << " ";
        }
        else
        {
            cout << "  " << i << " ";
        }
    }
    cout << endl;

    for(int j=0; j<r; j++)  //j = rows
    {
        cout << "   ";
        for(int i=0; i<c; i++)  //i = columns
        {
            cout << "+---";
        }
        cout << "+";
        cout << endl;
        cout << " " << j << " ";
        for(int i=0; i<c; i++)
        {
            cout << "| " << array[j][i] << " ";   //quadruple character
        }
        cout << "|" << endl;
    }
    cout << "   ";
    for(int i=0; i<c; i++)
    {
        cout << "+---";
    }
    cout << "+";
}//grid func ends