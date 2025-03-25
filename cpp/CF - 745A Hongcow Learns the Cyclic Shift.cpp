#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int main() {
  char a[58];
  map<string, bool> m;
  while (scanf("%s", a) != EOF) {
    int i, n = strlen(a);
    m[a] = true;
    int flag = 1;
    for (i = 1; i < n; i++) {
      char temp[58];
      int k = 0;
      for (int j = i; j < n; j++)
        temp[k++] = a[j];
      for (int j = 0; j < i; j++)
        temp[k++] = a[j];
      temp[k] = '\0';
      if (m[temp] == false) {
        flag++;
        m[temp] = true;
      }
    }
    printf("%d\n", flag);
  }
}
