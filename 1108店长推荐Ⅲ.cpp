#include<stdio.h>///ˮ�⣬�������˱�����������ַ��ȽϷ���
#include<string.h>
int main()
{
    int t,n,m,i,j;
    char a[55][55];
    while(scanf("%d",&t)!=EOF)
    {
        char key[55];
        while(t--)
        {
            scanf("%d%d",&m,&n);
            scanf("%s",key);
            for(i=1; i<=m; i++)
            {
                scanf("%s",a[i]);
            }
            int flag=0,len;
            len=strlen(key);
            for(i=1; i<=m; i++)///��m���ַ�����������Ƚ�
            {
                int len1=strlen(a[i]),k=0;
                for(j=0; j<len1; j++)///������͹ؼ��ֱȽ�
                {
                    if(a[i][j]==key[k])///ֻҪ�����͹ؼ��ֶ�Ӧ�ַ�һ������ô�ַ������ƶ�ָ�룬����һ����ͬ���ַ�
                    {
                        k++;
                    }
                }
                if(k==len)///����ַ��ӵ��˹ؼ��ֵĳ��ȣ���ô˵����ƥ��Ĺؼ��֣���������һ
                {
                    flag++;
                }
            }
            if(flag==n)///�Ƚϲ���
            {
                printf("Orz!\n");
            }
            else if(flag<n)
            {
                printf("Vagaa V5!\n");
            }
            else
            {
                printf("EMule V5!\n");
            }
        }
        printf("\n");
    }
    return 0;
}
