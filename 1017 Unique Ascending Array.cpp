#include <iterator>
#include <set>
#include <stdio.h>
using namespace std;
int main() {
  set<int> s;
  int n, x;
  while (scanf("%d", &n) && n) {
    set<int>::iterator it;
    s.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      s.insert(x);
    }
    for (it = s.begin(); it != s.end(); it++)
      printf("%d%c", *it, it != --s.end() ? ' ' : '\n');
  }
}
