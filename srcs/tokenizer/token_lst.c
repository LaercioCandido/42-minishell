# include "minishell.h"

t_token	*lst_token_new(char *content)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof (t_token));
	if (!(new))
		return (NULL);
	new->type = NULL;
	new->content = ft_strdup(content);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	lst_token_add_back(t_token **token, t_token *new)
{
	t_token	*tmp;

	if (!token)
		return ;
	if (!(*token))
		*token = new;
	else
	{
		tmp = lst_token_last(*token);
		new->prev = tmp;
		tmp->next = new;
	}
}

void	lst_token_insert(t_token **token, t_token *new)
{
	if (!token)
		return ;
	if (!(*token))
		*token = new;
	else
	{
		if ((*token)->next)
			(*token)->next->prev = new;
		new->next = (*token)->next;
		new->prev = (*token);
		(*token)->next = new;
	}
}

void	lst_token_del(t_token **token)
{
	if ((*token)->prev)
		(*token)->prev->next = (*token)->next;
	if ((*token)->next)
		(*token)->next->prev = (*token)->prev;
	if ((*token)->content)
		free((*token)->content);
	(*token)->content = NULL;
	free(*token);
	*token = NULL;
}

t_token	*lst_token_last(t_token *token)
{
	while (token != NULL && token->next != NULL)
		token = token->next;
	return (token);
}

void	lst_token_clear(t_token **token)
{
	t_token	*tmp;

	if (!token)
		return ;
	while (*token)
	{
		tmp = (*token)->next;
		if ((*token)->content)
			free((*token)->content);
		free(*token);
		*token = NULL;
		*token = tmp;
	}
	*token = NULL;
}
