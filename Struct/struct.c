#include <stdio.h>
//枚举
enum weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

//共用体
union myU
{
	int i;
	char a;
};

//项目
struct project
{
    char name[40];//名称
    int id;//序号
    int period;//时长
}project1,project2;

//工人
struct worker
{
    char name[20];//姓名
    int num; //工号
    int sal; //工资
} per[3] = {"Jason",1001, 8000, "Michael",1002, 10000, "David",1003, 12000};
//注：在初始化的时候，可以对char数组直接赋值。

typedef struct worker WORKER;//*给类型起个别名，请理解这样做的目的。

//输出星期
void printfDay(int d)
{
    switch (d)
    {
    case MONDAY:
        printf("1");
        break;
    case TUESDAY:
        printf("2");
        break;
    case WEDNESDAY:
        printf("3");
        break;
    case THURSDAY:
        printf("4");
        break;
    case FRIDAY:
        printf("5");
        break;
    case SATURDAY:
    case SUNDAY:
    default:
        printf("weekend");
        break;
    }
    return;
}
int main()
{
    int total = 0;
    int i;
    //计算所有人工资的和
    for (i = 0; i < 3; i++)
    {
        total = total + per[i].sal;
    }
    printf("sum of salary: %d\n", total);

    struct worker w;
    struct worker *p;
    w.num = 1004;
    w.sal = 9000;
    //w.name ="Cook"; //错误。让w.name再指向数据区中的Cook常量，这里的指针w.name出现混乱，不允许
    strcpy(w.name,"Cook"),//借助strcpy函数进行char数组赋值
    p = &w;
    printf("name:%s, number:%d, salary:%d\n",(*p).name,(*p).num, (*p).sal);

    WORKER worker[3]={
                                {"Tom",1005,8000},
                                {"Jerry",1006,10000},
                                {"Ray",1007,12000}
                            };//这种初始化方式更清楚
	for(p=worker;p<worker+3;p++)
	{
		printf("name:%s, number:%d, salary:%d\n",(*p).name,(*p).num,(*p).sal);
	}

    union myU uTest;
	uTest.i=97;
    printf("union info:\n");
	printf("i=%d, a=%c\n",uTest.i,uTest.a);
	uTest.a='b';
	printf("i=%d, a=%c\n",uTest.i,uTest.a);
    //注意Union和Struct的区别。

    enum weekday today;
    today = TUESDAY;
    printfDay(today);

    getchar();
    return 0;
}