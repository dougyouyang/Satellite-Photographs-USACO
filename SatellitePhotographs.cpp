//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
char mat[1010][100];

int rec(int row, int col)
{
    int sum=1;
    mat[row][col]='.';
    if(mat[row][col+1]=='*')
        sum+=rec(row, col+1);
    if(mat[row][col-1]=='*')
        sum+=rec(row, col-1);
    if(mat[row+1][col]=='*')
        sum+=rec(row+1, col);
    if(mat[row-1][col]=='*')
        sum+=rec(row-1, col);
    
    return sum;
}

int main()
{
    int w, h, m=0;
    int i, j;
    
    cin >> w >> h;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            cin >> mat[i][j];
        }
    }
    
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(mat[i][j]=='*'){
                m=max(m, rec(i,j));
            }
        }
    }
    
    cout << m << endl;
    
    return 0;
}
