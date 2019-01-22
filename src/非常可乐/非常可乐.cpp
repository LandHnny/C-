/*非常可乐：
题目要求最少的倒杯次数。（需要统计次数）
可以平分的条件为：其中两杯内可乐相等，第三杯为空。
a杯可乐有两种选择：将可乐倒向b杯，将可乐倒向c杯
可以倒的条件为：a杯不是空杯,要倒向的杯不满。

易知，该题与给定一个迷宫求最短路径相同。
（题目要求最少的步数。（需要统计次数）
结束的条件为：到达终点。
每一次有四种选择：向东西南北走
可以走的条件为：下一步不为墙。）

使用广度搜索。
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<memory.h>

using namespace std;
//保存每杯的容量
int bei[3];
//保存每步的数据，前三个为杯子的状态，后一个为达到这个状态倒了几次
int zt[100][4], end = 0;


bool ispf(int n)
{
	//判断是不是满足平分条件
	if (zt[n][0] == zt[n][1] && zt[n][2] == 0
		|| zt[n][0] == zt[n][2] && zt[n][1] == 0
		|| zt[n][1] == zt[n][2] && zt[n][0] == 0)
	{
		return 1;
	}
	//如果不满足则走下一步
	else
	{//看看三个杯是否可以倒
		for (int i = 0; i<3; i++)
		{
			//判断该杯是否为空
			if (zt[n][i] != 0)
			{
				for (int j = 0; j<3; j++)
				{
					//看看另外两个杯是否符合被倒入可乐的条件
					if (j != i && zt[n][j]<bei[j])
					{
						//ds保存被倒入可乐的杯还剩的空间
						int ds = bei[j] - zt[n][j];
						if (ds>zt[n][i])
						{
							zt[end + 1][0] = zt[n][0];
							zt[end + 1][1] = zt[n][1];
							zt[end + 1][2] = zt[n][2];
							zt[end + 1][i] = 0;
							zt[end + 1][j] = zt[n][j] + zt[n][i];
							zt[end + 1][3] = zt[n][3] + 1;
						}
						else
						{
							zt[end + 1][0] = zt[n][0];
							zt[end + 1][1] = zt[n][1];
							zt[end + 1][2] = zt[n][2];
							zt[end + 1][i] = zt[n][i] - ds;
							zt[end + 1][j] = bei[j];
							zt[end + 1][3] = zt[n][3] + 1;
						}
						//以下判断是否重复了之前的状态
						int k;
						for (k = 0; k <= end; k++)
						{
							if (zt[k][0] == zt[end + 1][0]
								&& zt[k][1] == zt[end + 1][1]
								&& zt[k][2] == zt[end + 1][2])
							{
								break;
							}
						}
						if (k == end + 1)
						{
							end++;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d", &bei[0], &bei[1], &bei[2]);
	while (bei[0] || bei[1] || bei[2])
	{
		//初始化zt数组
		memset(zt, 0, sizeof(int) * 400);
		//如果不为双数则无法平分
		if (bei[0] % 2 != 0)
		{
			printf("NO\n");
		}
		else
		{
			zt[0][0] = bei[0];
			int i;
			for (i = 0; zt[i][3] != 0 || i == 0; i++)
			{
				if (ispf(i))
				{
					printf("%d\n", zt[i][3]);
					break;
				}
			}
			if (zt[i][3] == 0)
			{
				printf("NO\n");
			}
		}
		scanf("%d%d%d", &bei[0], &bei[1], &bei[2]);
	}
	return 0;
}