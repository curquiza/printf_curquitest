#include "conv_u_bigu_test.h"

int		u_all_02(void)
{
	t_data	data;
	int		pfd[2];
	int		ret;
	int		save_stdout;

	ft_connect_stdout(pfd, &save_stdout);
	data.r1 = ft_printf("\ntoto et %00009U%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	data.s1 = ft_get_stdout(pfd, &save_stdout);
	ft_connect_stdout(pfd, &save_stdout);
	data.r2 = printf("\ntoto et %00009U%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	data.s2 = ft_get_stdout(pfd, &save_stdout);
	ret = 0;
	if (data.r1 != data.r2)
		ret = -1;
	if (ft_strcmp(data.s1, data.s2))
		ret = -1;
	ft_write_debug("\\ntoto et %00009U%-2lu mimi et titi%--14u, 0, (unsigned long)14, 200", data, ret);
	ft_strdel(&data.s1);
	ft_strdel(&data.s2);
	return (ret);
}
