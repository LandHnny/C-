/*�ǳ����֣�
��ĿҪ�����ٵĵ�������������Ҫͳ�ƴ�����
����ƽ�ֵ�����Ϊ�����������ڿ�����ȣ�������Ϊ�ա�
a������������ѡ�񣺽����ֵ���b���������ֵ���c��
���Ե�������Ϊ��a�����ǿձ�,Ҫ����ı�������

��֪�����������һ���Թ������·����ͬ��
����ĿҪ�����ٵĲ���������Ҫͳ�ƴ�����
����������Ϊ�������յ㡣
ÿһ��������ѡ�������ϱ���
�����ߵ�����Ϊ����һ����Ϊǽ����

ʹ�ù��������
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<memory.h>

using namespace std;
//����ÿ��������
int bei[3];
//����ÿ�������ݣ�ǰ����Ϊ���ӵ�״̬����һ��Ϊ�ﵽ���״̬���˼���
int zt[100][4], end = 0;


bool ispf(int n)
{
	//�ж��ǲ�������ƽ������
	if (zt[n][0] == zt[n][1] && zt[n][2] == 0
		|| zt[n][0] == zt[n][2] && zt[n][1] == 0
		|| zt[n][1] == zt[n][2] && zt[n][0] == 0)
	{
		return 1;
	}
	//���������������һ��
	else
	{//�����������Ƿ���Ե�
		for (int i = 0; i<3; i++)
		{
			//�жϸñ��Ƿ�Ϊ��
			if (zt[n][i] != 0)
			{
				for (int j = 0; j<3; j++)
				{
					//���������������Ƿ���ϱ�������ֵ�����
					if (j != i && zt[n][j]<bei[j])
					{
						//ds���汻������ֵı���ʣ�Ŀռ�
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
						//�����ж��Ƿ��ظ���֮ǰ��״̬
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
		//��ʼ��zt����
		memset(zt, 0, sizeof(int) * 400);
		//�����Ϊ˫�����޷�ƽ��
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