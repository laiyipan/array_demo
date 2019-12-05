#include <stdio.h>

int main()
{
	char* pName[]={"aaaaa","ccccc","ddd","eee","newcapec"};
	char** p; //指向指针的指针
	int i;
	for(i=0;i<5;i++)
	{
		p=pName+i;
		printf("%s\n",*p);
	}

    /* 
    int a[5]={1,2,3,4,5};
	char* pNum[]={&a[0],&a[1],&a[2],&a[3],&a[4]};
	char** p;
	p=pNum;
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d\n",**p);
		p++;
	}
   */
	getchar();
}

