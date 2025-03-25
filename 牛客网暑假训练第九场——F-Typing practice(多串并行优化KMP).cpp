#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof b)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 100008;
const int inf = 0x3f3f3f3f;
int n;
char str[6][maxn], mastr[maxn];
int nxt[6][maxn], len[6],
    checkpoint
        [6]
        [maxn]; /// checkpoint�����¼����ÿһλ���ڲ�ͬ�Ӵ���ƥ���¼����Ϊ�ǲ���ͬʱƥ�䣬��˲�֪��ÿ���Ӵ��ڲ�ͬλ�õĻ��˹���
/// һһ��¼������Ҳ��֤��̬����ǰ�벿�ֲ�����Ϣ�ܹ��������
inline void kmp_pre(char x[], int m, int num) /// �Ż�next���鹹��
{
  int i, j;
  j = nxt[num][0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = nxt[num][j];
    ++i, ++j;
    nxt[num][i] =
        x[i] == x[j]
            ? nxt[num][j]
            : j; /// ˵���Ż������Ѿ��ı����ڲ�����������Щ����������ܳ�ʱ
  }
}
int main() /// Ҫ�仯�������ĺ�׺������ƥ���ֵ��е��ʵ�ǰ׺��ʹ�ü������ĸԽ��Խ�ã���KMPǰ׺��׺ƥ�䣬ÿ���ҵ����Ӵ������ǰ׺��׺ƥ�伴��ǰ��һ��ans
{          /// ��ʹ����next���˵Ĺ���Ҳ��Ѱ�����ǰ׺ƥ��Ĺ���
  while (scanf("%d", &n) != EOF) {
    int ans = inf;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      kmp_pre(str[i], len[i] = strlen(str[i]), i);
      ans = min(ans, len[i]);
    }
    scanf("%s", mastr);
    int mlen = strlen(mastr);
    printf("%d\n", ans); /// ���ڿմ������̵���
    int pt =
        0; /// ��̬����ָ�룬ָ��Ĳ��������е��ĸ��ַ������������仯�ĳ����ϵ��±�λ
    for (int i = 0; i < mlen; i++) /// ����������ÿһ���ַ������ڱȽϺ���λָ��
    {
      ans = inf;
      if (mastr[i] == '-') /// ��λ��ֱ��ȡ֮ǰ�Ĵ���Сֵ�������
      {
        if (pt != 0)
          pt--;
        for (int j = 0; j < n; j++)
          ans = min(ans, len[j] - checkpoint[j][pt]);
        printf("%d\n", ans);
      } else /// �ַ����ӵ�ʱ����жമ���е�KMPƥ��
      {
        for (int j = 0; j < n; j++) /// ��ÿ�����Ƚ�ȡȡ��Сֵ��ans
        {
          int tmj = checkpoint[j][pt];
          while (tmj != -1 && str[j][tmj] != mastr[i])
            tmj = nxt[j][tmj];
          checkpoint[j][pt + 1] = tmj + 1;
        }
        pt++;
        for (int j = 0; j < n; j++)
          ans = min(ans, len[j] - checkpoint[j][pt]);
        printf("%d\n", ans);
      }
    }
  }
}
