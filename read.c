#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 200
#define size 10
int std(int data_matrix[][],int n);//n= number of data set
int main()
{
	FILE *fp;
	fp=fopen("data.txt","r");
	char ch,str[15];
	int count=1,count1=0,data_set_count=0;
	static int data_matrix[size][size],data_set[max];
	ch=fgetc(fp);
	str[count1]=ch;
	while(1)
	{
		if(ch==' '||ch=='\n')
		{
			count++;
			str[count1]='\0';
			
			data_set[data_set_count]=atoi(str);
			printf("%s\t%d\t",str,data_set[data_set_count]);
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
	printf("\n\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			data_matrix[i][j]=data_set[data_set_count];
			printf("%d\t",data_matrix[i][j]);
			if(data_set[data_set_count]!=0)
				data_set_count++;
		}
		printf("\n");
	}
	std(data_matrix,data_set_count);
fclose(fp);
return 0;
}
int std(int data_matrix[size][size])
{
	float std_matrix[size][size];
	
	
}



















