#include<stdio.h>
#include<algorithm>///reverse����ͷ�ļ�
#include<string.h>///�˺�����ֱ�������鵹�������ʱ�����2330
using namespace std;
int main()
{
    char a[10008],b[10008];
    int i,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        int n=strlen(a);
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=' ')
            {
                b[flag++]=a[i];
            }
            else
            {
                reverse(b,b+flag);///��ĳ��λ����ĳ��λ�õ�ת
                printf("%s",b);
                memset(b,0,sizeof(b));
                printf("%c",a[i]);
                flag=0;
            }
        }
        reverse(b,b+flag);
        printf("%s\n",b);
        memset(b,0,sizeof(b));///����ַ�����ʱ����Ϊ0Ҳ����ȫ�յ�
    }
    return 0;
}
