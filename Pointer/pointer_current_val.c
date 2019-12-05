#include <stdio.h>

int main()
{
	int a[10];
	int i;
	int* p;
	p=a;
	for(i=0;i<10;i++)
	{
		scanf("%d",p++);
	}

	printf("\n");
    p=p-1;  
	for(i=0;i<10;i++,p--) //注意指针减回去
	{
		printf("%d ",*p);
	}

	system("pause");
}