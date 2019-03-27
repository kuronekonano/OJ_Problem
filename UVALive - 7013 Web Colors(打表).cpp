#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;
struct color
{
    int R,G,B;
    int i;
    double dis;
}a[20];
bool cmp(color a,color b)
{
    if(a.dis==b.dis)return a.i<b.i;
    return a.dis<b.dis;
}
int main()
{
    int r,g,b;
    map<int,string>link;
    link[1]="White";
    link[2]="Silver";
    link[3]="Gray";
    link[4]="Black";
    link[5]="Red";
    link[6]="Maroon";
    link[7]="Yellow";
    link[8]="Olive";
    link[9]="Lime";
    link[10]="Green";
    link[11]="Aqua";
    link[12]="Teal";
    link[13]="Blue";
    link[14]="Navy";
    link[15]="Fuchsia";
    link[16]="Purple";
    a[1].R=255,a[1].G=255,a[1].B=255,a[1].i=1;
    a[2].R=192,a[2].G=192,a[2].B=192,a[2].i=2;
    a[3].R=128,a[3].G=128,a[3].B=128,a[3].i=3;
    a[4].R=0,a[4].G=0,a[4].B=0,a[4].i=4;
    a[5].R=255,a[5].G=0,a[5].B=0,a[5].i=5;
    a[6].R=128,a[6].G=0,a[6].B=0,a[6].i=6;
    a[7].R=255,a[7].G=255,a[7].B=0,a[7].i=7;
    a[8].R=128,a[8].G=128,a[8].B=0,a[8].i=8;
    a[9].R=0,a[9].G=255,a[9].B=0,a[9].i=9;
    a[10].R=0,a[10].G=128,a[10].B=0,a[10].i=10;
    a[11].R=0,a[11].G=255,a[11].B=255,a[11].i=11;
    a[12].R=0,a[12].G=128,a[12].B=128,a[12].i=12;
    a[13].R=0,a[13].G=0,a[13].B=255,a[13].i=13;
    a[14].R=0,a[14].G=0,a[14].B=128,a[14].i=14;
    a[15].R=255,a[15].G=0,a[15].B=255,a[15].i=15;
    a[16].R=128,a[16].G=0,a[16].B=128,a[16].i=16;
    while(scanf("%d%d%d",&r,&g,&b)!=EOF)
    {
        if(r==-1&&g==-1&&b==-1)return 0;
        for(int i=1;i<=16;i++)
        {
            a[i].dis=sqrt((a[i].R-r)*(a[i].R-r)+(a[i].G-g)*(a[i].G-g)+(a[i].B-b)*(a[i].B-b));
        }
        sort(a+1,a+17,cmp);
        cout<<link[a[1].i]<<endl;
    }
}
