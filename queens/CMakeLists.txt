add_library(queens include/queens/board/board.h src/board/board.c src/alg/solve.c include/queens/alg/solve.h)
target_include_directories(queens PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)