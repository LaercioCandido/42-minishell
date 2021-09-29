/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:10:53 by lcandido          #+#    #+#             */
/*   Updated: 2021/09/29 19:37:14 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	pwd(void)
{
	char	cwd[2048];
	char	*buf;

	buf = getcwd(cwd, sizeof(cwd));
	printf("%s\n", buf);
}

static void	loop(void)
{
	char	*prompt;
	char	*command;
	char	cwd[2048];

	while (1)
	{
		prompt = "";
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			prompt = ft_strjoin(cwd, "$ ");
		command = readline(prompt);
		free(prompt);
		if (!strcmp("exit", command))
		{
			free(command);
			break;
		}
		if (!strcmp("pwd", command))
			pwd();
		free(command);
	}
}

int	main(int argc, char *argv[])
{
	//(void)argc;
	//(void)argv;
	if (argc > 1 && argv)
	{
		printf("ERROR: MANY ARGS\n");
		return (0);
	}
	loop();
	return (1);
}
