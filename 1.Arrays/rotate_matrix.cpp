#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    //transposing
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);
    
    // reversing each row
    for(int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

}