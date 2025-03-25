#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        printf("%.0f %.0f %.0f\n",ceil(n),floor(n),round(n));
    }
    return 0;
}
