#include <algorithm>
#include <iostream>
#include <stdio.h> ///字典树
#include <string.h>
#include <string>
#include <vector>
#define pb push_back
using namespace std;
int tot;
int tre[50005][26];
bool vis[50005];
vector<string> v, ans;
int insert(string str, int rt) /// 插入单词
{
  for (int j = 0; j < str.size(); j++) /// 遍历单词string
  {
    int x = str[j] - 'a';
    if (tre[rt][x] == 0)  /// 新节点
      tre[rt][x] = ++tot; /// 节点编号
    rt = tre[rt][x];      /// 下一个节点
  }
  vis[rt] = true; /// 单词末尾标记
}
bool finds(string str, int rt) /// 查询
{
  for (int i = 0; i < str.size(); i++) {
    int x = str[i] - 'a';
    if (tre[rt][x] == 0)
      return false;
    rt = tre[rt][x];
  }
  return vis[rt];
}
int main() {
  tot = 0;
  int num = ++tot;
  memset(vis, false, sizeof(vis));
  memset(tre[num], 0, sizeof(tre[num]));
  string a;
  v.clear();
  ans.clear();
  while (cin >> a) /// 建树
    insert(a, num), v.pb(a);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      string tma = v[i].substr(0, j + 1);
      string tmb = v[i].substr(j + 1);
      //            cout<<tma<<"======"<<tmb<<endl;
      if (finds(tma, num) && finds(tmb, num)) {
        /// 一旦当前单词确定是ans，则可以不用再遍历这个单词剩余的组合
        ans.pb(v[i]);
        break;
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << "\n";
}
