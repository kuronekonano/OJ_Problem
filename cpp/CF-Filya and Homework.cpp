#include <iterator> //����������ͷ�ļ���
#include <set>      ///������set����ȥ������
#include <stdio.h>
using namespace std;
int main() {
  int i, j, n, k;
  while (scanf("%d", &n) != EOF) {
    set<long long> q;
    set<long long>::iterator nano;
    q.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      q.insert(k);
    }
    if (q.size() > 3)
      printf("NO\n");
    else {
      if (q.size() <= 2) {
        printf("YES\n");
      } else {
        nano = ++q.begin();
        if (*nano - *q.begin() == *(--q.end()) - *nano)
          printf("YES\n");
        else {
          printf("NO\n");
        }
      }
    }
  }
  return 0;
}
