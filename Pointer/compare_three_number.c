#include <stdio.h>
void swap(int * p1,int * p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	return;
}

void myFun(int *p1,int* p2,int* p3)
{
	if(*p1<*p2)
	{
		swap(p1,p2);
	}
	if(*p1<*p3)
	{
		swap(p1,p3);
	}
	if(*p2<*p3)
	{
		swap(p2,p3);
	}
}

int main()
{
	int a;
	int b;
	int c;
	int* p_pointer1;
	int* p_pointer2;
	int* p_pointer3;
	scanf("%d,%d,%d",&a,&b,&c);
	p_pointer1=&a;
	p_pointer2=&b;
	p_pointer3=&c;
	myFun(p_pointer1,p_pointer2,p_pointer3);
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	system("pause");
}