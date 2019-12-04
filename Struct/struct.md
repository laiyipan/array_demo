#Struct(结构体)
##1.应用情形
###1.1物联网
项目：LoRa通信
目的：理解结构体在通信项目中的具体应用。
项目涉及主要文件：
|文件名|说明|
|-----|---|
|main.c|包含main(),具体应用逻辑|
|sx1276Lora.h|LoRa射频芯片驱动头文件|
|sx1276Lora.c|LoRa射频芯片驱动|

在main.c中：
```C
#include "sx1276Lora.h" //引用LoRa驱动的头文件
int main(void)
{
  App_LoRa_Init();//LoRa初始化
}

```
在sx1276Lora.h中：
```C
void App_LoRa_Init(void);//lora应用层初始化
```

在sx1276Lora.c中：
```C
//LoRa初始化
void App_LoRa_Init(void)
{
    LoRaWL = RadioDriverInit();
    LoRaWL->Init();
    LoRaWL->RFRxStateEnter();
    LoRaRxStateEnter();
    SX1276WriteRx(); // ENABLE RX
}

tRadioDriver* RadioDriverInit( void );//返回结构体指针

tRadioDriver RadioDriver;//定义结构体
tRadioDriver *LoRaWL = 0;//结构体指针
//射频驱动初始化
tRadioDriver* RadioDriverInit( void )
{
    RadioDriver.Init = SX1276Init; //sx1276射频芯片初始化 方法
    RadioDriver.Reset = SX1276Reset;//sx1276射频芯片复位 方法
    RadioDriver.StartRx = SX1276StartRx;
    RadioDriver.GetRxPacket = SX1276LoRaGetRxPacket;
    RadioDriver.SetTxPacket = SX1276LoRaSetTxPacket;
    RadioDriver.Process = SX1276LoRaProcess;

    RadioDriver.RFDio0State = SX1276Dio0State;
    RadioDriver.RFGetPacketSnr = GetLoRaSNR;
    RadioDriver.RFGetPacketRssi = GetPackLoRaRSSI;
    RadioDriver.RFReadRssi = SX1276LoRaReadRssi;
    RadioDriver.RFRxStateEnter = LoRaRxStateEnter;
    RadioDriver.RFRxDataRead = LoRaRxDataRead;
    RadioDriver.RFTxData = LoRaTxData;
    RadioDriver.RFTxPower = LoRaTxPower;
    RadioDriver.RFFreqSet = SX1276LoRaSetRFFrequency;
    RadioDriver.RFOpModeSet = SX1276LoRaSetOpMode;

    RadioDriver.RFCADModeEnter = SX1276CADModeEnter;

    return &RadioDriver;
}
///LoRa射频参数设置
typedef struct sLoRaSettings
{
    uint32_t RFFrequency; //频率
    int8_t Power; //功率
    uint8_t SignalBw;  //信号带宽 LORA [0: 7.8 kHz, 1: 10.4 kHz, 2: 15.6 kHz, 3: 20.8 kHz, 4: 31.2 kHz,
    // 5: 41.6 kHz, 6: 62.5 kHz, 7: 125 kHz, 8: 250 kHz, 9: 500 kHz, other: Reserved]
    uint8_t SpreadingFactor;  // 扩频因子 LORA [6: 64, 7: 128, 8: 256, 9: 512, 10: 1024, 11: 2048, 12: 4096  chips]
    uint8_t ErrorCoding;      // 误差编码 误码 LORA [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
    bool CrcOn;               // 是否CRC校验[0: OFF, 1: ON]
    bool ImplicitHeaderOn;    // 是否隐式头部[0: OFF, 1: ON]
    bool RxSingleOn;          // 是否接收单次[0: Continuous, 1 Single]
    bool FreqHopOn;           // 是否跳频[0: OFF, 1: ON]
    uint8_t HopPeriod;        // 跳频周期：Hops every frequency hopping period symbols
	uint32_t TxPacketTimeout; //发送包超时
    uint32_t RxPacketTimeout; //接收包超时
    uint8_t PayloadLength; //payload 长度
} tLoRaSettings;

// Default settings 默认的设置
tLoRaSettings LoRaSettings =
{
    470000000, //470000000,       /* 载波频率 */
    20,//20,               /* 发射功率 */


    /* Modified by liulei for test (Begin) */
    8,//9,//7,                /* 带宽  [0: 7.8kHz, 1: 10.4 kHz, 2: 15.6 kHz, 3: 20.8 kHz, 4: 31.2 kHz,
    //                   5: 41.6 kHz, 6: 62.5 kHz, 7: 125 kHz, 8: 250 kHz, 9: 500 kHz, other: Reserved] */
    12,//7,//10,               /* 扩频因数 [6: 64, 7: 128, 8: 256, 9: 512, 10: 1024, 11: 2048, 12: 4096  chips] */
    1,///1,                // ErrorCoding [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
    /* Modified by liulei for test (End) */

    true,             /* CRC 校验 [0: OFF, 1: ON] */
    false,            // ImplicitHeaderOn [0: OFF, 1: ON] /* 包头模式 */
    (bool)0,                // RxSingleOn [0: Continuous, 1 Single] /* 固定为设置0 */
    (bool)0,                // FreqHopOn [0: OFF, 1: ON]  /* 固定为设置0 */
    4,                // HopPeriod Hops every frequency hopping period symbols
    100,              // TxPacketTimeout
    100,              // RxPacketTimeout
    128,              // PayloadLength (used for implicit header mode)
};
```
成员为函数指针的结构体：
```C
//射频驱动 结构体
typedef struct sRadioDriver
{
    void ( *Init )( void );
    void ( *Reset )( void );
    void ( *StartRx )( void );
    void ( *GetRxPacket )( void *buffer, uint16_t *size );
    void ( *SetTxPacket )( const void *buffer, uint16_t size );
    uint32_t ( *Process )( void );
    uint8_t ( *RFDio0State )(void);
    int8_t  ( *RFGetPacketSnr)( void );
    double ( *RFGetPacketRssi)( void );
    double ( *RFReadRssi)( void );
    void ( *RFRxStateEnter )(void);
    void ( *RFRxDataRead )(uint8_t *pbuf, uint8_t *size );
    uint8_t ( *RFTxData )(uint8_t *pbuf, uint8_t size );
    void ( *RFTxPower)(uint8_t pwr );
    void ( *RFFreqSet)(uint32_t freq );
    void ( *RFOpModeSet)(uint8_t opMode);

    void ( *RFCADModeEnter )(void);
} tRadioDriver;

```



枚举的使用（摘自sx1276Lora.c)：
```C
//RFLR(射频状态)枚举。
typedef enum
{
    RFLR_STATE_IDLE,
    RFLR_STATE_RX_INIT,
    RFLR_STATE_RX_RUNNING,
    RFLR_STATE_RX_DONE,
    RFLR_STATE_RX_TIMEOUT,
    RFLR_STATE_TX_INIT,
    RFLR_STATE_TX_RUNNING,
    RFLR_STATE_TX_DONE,
    RFLR_STATE_TX_TIMEOUT,
    RFLR_STATE_CAD_INIT,
    RFLR_STATE_CAD_RUNNING,
} tRFLRStates;
```
##2.知识点
- 结构体类型定义、变量定义、初始化以及使用方法
- 结构体数组
- 结构体指针
- 共用体
- 枚举
- typedef
###2.1 Struct与Union的区别
union （ 共用体）：构造数据类型,也叫联合体 
 用途：使几个不同类型的变量共占一段内存(相互覆盖) 

struct ( 结构体 )：是一种构造类型
 用途： 把不同的数据组合成一个整体——自定义数据类型


主要区别：
1. struct和union都是由多个不同的数据类型成员组成, 但在任何同一时刻, union中只存放了一个被选中的成员; 而struct的所有成员都存在。在struct中，各成员都占有自己的内存空间，它们是同时存在的,一个struct变量的总长度等于所有成员长度之和，遵从字节对其原则; 在Union中，所有成员不能同时占用它的内存空间，它们不能同时存在 , Union变量的长度等于最长的成员的长度。 

2. 对于union的不同成员赋值, 将会对其它成员重写, 原来成员的值就不存在了,所以，共同体变量中起作用的成员是最后一次存放的成员; 而对于struct的不同成员赋值是互不影响的。

实践：定义一个Union，至少包含两种类型的字段（比如int和char），每次给一个字段赋值，然后输出各字段的值。

###2.2 结构体使用
将结构体变量传递给另一个函数，有3种方法：
- 用结构体变量的成员作参数
- 传值
- 传址

###2.3 枚举
####定义
```C
enum weekday
{
	SUN，
	MON，
	TUE，
	WED，
	THU，
	FRI，
	SAT，
};
```
####赋值规则
- 第一个值若不指定，默认是0，以下+1
- 可以随意指定每个值的大小，但若不指定，则是上一个值+1，且不能重复

###2.4 typedef
####作用
给已有的类型名起个别名
```C
typedef　int   INTEGER；
typedef　struct
{
          int　month；
　　　　   int　day；
　　　　   int　year；　　　    
}DATE；
```
####好处
- 不能用来定义变量。
- 没有创造新的类型。
- #define是在预编译时处理的，它只作简单的字符串替换，而typedef是在编译时处理的。
- *有利于程序的通用与移植。



