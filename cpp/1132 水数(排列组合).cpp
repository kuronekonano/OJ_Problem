// #include<stdio.h>///������1���������������ϣ�Ȼ��1�ĸ�����������Ϻ�ֱ��*�м���1
// #include<string.h>
// int a[30][30],n,ans[30],t;
// int main()
//{
//     for(int i=1; i<=25; i++)a[i][i]=1;
//     for(int i=2; i<=25; i++)a[i][1]=1;
//     for(int i=3; i<=25; i++)
//         for(int j=2; j<i; j++)
//             a[i][j]=a[i-1][j-1]+a[i-1][j];
//     memset(ans,0,sizeof(ans));
//     for(int i=1; i<=25; i++)
//         for(int j=1; j<=i; j++)
//             ans[i]+=a[i][j]*j;
//     scanf("%d",&t);
//     while(t--) scanf("%d",&n),printf("%d\n",ans[n]);
// }

#include <stdio.h>
int main() {
  int a[26], pow = 1, t, n;
  a[1] = 1;
  for (int i = 2; i <= 25; i++)
    a[i] = a[i - 1] * 2 + pow, pow *= 2;
  scanf("%d", &t);
  while (t--)
    scanf("%d", &n), printf("%d\n", a[n]);
}
/*
��������ǰ���һ���ÿ�����������м���0��1��ɱ���Ķ���������
��������ġ�1���ĸ��������ϲ�Ľ��*2�����ӵ�1�ĸ���
*/
