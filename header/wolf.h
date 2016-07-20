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
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


typedef struct s_co
{
	char *filename;
	struct s_co *next;
}				t_co;



void print_list(t_co *list);
void		ft_push_back_t(t_co **list, char *str);
t_co *add_link(char *str);
