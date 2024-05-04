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

auto isValid(int x, int y, const Vec2D<int>& maze) -> bool {
  std::size_t rows = maze.size();
  std::size_t cols = maze[0].size();

  return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}

// Function to initialize a random maze
auto initializeRandomMaze(int rows, int cols, Point& start,
                          Point& end) -> Vec2D<int> {
  // Initialize maze grid with all passages (0)
  Vec2D<int> maze(rows, std::vector<int>(cols, 0));

  // Random number generator
  std::mt19937 rng(time(nullptr));  // Seed with current time
  // Uniform distribution for generating walls/passages
  std::uniform_int_distribution<int> dist(0, 1);

  // Set start and end points
  start = {0, 0};
  end = {rows - 1, cols - 1};
  maze[start.x][start.y] = 0;  // Start point
  maze[end.x][end.y] = 0;      // End point

  // Randomly generate walls in the maze
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (!(i == start.x && j == start.y) && !(i == end.x && j == end.y)) {
        maze[i][j] = dist(rng);  // Generate random walls/passages
      }
    }
  }

  return maze;
}
// BFS function to find the shortest path in the maze
auto bfs(const Vec2D<int>& maze, Point start, Point end) -> std::vector<Point> {
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
      // Destination reached, reconstruct the path
      std::vector<Point> path;

      while (!(curr.x == start.x && curr.y == start.y)) {
        path.push_back(curr);
        curr = parent[curr.x][curr.y];
      }

      path.push_back(start);
      std::reverse(path.begin(), path.end());
      return path;
    }

    for (const Point& dir : directions) {
      int new_x = curr.x + dir.x;
      int new_y = curr.y + dir.y;
      if (isValid(new_x, new_y, maze) && !visited[new_x][new_y]) {
        q.push({new_x, new_y});
        visited[new_x][new_y] = true;
        parent[new_x][new_y] = curr;
      }
    }
  }

  // no path found
  return {};

}  // bfs

int main(int argc, char* argv[]) {
  // Define maze dimensions
  constexpr int rows = 5;
  constexpr int cols = 5;

  // Initialize random maze
  Point start{}, end{};
  Vec2D<int> maze = initializeRandomMaze(rows, cols, start, end);

  std::vector<Point> path = bfs(maze, start, end);

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