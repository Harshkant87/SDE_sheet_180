// You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.

#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	vector<pair<int,int>>indexHash;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		{
			if(matrix[i][j] == 0){
				indexHash.push_back({i, j});
			}
		}
	}

	int indexLength = indexHash.size();
	for(int i = 0; i < indexLength; i++){
		int row = indexHash[i].first;
		int col = indexHash[i].second;

		for(int c = 0; c < m; c++) //nullifying row
			matrix[row][c] = 0;

		for(int r = 0; r < n; r++) //nullifying column
			matrix[r][col] = 0;
	}

	return matrix;

}