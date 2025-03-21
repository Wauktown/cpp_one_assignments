#include <iostream>
#include "../include/user_solver.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

void UserSolver::solve(Board &board) {
    // Come back to this for refernce if you get lost or go back to classnotes 2 or 3
    // ReturnType test = guess(0, 0, board);
    // std::cout << "Return type: " << static_cast<int>(test) << std::endl;

    int x_size = board.getX();
    int y_size = board.getY();
    int ships_found = 0;
    const int TOTAL_SHIPS = 5;

   
    std::unordered_set<std::pair<int, int>, pair_hash> visited;

    
    std::queue<std::pair<int, int>> to_check;

    
    int step_size = 30;

    
    for (int i = 0; i < x_size; i += step_size) {
        for (int j = 0; j < y_size; j += step_size) {
            to_check.push(std::make_pair(i, j));
        }
    }

    
    while (!to_check.empty() && ships_found < TOTAL_SHIPS) {
        std::pair<int, int> current = to_check.front();
        int x = current.first;
        int y = current.second;
        to_check.pop();

       
        if (visited.find(std::make_pair(x, y)) != visited.end()) {
            continue;
        }

       
        ReturnType result = guess(x, y, board);
        visited.insert(std::make_pair(x, y));

        
        
        if (result == 0) {  
            ships_found++;

            const int dx[] = {1, 0, -1, 0};
            const int dy[] = {0, 1, 0, -1};

            for (int dir = 0; dir < 4; dir++) {
                int nx = x;
                int ny = y;

                
                while (true) {
                    nx += dx[dir];
                    ny += dy[dir];

                    
                    if (nx < 0 || nx >= x_size || ny < 0 || ny >= y_size ||
                        visited.find(std::make_pair(nx, ny)) != visited.end()) {
                        break;
                    }

                    
                    ReturnType dir_result = guess(nx, ny, board);
                    visited.insert(std::make_pair(nx, ny));

                    if (dir_result == 0) {  
                        
                    } else {
                        if (dir_result == 2) {  
                            
                            const int adj_dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
                            const int adj_dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

                            for (int i = 0; i < 8; i++) {
                                int adj_x = nx + adj_dx[i];
                                int adj_y = ny + adj_dy[i];

                                
                                if (adj_x >= 0 && adj_x < x_size && adj_y >= 0 && adj_y < y_size &&
                                    visited.find(std::make_pair(adj_x, adj_y)) == visited.end()) {
                                    to_check.push(std::make_pair(adj_x, adj_y));
                                }
                            }
                        }
                       
                        break;
                    }
                }
            }
        } else if (result == 2) {  
            
            const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
            const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                
                if (nx >= 0 && nx < x_size && ny >= 0 && ny < y_size &&
                    visited.find(std::make_pair(nx, ny)) == visited.end()) {
                    to_check.push(std::make_pair(nx, ny));
                }
            }
        }

        
        if (to_check.empty() && ships_found < TOTAL_SHIPS) {
            
            step_size = std::max(step_size / 2, 1);

            for (int i = 0; i < x_size; i += step_size) {
                for (int j = 0; j < y_size; j += step_size) {
                    if (visited.find(std::make_pair(i, j)) == visited.end()) {
                        to_check.push(std::make_pair(i, j));
                    }
                }
            }
        }
    }
}
