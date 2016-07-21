#include <iostream>

int calc_fib(int n) {
	if ( n <= 1) {
		return n;
	}

	long long fib_prev = 0,
				fib_curr = 1,
				fib_tmp = 1;
    for (int i = 1; i < n; ++i) {
    	fib_tmp = fib_curr + fib_prev;
    	fib_prev = fib_curr;
    	fib_curr = fib_tmp;
    }
    return fib_curr;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
