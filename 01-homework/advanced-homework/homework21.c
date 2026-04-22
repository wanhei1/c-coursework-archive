 #include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j,current;scanf("%d",&n);//输入数字菱形的关键数（最大数）
	int max=2*n-1;//max为菱形中间行的元素个数，也是菱形的行数
	for(i=1;i<=max;i++)//i为当前行数
	{
		for(j=1;j<=max-abs(i-n);j++)//j为行数下的列数，第i行的元素个数由第i行和中间行（第n行）的间隔确定
		{
			current=1+abs(i-n)+abs(j-n);
			//对于第i行，第n列（菱形的中心线）上的元素为1+abs(i-n)，以此为基准，确定第j列的元素为+abs(j-n)
			if(current>n) printf("  ");
			//如果元素超过外围数（关键数），打印空格
			else printf("%-2d",current);
			//不超过则打印数字
		}
		printf("\n");//打印完每行后换行
	}
	return 0;
}