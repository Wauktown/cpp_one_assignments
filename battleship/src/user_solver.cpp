#include <iostream>
#include "../include/user_solver.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

void UserSolver::solve(Board &board) {
    // Your Implementation goes here
    ReturnType t = guess(1, 1, board);
    std::cout << t << std::endl;
}
