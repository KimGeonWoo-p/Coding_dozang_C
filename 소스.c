#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//표준 입력으로 행렬의 크기 m, n과 문자 행렬이 입력됨
	//*는 지뢰이고 .은 지뢰가 아님
	//지뢰가 아닌 요소에서는 인접한 지뢰의 개수를 출력함

	//맵의 크기를 설정
	int m, n;
	scanf("%d %d", &m, &n);

	//설정된 맵의 크기를 기반으로 한 행렬 (matrix)를 생성
	char** matrix = (char**)malloc(sizeof(char*) * (m));
	for (int i = 0; i < m; i++)
	{
		matrix[i] = (char*)malloc(sizeof(char) * (n + 1));
	}

	//맵 초기화(initializing)
	for (int i = 0; i < m; i++)
	{
		scanf("%s", matrix[i]);
	}

	//맵에서 지뢰인 블럭과 지뢰가 아닌 블럭을 구별
	//지뢰가 아닌 블럭인 경우 주변(인접한) 지뢰의 개수를 출력
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] != '*')
			{
				//지뢰의 갯수
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

	//맵 정보를 출력
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}

	//동적할당 해제
	for (int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
	return 0;
}