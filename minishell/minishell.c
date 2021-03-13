/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:56:01 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/13 19:44:31 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	mini_env(void)
{
	ft_putstr_fd("\033[0;35m minishell-> \033[0m", 1);
}

void	free_content(void *content)
{
	if ((char *)content)
	{
		free((char *)content);
		content = 0;
	}
}

void	double_char_to_list(t_list **list, char **str)
{
	int		i;
	int		len;

	len = 0;
	while (str[len])
		len++;
	i = -1;
	while (++i < len)
	{
		if (!*list)
			*list = ft_lstnew(str[i]);
		else
			ft_lstadd_back(list, ft_lstnew(str[i]));
	}
}

void	execute_cmd(t_all *all, t_list *l_cmd)
{
	t_list *tmp;

	tmp = l_cmd;
	all->col_count = 0;
	while (tmp)
	{
		ft_putstr_fd((char*)tmp->content, 1);
		tmp = tmp->next;
		if (tmp)
			ft_putstr_fd(" -> ", 1);
	}
}

void	get_cmd(t_all *all, char *line, char *ref_line)
{
	char	**str;

	str = ft_split_ref(line, ref_line,' ');
	double_char_to_list(&all->l_cmd, str);
	execute_cmd(all, all->l_cmd);
}

void	get_pips(t_all *all, char *line, char *line_ref)
{
	char	**str;
	char	**ref;
	t_list	*tmp;
	t_list	*tmp_ref;

	str = ft_split_ref(line, all->ref_line, '|');
	ref = ft_split(line_ref, '|');
	double_char_to_list(&all->l_pip, str);
	double_char_to_list(&all->l_pip_ref, ref);
	tmp = all->l_pip;
	tmp_ref = all->l_pip_ref;
	while (tmp)
	{
		if (ft_strchr(tmp_ref->content, ' '))
		{
			get_cmd(all, tmp->content, tmp_ref->content);
			if (all->l_cmd)
				ft_lstclear(&all->l_cmd, &free_content);
		}
		else
		{
			all->l_cmd = ft_lstnew(tmp->content);
			execute_cmd(all, all->l_cmd);
			if (all->l_cmd)
				ft_lstclear(&all->l_cmd, &free_content);
		}
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
		if (tmp)
			ft_putstr_fd(" + ", 1);
	}
}

void	get_colons(t_all *all, char *line)
{
	char	**str;
	char	**ref;
	t_list	*tmp;
	t_list	*tmp_ref;
	
	str = ft_split_ref(line, all->ref_line, ';');
	ref = ft_split(all->ref_line, ';');
	double_char_to_list(&all->l_colon, str);
	double_char_to_list(&all->l_colon_ref, ref);
	tmp = all->l_colon;
	tmp_ref = all->l_colon_ref;
	while (tmp)
	{
		if (ft_strchr(tmp_ref->content, '|'))
		{
			get_pips(all, tmp->content, tmp_ref->content);
			if (all->l_pip)
			{
				ft_lstclear(&all->l_pip, &free_content);
				ft_lstclear(&all->l_pip_ref, &free_content);
			}
		}
		else if (ft_strchr(tmp_ref->content, ' '))
		{
			get_cmd(all, tmp->content, tmp_ref->content);
			if (all->l_cmd)
				ft_lstclear(&all->l_cmd, &free_content);
		}
		else
		{
			all->l_cmd = ft_lstnew(tmp->content);
			execute_cmd(all, all->l_cmd);
			if (all->l_cmd)
				ft_lstclear(&all->l_cmd, &free_content);
		}
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
		if (tmp)
			ft_putstr_fd("\n", 1);
	}
}

void	get_data(t_all *all)
{
	if (!all->line)
		return ;
	if (ft_strchr(all->ref_line, ';'))
	{
		get_colons(all, all->line);
		if (all->l_colon)
		{
			ft_lstclear(&all->l_colon, &free_content);
			ft_lstclear(&all->l_colon_ref, &free_content);
		}
	}
	else if (ft_strchr(all->ref_line, '|'))
	{
		get_pips(all, all->line, all->ref_line);
		if (all->l_pip)
		{
			ft_lstclear(&all->l_pip, &free_content);
			ft_lstclear(&all->l_pip_ref, &free_content);
		}
	}
	else if (ft_strchr(all->ref_line, ' '))
	{
		get_cmd(all, all->line, all->ref_line);
		if (all->l_cmd)
			ft_lstclear(&all->l_cmd, &free_content);
	}
	else
	{
		all->l_cmd = ft_lstnew(all->line);
		execute_cmd(all, all->l_cmd);
		if (all->l_cmd)
			ft_lstclear(&all->l_cmd, &free_content);
	}
}

int		cor_char(char c)
{
	if (c == '\"')
		return (OPEN_D_Q);
	else if (c == '\'')
		return (OPEN_S_Q);
	else if (c == '\\')
		return (BACK_S);
	else if (c == '$')
		return (VAR);
	else if (c == ';')
		return (COLON);
	else if (c == ' ')
		return (SPACE);
	else if (c == '|')
		return (PIP);
	else if (c == '-')
		return (FLAG);
	else
		return (TEXT);
}

void	skip_back_s(t_all *all, int *i)
{
	all->ref_line[*i] = SKIP;
	all->ref_line[++*i] = TEXT;
}

void	handle_quotes(t_all *all, int d, int *i, char c)
{
	all->ref_line[*i] = d + 48;
	while (all->line[++*i] != '\0')
	{
		if (all->line[*i] == '\\' && all->line[*i + 1] == c)
			skip_back_s(all, i);
		else if (all->line[*i] == c)
		{
			all->ref_line[*i] = d + 48 + 1;
			break ;
		}
		else
			all->ref_line[*i] = TEXT;
	}
}

void	parse(t_all *all)
{
	int i;
	int ret;

	i = -1;
	while (all->line[++i])
	{
		if ((ret = cor_char(all->line[i])) == BACK_S)
			skip_back_s(all, &i);
		else if (ret == OPEN_S_Q)
			handle_quotes(all, OPEN_S_Q, &i, '\'');
		else if (ret == OPEN_D_Q)
			handle_quotes(all, OPEN_D_Q, &i, '\"');
		else if (ret == FLAG)
			all->ref_line[i] = FLAG;
		else if (ret == SPACE)
			all->ref_line[i] = SPACE;
		else if (ret == PIP)
			all->ref_line[i] = PIP;
		else if (ret == COLON)
			all->ref_line[i] = COLON;
		else if (ret == VAR)
			all->ref_line[i] = VAR;
		else
			all->ref_line[i] = TEXT;
	}
}

int		main(void)
{
	t_all	all;

	while (1)
	{
		ft_struct_bezero(&all, sizeof(t_all));
		mini_env();
		get_next_line(0, &all.line);
		//get_data(&all);
		//if (all.line)
			//free(all.line);
		all.ref_line = ft_strdup(all.line);
		parse(&all);
		ft_putstr_fd(all.line, 1);
		printf("\n");
		ft_putstr_fd(all.ref_line, 1);
		printf("\n");
		get_data(&all);
		printf("\n");
		//if (all.line)
		//	free(all.line);
	}
	return (0);
}
