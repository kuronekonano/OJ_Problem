#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int t,n,i,m,j;
    char s[130];
    char a[20];
    scanf("%d",&t);
    getchar();//getchar�������Զ�ȡ�ַ��������ַ���ֻ�ܶ�ȡһ������˿��Զ�ȡÿ��ĩʱ����Ļس�����������洢����
    while(t--)
    {
        gets(s);//��Ϊ����������ڿո����ֻ����gets�����ַ���
        n=strlen(s);
        printf("%c",s[0]-('a'-'A'));//Сдת��Ϊ��д
        for(i=1;i<n;i++)
        {
            if(s[i]==' ')//�������жϿ����жϺ���ĵ��ʵ�����ĸ�����˵�һ������
            {
                s[i+1]=s[i+1]-('a'-'A');
                printf("%c",s[i+1]);
            }
        }
        printf("\n");
    }
    return 0;
}
