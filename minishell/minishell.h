/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:59:03 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/19 17:59:26 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# define OPEN_S_Q 1
# define CLOSE_S_Q 2
# define OPEN_D_Q 3
# define CLOSE_D_Q 4
# define BACK_S 92
# define VAR 36
# define COLON 59
# define TEXT 97
# define PIP 124
# define SPACE 32
# define FLAG 45
# define SKIP 48
# define GREAT 62
# define LESS 60
# define GREATER 63

typedef struct		s_cmd
{
	char	*cmd;
	char	**arg;
	char	**flag;
	int		fd;
	char	**f_name;
	int		valid;
}					t_cmd;

typedef struct		s_all
{
	t_list	*l_colon;
	t_list	*l_colon_ref;
	t_list	*l_pip;
	t_list	*l_pip_ref;
	t_list	*l_cmd;
	char	*line;
	char	*ref_line;
	char	**env;
	int		ex;
}					t_all;

#endif
