#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//ǥ�� �Է����� ����� ũ�� m, n�� ���� ����� �Էµ�
	//*�� �����̰� .�� ���ڰ� �ƴ�
	//���ڰ� �ƴ� ��ҿ����� ������ ������ ������ �����

	//���� ũ�⸦ ����
	int m, n;
	scanf("%d %d", &m, &n);

	//������ ���� ũ�⸦ ������� �� ��� (matrix)�� ����
	char** matrix = (char**)malloc(sizeof(char*) * (m));
	for (int i = 0; i < m; i++)
	{
		matrix[i] = (char*)malloc(sizeof(char) * (n + 1));
	}

	//�� �ʱ�ȭ(initializing)
	for (int i = 0; i < m; i++)
	{
		scanf("%s", matrix[i]);
	}

	//�ʿ��� ������ ���� ���ڰ� �ƴ� ���� ����
	//���ڰ� �ƴ� ���� ��� �ֺ�(������) ������ ������ ���
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] != '*')
			{
				//������ ����
				int cnt = '0';
				for (int a = i - 1; a <= i + 1; a++)
				{
					for (int b = j - 1; b <= j + 1; b++)
					{
						if ((a < 0 || b < 0) || (a >= m || b >= n)) continue;
						else
						{
							if (matrix[a][b] == '*')
								cnt++;
						}
					}
				}
				matrix[i][j] = cnt;
			}
		}
	}

	//�� ������ ���
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}

	//�����Ҵ� ����
	for (int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
	return 0;
}