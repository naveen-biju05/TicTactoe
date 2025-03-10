#include <stdio.h>
#include <stdlib.h>

void drawBoard();
int checkWin();
void resetBoard();

char board[3][3];
char player = 'X';

int main() {
    int row, col;
    int moves = 0;
    int gameOver = 0;

    resetBoard();

    printf("TIC TAC TOE GAME\n");
    printf("Player 1: X\nPlayer 2: O\n\n");

    while (!gameOver) {
        drawBoard();

        printf("Player %c, enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        if (board[row - 1][col - 1] != ' ') {
            printf("Cell already occupied! Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = player;
        moves++;

        if (checkWin()) {
            drawBoard();
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (moves == 9) {
            drawBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void drawBoard() {
    system("clear");
    printf("\n");
    printf("  1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}
