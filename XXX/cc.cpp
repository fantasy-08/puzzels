#include <bits/stdc++.h> 
using namespace std; 
  
// UNASSIGNED is used for empty cells in sudoku grid  
#define UNASSIGNED 0    
#define N 2000
int n;
int grid[N][N];
bool FindUnassignedLocation(int grid[N][N],  
                            int &row, int &col);  
bool isSafe(int grid[N][N], int row, 
                   int col, int num);  

bool SolveSudoku(int grid[N][N])  
{  
    int row, col;  
 
    if (!FindUnassignedLocation(grid, row, col))  
    return true; // success!  
 
    for (int num = (2*n-1); num >=0; num--)  
    {  
        
        if (isSafe(grid, row, col, num))  
        {  
            // make tentative assignment  
            grid[row][col] = num;  
  
            // return, if success, yay!  
            if (SolveSudoku(grid))  
                return true;  
  
            // failure, unmake & try again  
            grid[row][col] = UNASSIGNED;  
        }  
    }  
    return false; // this triggers backtracking  
}  
bool FindUnassignedLocation(int grid[N][N],  
                            int &row, int &col)  
{  
    for (row = 0; row < n; row++)  
        for (col = 0; col < n; col++)  
            if (grid[row][col] == UNASSIGNED)  
                return true;  
    return false;  
}  

bool UsedInRow(int grid[N][N], int row,int col, int num)  
{  
    for (int i = 0; i < n; i++)  
        if (grid[row][i] == num)  
            return true;
    for (int i = 0; i < n; i++)  
        if (grid[i][row] == num)  
            return true;    
    return false;  
}  

bool UsedInCol(int grid[N][N],int row, int col, int num)  
{  
    for (int i = 0; i < n; i++)  
        if (grid[i][col] == num)  
            return true;
    for (int i = 0; i < n; i++)  
        if (grid[col][i] == num)  
            return true;  
    return false;  
}  

bool UsedInBox(int grid[N][N], int boxStartRow, 
               int boxStartCol, int num)  
{  
    for (int row = 0; row < n; row++)  
        for (int col = 0; col < n; col++)  
            if (grid[row + boxStartRow] 
                    [col + boxStartCol] == num)  
                return true;  
    return false;  
}  

bool isSafe(int grid[N][N], int row,  
                   int col, int num)  
{  
  
    return !UsedInRow(grid, row,col, num) &&  
           !UsedInCol(grid,row, col, num) &&  
            grid[row][col] == UNASSIGNED;  
}  
  
void printGrid(int grid[N][N])  
{  
    for (int row = 0; row < n; row++)  
    {  
    for (int col = 0; col < n; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  
int main()  
{  int test;
    cin>>test;
    while(test--){
    cin>>n;  
    //int grid[N][N];
    memset(grid,0,sizeof(int)*n*n);
    
    if (SolveSudoku(grid) == true)
    {   cout<<"Hooray\n";
        printGrid(grid);  }
    else
        cout << "Boo\n";  
    cin>>n;
    }

    return 0;  
} 