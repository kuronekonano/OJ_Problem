#include<stdio.h>
int main()
{
    int sum,x,y,j,i;
    while(scanf("%d%d%d%d",&x,&y,&i,&j)!=EOF)
    {
        if(i>x&&(j+y)%(i-x)==0)//由(人数)*x+y=(人数)*i-j,移项后得(人数)*(i-x)=y+j,最后(人数)=(y+j)/(i-x)
            printf("He is right\n");//由于人数固定，且不为小数，所以(y+j)/(i-x)必定整除，(j+y)%(i-x)==0
        else
            printf("Back to the adult, it surely has something\n");
    }
    return 0;
}
