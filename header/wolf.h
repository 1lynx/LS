/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:40:08 by cchampda          #+#    #+#             */
/*   Updated: 2016/07/20 16:13:46 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct s_info
{
	DIR* rep;
	struct dirent* read_file;
	struct stat *stat;
}								t_info;


typedef struct s_co
{
	char *filename;
	int size;
	struct s_co *next;
}							t_co;



void print_list(t_co **list);
void	ft_push_back_t(t_co **list, t_info *e);
t_co *add_link(t_info *e);
void ft_readdir(t_info *e, t_co **list);
// void print_co(t_co *e);
