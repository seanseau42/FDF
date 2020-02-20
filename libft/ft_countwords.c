/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwords.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 19:09:56 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 16:00:16 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_countwords(char *str, char c)
{
	unsigned int	i;
	int				nbwords;

	nbwords = 0;
	if (str[0] != c)
		nbwords++;
	i = 1;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0' && str[i - 1] == c)
			nbwords++;
		i++;
	}
	return (nbwords);
}
