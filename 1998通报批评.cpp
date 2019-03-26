#include<stdio.h>
struct student
{
    char name[30];
    int pp;
}stu[105];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s %d",stu[i].name,&stu[i].pp);
        }
        for(i=1;i<=n;i++)
        {
            if(stu[i].pp==0)
            {
                printf("%s\n",stu[i].name);
            }
        }
        printf("\n");
    }
    return 0;
}
