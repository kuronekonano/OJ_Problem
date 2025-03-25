#include<stdio.h>
int main()
{
    int t,n,j;
    scanf("%d",&t);
    while(t--)//为毛定义t时用for语句，无论i++还是i--都无法循环，明明初始化i为1，输出的i都是t+1
    {
        scanf("%d",&n);
        int a[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<n;j++)
      {
        if(a[j]>=90&&a[j]<=100)
        {
            printf("A ");
        }
        if(a[j]>=80&&a[j]<=89)
        {
            printf("B ");
        }
        if(a[j]>=70&&a[j]<=79)
        {
            printf("C ");
        }
        if(a[j]>=60&&a[j]<=69)
        {
            printf("D ");
        }
        if(a[j]<60&&a[j]>=0)
        {
            printf("E ");
        }
      }
      printf("\n");
    }
    return 0;
}
