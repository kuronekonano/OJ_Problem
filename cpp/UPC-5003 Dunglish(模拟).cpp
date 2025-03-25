#include <bits/stdc++.h> ///组合，最后样例没给出所有题意有坑点，只有一种排列时输出那种排列并判断
#define LL long long
using namespace std;
map<string, int> mp;
map<string, string> link;
LL poww(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n, num[30], cnt[30], worry[30], sum;
  string str[30];
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    mp.clear();
    link.clear();
    memset(num, 0, sizeof(num));
    memset(cnt, 0, sizeof(cnt));
    memset(worry, 0, sizeof(worry));
    for (int i = 0; i < n; i++) {
      cin >> str[i];
      if (mp[str[i]] == 0)
        mp[str[i]] = ++sum;
      num[mp[str[i]]]++;
    }
    int m;
    string l, r, ju;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      cin >> l >> r >> ju;
      if (mp[l])
        link[l] = r;
      if (ju[0] == 'c' && mp[l])
        cnt[mp[l]]++;
      else if (ju[0] == 'i' && mp[l])
        worry[mp[l]]++;
    }
    LL ans = 1, right = 1;
    for (int i = 1; i <= sum; i++) {
      right *= poww((LL)cnt[i], (LL)num[i]);
      ans *= poww((LL)cnt[i] + (LL)worry[i], (LL)num[i]);
    }
    if (ans == 1) {
      for (int i = 0; i < n; i++) {
        cout << link[str[i]];
        if (i == n - 1)
          printf("\n");
        else
          printf(" ");
      }
      printf("%s\n", right == 1 ? "correct" : "incorrect");
    } else {
      ans = ans - right;
      printf("%lld correct\n%lld incorrect\n", right, ans);
    }
  }
}
