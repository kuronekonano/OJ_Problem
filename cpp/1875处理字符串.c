#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    int i,n;
    while(scanf("%s",a)!=EOF)
    {
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]>64)//����ASCII��Ƚϴ�С��Ҳ��ֱ�����ַ���9���Ƚϴ�С
            {
                printf("%c",a[i]);
            }
            if(a[i]>64&&a[i+1]<64)
                printf("\n");
        }
    }
    return 0;
}
