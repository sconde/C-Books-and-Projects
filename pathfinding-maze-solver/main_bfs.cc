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

bool isValid(int x, int y, const std::vector<std::vector<int>>& maze) {
  int rows = maze.size();
  int cols = maze[0].size();

  return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}

// Function to initialize a random maze
std::vector<std::vector<int>> initializeRandomMaze(int rows, int cols,
                                                   Point& start, Point& end) {
  // Initialize maze grid with all passages (0)
  vector<vector<int>> maze(rows, vector<int>(cols, 0));

  // Random number generator
  mt19937 rng(time(nullptr));  // Seed with current time
  uniform_int_distribution<int> dist(
      0, 1);  // Uniform distribution for generating walls/passages

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
vector<Point> bfs(const std::vector<std::vector<int>>& maze, Point start,
                  Point end) {
  static const vector<Point> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, 1}};

  std::vector<std::vector<bool>> visited(maze.size(),
                                         vector<bool>(maze[0].size()), false);
  std::vector<std::vector<Point>> parent(maze.size(),
                                         vector<Point>(maze[0].size()));

  std::queue<Point> q;
  q.push(start);

  visited[start.x][start.y] = true;

  while (!q.empty()) {
    Point curr = q.front();

    q.pop();

    if (curr.x == end.x && curr.y == end.y) {
      // Destination reached, reconstruct the path
      vector<Point> path;

      while (!(curr.x == start.x && curr.y == start.y)) {
        path.push_back(curr);
        curr = parent[curr.x][curr.y];
      }

      path.push_back(start);
      reverse(path.begin(), path.end());
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

int int main(int argc, char* argv[]) {
  // Example maze represented as 2D grid {0 for passage, 1 for wall}
  std::vector<vector<int>> maze = {{0, 1, 0, 0, 0},
                                   {0, 1, 0, 1, 0},
                                   {0, 0, 0, 1, 0},
                                   {0, 1, 0, 0, 0},
                                   {0, 0, 0, 1, 0}};

  Point start = {0, 0};  // Start point
  Point end = {4, 4};    // End point

  std::vector<Point> path = bfs(maze, start, end);

  if (path.empty()) {
    cout << "No path found!" << endl;
  } else {
    cout << "Path found:" << endl;
    for (const Point& p : path) {
      cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
  }
  return 0;
}
return 0;
}
