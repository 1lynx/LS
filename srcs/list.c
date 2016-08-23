#include "../header/wolf.h"

// void print_co(t_co *e)
// {
// 	printf("%s  ", e->filename);
// 	printf("%d\n", e->test);
// 	printf("%lld\n", e->stat->st_size);
// }

void print_list(t_co **list)
{
	t_co *tmp;
	tmp = *list;

	 while(tmp != NULL)
	 {
		 printf("%s     ", tmp->filename);
		 printf("%d\n", tmp->size);
		 tmp = tmp->next;
	 }
}

void		ft_push_back_t(t_co **list, t_info *e)
{
	t_co	*tmp;
	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_link(e);
	}
	else
		*list = add_link(e);
}

t_co *add_link(t_info *e)
{
	t_co *tmp;
	tmp = malloc(sizeof(t_co));
	if (tmp)
	{
		tmp->filename = ft_strdup(e->read_file->d_name);
		tmp->size = (int)e->stat->st_size;
		tmp->next = NULL;
	}
	return(tmp);
}
