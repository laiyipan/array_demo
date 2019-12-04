#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//get an array
int *getArray()
{
    static int r[10];//定义静态数组，只有静态数组才能被返回。
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

    return r; //这是最简洁的一种写法。返回数组首个元素的地址
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
        //打印出数组中的每个元素
        printf("*(p + %d) : %d\n", i, *(p + i));//让指针p增长，通过取地址中的值（*p），来获取值。
        // printf( "*(p + %d) : %d\n", i, *(&p[i])); //等同
        // printf( "*(p + %d) : %d\n", i, p[i]); //等同。（直接获取元素的值）
        //注意：请理解以上3种写法。
    }
    printf("put anything to close\n");
    getchar();
    getchar();
    return 0;
}
