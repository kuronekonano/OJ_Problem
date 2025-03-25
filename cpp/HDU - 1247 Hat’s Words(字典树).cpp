#include <algorithm>
#include <iostream>
#include <stdio.h> ///�ֵ���
#include <string.h>
#include <string>
#include <vector>
#define pb push_back
using namespace std;
int tot;
int tre[50005][26];
bool vis[50005];
vector<string> v, ans;
int insert(string str, int rt) /// ���뵥��
{
  for (int j = 0; j < str.size(); j++) /// ��������string
  {
    int x = str[j] - 'a';
    if (tre[rt][x] == 0)  /// �½ڵ�
      tre[rt][x] = ++tot; /// �ڵ���
    rt = tre[rt][x];      /// ��һ���ڵ�
  }
  vis[rt] = true; /// ����ĩβ���
}
bool finds(string str, int rt) /// ��ѯ
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
  while (cin >> a) /// ����
    insert(a, num), v.pb(a);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      string tma = v[i].substr(0, j + 1);
      string tmb = v[i].substr(j + 1);
      //            cout<<tma<<"======"<<tmb<<endl;
      if (finds(tma, num) && finds(tmb, num)) {
        /// һ����ǰ����ȷ����ans������Բ����ٱ����������ʣ������
        ans.pb(v[i]);
        break;
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << "\n";
}
