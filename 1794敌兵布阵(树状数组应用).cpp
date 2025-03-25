#include <stdio.h>
#include <string.h>
int tree[50050], n;
int lowbit(int x) /// Ѱ����һ��2�Ľڵ�
{                 /// lowbit2=2   lowbit4=4  lowbit8=8
  return x & (-x);
} /// �����-������ô�������䱾�������+�ϣ���������˫����Ҳ����2����һ���η�
void update(int p, int x) /// ����ÿ���ڵ�ĺ�
{
  while (p <= n) {
    tree[p] += x;   /// ��ÿ���ڵ�����(����)�ϸ��µ�ֵ
    p += lowbit(p); /// Ѱ����һ���ڵ�
  }
}
int sum(int p) /// ��ͣ����������ڵ㣬��ǰ������һ���ܺͽڵ��ֵ
{              /// ����������ܺͽڵ㣬ֱ�ӷ����Ǹ��ڵ�洢���ܺ�
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p); /// lowbit���̼������䱾��
  }
  return sum;
}
int main() {
  int t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    int i, j;
    memset(tree, 0, sizeof(tree));
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &j);
      update(i, j); /// ��ֵ��ͬʱ�Ϳ�ʼ������
    }
    //        for(i=1;i<=n;i++)///�����״�����ÿһ���ڵ�洢��ֵ
    //        {
    //            printf("
    //            %d",tree[i]);///��״����ÿһ��2�ı����Ľڵ㣬���洢����֮ǰ�������ĺ�
    //        }///�������ڵ���洢�䱾��
    printf("Case %d:\n", ++cas);
    char a[10];
    while (scanf("%s", a) != EOF) {
      if (a[0] == 'E') {
        break;
      }
      if (a[0] == 'A') {
        scanf("%d%d", &i, &j);
        update(i, j);
      }
      if (a[0] == 'S') {
        scanf("%d%d", &i, &j);
        update(i, -j);
      }
      if (a[0] == 'Q') {
        scanf("%d%d", &i, &j);
        printf(
            "%d\n",
            sum(j) -
                sum(i -
                    1)); /// ���ʱ��Ϊ��һ�������ڵ���ͣ�����������ڵ�洢���ܺ�֮��
      } /// ��һ����Ϊ��j��ʾ��1��j����Ӫ�������ܺͣ�i��ʾ��1��i���������ܺͣ������jֱ��-i����ô��������i��Ӫ�ص����������Ҫ��i-1�������ܺͣ��������iӪ����������
    }
  }
  return 0;
}
