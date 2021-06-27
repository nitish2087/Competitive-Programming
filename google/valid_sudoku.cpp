#include<bits/stdc++.h>
using namespace std;
bool UsedInRow(int v[][9], int row, int num) 
{ 
    for (int col = 0; col < 9; col++) 
        if (v[row][col] == num) 
            return true; 
    return false; 
} 
bool UsedInCol(int v[][9], int col, int num) 
{ 
    for (int row = 0; row < 9; row++) 
        if (v[row][col] == num) 
            return true; 
    return false; 
}
bool UsedInBox(int v[][9], int boxStartRow, int boxStartCol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (v[row + boxStartRow][col + boxStartCol] == num) 
                return true; 
    return false; 
}




bool FindUnassignedLocation(int v[][9], int& row, int& col){ 
    for (row = 0; row < 9; row++) 
        for (col = 0; col < 9; col++) 
            if (v[row][col] == 0) 
                return true; 
    return false; 
}

bool isSafe(int v[][9], int row, int col, int num){ 
    return !UsedInRow(v, row, num) && !UsedInCol(v, col, num) && !UsedInBox(v, row - row % 3, col - col % 3, num) 
           && v[row][col] == 0; 
}



bool isValidMAt(int v[][9]){
    int row, col;  
    if (!FindUnassignedLocation(v, row, col)) return true;  
    for (int num = 1; num <= 9; num++) { 
        if (isSafe(v, row, col, num)) { 
            v[row][col] = num; 
            if (isValidMAt(v)) return true; 
            v[row][col] = 0; 
        } 
    }  
    return false;      
}

void printGrid(int v[][9]) 
{ 
    for (int row = 0; row < 9; row++) { 
        for (int col = 0; col < 9; col++) 
            cout << v[row][col] << " "; 
        cout << endl; 
    } 
} 

int main(){
    int v[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
               cin>>v[i][j];
    if (isValidMAt(v) == true) 
            printGrid(v); 
    else
        cout << "No solution exists";
    return 0;
}