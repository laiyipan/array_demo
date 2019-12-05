#include <stdio.h>

//求平均成绩
//注意：第一个参数：指向float值的指针
void average(float *p,int n)
{
	float*p_end;
	float sum=0;
	float aver;
	p_end=p+n-1;
	for(;p<=p_end;p++)
	{
		sum=sum+(*p);
	}
	aver=sum/n;
	printf("average=%5.2f\n",aver);
}

//查找不及格学生的成绩
void search2(float (*p)[4], int n)//n是总行数
{
	int i;
	int j;
	int flag;//不及格标志
	for(j=0;j<n;j++)
	{
		flag=0;
		for(i=0;i<4;i++)
		{
			if(*(*(p+j)+i)<60)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("No.%d fails,his scores are:\n",j+1);
			for(i=0;i<4;i++)
			{
				printf("%5.1f ",*(*(p+j)+i));
			}
			printf("\n");
		}
	}
}

//查找第N个学生的成绩
void search(float (*p)[4],int n)//n为第几行
{
	int i;
	printf("the score of No.%d are:\n",n);
	for(i=0;i<4;i++)
	{
		printf("%5.2f ",*(*(p+n)+i));
	}
	printf("\n");
}

int main()
{
	float score[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	average(score,12);
	search(score,2);
	search2(score,3);
	system("pause");
}