/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:56:01 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/22 10:46:57 by nwakour          ###   ########.fr       */
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
	t_list	*tmp;
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
		tmp = tmp->next;
	}
}

void	remove_zero_ref(char **s, char **ref)
{
	int		zeros;
	int		i;
	int		len;
	char	*new_s;
	char	*new_ref;
	int		j;

	if (!*s || !*ref || ((len = ft_strlen(*s)) != (int)ft_strlen(*ref)))
		return ;
	i = -1;
	zeros = 0;
	while ((*ref)[++i] != '\0')
	{
		if ((*ref)[i] != 'a' && (*ref)[i] != ' ' && (*ref)[i] != 45 && (*ref)[i] != 36
			&& (*ref)[i] != 62 && (*ref)[i] != 60 && (*ref)[i] != 63)
			zeros++;
	}
	if (!zeros)
		return ;
	len -= zeros;
	i = -1;
	if (!(new_s = ((char*)malloc((len) * sizeof(char)))))
		return ;
	if (!(new_ref = ((char*)malloc((len) * sizeof(char)))))
		return ;
	j = 0;
	while ((*s)[++i] != '\0')
	{
		if ((*ref)[i] == 'a' || (*ref)[i] == ' ' || (*ref)[i] == 45 || (*ref)[i] == 36
			|| (*ref)[i] == 62 || (*ref)[i] == 60 || (*ref)[i] == 63)
		{
			new_ref[j] = (*ref)[i];
			new_s[j] = (*s)[i];
			j++;
		}
	}
	new_ref[j] = '\0';
	new_s[j] = '\0';
	*s = new_s;
	*ref = new_ref;
}

void	ft_echo(int n, char **arg, int fd)
{
	int i;

	i = 0;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		i++;
		if (arg[i] && arg[i][0] != '\0')
			ft_putstr_fd(" ", fd);
	}
	if (!n)
		ft_putstr_fd("\n", fd);
	
}

int     ft_cd(char* path)
{
    int r;
    r = chdir(path);
    if (r != 0)
        printf("cd: %s: No such file or directory\n", path);
    return (r);
}

void    ft_pwd(void)
{
    char s[100];

    ft_putstr_fd(getcwd(s, 100), 1);
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
	int i;

	flag = 0;
	if (!(cmd->valid))
	{
		ft_putstr_fd(cmd->cmd, 1);
		ft_putstr_fd(" NOT VALID\n", 1);
	}
	else if (!ft_strcmp(cmd->cmd, "echo"))
	{
		if (cmd->flag[0])
			flag = 1;
		if (cmd->f_name)
		{
			i = -1;
			while (cmd->f_name[++i])
			{
				if (cmd->f_name[i][0] == '?')
					cmd->fd = open((cmd->f_name[i] + 1), O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
				else
					cmd->fd = open((cmd->f_name[i] + 1), O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
				if (cmd->f_name[i + 1])
					close(cmd->fd);
			}
		}
		else
			cmd->fd = 1;
		ft_echo(flag, cmd->arg, cmd->fd);
		if (cmd->fd > 1)
			close(cmd->fd);
	}
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd->cmd, "cd"))
		ft_cd(cmd->arg[0]);
	else if (!ft_strcmp(cmd->cmd, "exit"))
		all->ex = 1;
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

int		check_cmd(t_cmd *cmd, int flags)
{
	if (flags > 1)
		return (0);
	else if (!ft_strcmp(cmd->cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "export"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "unset"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "env"))
		return (1);
	else if (!ft_strcmp(cmd->cmd, "exit"))
		return (1);
	else
		return (0);
}

char	*check_env(char **env, char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], str + 1, len - 1))
			return (ft_strdup(env[i] + len));
	}
	return ("\0");
}

void	get_cmd(t_all *all, char *line, char *ref_line)
{
	char	**str;
	char	**str_ref;
	int		flags;
	int		args;
	int		redirs;
	t_cmd	*cmd;
	int		i;

	remove_zero_ref(&line, &ref_line);
	str = ft_split_ref(line, ref_line, ' ');
	str_ref = ft_split(ref_line, ' ');
	flags = str_n_char(ref_line, '-');
	redirs = str_n_char(ref_line, '>');
	redirs += str_n_char(ref_line, '<');
	redirs += str_n_char(ref_line, '?');
	args = 0;
	while (str[args])
		args++;
	i = args;
	args = args - flags - redirs - 1;
	if (!i || !ft_struct_list(&all->l_cmd, (void*)&cmd, sizeof(t_cmd)))
		return ;
	cmd->flag = (char**)(malloc((flags + 1) * sizeof(char*)));
	cmd->flag[flags] = 0;
	cmd->f_name = (char**)(malloc((redirs + 1) * sizeof(char*)));
	cmd->f_name[redirs] = 0;
	cmd->arg = (char**)(malloc((args + 1) * sizeof(char*)));
	cmd->arg[args] = 0;
	while (i > 0 && str[--i])
	{
		if (i == 0)
			cmd->cmd = str[i];
		else if (str_ref[i][0] == '<' || str_ref[i][0] == '>' || str_ref[i][0] == '?')
		{
			if (str_ref[i][0] == '?')
			{
				cmd->f_name[--redirs] = str[i];
				cmd->f_name[redirs][0] = '?';
			}
			else
				cmd->f_name[--redirs] = str[i];
		}
		else if (str_ref[i][0] == '$')
			cmd->arg[--args] = check_env(all->env, str[i]);
		else if (str_ref[i][0] == '-' && flags)
			cmd->flag[--flags] = str[i];
		else
			cmd->arg[--args] = str[i];
	}
	cmd->valid = check_cmd(cmd, flags);
	execute_cmd(all, cmd);
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
		get_cmd(all, tmp->content, tmp_ref->content);
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
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
				ft_lstclear(&all->l_pip, &free_content);
			if (all->l_pip_ref)
				ft_lstclear(&all->l_pip_ref, &free_content);
		}
		else
			get_cmd(all, tmp->content, tmp_ref->content);
		tmp = tmp->next;
		tmp_ref = tmp_ref->next;
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
			ft_lstclear(&all->l_colon, &free_content);
		if (all->l_colon_ref)
			ft_lstclear(&all->l_colon_ref, &free_content);
	}
	else if (ft_strchr(all->ref_line, '|'))
	{
		get_pips(all, all->line, all->ref_line);
		if (all->l_pip)
			ft_lstclear(&all->l_pip, &free_content);
		if (all->l_pip_ref)
			ft_lstclear(&all->l_pip_ref, &free_content);
	}
	else
		get_cmd(all, all->line, all->ref_line);
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
	else if (c == '>')
		return (GREAT);
	else if (c == '<')
		return (LESS);
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
		else if (ret == GREAT)
		{
			if (all->ref_line[i + 1] == GREAT)
			{
				all->ref_line[i] = GREATER;
				all->ref_line[++i] = SKIP;
				while (all->line[i + 1] && all->line[i + 1] == ' ')
					all->ref_line[++i] = SKIP;
			}
			else
			{
				all->ref_line[i] = GREAT;
				while (all->line[i + 1] && all->line[i + 1] == ' ')
					all->ref_line[++i] = SKIP;
			}
		}
		else if (ret == LESS)
			all->ref_line[i] = LESS;
		else
			all->ref_line[i] = TEXT;
	}
}

int		main(int argc, char **argv, char **env)
{
	t_all	all;

	if (argc != 1)
		return (0);
	(void)argv;
	while (1)
	{
		ft_struct_bezero(&all, sizeof(t_all));
		all.env = env;
		mini_env();
		get_next_line(0, &all.line);
		all.ref_line = ft_strdup(all.line);
		parse(&all);
		ft_putstr_fd(all.line, 1);
		printf("\n");
		ft_putstr_fd(all.ref_line, 1);
		printf("\n");
		get_data(&all);
		if (all.l_cmd)
			ft_lstclear(&all.l_cmd, &free_content);
		if (all.line)
			free(all.line);
		if (all.ex)
			break ;
	}
	return (0);
}
