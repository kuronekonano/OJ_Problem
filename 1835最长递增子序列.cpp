#include <algorithm>
#include <stdio.h>  ///�����������������get��
#include <string.h> ///ʵ���Ͼ��ǽ�ÿ������ǰ���ǰ������ֵ�Ƚϣ�ѡȡ���ֵ���ϲ���ֵ�����ڱ�������
using namespace std;
int main() {
  int i, j, a[1080], dp[1080], n; /// �������飬dp�������������
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    int flag;
    int maxn = 1;
    dp[0] = 1;              /// ��ʼ��һ����������Ϊ����1
    for (i = 1; i < n; i++) /// ��ʼ��̬�滮
    {
      flag = dp[i];           /// ��¼��ʱ�������ֵĳ��ȣ�һ�㱻��ʼ��Ϊ0
      for (j = 0; j < i; j++) /// ���ǰ���dp�����д洢�������
      {
        if (a[i] > a[j] && dp[j] > flag) /// ������������������ҵ�����󳤶�
        {
          flag = dp[j]; /// ��¼����
        } /// ������ϵ������е���������ô�ͽ��䳤�ȼ�¼����flag�����ڴ�����iλ��Ϊ�����
      }
      dp[i] = flag + 1; /// ���������˵�i���������+1����ʾΪi�ĳ���
      maxn = max(maxn, dp[i]);
    } /// ��Ϊ����ȣ���flag��+1��i������¼����i������
    //        for(i=0;i<=n;i++)
    //        {
    //            printf("%d\n",dp[i]);
    //        }
    //        sort(dp,dp+n);///������dp�����ĳ������ֵ���е�С������ˣ�����Ϊ��ʡ��
    printf("%d\n", maxn);
  }
  return 0;
}
