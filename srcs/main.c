#include "../header/wolf.h"

void ft_readdir(t_info *e, t_list **list)
{
	t_co *co;
	int i = 0;

	while((e->read_file = readdir(e->rep)) != NULL)
	{
		if((ft_strcmp(e->read_file->d_name, ".") != 0) && (ft_strcmp(e->read_file->d_name, "..") != 0))
		{
				co = malloc(sizeof(t_co));
				co->test = i;
				co->filename = ft_strdup(e->read_file->d_name);
				ft_push_back(list, co, 0);
				i++;
		}

	}
}

int main(int ac, char **av)
{
	t_list *list;
	t_info *e;
	e = malloc(sizeof(t_info));
	e->rep = NULL;
	e->read_file = NULL;
	if (ac == 1)
		e->rep = opendir("./");
	if (ac == 2)
		e->rep = opendir(av[1]);
	list = NULL;
	ft_readdir(e, &list);
	print_list(&list);
	if (e->rep == NULL)
    	perror("");
	if (closedir(e->rep) == -1)
        exit(-1);
}
