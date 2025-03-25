#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int m, n, i, ab[130000], a[130000];
  while (scanf("%d", &m) != EOF) {
    n = (sqrt(8 * m + 1) - 1) / 2;
    map<int, int> q;
    q.clear();
    for (i = 0; i < m; i++)
      scanf("%d", &ab[i]);
    printf("%d\n", n);
    sort(ab, ab + m);
    a[0] = ab[0];
    a[1] = ab[1];
    q[a[0] + a[1]]++;
    int num = 1;
    for (i = 2; i < m; i++) {
      if (q[ab[i]])
        q[ab[i]]--;
      else {
        a[++num] = ab[i];
        for (int j = 0; j < num; j++)
          q[a[j] + a[num]]++;
      }
      if (num == n - 1)
        break;
    }
    for (i = 0; i <= num; i++)
      printf("%d%c", a[i], i == num ? '\n' : ' ');
  }
}
