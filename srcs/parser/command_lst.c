# include "minishell.h"

t_command	*lst_command_new(t_name name)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof (t_command));
	if (!(new))
		return (NULL);
	new->name = name;
	new->redirect = NULL;
	new->flag = NULL;
	new->input = NULL;
	new->output = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_command_add_back(t_command **lst, t_command *new)
{
	t_command	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = lst_command_last(*lst);
		new->prev = tmp;
		tmp->next = new;
	}
}

void	lst_command_cut(t_command *command)
{
	if (command->prev)
		command->prev->next = command->next;
	if (command->next)
		command->next->prev = command->prev;
}

t_command	*lst_command_last(t_command *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_command_clear(t_command **lst)
{
	t_command	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
