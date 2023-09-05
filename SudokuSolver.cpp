#include <bits/stdc++.h> 
using namespace std; 


bool isSafe(int N,vector<vector<int>>&board,int row, int col, int num) 
    { 
     
        for (int d = 0; d < N; d++)  
        { 
            
            if (board[row][d] == num) { 
                return false; 
            } 
        } 
  
        for (int r = 0; r < N; r++)  
        { 
               
            if (board[r][col] == num)  
            { 
                return false; 
            } 
        }  
        int s = (int)sqrt(N); 
        int boxRowStart = row - row % s; 
        int boxColStart = col - col % s; 
  
        for (int r = boxRowStart; 
             r < boxRowStart + s; r++)  
        { 
            for (int d = boxColStart; 
                 d < boxColStart + s; d++)  
            { 
                if (board[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true; 
    } 

bool solve( vector<vector<int>> &board,int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(n,board, row, col, num))  
            { 
                board[row][col] = num; 
                if (solve(board, n))  
                { 
                    // print(board, n); 
                    return true; 
                } 
                else 
                { 
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 

void printGrid(int N,vector<vector<int>> &grid) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 
 
int main() 
{ 
    int N;
    cin>>N;
    vector<vector<int>> board(N,vector<int>(N,0));
    for(int i =0;i<N;i++)
    {
        for(int j =0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
	if (solve(board,N) == true) 
		printGrid(N,board); 
	else
		cout << "No solution exists"; 

	return 0; 
} 

