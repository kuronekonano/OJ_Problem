#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    int n,i,d,x,k;
    while(gets(s))//必须用gets函数输入，或是getchar，否则scanf不读入空格则无法计数空格
    {
        x=0;
        d=0;
        k=0;
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                x++;
            if(s[i]>='A'&&s[i]<='Z')
                d++;
            if(s[i]==' ')
                k++;
        }
        printf("%d %d %d\n",x,d,k);
    }
    return 0;
}
