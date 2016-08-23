#include "../header/wolf.h"

void ft_readdir(t_info *e, t_co **list)
{
	t_co *co;
	struct stat *buf;

	while((e->read_file = readdir(e->rep)) != NULL)
	{
		if((ft_strcmp(e->read_file->d_name, ".") != 0) && (ft_strcmp(e->read_file->d_name, "..") != 0))
		{
				co = malloc(sizeof(t_co));
				buf = (struct stat *)malloc(sizeof(struct stat));
				lstat(e->read_file->d_name, buf);
				e->stat = buf;
				ft_push_back_t(list, e);
		}
	}
}

int main(int ac, char **av)
{
	t_info *e;
	t_co *list;
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
