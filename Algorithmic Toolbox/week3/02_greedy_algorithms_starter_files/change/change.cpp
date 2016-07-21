#include <iostream>

int get_change(int m) {
  //write your code here
	int n10 = m % 10;
	int n5 = n10 % 5;
  	return m / 10 + n10 / 5 + n5;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
