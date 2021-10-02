/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugrug <gustavorugg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########          */
/* ************************************************************************** */

#include "minishell.h"

//Checkar erro ao dar free no head sem auterar a referencia para a funcao tokenizer.
//Precisa corregir desreferenciacao
//Precisa lidar com aspas
t_token	*tokenizer(char **str)
{
	t_token	*token;

	token = lst_token_new(str);
	token_init_splits(token);
	token_redirect(token);
	token_command_flag(token);
	token_arg_outp(token);
	return (token);
}

void	token_init_splits(t_token *token)
{
	ft_split_token(token, '|');
	ft_split_token(token, '<');
	ft_split_token(token, '>');
	ft_split_token(token, '-'); //caso especial
}

void	token_redirect(t_token *token)
{
}

void	token_command_flag(t_token *token)
{
}

void	token_arg_outp(t_token *token)
{

}

void	ft_split_token(t_token *token, char c)
{
	t_token	*new;
	t_token	*ptr;
	t_token	*ptr_del;
	char	**splitted;
	int		i;

	splitted = NULL;
	ptr = token;
	while (ptr)
	{
		splitted = ft_split_ms(ptr->content, c);
		if (splitted)
		{
			ptr_del = ptr;
			ptr = ptr->next;
			lst_token_del(&ptr_del);
			i = 0;
			while (splitted[i])
			{
				new = lst_token_new(splitted[i]);
				if (!ptr)
				{
					ptr = lst_token_last(token);
				}
				lst_token_insert(&ptr, new);
				ptr = ptr->next;
				i++;
			}
			ft_free_array(splitted);
		}
		else
			ptr = ptr->next;
	}
}
