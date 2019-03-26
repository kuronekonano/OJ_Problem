#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int t,n,i,m,j;
    char s[130];
    char a[20];
    scanf("%d",&t);
    getchar();//getchar函数可以读取字符，单个字符，只能读取一个，因此可以读取每行末时输入的回车，读入后避免存储出错
    while(t--)
    {
        gets(s);//因为输入的数存在空格，因此只能用gets输入字符串
        n=strlen(s);
        printf("%c",s[0]-('a'-'A'));//小写转换为大写
        for(i=1;i<n;i++)
        {
            if(s[i]==' ')//这里用判断可以判断后面的单词的首字母，除了第一个单词
            {
                s[i+1]=s[i+1]-('a'-'A');
                printf("%c",s[i+1]);
            }
        }
        printf("\n");
    }
    return 0;
}
