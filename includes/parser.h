/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugrug <gustavorugg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########          */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
**	--------------- STRUCT DECLARATIONS ---------------
*/

typedef enum e_name {
	ECHO_E,
	CD_E,
	PWD_E,
	EXPORT_E,
	UNSET_E,
	ENV_E,
	EXIT_E
}				t_name;

typedef struct s_command
{
	t_name				name;
	char				*flag;
	char				*redirect;
	char				*input;
	char				*output;
	struct s_command	*prev;
	struct s_command	*next;
}				t_command;

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

/*
**	parser.c
*/
t_command	*parser(t_token *token, char **str);

/*
**	command_lst.c
*/
t_command	*lst_command_new(t_name name);
void		lst_command_add_back(t_command **lst, t_command *new);
void		lst_command_cut(t_command *command);
t_command	*lst_command_last(t_command *lst);
void		lst_command_clear(t_command **lst);
#endif
