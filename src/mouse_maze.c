#include <stdio.h>


int in_maze(int row, int col, int nrow, int ncol);
int go_maze(int maze[100][100], int step, int current_row, int current_col,
            int end_row, int end_col, int nrow, int ncol);


int in_maze(int row, int col, int nrow, int ncol)
{
        return row >= 0 && row < nrow && col >= 0 && col < ncol;
}


int go_maze(int maze[100][100], int step, int current_row, int current_col,
            int end_row, int end_col, int nrow, int ncol)
{
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int d, next_row, next_col;

        if (current_row == end_row && current_col == end_col)
                return 1;

        for (d = 0; d < 4; ++d) {
                next_row = current_row + drow[d];
                next_col = current_col + dcol[d];
                if (in_maze(next_row, next_col, nrow, ncol) &&
                    maze[next_row][next_col] == 0) {
                        maze[next_row][next_col] = step;
                        if (go_maze(maze, step + 1, next_row, next_col,
                                    end_row, end_col, nrow, ncol) == 1) {
                                return 1;
                        }
                        maze[next_row][next_col] = 0;
                }
        }

        return 0;
}


int main()
{
        int nrow = 4, ncol = 5;

        /* Maze initialization
           0 = have a way
           -1 = no way
         */
        int maze[100][100] = {
                {0, 0, 0, -1, 0},
                {0, 0, 0, 0, 0},
                {0, -1, 0, -1, 0},
                {-1, 0, -1, 0, 0}
        };
        int i, j;
        int start_row = 0, start_col = 0;
        int end_row = 3, end_col = 4;

        maze[start_row][start_col] = 1;
        go_maze(maze, 2, start_row, start_col, end_row, end_col, nrow, ncol);

        for (i = 0; i < nrow; ++i) {
                for (j = 0; j < ncol; ++j) {
                        printf("%2d ", maze[i][j]);
                }
                printf("\n");
        }

        return 0;
}
