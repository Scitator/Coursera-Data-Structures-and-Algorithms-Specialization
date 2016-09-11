#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here

  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int knapsack(int W, const vector<int> &w) {
  vector< vector<int> > values (w.size() + 1, vector<int>(W + 1));

  for (size_t i = 1; i <= w.size(); ++i) {
    for (size_t j = 1; j <= W; ++j) {
      if (w[i-1] <= j) {
        values[i][j] = std::max(values[i - 1][j - w[i-1]] + w[i-1],
                                values[i - 1][j]);
      } else {
        values[i][j] = values[i - 1][j];
      }
    }
  }
  return values[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << knapsack(W, w) << '\n';
}
