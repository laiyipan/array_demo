#include <stdio.h>

int main()
{
	int a;
	int b;
	int* p1;
	int* p2;
	int* p;
	scanf("%d,%d",&a,&b);
	p1=&a;
	p2=&b;
	if(a<b)
	{
        //把地址进行交换
		p=p1; 
		p1=p2;
		p2=p;
	}
	printf("max=%d,min=%d\n",*p1,*p2);
	system("pause");
}