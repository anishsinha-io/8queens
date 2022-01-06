#include <stdlib.h>
#include <stdio.h>

typedef struct Board {
    unsigned int rows;
    unsigned int cols;
    char **data;
} Board;

static Board *construct_board(unsigned int rows, unsigned int cols) {
    Board *board = malloc(sizeof(Board));
    board->rows = rows;
    board->cols = cols;
    char **data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        data[i] = calloc(cols, sizeof(char));
    }
    board->data = data;
    return board;
}

Board *initialize_board(unsigned int rows, unsigned int cols) {
    return construct_board(rows, cols);
}

static void set(Board *b, unsigned int row_index, unsigned int col_index, const char *val) {
    if (b->rows <= row_index || b->cols <= col_index) {
        printf("requested indices {%d, %d} out of bounds for board!", row_index, col_index);
        return;
    }
    b->data[row_index][col_index] = *val;
}

void set_queen(Board *b, unsigned int row_index, unsigned int col_index) {
    char q = 'Q';
    set(b, row_index, col_index, &q);
}

void remove_queen(Board *b, unsigned int row_index, unsigned int col_index) {
    char z = 0;
    set(b, row_index, col_index, &z);
}

char *get(Board *b, unsigned int row_index, unsigned int col_index) {
    if (b->rows <= row_index || b->cols <= col_index) {
        printf("requested indices {%d, %d} out of bounds for board! \nReturning null pointer.\n", row_index, col_index);
        return NULL;
    }
    return &b->data[row_index][col_index];
}

unsigned int row_count(Board *b) {
    return b->rows;
}

unsigned int col_count(Board *b) {
    return b->cols;
}

void display_board(Board *b) {
    printf("\n");
    for (unsigned int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            printf("%c\t", b->data[i][j]);
        }
        printf("\n");
    }
}
