#include <stdio.h>

void swap(int * p1,int * p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	return;
}

int main()
{
	int a;
	int b;
	int* p_pointer1;
	int* p_pointer2;
	scanf("%d,%d",&a,&b);
	p_pointer1=&a;
	p_pointer2=&b;
	if(a<b)
	{
		swap(p_pointer1,p_pointer2);
	}
	printf("a=%d,b=%d\n",a,b);
	system("pause");
}