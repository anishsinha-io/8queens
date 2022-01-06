#include <stdbool.h>
#include <stdio.h>
#include "queens/board/board.h"

bool is_safe(Board *b, unsigned int row_index, unsigned int col_index) {
    unsigned int rows = row_count(b);
    for (int i = 0; i < col_index; i++) {
        if (*get(b, row_index, i) == 'Q') return false;
    }
    for (int i = (int) row_index, j = (int) col_index; i >= 0 && j >= 0; i--, j--) {
        if (*get(b, i, j) == 'Q') return false;
    }
    for (int i = (int) row_index, j = (int) col_index; i >= 0 && j >= 0; i++, j--) {
        if (i >= rows) break;
        if (*get(b, i, j) == 'Q') return false;
    }
    return true;
}

bool place_queen(Board *b, unsigned int col_index, const unsigned int *n_queens) {
    if (col_index == *n_queens) return true;
    for (int row_index = 0; row_index < *n_queens; row_index++) {
        if (is_safe(b, row_index, col_index)) {
            set_queen(b, row_index, col_index);
            printf("Placed queen at: {%d, %d}\n", row_index, col_index);
            if (place_queen(b, col_index + 1, n_queens)) return true;
            printf("Backtracking from: {%d, %d}\n", row_index, col_index);
            remove_queen(b, row_index, col_index);
        }
    }
    return false;
}

void solve(unsigned int n_queens) {
    Board *b = initialize_board(n_queens, n_queens);
    if (!place_queen(b, 0, &n_queens)) {
        printf("no solution");
        return;
    }
    display_board(b);
}