/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/09 12:56:05 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_echo(char **argv, char **env)
{
	int	i;
	int	space;
	char	*var_env;

	i = 1;
	space = 0;
	while (argv[i])
	{
		if (space == 1)
			ft_printf(" ");
		else
			space = 1;
		if (argv[i][0] == '$')
		{
			if ((var_env = ft_getenv(argv[i] + 1, env)))
				ft_printf("%s", var_env);
			else
				space = 0;
		}
		else
			ft_printf("%s", argv[i]);
		i++;
	}
	ft_printf("\n");
}
