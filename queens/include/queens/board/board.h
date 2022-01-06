
#ifndef SRC_BOARD_H
#define SRC_BOARD_H

typedef struct Board Board;

Board *initialize_board(unsigned int, unsigned int);
void display_board(Board *);
void set_queen(Board *, unsigned int, unsigned int);
void remove_queen(Board *, unsigned int, unsigned int);
char *get(Board *, unsigned int, unsigned int);
unsigned int row_count(Board *);
unsigned int col_count(Board *);

#endif //SRC_BOARD_H
