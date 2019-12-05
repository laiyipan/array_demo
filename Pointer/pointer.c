#include <stdio.h>

#define FORMAT "0x%x,0x%x\n"
//二维数组地址和访问练习
void ArrayAddress()
{
    int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    printf(FORMAT, a, *a);           //第0行的地址，第0行的地址(简洁的表达形式)
    printf(FORMAT, a[0], *(a + 0));  //第0行的地址（a[0]中存放着第0行的地址)，第0行的地址
    printf(FORMAT, &a[0], &a[0][0]); //第0行的地址（带上索引下标了，前面加&），第0行的地址（既第一个元素的地址）

    printf(FORMAT, a[1], a + 1);            //第1行的地址，第1行的地址
    printf(FORMAT, &a[1][0], *(a + 1) + 0); //第1行的地址，第1行的地址

    printf(FORMAT, a[2], *(a + 2));              //第2行的地址，第2行的地址
    printf(FORMAT, &a[2], a + 2);                //第2行的地址，第2行的地址
    printf("%d,%d\n", a[1][0], *(*(a + 1) + 0)); //第1行第一个元素的值，第1行第一个元素的值
}

//返回指针的函数，输出不及格学生的成绩（有一科不及格，就全部输出）
//p1:指向数组的一个指针（指向一个有4个float元素的数组：二维数组的一行）
//指针数组：如果写成 float*pointer[4]:表示 pointer 是一个具有 4 个 float 类型指针的数组。
//p2:
//return:
float *search(float (*pointer)[4], int n)
{
    int i;
    float *pt;
    pt = *(pointer + n); //第n行的地址。这个自增运算会造成存储在数组指针
    //的地址增加一个数组空间大小，在本例中，即增加矩阵一行的空间大小，也就是 4 乘以 float 元素在内存中所占字节数量。

    for (i = 0; i < 4; i++)
    {
        if (*(pt + i) < 60) //取出第n行的元素值。
        {
            return pt; //返回第n行的地址
        }
    }
    return NULL; //返回空指针
}
//返回行的地址
float *searchStudent(float (*pointer)[4], int n)
{
    float *pt;
    pt = *(pointer + n); //第n行的地址
    return pt;
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}
//p3:指向函数的指针
int process(int x, int y, int (*fun)(int, int))
{
    int result;
    result = (*fun)(x, y);
    printf("result=%d\n", result);
    return result;
}

int main()
{
    //ArrayAddress();

    int m;
    int i;
    int j;
    float *p;
    float score[][4] = {{22, 33, 44, 11}, {21, 31, 41, 51}, {23, 24, 25, 26}, {70, 88, 99, 67}}; //学生以及各科的成绩
    for (i = 0; i < 4; i++)
    {
        p = search(score, i);  //p：第i行的地址（该行有元素值<60)
        if (p == *(score + i)) //所返回的第i行的地址==第i行的地址
        {
            printf("Num%d scores:\n", i); //i:第几行
            for (j = 0; j < 4; j++)       //遍历该行的元素
            {
                printf("%f ", *(p + j)); //输出元素值
            }
            printf("\n");
        }
    }
    printf("num 1's score:");
    p = searchStudent(score, 1);
    for (i = 0; i < 4; i++)
    {
        printf("%f ", *(p + i));
    }

    //函数指针----------------------
    process(10, 10, add);//函数名传入
    process(10, 10, sub);
    //--------------------------
    int (*fun)(); //定义函数指针
    fun=add; //把函数名赋值给函数指针
    printf("10+20 sum=%d\n",(*fun)(10,20));//*fun:取出函数

    system("pause");
    return 0;
}