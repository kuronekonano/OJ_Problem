#include <algorithm>
#include <stdio.h> ///若出发点和终点的公司一样则花费为0，不一样则花费为1
#include <string.h>
using namespace std;
int main() {
  int n, a, b, i;
  char str[100005];
  while (scanf("%d%d%d", &n, &a, &b) != EOF) {
    scanf("%s", str);
    int st = str[a - 1] - '0';
    int ed = str[b - 1] - '0';
    if (st != ed) {
      printf("1\n");
    } else
      printf("0\n");
  }
}
