#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,t,i;
    float s,p;
    scanf("%d",&t);
    for(i=t;i>=1;i--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if((a+b<=c)||(a+c<=b)||(b+c<=a))
            {
                printf("it's not a triangle!\n");
            }
            else
            {
                p=(a+b+c)/2.0;
                s=sqrt(p*(p-a)*(p-b)*(p-c));
                printf("%.02f\n",s);
            }
        }
        return 0;
}
//#include<stdio.h>
//#include<math.h>
//#include<iostream>
//using namespace std;
//
//class triangle
//{
//private:
//    double x1,y1,x2,y2,x3,y3,a,b,c;
//public:
//    double d,s;
//    triangle()
//    {
//        x1=0;
//        x2=0;
//        x3=0;
//        y1=0;
//        y2=0;
//        y3=0;
//    }
//    void set_coordinates();
//    void length();
//    void area();
//    void output();
//} m;
//void triangle::set_coordinates()
//{
//    cin>>x1>>y1>>x2>>y2>>x3>>y3;
//}
//void triangle::length()
//{
//    a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
//    c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
//    d=(a+b+c)/2;
//}
//void triangle::area()
//{
//    s=sqrt(d*(d-a)*(d-b)*(d-c));
//}
//void triangle::output()
//{
//    if((x1-x2)/(y1-y2)==(x3-x2)/(y3-y2))
//    {
//        cout<<"not a triangle!"<<endl;
//    }
//    else
//        printf("area=%.2f\n",s);
//        //cout<<"area"<<"="<<s<<endl;
//}
//int main()
//{
//    int n;
//    cin>>n;
//    while(n--)
//    {
//        m.set_coordinates();
//        m.length();
//        m.area();
//        m.output();
//    }
//    return 0;
//}
