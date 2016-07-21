#include "../header/wolf.h"

void ft_readdir(t_info *e, t_co *list)
{
	while((e->read_file = readdir(e->rep)))
	{
		if((ft_strcmp(e->read_file->d_name, ".") != 0) && (ft_strcmp(e->read_file->d_name, "..") != 0))
		{
			ft_push_back_t(&list, e->read_file->d_name);
		}

	}
	print_list(list);
}

int main(int ac, char **av)
{
	t_co *list;
	t_info *e;
	e = malloc(sizeof(t_info));
	e->rep = NULL;
	e->read_file = NULL;
	if (ac == 1)
		e->rep = opendir("./");
	if (ac == 2)
		e->rep = opendir(av[1]);
	list = NULL;
	ft_readdir(e, list);
	if (e->rep == NULL)
    	perror("");
	if (closedir(e->rep) == -1)
        exit(-1);
}
