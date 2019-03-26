#include<string>
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map<string,int>v;
void init()
{
    v.clear();
    string a[100]=
    {
        "Cleveland Cavaliers",
        "Golden State Warriors",
        "San Antonio Spurs",///,
        "Miami Heat",
        "Miami Heat",
        "Dallas Mavericks",
        "L.A. Lakers",
        "L.A. Lakers",
        "Boston Celtics",
        "San Antonio Spurs",
        "Miami Heat",
        "San Antonio Spurs",
        "Detroit Pistons",
        "San Antonio Spurs",
        "L.A. Lakers",
        "L.A. Lakers",
        "L.A. Lakers",
        "San Antonio Spurs",
        "Chicago Bulls",
        "Chicago Bulls",
        "Chicago Bulls",
        "Houston Rockets",
        "Houston Rockets",
        "Chicago Bulls",
        "Chicago Bulls",
        "Chicago Bulls",
        "Detroit Pistons",
        "Detroit Pistons",
        "L.A. Lakers",
        "L.A. Lakers",
        "Boston Celtics",
        "L.A. Lakers",
        "Boston Celtics",
        "Philadelphia 76ers",
        "L.A. Lakers",
        "Boston Celtics",
        "L.A. Lakers",
        "Seattle Sonics",
        "Washington Bullets",
        "Portland Trail Blazers",
        "Boston Celtics",
        "Golden State Warriors",
        "Boston Celtics",
        "New York Knicks",
        "L.A. Lakers",
        "Milwaukee Bucks",
        "New York Knicks",
        "Boston Celtics",
        "Boston Celtics",
        "Philadelphia 76ers",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "Boston Celtics",
        "St. Louis Hawks",
        "Boston Celtics",
        "Philadelphia Warriors",
        "Syracuse Nats",
        "Minneapolis Lakers",
        "Minneapolis Lakers",
        "Minneapolis Lakers",
        "Rochester Royals",
        "Minneapolis Lakers",
        "Minneapolis Lakers",
        "Baltimore Bullets",
        "Philadelphia Warriors"
    };
    for(int i=0;i<70;i++)///69,70
        v[a[i]]++;
}
int main()
{
    int t,cas=0;
    string aa;
    init();
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getline(cin,aa);
        printf("Case #%d: %d\n",++cas,v[aa]);///case
    }
}
