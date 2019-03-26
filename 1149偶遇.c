#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,n;
    char a[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        n=strlen(a);
        for(i=n;i>=0;i--)
        {
            switch(a[i])
            {
                case '1':printf("O");break;
                case '2':printf("T");break;
                case '3':printf("T");break;
                case '4':printf("F");break;
                case '5':printf("F");break;
                case '6':printf("S");break;
                case '7':printf("S");break;
                case '8':printf("E");break;
                case '9':printf("N");break;
                case '0':printf("O");break;
            }
        }
        printf("\n");
    }
    return 0;
}
