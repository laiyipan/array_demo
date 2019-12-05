#include <stdio.h>

int main()
{
	char a[]="welcome to newcapec";
	char b[20];
	int i;
	for(i=0;*(a+i)!='\0';i++)
	{
		*(b+i)=*(a+i);
	}
	*(b+i)='\0';
	printf("string a is:%s\n",a);//输出方式1

	printf("string b is:");
	for(i=0;b[i]!='\0';i++)//输出方式2
	{
		printf("%c",b[i]);
	}
	printf("\n");
	getchar();
}