#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,flag,k;
    char a[1005],b[1005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int n=strlen(a);
        j=0;
        bool num=false;
        flag=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>'0'&&a[i]<='9')//找到数字
            {
                while(a[i]>='0'&&a[i]<='9')//观察这个数字之后有没有数字
                {
                    flag=flag*10+a[i]-'0';//有的话则是二位数甚至更多
                    i++;//每次检阅过的数字是一个字符，可以跳过去不用看了
                }
                num=true;
            }

            if((a[i]<'0'||a[i]>'9')&&num==true)
            {
                b[j]=a[i];
                j++;
                b[j]='\0';
            }
            if(a[i+1]>='0'&&a[i+1]<='9'||a[i+1]=='\0')
            {
//                printf("%d\n",flag);
                for(k=1;k<=flag;k++)
                {
                    printf("%s",b);
                }
                j=0;
                flag=0;
            }
        }
        printf("\n");
    }
    return 0;
}
