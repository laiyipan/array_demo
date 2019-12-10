#include <stdio.h>

int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int (*p)[4];//指针数组：举例 {0x12,0x13,0x14,0x15}
	int i;
	int j;
	p=a;//p指向数组a的第一行
	scanf("%d,%d",&i,&j);//行，列

	printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));//注意这种访问二维数组元素的方式
	system("pause");
}