int find_mean(float mean_set[max],float cluster_set[max][max],int k,int n)
{
	int i,j,mean=0,count=0;
	for(i=0;i<k;i++)
	{
	 for(j=0;j<n;j++)
	  {
	   if(cluster_set[i][j]!=0)
	    {
	     count++;
	     mean+=cluster_set[i][j];}
	   }
	  if(count!=0)
	   {
	    mean=(int)(mean/count);
	    mean_set[i]=mean;
	    count=0;mean=0;}
	  mean=0;
        }
return 0;//(mean_set);
}
int find_min_index(int k,float distance[max])
{
	int min_index=0,i;
	for(i=1;i<k;i++)
	{
	 if(distance[min_index]>distance[i])
	  {
	   min_index=i;}
	}
return(min_index);
}
int cluster(int k,float mean_set[max],float cluster_set[max][max],float data_set[max],int n)
{
	int min_index,i,j;
	float distance[max],mean_set2[max];
	while(1){	
	  for(i=0;i<n;i++)
	  {
	   for(j=0;j<k;j++)
	    {
	      distance[j]=abs(data_set[i]-mean_set[j]);
	      mean_set2[j]=mean_set[j];
	    }
	    min_index=find_min_index(k,distance);
	    cluster_set[min_index][i]=data_set[i];
	   }
	  find_mean(mean_set,cluster_set,k,n);
	  if(mean_set[0]==mean_set2[0]&&mean_set[1]==mean_set2[1])
	    {break;}
	}
return 0;//(cluster_set);
}
int k(float data_set[max],int k)
{
	//int data_set[max]={1,2,3,4,5,6,7,8,19,29,24,25,26,19,30,31};
	float mean_set[max],cluster_set[max][max];
	int random_index,i,j,n=25;
	//printf("give the value of k");
	//scanf("%d",&k);
	printf("initial randomly choose mean values are\n");
	srand(time(NULL));	
	for(i=0;i<k;i++)
	{
	 random_index=(int)rand() % (25+1-0)+0;//random no between 17 and 0
	 mean_set[i]=data_set[random_index];
	 printf("%f  ",mean_set[i]);
	}
	cluster(k,mean_set,cluster_set,data_set,n);
	printf("\nCluster sets are:\n\n");
	for(i=0;i<k;i++)
	{
  	 for(j=0;j<n;j++)
 	 {if(cluster_set[i][j]!=0)
	  {printf("%f  ",cluster_set[i][j]);}
	 }
	 printf("\n\n\n");
	}
return 0;	
}
