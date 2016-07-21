#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::sort(segments.begin(), segments.end(), 
    [](const Segment &s1, const Segment &s2) -> bool {
      return s1.end < s2.end;
    });

  // for (size_t i = 0; i < segments.size(); ++i) {
  //   std::cout << segments[i].end << " ";
  // }

  // int currSermentPoint = 0;
  // for (size_t i = 0; i < segments.size(); ++i) {
  //   if (segments[i].start > currSermentPoint) {
  //     currSermentPoint = segments[i].end;
  //     points.push_back(currSermentPoint);
  //   }
  // }
  for (size_t i = 0; i < segments.size(); ++i) {
    int currEnd = segments[i].end;
    int currPos = segments[i].end;
    while (i < segments.size() && segments[i].start <= currEnd) {
      if (segments[i].end < currPos) {
        currPos = segments[i].end;
      }
      i++;
    }
    i--;
    points.push_back(currPos);
  }



  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
