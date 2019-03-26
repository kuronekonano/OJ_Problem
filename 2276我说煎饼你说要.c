#include<stdio.h>
#include<string.h>
int main()
{
    char j[10]="Jianbin",y[10]="Yaoyao",c[15]="Check now",s[18];
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,j)==0)
        {
            printf("Yao\n",y);
        }
        else if(strcmp(s,y)==0)
        {
            printf("%s\n",c);
        }
    }
    return 0;
}
