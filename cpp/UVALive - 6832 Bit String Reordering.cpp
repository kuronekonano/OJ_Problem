#include <algorithm>
#include <stdio.h>
using namespace std;
int change(
    int a[], int b[], int i,
    int j) /// dfs����,�ҵ�һ���ͱ�׼��������ͬ�����ֺ󣬻��ݵ���������¼����
{
  int ans = 0;
  if (a[i] == b[j])
    return ans;
  else {
    ans += change(
        a, b, i + 1,
        j); /// ���뵱ǰλ��ͬʱ��ѡ����һλ��ֱ���ҵ���ͬ�ģ������ͬλ�ǽ�����·���ϵ�һ��������
    swap(a[i + 1], a[i]); /// �Ѿ��ҵ�һ����λ��ʱ���ͻ��ݽ���
    return ans + 1;       /// ���ؽ���ӵ�ǰ����
  }
}
int main() {
  int n, m, a[20], judge[20],
      check
          [20]; /// aΪԭ���С�judgeΪһ��1��ͷ�ı�׼���У�checkΪ��0��ͷ�ı�׼����
  while (scanf("%d%d", &n, &m) != EOF) {
    int num =
        0; /// ��¼1�ĸ�������1��0�ĸ�����ͬʱ�Ż��������������Ҫ�Ƚϲ����㲽�裬ȡ��Сֵ������ֻ�ñȽ�һ�ֺ����봮һ���ı�׼��
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i])
        num++;
    }
    int tmp,
        it = 0, flag = 0, nn = 0,
        uu =
            0; /// itΪ��¼ָ�룬������n��nnΪ��0��ͷ�ı�׼����1�ĸ�����uu����1Ϊ��׼����1�ĸ���
    for (int i = 0; i < m; i++) {
      scanf("%d", &tmp);
      while (tmp--) /// �����׼��
      {
        check[it] = flag;
        judge[it++] = !flag;
        if (flag)
          nn++;
        else
          uu++;
      }
      flag = !flag;
    }
    int b[20];
    for (int i = 0; i < n; i++)
      b[i] = a
          [i]; /// ��1��0�ĸ�����ͬʱ����Ҫ�Ƚ�����������Ϊ��һ�����Ѿ��Ƚϲ������ɱ�׼��������Ҫ�洢��ʼ��
    int ansn = 0, ansu = 0; /// ����ans
    if (nn == num)
      for (int i = 0; i < n; i++)
        if (a[i] != check[i])
          ansn += change(a, check, i, i);
    if (uu == num)
      for (int i = 0; i < n; i++)
        if (b[i] != judge[i])
          ansu += change(b, judge, i, i);
    if (nn == uu)
      ansn = ansn < ansu ? ansn
                         : ansu; /// ���1��0������ͬ���Ƚ�������ʽ��ȡ��С����
    else
      ansn =
          ansn < ansu
              ? ansu
              : ansn; /// ����ֻ����һ�ִ𰸣���һ��ans��Ϊû���ܣ����Ի��ǳ�ʼֵ0��ȡ���ֵ�������˵Ĵ�
    printf("%d\n", ansn);
  }
}
