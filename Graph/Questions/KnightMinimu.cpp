/*In this problem, we are given an infinite chess board that can be imagined as an endless grid with coordinates ranging from negative infinity to positive infinity. We have a chess piece—a knight—placed at the origin [0, 0] of this 
grid. The objective is to calculate the minimum 
number of moves that the knight must make to reach a 
specific square [x, y] on the chessboard.

A knight in chess moves in an L-shape: it can move 
two squares in one direction (either horizontally or 
vertically) and then make a 90-degree turn to move 
one square in a perpendicular direction. This gives 
the knight a total of eight possible moves at any 
given point.

The problem requires us to determine the least 
number of moves necessary to get the knight from its 
starting position [0, 0] to any target coordinates 
[x, y]. The question assures that it is always 
possible to reach the target square.*/

#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Offset the x and y to avoid negative index issues.
        // The number 310 is chosen to handle negative coordinates 
        // because a knight cannot be more than 310 moves away from the origin in any direction.
        x += 310;
        y += 310;

        // Initialize the answer to 0, which represents the number of moves.
        int minMoves = 0;
        std::queue<std::pair<int, int>> queue; // Queue to manage BFS.
        queue.push({310, 310}); // Starting point (0,0) with the offset.

        // Visited matrix to keep track of visited cells.
        std::vector<std::vector<bool>> visited(700, std::vector<bool>(700, false));
        visited[310][310] = true; // Mark the starting point as visited.

        // Directions a knight can move on a chessboard.
        std::vector<std::vector<int>> directions = {
            {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
        };

        // BFS Algorithm.
        while (!queue.empty()) {
            // Traverse nodes level by level.
            for (int size = queue.size(); size > 0; --size) {
                auto current = queue.front();
                queue.pop();

                // Check if we have reached the target (x, y) cell.
                if (current.first == x && current.second == y) return minMoves;
              
                // Explore all possible moves from the current position.
                for (auto& direction : directions) {
                    int nextRow = current.first + direction[0];
                    int nextCol = current.second + direction[1];

                    // If the cell is not visited, mark it visited and add to the queue.
                    if (!visited[nextRow][nextCol]) {
                        visited[nextRow][nextCol] = true;
                        queue.push({nextRow, nextCol});
                    }
                }
            }
            // Increment the number of moves after exploring all positions in current level.
            ++minMoves;
        }
      
        // If the function hasn't returned yet, something went wrong.
        // With the BFS approach, however, we should always be able to return before hitting this line.
        return -1;
    }
};