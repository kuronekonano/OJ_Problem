#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 4e4;
int tree[maxn];
int n;
int lowbit(int x) { return x & (-x); }
void update(int p, int x) {
  while (p <= maxn) {
    tree[p] += x;
    p += lowbit(p);
  }
}
int sum(int x) {
  int sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int num[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    int x, y;
    memset(tree, 0, sizeof tree);
    memset(num, 0, sizeof num);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &x, &y);
      num[sum(x + 1)]++;
      update(x + 1, 1);
    }
    for (int i = 0; i < n; i++) {
      printf("%d\n", num[i]);
    }
  }
}
