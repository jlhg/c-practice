#include <stdio.h>
#include <stdlib.h>

void palce_queen(const int col, int queen_pos[], const int max_col);

void place_queen(const int col, int queen_pos[], const int max_col)
{
        int i, row, conflict;

        if (col == max_col) {
                for (i = 0; i < max_col; ++i) {
                        printf("%d ", queen_pos[i]);
                }
                printf("\n");
                return;
        }

        for (row = 0; row < max_col; ++row) {
                conflict = 0;
                for (i = 0; i < col && !conflict; ++i) {
                        if (queen_pos[i] == row || abs(row - queen_pos[i]) == (col - i)) {
                                conflict = 1;
                        }
                }

                if (!conflict) {
                        queen_pos[col] = row;
                        place_queen(col + 1, queen_pos, max_col);
                }

        }

}

int main()
{
        int max_col = 8;
        int queen_pos[max_col];
        place_queen(0, queen_pos, max_col);

        return 0;
}
