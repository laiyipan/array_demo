#Array（数组）
##1.应用情形
项目：LoRa通信
目的：理解数组在通信项目中的具体应用。
项目涉及主要文件：
|文件名|说明|
|-----|---|
|main.c|包含main(),具体应用逻辑|
|sx1276Lora.c|LoRa射频芯片驱动|
在sx1276Lora.c中：
```C
//跳频的频率
const int32_t HoppingFrequencies[] =
{
    916500000,
    923500000,
    906500000,
    917500000,
    917500000,
    //......... 省略一些代码
    915000000,
    913000000,
    907000000,
    910000000,
    926500000,
    925500000,
    911000000,
};

//以下为代码片段
//.........
 case RFLR_STATE_TX_RUNNING:
        if( DIO0 == 1 ) // TxDone
        {
            // Clear Irq
            SX1276Write( REG_LR_IRQFLAGS, RFLR_IRQFLAGS_TXDONE  );
            RFLRState = RFLR_STATE_TX_DONE;
        }
        if( DIO2 == 1 ) // FHSS Changed Channel
        {
            if( LoRaSettings.FreqHopOn == true )//如果需要跳频
            {
                SX1276Read( REG_LR_HOPCHANNEL, &SX1276LR->RegHopChannel );
                SX1276LoRaSetRFFrequency( HoppingFrequencies[SX1276LR->RegHopChannel & RFLR_HOPCHANNEL_CHANNEL_MASK] );//设置频率
            }
            // Clear Irq
            SX1276Write( REG_LR_IRQFLAGS, RFLR_IRQFLAGS_FHSSCHANGEDCHANNEL );
        }
        break;
//......
```

##2.知识点
- 数组的本质
- 一维数组的定义、初始化、使用方法
- 二维数组的定义、初始化、使用方法
- 字符数组的定义、初始化、使用方法
###2.1 数组含义
数组：相同类型的值的集合
- 有序数据的集合
- 每一个元素都属于同一个数据类型
- 用数组名和下标来唯一地确定数组中的元素
- 内存中连续存放
###2.2 一维数组
```C
int a[10];
int a［10］={0，1，2，3，4，5，6，7，8，9};
int a［10］={0，1，2，3，4};
int a［］={1，2，3，4，5}
a［0］=a［5］+a［7］-a［2*3］
```
###2.3 二维数组
```C
float a[3][4];
int b[5][4]；

```
二维数组在内存中的存放：
- 按行存放
- 连续空间
![数组内存分配](pics\array_mem.png "数组内存分配")

```C
int a[2][4]={{1，2，3，4}，{5，6，7，8}}；
int a[3][4]={{1}，{0，6}，{0，0，11}};
int a[][4]={1，2，3，4，5，6，7，8，9，10，11，12};
```

###2.4 字符数组
```C
char a[10];
char c［8］={'N'，' e'，'w'，'c'，' a'，'p'，'e'，'c'};
//初值个数 > 数组长度  语法错误
//初值个数 < 数组长度 后补'\0'
char c[9]=”Newcapec”;
char c[9]={“Newcapec”};
```
格式化输入输出:
逐个字符输入输出。用格式符“%c”
将整个字符串一次输入或输出。用“%s”格式符（遇'\0'结束）

怎么给这个数组赋值呢？
1、定义的时候直接用字符串赋值
```C
char a[10]="hello";
```
注意：不能先定义再给它赋值，如char a[10]; a[10]="hello";这样是错误的！
2、对数组中字符逐个赋值
```C
char a[10]={'h','e','l','l','o'};
```
 3、利用strcpy
 ```C
 char a[10]; strcpy(a, "hello");
 ```
易错情况：
1、
```C
char a[10]; a[10]="hello";//一个字符怎么能容纳一个字符串？况且a[10]也是不存在的！
```

2、
```C
char a[10]; a="hello";//这种情况容易出现，a虽然是指针，但是它已经指向在堆栈中分配的10个字符空间，现在这个情况a又指向数据区中的hello常量，这里的指针a出现混乱，不允许！
```

C语言的运算符根本无法操作字符串。在C语言中把字符串当作数组来处理，因此，对字符串的限制方式和对数组的一样，特别是，它们都不能用C语言的运算符进行复制和比较操作。


直接尝试对字符串进行复制或比较操作会失败。例如，假定str1和str2有如下声明：
```C
char str1[10], str2[10];
```

利用=运算符来把字符串复制到字符数组中是不可能的：
```C
str1 = "abc";     /*** WRONG ***/

str2 = str1;       /*** WRONG ***/
```

C语言把这些语句解释为一个指针与另一个指针之间的（非法的）赋值运算。但是，使用=初始化字符数组是合法的：
```C
char str1[10] = "abc";
```
这是因为在声明中，=不是赋值运算符。

试图使用关系运算符或判等运算符来比较字符串是合法的，但不会产生预期的结果：
```C
if (str1==str2) ...    /*** WRONG ***/
```
这条语句把str1和str2作为指针来进行比较，而不是比较两个数组的内容。因为str1和str2有不同的地址，所以表达式str1 == str2的值一定为0。