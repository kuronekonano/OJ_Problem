#include<stdio.h>///�ҳ�����������ͬ�ַ�����
#include<string.h>
int main()
{
    char a[1005];
    int i;
    while(scanf("%s",a)!=EOF)
    {
        int n=strlen(a);
        int max=0,sum=1;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[i+1])///��κͺ����Ǹ�һ���ͼ���+1
            {
                sum++;
            }
            else///�����ʼ����
            {
                sum=1;
            }
            if(max<sum)///�жϸ���������
            {
                max=sum;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
