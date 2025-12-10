#include <stdlib.h>
#include <stdio.h>

int final = 0;

char **makeboard(int n)
{
	int col;
	int idx = 0;
	char **map = malloc(sizeof(char *)*n);
	while (idx < n)
	{
		map[idx] = malloc(n);
		col = 0;
		while (col < n)
		{
			map[idx][col] = '-';
			col++;
		}
		idx++;
	}
	return (map);
}

void	printboard(char **map, int n)
{
	int idx = 0;
	while (idx < n)
	{
		printf("%s\n", map[idx]);
		idx++;
	}
}

int	issafe(char **map, int n, int row, int col)
{
	int r;
	int c;

	r = 0;
	while (r < row)
	{
		if (map[r][col] == 'Q')
			return (0);
		r++;
	}

	r = row;
	c = col;
	while (r >= 0 && c >= 0)
	{
		if (map[r][c] == 'Q')
			return (0);
		r--;
		c--;
	}
	r = row;
	c = col;
	while (r >= 0 && c < n)
	{
		if (map[r][c] =='Q')
			return (0);
		r--;
		c++;
	}
	return (1);

}

void permute(char **map, int n, int row)
{
	if (row == n)
	{
		printboard(map, n);
		printf("\n");
		final++;
	}
	int col =0;
	while (col < n)
	{
		if (issafe(map, n, row, col))
		{
			map[row][col] = 'Q';
			permute(map, n, row+1);
			map[row][col] = '-';
		}
		col++;
	}
}

int	main(void)
{
	int n =8;
	char **map = makeboard(n);
	permute(map, n, 0);
	printf("final: %d\n", final);
	return (0);
}