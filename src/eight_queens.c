#include <stdio.h>
#include <stdlib.h>


typedef struct {
        int board_size;
        char** checkerboard;
        int *column;
        int *right;
        int *left;
} ChessBoard;


int queens(ChessBoard *chessboard, int x, int *num);
void print(ChessBoard *chessboard);


int queens(ChessBoard *chessboard, int x, int *num) {
        int n = chessboard->board_size;
        if (x < n) {
                int i;
                for (i = 0; i < n; ++i) {
                        int j = i - x + n - 1;
                        int k = i + x;

                        if (chessboard->column[i] &&
                            chessboard->right[j] &&
                            chessboard->left[k]) {
                                chessboard->column[i] = 0;
                                chessboard->right[j] = 0;
                                chessboard->left[k] = 0;
                                chessboard->checkerboard[x][i] = 'Q';

                                queens(chessboard, x + 1, num);

                                chessboard->column[i] = 1;
                                chessboard->right[j] = 1;
                                chessboard->left[k] = 1;
                                chessboard->checkerboard[x][i] = 'x';
                        }
                }
        } else {
                print(chessboard);
                ++*num;
        }

}


void print(ChessBoard *chessboard)
{
    int i, j;

    printf("\n");
    for(i = 0; i < chessboard->board_size; i++) {
        for(j = 0; j < chessboard->board_size; j++) {
                printf("%c", chessboard->checkerboard[i][j]);
        }
        printf("\n");
    }
}


int main()
{
        int i, j;
        int n = 10;
        int x = 0;
        int *num = malloc(sizeof(int));
        *num = 0;

        ChessBoard *chessboard = malloc(sizeof(ChessBoard));
        chessboard->board_size = n;
        chessboard->column = malloc(sizeof(int) * n);
        chessboard->right = malloc(sizeof(int) * (2 * n - 1));
        chessboard->left = malloc(sizeof(int) * (2 * n - 1));
        chessboard->checkerboard = malloc(sizeof(char*) * n);

        for (i = 0; i < n; ++i) {
                chessboard->column[i] = 1;
                chessboard->checkerboard[i] = malloc(sizeof(char) * n);
                for (j = 0; j < n; ++j) {
                        chessboard->checkerboard[i][j] = 'x';
                }
        }

        for (i = 0; i < 2 * n - 1; ++i) {
                chessboard->right[i] = 1;
                chessboard->left[i] = 1;
        }

        queens(chessboard, x, num);

        printf("\n總共有 %d 種排法\n\n", *num);

        for (i = 0; i < n; ++i) {
                free(chessboard->checkerboard[i]);
        }

        free(chessboard->checkerboard);
        free(chessboard->column);
        free(chessboard->right);
        free(chessboard->left);

        return 0;
}
