#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
char a[maxn];
struct str {
  int len[26], nxt[26];
} word[maxn];
int pos[26]; /// �뵱ǰλ�������26����ĸ��λ��
int minlen[maxn];
int main() {
  scanf("%s", a + 1);
  memset(pos, 0, sizeof pos);
  int len = strlen(a + 1);
  for (int i = len; i >= 0;
       i--) /// ��������ַ������Բ�ѯ��ÿ��λ���������һ����ĸ
  {
    minlen[i] = inf; /// ��ǰλ������ɲ�ѯ�Ĳ������Ӵ�����С����
    for (int j = 0; j < 26;
         j++) /// ���ڵ�iλ������һ��26����ĸ��ÿ����ĸ��λ����˭
    {
      word[i].nxt[j] = 0; /// ����һ����ĸa��λ��
      if (pos[j])         /// ����λ��֮����ڸ���ĸ
      {
        word[i].nxt[j] = pos[j]; /// ������һ������ĸ��λ��
        word[i].len[j] =
            minlen[pos[j]] +
            1; /// ����ǰλ����̲������Ӵ��ĳ��ȸ�����һ��λ��+1�ĳ��ȣ���Ϊ��λ�ô�����ĸj��������Ҹ�λ��С�ֵ�����ô���Ⱦ�Ҫ��Ӧ����
        if (i == 0)
          word[i].len[j]--; /// ����ǵ�һ��λ�ã����Ȳ��ü�һ
      } else
        word[i].len[j] =
            i == 0
                ? 0
                : 1; /// ���������ĳ����ĸ����˵�����˽������������Ӵ����Ƚ�ֹ
      minlen[i] = min(minlen[i], word[i].len[j]);
    }
    if (i != 0)
      pos[a[i] - 'a'] = i; /// ������ǵ�һ���ַ������µ�ǰ������ĸ������λ��
  }
  for (
      int k = 0, mini, minn;;
      k = word[k].nxt[mini],
          printf(
              "%c",
              mini +
                  'a')) /// ������֣�ÿ������֮ǰ����ĵ�ǰλ�õ���һ����ĸ����̳��������Ӧ�ַ�
  {                     /// ָ�����
    mini = 0, minn = inf;
    for (int i = 0; i < 26;
         i++) /// ÿ�β�����һ��������ַ�����֤�������������С
    {
      if (!word[k].nxt[i]) /// ��֮�󲻴���ĳ����ĸ�ˣ��Ǿ����������
      {
        printf("%c\n", i + 'a');
        return 0;
      }
      if (word[k].len[i] < minn)
        minn = word[k].len[i], mini = i; /// ��¼��С������ȵ���ĸ
    }
  }
  return 0;
}
