#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//say hello
void sayHello()
{
    int i;
	char str[19]={'W','e','l','c','o','m','e',' ','t','o',' ','N','e','w','c','a','p','e','c'};
	for(i=0;i<19;i++)
	{
		printf("%c",str[i]);
	}
    printf("\n");
}
//冒泡排序
void bubbleSort()
{
    int a[10];
	int i,j,t;
	printf("input 10 numbers :\n");
	for (i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	for(j=0;j<10-1;j++)
	{
		for(i=0;i<10-j-1;i++)
		{
			if (a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	printf("the sorted numbers :\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
    printf("\n");
}
//输出图案
void printPic()
{
    //5行5列
    char diamond[][5] = {{' ', ' ', '*'}, {' ', '*', ' ', '*'}, {'*', ' ', ' ', ' ', '*'}, {' ', '*', ' ', '*'}, {' ', ' ', '*'}};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        printf("%c", diamond[i][j]);
        printf("\n");
    }
}
//把数组的行列置换
void exchangeArray()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2], i, j;
    printf("array a:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
            b[j][i] = a[i][j]; //赋值
        }
        printf("\n");
    }
    printf("array b:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
//get an array
int *getArray()
{
    static int r[10]; //定义静态数组，只有静态数组才能被返回。
    int i;
    int j;
    //   for ( i = 0; i < 10; ++i)
    //   {
    //      r[i] = i;
    //      printf( "r[%d] = %d\n", i, r[i]);
    //   }

    int len = sizeof(r) / sizeof(r[0]); //计算数组的长度
    for (i = 0; i < len; i++)
    {
        scanf("%d", &r[i]);
    }
    //数组逆向输出
    for (i = len - 1; i >= 0; i--)
    {
        printf("%d\n", r[i]);
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
    sayHello();
    printPic();
    bubbleSort();
    exchangeArray();

    p = getArray();
    for (i = 0; i < 10; i++)
    {
        //打印出数组中的每个元素
        printf("*(p + %d) : %d\n", i, *(p + i)); //让指针p增长，通过取地址中的值（*p），来获取值。
        // printf( "*(p + %d) : %d\n", i, *(&p[i])); //等同
        // printf( "*(p + %d) : %d\n", i, p[i]); //等同。（直接获取元素的值）
        //注意：请理解以上3种写法。
    }
    printf("put anything to close\n");
    getchar();
    getchar();
    return 0;
}
