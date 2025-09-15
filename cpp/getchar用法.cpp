#include <stdio.h>
int main() {
    char a, b, c;
    while ( scanf( "%c%c%c", &a, &b, &c ) != EOF ) {
        getchar();  // ch=getchar()为读取一个字符。while((ch=getchar())!='\n)'
        printf( "%c%c%c\n", c, b, a );
    }
    return 0;
}
