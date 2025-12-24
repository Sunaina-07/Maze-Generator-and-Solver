#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define wall '#'
//Defining maze size. It must be odd numbers so that boundary of maze is only walls
#define rows 33
#define cols 33

char Maze[rows][cols]; //Declaring a 2D array which will be the maze

//Function 1: Intializing the Maze
//To intialize all the elements of Maze to the wall character
void InitializeMaze()
{
    int i, j;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
        Maze[i][j] = wall;
}

//Function 2: Printing the Maze
void PrintMaze()
{
    int i, j;
    for(i=0; i<rows; i++)
    {

        for(j=0; j<cols; j++)
            printf("%c ", Maze[i][j]);
        printf("\n");
    }
}

//Function 3: Maze Generator
//To randomly knock down walls to create Maze paths
void GetMaze()
{
    int i, j;
    for(i=1; i<rows-1; i+=2) //Incrementing by two to keep walls in between
    {
        for(j=1; j<cols-1; j+=2)
        {
            Maze[i][j] = ' '; 
            if((i>1) && (j>1)) //Checking if both upper or left wall can be 'knocked down'
            {
                if(rand()%2) //Randomly generating either 0(for left wall) or 1(for upper wall)
                    Maze[i-1][j] = ' '; //Upper wall knocked down
                else
                    Maze[i][j-1] = ' '; //Left wall knocked down
            }
            else if((i>1)) 
                Maze[i-1][j] = ' ';
            else if((j>1))
                Maze[i][j-1] = ' ';
        }
    }
}

//Function 4: Solving the Maze
//Uses Recursive backtracking. 
int SolveMaze(int m, int n)
{
    if(Maze[m][n]==wall || Maze[m][n]=='.')
        return 0;
    
    if(Maze[m][n]=='E') //Checking if end(E) position found
        return 1;
    
    if(Maze[m][n]!= 'S') //Checking if in start(S) position so not to overwrite start position
        Maze[m][n] = '.';  // Dot(.) denotes the solution path
    
    //Recursive part: Checking in each of the four directions to find end position
    if(SolveMaze((m+1),n)) //Checking down
        return 1;
    if(SolveMaze(m, (n+1))) //Checking right
        return 1;
    if(SolveMaze((m-1), n)) //Checking up
        return 1;
    if(SolveMaze(m, (n-1))) //Checking left
        return 1;
    
    //End position not found then erasing the solution paths
    if(Maze[m][n]!='S') 
        Maze[m][n]=' ';
    
    return 0;
}

int main()
{
    srand(time(NULL));
    
    //Maze setup
    InitializeMaze();
    GetMaze();
    
    Maze[1][1] = 'S'; //Initialising the start position
    Maze[rows-2][cols-2] = 'E'; //Initialising the end position
    
    printf("Generating Maze....\n");
    PrintMaze();
    
    printf("\nSolving Maze...\n");
    if(SolveMaze(1,1))
    {
        printf("Maze Solved!\n");
        PrintMaze();
    }
    else
        printf("Maze unable to be solved.\n");
    
        return 0;
}