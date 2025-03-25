#include <malloc.h>
#include <stdio.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
struct man {
  int num;
};
typedef struct {
  man *student;
  int length;
  int listsize;
} SqList;
int InitList_Sq(SqList &L) /// 创建
{
  L.student = (man *)malloc(LIST_INIT_SIZE * sizeof(man));
  L.length = 0;
  L.listsize = LIST_INIT_SIZE;
  return 1;
}
int ListInsert_Sq(SqList &L, int i, man e) /// 插入
{
  man *p, *q;
  if (i < 1 || i > L.length + 1)
    return 0;
  if (L.length >= L.listsize) {
    man *newbase =
        (man *)realloc(L.student, (L.listsize + LISTINCREMENT) * sizeof(man));
    L.student = newbase;
    L.listsize += LISTINCREMENT;
  }
  q = &(L.student[i - 1]);
  for (p = &(L.student[L.length - 1]); p >= q; p--)
    *(p + 1) = *p;
  *q = e;
  L.length++;
  return 1;
}
int ListDelete_Sq(SqList &L, int i, man &e) /// 删除
{
  man *p, *q;
  if (i < 1 || i > L.length + 1)
    return 0;
  p = &(L.student[i - 1]);
  e = *p;
  q = L.student + L.length - 1;
  for (p++; p <= q; p++)
    *(p - 1) = *p;
  L.length--;
  return 1;
}
int main() {
  SqList a;
  man tmp;
  int n;
  while (scanf("%d", &n) != EOF) {
    InitList_Sq(a);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp.num);
      ListInsert_Sq(a, i, tmp);
    }
    for (int i = 0; i < a.length; i++) {
      for (int j = i + 1; j < a.length; j++) {
        if (a.student[i].num == a.student[j].num) {
          //                    printf("%d=====%d\n",a.student[i].num,a.student[j].num);
          ListDelete_Sq(a, j + 1, tmp);
          j--;
        }
      }
    }
    printf("%d\n", a.length);
    for (int i = 0; i < a.length; i++)
      printf("%d%c", a.student[i].num, i == a.length - 1 ? '\n' : ' ');
  }
}

// #include<stdio.h>
// #include<malloc.h>
// #define LIST_INIT_SIZE 100
// #define LISTINCREMENT 10
// struct man
//{
//     char name[25];
//     int age;
// };
// typedef struct
//{
//     man *student;
//     int length;
//     int listsize;
// }SqList;
// int InitList_Sq(SqList &L)///创建
//{
//     L.student=(man *)malloc(LIST_INIT_SIZE*sizeof(man));
//     L.length=0;
//     L.listsize=LIST_INIT_SIZE;
//     return 1;
// }
// int ListInsert_Sq(SqList &L,int i,man e)///插入
//{
//     man *p,*q;
//     if(i<1||i>L.length+1) return 0;
//     if(L.length>=L.listsize)
//     {
//         man *newbase=(man
//         *)realloc(L.student,(L.listsize+LISTINCREMENT)*sizeof(man));
//         L.student=newbase;
//         L.listsize+=LISTINCREMENT;
//     }
//     q=&(L.student[i-1]);
//     for(p=&(L.student[L.length-1]);p>=q;p--)*(p+1)=*p;
//     *q=e;
//     L.length++;
//     return 1;
// }
// int ListDelete_Sq(SqList &L,int i,man &e)///删除
//{
//     man *p,*q;
//     if(i<1||i>L.length+1)return 0;
//     p=&(L.student[i-1]);
//     e=*p;
//     q=L.student+L.length-1;
//     for(p++;p<=q;p++) *(p-1)=*p;
//     L.length--;
//     return 1;
// }
// int main()
//{
//     SqList a;
//     man tmp;
//     InitList_Sq(a);
//     for(int i=1;i<=10;i++)
//     {
//         scanf("%s %d",tmp.name,&tmp.age);
//         ListInsert_Sq(a,i,tmp);
//     }
//     for(int i=0;i<10;i++)
//     {
//         printf("%s %d\n",a.student[i].name,a.student[i].age);
//     }
// }
