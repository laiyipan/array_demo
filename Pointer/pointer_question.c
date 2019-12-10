#include <stdio.h>
/*
*注意静态变量与非静态变量，在内存处理上的区别
*
*/
int *func()
{
    static int n = 100; //静态变量
    return &n;          //如果不是静态变量，在函数返回后，指针指向的内容已经被释放，调用就会出错。
    //但可以返回指向局部静态变量的指针，因为静态变量的生存期从定义起到程序结束。
}
int func1()
{
    int n = 100;
    return n; //可以返回局部变量的值
}

char *returnStr()
{
    char *p = "hello world!"; //常量存放在只读数据段（全局变量数据区），函数退出时，内存不被回收
    return p;                 //可以返回指向字符串常量的局部指针
}
char *returnStr1()
{
    static char p[] = "hello world!";
    return p;
}
int *returnArr()
{
    static int a[] = {1, 2, 3};
    return a;
}

char *GetMemory3(int num)
{
    char *p = (char *)malloc(sizeof(char) * num);
    return p; //返回指向堆内存的指针(调用malloc函数得到的指针)是可以的
}
void printAddr()
{
    int a = 1;
    char arr[] = {1, 2, 3};
    char *p;
    p = arr;
    printf("%X\n", &a);
    printf("%X\n", arr);
    // printf("%X",&arr);
    printf("%X\n", arr + 1);
    printf("%X\n", p + 1);
}
int main()
{
    printAddr();

    int *p;
    p = func();
    int a;
    a = *p;
    printf("value=%d\n", a);

    char *str;
    str = returnStr1();
    printf("value=%s\n", str);

    int *pa;
    pa = returnArr();
    printf("value=%d\n", *(pa + 1));

    char *str1 = NULL;
    str1 = GetMemory3(100);
    strcpy(str1, "hello");
    printf("%s\n", str1);
    free(str1);
    printf("%s\n", str1); //不会再输出str1的值，内存已经被释放
    //程序在运行的时候用 malloc 申请任意多少的内存,程序员自己负责在何时用 free释放内存。动态内存的生存期由程序员自己决定,使用非常灵活。

    system("pause");
    return 0;
}