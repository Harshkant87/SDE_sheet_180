bool isSafe(int row, int col, int num, int board[][9]){
    for(int i = 0; i < 9; i++){
        if(board[row][i] == num)
            return false;
        
        if(board[i][col] == num)
            return false;
        
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) // for inner square
            return false;
    }
    return true;
}

bool sudokuSolver(int board[][9]) {
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Don't print output and return output as specified in the question
    */
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                for(int num = 1; num <= 9; num++){
                    if(isSafe(i, j, num, board)){
                        board[i][j] = num;

                        if(sudokuSolver(board))
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}