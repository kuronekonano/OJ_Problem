#include <stdio.h>
#include <string.h>
bool a[10005];
void inti() {
  memset(a, true, sizeof(a));
  a[1] = false; /// ����ɸ
  for (int i = 2; i <= 10000; i++) {
    for (int j = i + i; j <= 10000; j += i) {
      a[j] = false;
    }
  }
}
int main() /// ע���ǲ�ͬ��������˲������2+2�����
{
  int n, sum;
  inti();
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    for (
        int i = 3; i < n / 2;
        i +=
        2) /// ��3��ʼ��������Ϊ�������ż����2��Ψһһ��ż��������ֻ�����һ��ż���Ż���õ�ż��
    {      /// ����Ȼ�ǲ����ڵģ����ұ���ֱ��n/2-1���ų���������������
      if (a[i] &&
          a[n -
            i]) /// ��������������������֮��͵���n����Ҳ����������ô����һ��������
        sum++;
    }
    printf("%d\n", sum);
  }
}
// #include<stdio.h>
// #include<math.h>
// int a[10005];
// int sushu(int n)
//{
//     int j,i,k=0;
//     for(i=2;i<n;i++)
//     {
//         bool flag=true;
//         for(j=2;j<=sqrt(i);j++)
//         {
//             if(i%j==0)
//             {
//                 flag=false;
//             }
//         }
//         if(flag==true)
//         {
//             a[k]=i;
//             k++;
//         }
//     }
//     return k;
// }
// int main()
//{
//     int t,n,j,flag1;
//     while(scanf("%d",&t)!=EOF)
//     {
//         n=sushu(t);
//         flag1=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(a[i]+a[j]==t)
//                 {
//                     flag1++;
//                 }
//             }
//         }
//         printf("%d\n",flag1);
//     }
//     return 0;
// }
