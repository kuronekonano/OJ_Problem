#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    int n,i,d,x,k;
    while(gets(s))//������gets�������룬����getchar������scanf������ո����޷������ո�
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
