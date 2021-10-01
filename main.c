/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:10:53 by lcandido          #+#    #+#             */
/*   Updated: 2021/09/30 23:23:58 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

void	echo(char **command)
{
	int	has_n;
	int		i;

	i = 1;
	has_n = 0;
	if (command[1] && ft_strcmp(command[1], "-n") == 0)
	{
		has_n = 1;
		i = 2;
	}
	while (command && command[i])
	{
		printf("%s ", command[i]);
		i++;
	}
	if (has_n == 0)
		printf("\n");
}

void	pwd(void)
{
	char	cwd[2048];
	char	*buf;

	buf = NULL;
	buf = getcwd(cwd, sizeof(cwd));
	if (buf != NULL)
		printf("%s\n", buf);
	else
		printf("ERROR: PWD\n");
}

void	print_command(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		printf("%d: %s\n", i, command[i]);
		i++;
	}
}

void	free_command(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(command);
}

static void	loop(void)
{
	char	*prompt;
	char	*cmd;
	char	**command;
	char	cwd[2048];

	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			prompt = ft_strjoin(getcwd(cwd, sizeof(cwd)), "$ ");
		printf("..:: MINIsHELL ::.. ");
		cmd = readline(prompt);
		command = ft_split(cmd, ' ');
		free(cmd);
		free(prompt);
		if (!ft_strcmp("exit", command[0]))
		{
			free_command(command);
			break;
		}
		else if (!ft_strcmp("pwd", command[0]))
			pwd();
		else if (!ft_strcmp("echo", command[0]))
			echo(command);
		free_command(command);
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1 && argv)
	{
		printf("ERROR: MANY ARGS\n");
		return (0);
	}
	loop();
	return (1);
}
