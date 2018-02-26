#include "test.h"

void findposition(int **heat, char **piece)
{
	int i;
	int j;
	int check = 1;
	int pcd = 2147483647;
	int pcdx = 0;
	int pcdy = 0;
	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 25)
			{
				if(heat[i][j] == -1)
				{
					if (j - 1 >= 0 && (heat[i][j - 1] != -1 && heat[i][j - 1] < pcd))
					{
						pcd = heat[i][j - 1];
						pcdx = j - 1;
						pcdy = i;
						check = 1;
					}
					if (j+1 <= 24 && (heat[i][j + 1] != -1 && heat[i][j + 1] < pcd))
					{
						pcd = heat[i][j + 1];
						pcdx = j + 1;
						pcdy = i;
						check = 1;
					}
					if (i-1 >= 0 && (heat[i - 1][j] != -1 && heat[i-1][j] < pcd))
					{
						pcd = heat[i - 1][j];
						pcdx = j;
						pcdy = i - 1;
						check = 1;
					}
					if (i + 1 <= 10 && (heat[i + 1][j] != -1 && heat[i+1][j] < pcd))
					{
						pcd = heat[i + 1][j];
						pcdx = j;
						pcdy = i + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
}
