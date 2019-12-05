#include <stdio.h>

void inv2(int *x, int n) /*形参x为指针变量*/
{
    int *p; //
    int temp;
    int *i;
    int *j;
    int m = (n - 1) / 2;

    i = x; //指向数组第一个元素
    j = x + n - 1; //指向数组最后一个元素
    p = x + m; //指向中间元素
    for (; i <= p; i++, j--)
    {}
        //前后对应的数据进行交换
        temp = *i;
        *i = *j;
        *j = temp;
    }
    return;
}

void inv(int x[], int n) /*形参x是数组名*/
{
    int temp;
    int i;
    int j;
    int m = (n - 1) / 2;

    for (i = 0; i <= m; i++)
    {
        j = n - 1 - i;
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
    return;
}

int main()
{
    int i;
    int a[10];
    printf("please input array a:\n");
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    printf("The oriGinal array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
    //inv(a, 10);
    inv2(a, 10);
    printf("The array has been inverted:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

    getchar();
}