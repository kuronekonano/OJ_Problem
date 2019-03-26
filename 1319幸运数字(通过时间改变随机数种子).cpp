#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    printf("%d\n",rand()%10);
}
/*srand函数在stdlib.h头文件中，time函数在time.h头文件中。srand一般与rand函数配合生成随机数据。
一般srand和rand配合使用产生伪随机数序列。rand函数在产生随机数前，需要系统提供的生成伪随机数序
列的种子，rand根据这个种子的值产生一系列随机数。如果系统提供的种子没有变化，每次调用rand函数生
成的伪随机数序列都是一样的。srand(unsigned seed)通过参数seed改变系统提供的种子值，从而可以使得
每次调用rand函数生成的伪随机数序列不同，从而实现真正意义上的“随机”。通常可以利用系统时间来改变
系统的种子值，即srand(time(NULL))，可以为rand函数提供不同的种子值，进而产生不同的随机数序列。


time_t time(time_t *t);主要用来获取当前的系统时间，返回的结果是一个time_t类型，其值表示从UTC时
间1970年1月1日00:00:00到当前时刻的秒数。如果t是空指针，直接返回当前时间；如果t不是空指针，返回
当前时间的同时，将返回值赋予指针t所指向的内存空间。*/
