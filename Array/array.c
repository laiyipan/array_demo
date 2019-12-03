#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//get an array
int *getArray()
{
    static int r[10];//定义静态数组
    int i;
    int j;
    //   for ( i = 0; i < 10; ++i)
    //   {
    //      r[i] = i;
    //      printf( "r[%d] = %d\n", i, r[i]);
    //   }

    int len = sizeof(r) / sizeof(r[0]);//计算数组的长度
    for (i = 0; i < len; i++)
    {
        scanf("%d", &r[i]);
    }

    return r;
    //return &r[0];  //等同
    // return &r; //等同
}

int main()
{
    /* 一个指向整数的指针 */
    int *p;
    int i;

    p = getArray();
    for (i = 0; i < 10; i++)
    {
        printf("*(p + %d) : %d\n", i, *(p + i));
        // printf( "*(p + %d) : %d\n", i, *(&p[i])); //等同
        // printf( "*(p + %d) : %d\n", i, p[i]); //等同
    }
    printf("put anything to close\n");
    getchar();
    getchar();
    return 0;
}
