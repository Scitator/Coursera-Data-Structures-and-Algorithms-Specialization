#include <iostream>

#define really_long unsigned long long int

really_long get_period(really_long n, really_long m) {
  really_long period = 2;
  really_long x, a = 1;
  really_long b = 2;
  while (true) {
    x = a;
    a = b;
    b = a + x;
    if ((x % m == 0) && (a % m == 1)) {
      break;
    }
    ++period;
  }
  return period;
}

really_long get_fibonacci_last_digit(really_long n, really_long m) {
  	if ( n <= 1) {
		return n;
	}

	really_long fib_prev = 0,
				fib_curr = 1,
				fib_tmp = 1;
    for (int i = 1; i < n; ++i) {
    	fib_tmp = (fib_curr + fib_prev) % m;
    	fib_prev = fib_curr;
    	fib_curr = fib_tmp;
    }
    return fib_curr;
}

really_long get_fibonaccihuge(really_long n, really_long m) {
  //write your code here
  really_long pisano_period = get_period(n, m);
  // std::cout << pisano_period << std::endl;
  return get_fibonacci_last_digit(n % pisano_period, m);
}

int main() {
    really_long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
