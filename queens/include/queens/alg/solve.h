#include <stdbool.h>
#include "queens/board/board.h"

#ifndef INC_8QUEENS_SOLVE_H
#define INC_8QUEENS_SOLVE_H

bool is_safe(Board *b, unsigned int, unsigned int);
void solve(unsigned int);

#endif //INC_8QUEENS_SOLVE_H
