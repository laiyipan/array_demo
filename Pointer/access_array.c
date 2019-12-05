#include <stdio.h>
//三种方法访问数组
int main()
{
	int a[10];
	int i;
	int* p;
	for(i=0;i<10;i++)
	{
		a[i]=i;
	}
	p=a;
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",*(a+i));
	}
	printf("\n");
	for(p=a;p<(a+10);p++)
	{
		printf("%d ",*p);
	}
	getchar();
}