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

int main(int ac, char **av)
{
	t_co *list;
	t_info *e;
	e = malloc(sizeof(t_info));
	ft_memset();
	if (ac == 1)
		rep = opendir("./");
	if (ac == 2)
		rep = opendir(av[1]);

	list = NULL;

	if (rep == NULL)
    	perror("");

	while((read_file = readdir(rep)))
	{
		if((ft_strcmp(read_file->d_name, ".") != 0) && (ft_strcmp(read_file->d_name, "..") != 0))
		{
			ft_push_back_t(&list, read_file->d_name);
			printf("Le fichier lu s'appelle '%s'\n", read_file->d_name);
		}
	}
	print_list(list);

	if (closedir(rep) == -1)
        exit(-1);
}
