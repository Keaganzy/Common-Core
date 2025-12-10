/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:10:44 by marvin            #+#    #+#             */
/*   Updated: 2025/10/09 22:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solve(int c, int *pos, int n)
{
    if (c == n)
    {
        printf("[");
        for (int i = 0; i < n; i++)
            printf("%d%s", pos[i], i < n - 1 ? ", " : "");
        printf("]\n");
        return;
    }
    for (int r = 0; r < n; r++ )
    {
        int ok = 1;
        for (int i = 0; i < c; i++)
        {
            if (pos[i] == r || abs(pos[i] - r) == abs(i - c))
                ok = 0;
        }
        if (ok)
        {
            pos[c] = r;
            solve(c + 1, pos , n);
        }
    }
}

void nqueens(int n)
{
    int *pos;

    pos = calloc(n, sizeof(int));
    solve(0, pos, n);
    free(pos);
}


int main()
{
    nqueens(4);
}