#include <stdio.h>

// Function to draw the game board
void drawBoard(char board[][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to get player's move and mark the board
void getPlayerMove(char board[][3], char mark) {
    int row, col;
    do {
        printf("Enter row (1, 2, or 3) and column (1, 2, or 3) of your move: ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (board[row][col] != ' ')
            printf("This cell is already taken. Try again.\n");
        else
            board[row][col] = mark;
    } while (board[row][col] == ' ');
}

// Function to check if there is a winner or a draw
int checkWin(char board[][3], char mark) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return 1;
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
            return 1;
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return 1;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 2;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};  // Initialize game board
    int player = 1, winner, i;
    char mark;
    printf("Tic Tac Toe\n\n");
    do {
        drawBoard(board);  // Draw the board
        mark = (player == 1) ? 'X' : 'O';  // Set player's mark
        getPlayerMove(board, mark);  // Get player's move and mark the board
        winner = checkWin(board, mark);  // Check if there is a winner or a draw
        player = (player == 1) ? 2 : 1;  // Switch player
    } while (winner == 0);
    drawBoard(board);
    if (winner == 1)
        printf("\nPlayer %d (%c) wins!\n", player, mark);
    else
        printf("\nDraw!\n");
    return 0;
}