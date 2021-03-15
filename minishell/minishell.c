/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:56:01 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/15 19:20:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	mini_env(void)
{
	ft_putstr_fd("\033[0;35m minishell-> \033[0m", 1);
}

void	read_data(t_all *all)
{
	t_list *tmp;
	t_cmd	*cmd;
	int		i;

	tmp = all->l_cmd;
	while (tmp)
	{
		cmd = (t_cmd*)tmp->content;
		printf("cmd = %s\n", cmd->cmd);
		i = -1;
		while (cmd->flag[++i])
			printf("flags = %s\n", cmd->flag[i]);
		i = -1;
		while (cmd->arg[++i])
			printf("args = %s\n", cmd->arg[i]);
		i = -1;
		while (cmd->var[++i])
			printf("vars = %s\n", cmd->var[i]);
		tmp = tmp->next;
	}
}
void    ft_echo(int n, char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
    	ft_putstr_fd(arg[i], 1);
		i++;
		if (arg[i])
			ft_putstr_fd(" ", 1);
	}
    if (!n)
        ft_putstr_fd("\n", 1);
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

void	execute_cmd(t_all *all, t_cmd *cmd)
{
	int flag;

	flag = 0;
	if (!ft_strcmp(cmd->cmd, "echo"))
	{
		if (cmd->flag[0])
			flag = 1;
		ft_echo(flag, cmd->arg);
	}
	else
		read_data(all);
}

int		str_n_char(char *str, char c)
{
	int i;
	int nb;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		if (str[i] == c)
			nb++;
	}
	return (nb);
}

void	get_cmd(t_all *all, char *line, char *ref_line)
{
	char	**str;
	int		flags;
	int		vars;
	int		args;
	t_cmd	*cmd;
	int		i;

	str = ft_split_ref(line, ref_line,' ');
	flags = str_n_char(ref_line, '-');
	vars = str_n_char(ref_line, '$');
	args = 0;
	while (str[args])
		args++;
	i = args;
	args = args - flags - vars - 1;
	if (!i || !ft_struct_list(&all->l_cmd, (void*)&cmd, sizeof(t_cmd)))
		return ;
	cmd->flag = (char**)(malloc((flags + 1) * sizeof(char*)));
	cmd->flag[flags] = 0;
	cmd->arg = (char**)(malloc((args + 1) * sizeof(char*)));
	cmd->arg[args] = 0;
	cmd->var = (char**)(malloc((vars + 1) * sizeof(char*)));
	cmd->var[vars] = 0;
	while( i > 0 && str[--i])
	{
		if (i == 0)
			cmd->cmd = str[i];
		else if (str[i][0] == '$' && vars)
			cmd->var[--vars] = str[i];
		else if (str[i][0] == '-' && flags)
			cmd->flag[--flags] = str[i];
		else
			cmd->arg[--args] = str[i];
	}
	execute_cmd(all, cmd);
	//double_char_to_list(&all->l_cmd, str);
	//execute_cmd(all, all->l_cmd);
}

void	get_pips(t_all *all, char *line, char *line_ref)
{
	char	**str;
	char	**ref;
	t_list	*tmp;
	t_list	*tmp_ref;

	str = ft_split_ref(line, line_ref, '|');
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
			//if (all->l_cmd)
			//	ft_lstclear(&all->l_cmd, &free_content);
		}
		else
		{
			//all->l_cmd = ft_lstnew(tmp->content);
			//execute_cmd(all, all->l_cmd);
			get_cmd(all, tmp->content, tmp_ref->content);
			//if (all->l_cmd)
			//	ft_lstclear(&all->l_cmd, &free_content);
		}
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
		// if (tmp)
		// 	ft_putstr_fd(" + ", 1);
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
			// if (all->l_cmd)
			// 	ft_lstclear(&all->l_cmd, &free_content);
		}
		else
		{
			get_cmd(all, tmp->content, tmp_ref->content);
			// all->l_cmd = ft_lstnew(tmp->content);
			// execute_cmd(all, all->l_cmd);
			// if (all->l_cmd)
			// 	ft_lstclear(&all->l_cmd, &free_content);
		}
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
		// if (tmp)
		// 	ft_putstr_fd("\n", 1);
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
		// if (all->l_cmd)
		// 	ft_lstclear(&all->l_cmd, &free_content);
	}
	else
	{
		get_cmd(all, all->line, all->ref_line);
		// all->l_cmd = ft_lstnew(all->line);
		// execute_cmd(all, all->l_cmd);
		// if (all->l_cmd)
		// 	ft_lstclear(&all->l_cmd, &free_content);
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

void	handle_d_quotes(t_all *all, int d, int *i, char c)
{
	all->ref_line[*i] = d + 48;
	while (all->line[++*i] != '\0')
	{
		if (all->line[*i] == '\\' && c == '\'')
		{
			all->ref_line[*i] = d + 48 + 1;
			break ;
		}
		else if (all->line[*i] == '\\' && all->line[*i + 1] == c)
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

void	handle_s_quotes(t_all *all, int d, int *i, char c)
{
	all->ref_line[*i] = d + 48;
	while (all->line[++*i] != '\0')
	{
		if (all->line[*i] == c)
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
			handle_s_quotes(all, OPEN_S_Q, &i, '\'');
		else if (ret == OPEN_D_Q)
			handle_d_quotes(all, OPEN_D_Q, &i, '\"');
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
		all.ref_line = ft_strdup(all.line);
		parse(&all);
		//ft_putstr_fd(all.line, 1);
		//printf("\n");
		//ft_putstr_fd(all.ref_line, 1);
		//printf("\n");
		get_data(&all);
		if (all.l_cmd)
			ft_lstclear(&all.l_cmd, &free_content);
		//read_data(&all);
		//printf("\n");
		if (all.line)
			free(all.line);
	}
	return (0);
}
