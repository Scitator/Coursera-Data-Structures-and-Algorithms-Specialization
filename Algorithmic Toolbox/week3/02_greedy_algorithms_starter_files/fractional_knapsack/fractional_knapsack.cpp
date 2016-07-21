#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using std::vector;
using std::pair;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  int n = weights.size();
  vector<pair<int, int> > itemWeightValuePairs(n);
  for (int i = 0; i < n; i++) {
    // itemWeightValuePairs.push_back(std::make_pair(weights[i], values[i]));
    itemWeightValuePairs[i].first = weights[i];
    itemWeightValuePairs[i].second = values[i];
    // std::cout << itemWeightValuePairs[i].first << "; " << itemWeightValuePairs[i].second << std::endl;
  }
  std::sort(itemWeightValuePairs.begin(), itemWeightValuePairs.end(), 
    [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
      return double(a.second)/a.first > double(b.second)/b.first;
    });


  for (int i = 0; i < n; i++) {
    // std::cout << itemWeightValuePairs[i].first << "; " << itemWeightValuePairs[i].second << std::endl;
    if (capacity == 0) {
      return value;
    }
    int a = std::min(itemWeightValuePairs[i].first, capacity);
    value += a * double(itemWeightValuePairs[i].second)/itemWeightValuePairs[i].first;
    capacity -= a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
