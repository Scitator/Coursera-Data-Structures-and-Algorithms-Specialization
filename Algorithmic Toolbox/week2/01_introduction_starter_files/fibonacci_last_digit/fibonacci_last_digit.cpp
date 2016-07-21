#include <iostream>

int get_fibonacci_last_digit(int n) {
  	if ( n <= 1) {
		return n;
	}

	long long fib_prev = 0,
				fib_curr = 1,
				fib_tmp = 1;
    for (int i = 1; i < n; ++i) {
    	fib_tmp = (fib_curr + fib_prev) % 10;
    	fib_prev = fib_curr;
    	fib_curr = fib_tmp;
    }
    return fib_curr;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
