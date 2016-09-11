#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  size_t n = str1.length();
  size_t m = str2.length();
  vector< vector<int> > d (n + 1, vector<int>(m + 1));

  for (int i = 0; i <= n; ++i) {
  	d[i][0] = i;
  }

  for (int j = 0; j <= m; ++j) {
  	d[0][j] = j;
  }

  for (size_t j = 1; j <= m; ++j) {
  	for (size_t i = 1; i <= n; ++i) {

  		int insertion = d[i][j - 1] + 1;
  		int deletion = d[i - 1][j] + 1;
  		int match = d[i - 1][j - 1];
  		int mismatch = d[i - 1][j - 1] + 1;

  		if (str1[i-1] == str2[j-1]) {
  			d[i][j] = std::min(
  						std::min(insertion, 
  						 	   	 deletion),
  						match);
  		} else {
  			d[i][j] = std::min(
  						std::min(insertion, 
  						 	   	 deletion),
  						mismatch);
  		}
  	}
  }

  return d[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
