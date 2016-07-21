#include <algorithm>
#include <iostream>
#include <vector>

#include <algorithm>
#include <functional>

using std::vector;

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  std::sort(a.begin(), a.end(), 
    [](const int &i1, const int &i2) -> bool {
      return i1 > i2;
    });
  std::sort(b.begin(), b.end(), 
    [](const int &i1, const int &i2) -> bool {
      return i1 < i2;
    });
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}