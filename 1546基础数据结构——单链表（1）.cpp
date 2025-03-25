#include <malloc.h>
#include <stdio.h> ///����
struct num {
  int a;
};
typedef struct Node {
  num date;
  struct Node *next;
} *LinkList, Node;
int GetElem_L(LinkList L, int i, num &e) /// ��ȡԪ��
{
  Node *p;
  int j = 1;
  p = L->next;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  e = p->date;
  return 1;
}
int Check_L(LinkList L) /// ��������
{
  Node *p;
  int j = 1;
  p = L->next;
  while (p) {
    printf("%d%c", p->date, p->next == NULL ? '\n' : ' ');
    p = p->next;
  }
  return 1;
}
int ListInsert_L(LinkList &L, int i, num e) /// ����Ԫ��
{
  Node *p;
  p = L;
  int j = 0;
  while (p && j < i - 1) {
    p = p->next;
    j++;
  }
  Node *s = (LinkList)malloc(sizeof(Node));
  s->date = e;
  s->next = p->next;
  p->next = s;
  return 1;
}
int ListDelete_L(LinkList &L, int i, num &e) /// ɾ��Ԫ��
{
  Node *p, *q;
  p = L;
  int j = 0;
  while (p->next && j < i - 1) {
    p = p->next;
    j++;
  }
  q = p->next;
  p->next = q->next;
  e = q->date;
  free(q);
  return 1;
}
void CreateList_L(LinkList &L) /// ��������
{
  L = (LinkList)malloc(sizeof(Node));
  L->next = NULL;
}
int main() {
  LinkList L;
  num tmp;
  int n, del;
  while (scanf("%d", &n) != EOF) {
    CreateList_L(L);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp.a);
      ListInsert_L(L, i, tmp);
    }
    scanf("%d", &del);
    printf("%d\n", n);
    Check_L(L);
    for (int i = 1; i <= n; i++) {
      GetElem_L(L, i, tmp);
      if (tmp.a == del) {
        n--;
        ListDelete_L(L, i, tmp);
      }
    }
    printf("%d\n", n);
    Check_L(L);
  }
}

// #include<stdio.h>//�桤����
// #include<stdlib.h>//����ͷ�ļ������ڴ����µ��ڴ�洢������
// struct number//����ṹ�壬���нṹ��ָ����������洢��һ���ṹ���׵�ַ
//{
//     int num;
//     struct number *next;
// };
// int main()
//{
//     int i,n,a;
//     struct number
//     *p1,*head,*p2;//headͷָ��Ϊ����ʼ���洢���ǵ�ַ�����洢��һ��Ԫ�أ�p1,p2���ڳн��¾�������ȡ�е�����
//     while(scanf("%d",&n)!=EOF)
//     {
//         p1=NULL;//��ʼ��
//         head=NULL;
//         p2=NULL;
//         for(i=0; i<n; i++)//����n����
//         {
//             scanf("%d",&a);//���벿��
//             if(head==NULL)//�ж�ͷָ���Ƿ�Ϊ�գ������ж��Ƿ��ǵ�һ��������ʱӦ�洢��headͷָ��ָ��Ľṹ����
//             {
//                 p1=(struct number *)malloc(sizeof(struct
//                 number));//�����µ�number�ͽṹ���ڴ�ռ� head=p1;
//                 p2=head;//��ͷָ��ŵ�p2�д洢
//             }
//             p1=(struct number *)malloc(sizeof(struct number));
//             p2->next=p1;//���ݳнӣ��´���������������õ�p1��
//             p1->num=a;
//             p1->next=NULL;//����p1��o2����
//             p2=p1;//����p1��Ϊ2�д洢Ϊ��һ��Ԫ��
//         }
//         int del;
//         scanf("%d",&del);
//
//
//         printf("%d\n",n);
//         p2=head->next;
//         while(p2!=NULL)//ԭ���������
//         {
//             printf("%d",p2->num);
//             if(p2->next!=NULL)
//             {
//                 printf(" ");
//             }
//             p2=p2->next;
//         }
//         printf("\n");
//
//
//         p2=head->next;//��������
//         while(p2!=NULL)
//         {
//             if(p2->num==del)
//             {
//                 n--;
//             }
//             p2=p2->next;
//         }
//         printf("%d\n",n);
//
//         p2=head;//p2ָ��ͷָ�룬���ң�p2Ϊ��һ��Ԫ��
//         while(p2->next!=NULL)//delɾ�����֣�ɾȥ����������Ԫ��
//         {
//             p1=p2->next;//p1Ϊ��ǰ��ȡԪ��
//             if(p1->num==del)//����ǰԪ�ط���ɾ������,�����������һ��Ϊ��ɾ��Ԫ��Ϊ��һ��Ԫ��ʱ��һ��Ϊ�������
//             {
//                 if(p1==head->next)//��Ϊ��һ��Ԫ��ʱ����ͷָ���next�ӱ�ɾ��Ԫ��ָ����һ��Ԫ��
//                 {
//                     head->next=p1->next;//�˴��ı�ͷָ��head��ָ��ͷָ����Ȼû�䣬��˵����ڵ�һ���У�p1��ȡ������p2��Ҳ����head�У����º��ָ��ֵ
//                 }
//                 else
//                 {
//                     p2->next=p1->next;//������һ��Ԫ�ص�nextָ��ɾ��Ԫ�ص�next
//                     p1=p1->next;//p1ָ����һ��Ԫ�أ�����ʱp1��p2ָ��ͬһ��Ԫ��
//                 }
//             }
//             else//�������
//             {
//                 p2=p1;
//                 p1=p1->next;
//             }
//         }
//
//
//         p2=head;//������֣����ɾ���������
//         while(p2->next!=NULL)
//         {
//             p2=p2->next;
//             printf("%d",p2->num);
//             if(p2->next!=NULL)
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//         p2=head;
//         while(p2!=NULL)//�ͷ����нڵ�
//         {
//             p1=p2->next;
//             free(p2);//�ͷŵ��ǵ�ǰ��������һ���ڵ�
//             p2=p1;
//         }
//     }
//     return 0;
// }

// #include<stdio.h>
// int main()
//{
//     int i,out,n,t,a[100000];
//     while(scanf("%d",&n)!=EOF)
//     {
//         for(i=0;i<n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         scanf("%d",&out);
//         printf("%d\n",n);
//         for(i=0;i<n;i++)
//         {
//             printf("%d%c",a[i],i==(n-1)?'\n':' ');
//         }
//         int flag=0;
//         for(i=0;i<n;i++)
//         {
//             if(a[i]!=out)
//             {
//                 flag++;
//             }
//         }
//         printf("%d\n",flag);
//         flag=0;
//         for(i=0;i<n;i++)
//         {
//             if(a[i]!=out)
//             {
//                if(flag==0)
//                     printf("%d",a[i]);
//                else
//                     printf(" %d",a[i]);
//                flag++;
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }
