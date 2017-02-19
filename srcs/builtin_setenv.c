/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:23:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/19 12:33:44 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setenv_one(char *env_entryname, char *env_newentry, char ***env)
{
	char	**envptr;

	if ((envptr = ft_getenvptr(env_entryname, *env)))
	{
		free(*envptr);
		*envptr = ft_strdup(env_newentry);
	}
	else
	{
		*env = ft_strtabappend(*env, env_newentry);
	}
	return (1);
}

int	builtin_setenv(char **argv, char ***env)
{
	int		i;
	int		len;
	char	*env_entryname;

	i = 1;
	while (argv[i])
	{
		len = ft_strchr(argv[i], '=') - argv[i];
		env_entryname = strndup(argv[i], len);
		setenv_one(env_entryname, argv[i], env);
		ft_strdel(&env_entryname);
		i++;
	}
	return (1);
}
