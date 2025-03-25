#include <stdio.h>
#include <string.h>
int z[60001];
int find(int x) {
  int r = x, t;
  while (r != z[r]) // ���ϼ�����ѹ��·��
  {
    t = r;       /// ѹ��·������
    r = z[r];    /// ���ݲ���
    z[t] = z[r]; /// ѹ��·������
  }
  return r;
}
void join(int a, int b) // join��������������֮��Ĵ�����ϵ
{
  int fa = find(a), fb = find(b); // ����˫�����ϼ��������ͬ����������ϵ
  if (fa != fb)                   // ���ϼ���ͬ
  {
    z[fa] = fb; // ����������ϵ
  }
}
int main() {
  int j, n, m, u, v, i, sum;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) // ��ʼ�����Լ�Ϊ�Լ����ϴ�
    {
      z[i] = i;
    }
    for (i = 0; i < m; i++) // �����ϵ
    {
      scanf("%d%d", &u, &v);
      join(u, v);
    }
    int boss = find(0);
    sum = 0;
    for (j = 0; j < n; j++) {
      if (find(j) == boss) // ���ҵ����ϼ����ȾԴ���ʱ����Ⱦ������һ
      {
        sum++;
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
