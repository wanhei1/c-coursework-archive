#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int m,n,t,flag[100006]={0}, next[100006][2]={0},head[100006]={0},end[100006]={0},num[100006]={0};
	scanf("%d %d",&n,&m);
	int i,j,x,y;
	for(i=1;i<=n;i++)//为了方便思考，n组数据我们选择从1到n而不是从0到n-1 
	{
		head[i]=i; end[i]=i; num[i]=1;//初始的时候是每个盒子里放着一个物品，是第几个盒子物品编号就是几 
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld",&x,&y);
		if(num[x]==0) continue;//每次输入的第一个盒子是空的的话，直接跳过了 
		else
		{
			if(num[y]==0)//如果第二个盒子是空的，直接倒着装进去就行了，很好理解
			{
				head[y]=end[x];
				end[y]=head[x];
			}
			else
			{
				if(next[head[x]][1]==0)      next[head[x]][1]=head[y]; //第一个盒子内的head物体只有一个邻居，所以看next中两个位置哪个空就把y的head物体放进去 
				else if(next[head[x]][0]==0) next[head[x]][0]=head[y];
				if(next[head[y]][1]==0)      next[head[y]][1]=head[x];//同理，给x的head配上邻居，也得对y进行同样的操作 
				else if(next[head[y]][0]==0) next[head[y]][0]=head[x];
				head[y]=end[x];// 第二个盒子新的head就是第一个盒子原来的end 
			}
			num[y]+=num[x];//别忘更新物体数量 
		    head[x]=0;//第一个盒子就空了 
		    end[x]=0;
		    num[x]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(num[i]==0) printf("0\n");
		else
		{
			printf("%d",num[i]);
			printf(" %d",head[i]);
			flag[head[i]]=1;//用flag数组存储数据是不是输出过了，输出过了设为1 
			t=head[i];
			for(j=1;j<num[i];j++)
			{
				if(next[t][0]!=0&&flag[next[t][0]]!=1) 
				{
					printf(" %d",next[t][0]);
					t=next[t][0];
					flag[t]=1;
				}
				if(next[t][1]!=0&&flag[next[t][1]]!=1)
				{
					printf(" %d",next[t][1]);
					t=next[t][1];
					flag[t]=1;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
