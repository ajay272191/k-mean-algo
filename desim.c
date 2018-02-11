#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 200
#define size 5
int std(int data_matrix[size][size],int n,int min,int maxd);//n= number of data set
int disim(float std_matrix[size][size],int data_matrix[size][size]);
int main()
{
	FILE *fp;
	fp=fopen("data.txt","r");
	char ch,str[15];
	int count=1,count1=0,data_set_count=0;
	static int data_matrix[size][size],data_set[max];
	int maxd,min;
	ch=fgetc(fp);
	str[count1]=ch;
	while(1)
	{
		if(ch==' '||ch=='\n')
		{
			count++;
			str[count1]='\0';
			
			data_set[data_set_count]=atoi(str);
			//printf("%s\t%d\t",str,data_set[data_set_count]);
			data_set_count++;
			strcpy(str," ");
			count1=0;
				
		}
		else if(ch==EOF)
			break;
			str[count1]=ch;
			count1++;
			ch=fgetc(fp);
	}
	data_set_count=0;
	printf("\nData matrix is\n\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			data_matrix[i][j]=data_set[data_set_count];
			printf("%d\t\t",data_matrix[i][j]);
			if(data_set[data_set_count]!=0)
				data_set_count++;
		}
		printf("\n\n");
	}
	min=data_set[0];
	maxd=data_set[0];
	for(int i=1;i<data_set_count;i++)
	{
		if(min>data_set[i])
			min=data_set[i];
		if(maxd<data_set[i])
			maxd=data_set[i];
	}
	std(data_matrix,data_set_count,min,maxd);
fclose(fp);
return 0;
}
int std(int data_matrix[size][size],int n,int min,int maxd)
{
	float std_matrix[size][size];
	float z,divisor=maxd-min;
	printf("Standardized matrix is\n\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(data_matrix[i][j]!=0)
			{
 			 z=(float)(data_matrix[i][j]-min)/divisor;
			 std_matrix[i][j]=z;
			 printf("%f\t",std_matrix[i][j]);
			}
			else
			 printf("%f\t",std_matrix[i][j]);
		}
		printf("\n");
	}
	disim(std_matrix,data_matrix);
return 0;
}
int disim(float std_matrix[size][size],int data_matrix[size][size])
{
	static float dsim_matrix[size][size],distance,data_set[max];
	printf("Dissimilarity matrix is\n");	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<size;k++)
			{
				distance+=pow((std_matrix[i][k]-std_matrix[j][k]),2);
			}
			distance=sqrt(distance);
			dsim_matrix[i][j]=distance;
			dsim_matrix[j][i]=distance;
			printf("%f\t",dsim_matrix[i][j]);
			distance=0;
		}
		printf("\n\n");
	}
	 
return 0;
}

















