#include "../header/wolf.h"

void print_list(t_co *list)
{
	 while(list)
	 {
		 printf("%s\n", list->filename);
		 list = list->next;
	 }
}
void		ft_push_back_t(t_co **list, char *str)
{
	t_co	*tmp;
	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_link(str);
	}
	else
		*list = add_link(str);
}
t_co *add_link(char *str)
{
	t_co *tmp;
	tmp = malloc(sizeof(t_co));
	if (tmp)
	{
		tmp->filename = str;
		tmp->next = NULL;
	}
	return(tmp);
}
