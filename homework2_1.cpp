#include<stdio.h>
#include<stdlib.h>
int find(int num,int &s,int &max)
{
  s+=num; 
  if(s<num)s=num;
  if (max<s) max=s;

}

int main()
{
    int s,max;
    int x,y,a[100][100],b[1000][100],i,j,t,n,sum,flag=0;
    char c;
    freopen("input.txt","r",stdin);   
    freopen("output.txt","w",stdout);
    scanf("%d",&y);
    scanf("%d",&x);
    for(i=0;i<y;i++)
    {
        for(j=0;j<x-1;j++)
        {        
        if (!(scanf("%d",&a[i][j])))  flag=-1; 
        scanf("%c",&c);
        if (c!=',') flag=-1; 
        }
    scanf("%d",&a[i][x-1]);
    }
   for(i=0;i<x;i++)
   {
   n=0;
       for(j=0;j<y;j++)
       {
       sum=0;
           for(t=j;t>=0;t--)
           {           
           sum=sum+a[t][i]; 
           b[n][i]=sum;
           n++;          
           }

       }
   }
   max=b[0][0];
   for(i=0;i<1000;i++)
   {
   s=b[i][0];
        for(j=1;j<x;j++)
        find(b[i][j],s,max);
   }
   if (flag==-1) printf("error!");
   else   printf("%d",max);
            
}
 
