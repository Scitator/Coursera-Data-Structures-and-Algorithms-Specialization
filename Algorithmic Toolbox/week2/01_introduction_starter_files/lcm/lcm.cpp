#include <iostream>

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  // int a_prime = b % a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  //write your code here
  // std::cout << a*b << std::endl;
  // std::cout << gcd(a,b) << std::endl;
  return std::abs(a*b)/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
