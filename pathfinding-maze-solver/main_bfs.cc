#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

template <typename T>
using Vec2D = std::vector<std::vector<T>>;

// Define a structure to represent coordinates in the maze
struct Point {
  int x, y;
};

constexpr auto isValid(const int x, const int y,
                       const Vec2D<int>& maze) -> bool {
  const std::size_t rows = maze.size();
  const std::size_t cols = maze[0].size();

  return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}

// Function to initialize a random maze
auto initializeRandomMaze(Vec2D<int>& maze, const int rows, const int cols,
                          Point& start, Point& end) -> void {
  for (auto& el : maze) {
    for (auto& i : el) {
      i = 0;
    }
  }

  // Set start and end points
  start = {0, 0};
  end = {rows - 1, cols - 1};

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (!(i == start.x && j == start.y) && !(i == end.x && j == end.y)) {
        maze[i][j] = std::rand() % 2;  // Generate random walls/passages
      }
    }
  }

  maze[start.x][start.y] = 0;  // Start point
  maze[end.x][end.y] = 0;      // End point
}

// Function to print the maze
void printMaze(const Vec2D<int>& maze) {
  for (const auto& row : maze) {
    for (int cell : row) {
      std::cout << (cell == 0 ? " " : "#")
                << " ";  // Print passages as space and walls as #
    }
    std::cout << "\n";
  }
}

// BFS function to find the shortest path in the maze
auto bfs(const Vec2D<int>& maze, std::vector<Point>& path, const Point start,
         const Point end) -> void {
  // set the directions
  static const std::vector<Point> directions = {
      {-1, 0}, {0, 1}, {1, 0}, {0, 1}};

  Vec2D<bool> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
  Vec2D<Point> parent(maze.size(), std::vector<Point>(maze[0].size()));

  std::queue<Point> q;
  q.push(start);

  visited[start.x][start.y] = true;

  while (!q.empty()) {
    Point curr = q.front();
    q.pop();

    if (curr.x == end.x && curr.y == end.y) {
      while (!(curr.x == start.x && curr.y == start.y)) {
        path.push_back(curr);
        curr = parent[curr.x][curr.y];
      }

      path.emplace_back(start);
      std::reverse(path.begin(), path.end());  // O(n)
      return;
    }

    for (const auto& [x, y] : directions) {
      const int new_y = curr.y + y;
      const int new_x = curr.x + x;
      if (isValid(new_x, new_y, maze) && !visited[new_x][new_y]) {
        q.push({new_x, new_y});
        visited[new_x][new_y] = true;
        parent[new_x][new_y] = curr;
      }
    }
  }

}  // bfs

int main(int argc, char* argv[]) {
  // Define maze dimensions
  constexpr int rows = 10000;
  constexpr int cols = 10000;

  Vec2D<int> maze(rows, std::vector<int>(cols, 0));

  // Initialize random maze
  Point start{}, end{};
  initializeRandomMaze(maze, rows, cols, start, end);

#ifdef DEBUG
  printMaze(maze);
#endif

  std::vector<Point> path;
  bfs(maze, path, start, end);

  if (path.empty()) {
    std::cout << "No path found!" << "\n";
  } else {
    std::cout << "Path found:" << "\n";
    for (const Point& p : path) {
      std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\n";
  }
  return 0;
}