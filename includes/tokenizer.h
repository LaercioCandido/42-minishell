/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugrug <gustavorugg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########          */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

/*
**	--------------- STRUCT DECLARATIONS ---------------
*/

typedef enum e_type {
	COMMAND_E,
	FLAG_E,
	ARGUMENT_E,
	REDIRECT_E,
	OUTPUT_E,
	PIPE_E
}				t_type;

typedef struct s_token
{
	t_type			type;
	char			*content;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

/*
**	--------------- FUNCTION DECLARATIONS ---------------
*/

/*
**	tokenizer.c
*/
t_token		*tokenizer(char **str);
void		token_init_splits(t_token *token);
void		token_redirect(t_token *token);
void		token_command_flag(t_token *token);
void		token_arg_outp(t_token *token);

/*
**	token_lst.c
*/
t_token		*lst_token_new(char *content);
void		lst_token_add_back(t_token **token, t_token *new);
void		lst_token_insert(t_token **token, t_token *new);
void		lst_token_del(t_token **token);
t_token		*lst_token_last(t_token *token);
void		lst_token_clear(t_token **token);

#endif
