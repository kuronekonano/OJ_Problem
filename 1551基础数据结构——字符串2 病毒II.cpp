#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char str[109];
    while(scanf("%s",&str)!=EOF)
    {
        n=strlen(str);
        bool flag=false;
        for(i=0;i<n;i++)
        {
            if(str[i]=='b'&&str[i+1]=='k'&&str[i+2]=='p'&&str[i+3]=='s'&&str[i+4]=='t'&&str[i+5]=='o'&&str[i+6]=='r')
                flag=true;
        }
        if(flag==false)
        {
            printf("Safe\n");
        }
        else
            printf("Warning\n");
    }
    return 0;
}
