#include "conv_s_test.h"

int		s_padding_03(void)
{
	t_data	data;
	int		pfd[2];
	int		ret;
	int		save_stdout;

	ft_connect_stdout(pfd, &save_stdout);
	data.r1 = ft_printf("%1s", "hi");
	data.s1 = ft_get_stdout(pfd, &save_stdout);
	ft_connect_stdout(pfd, &save_stdout);
	data.r2 = printf("%1s", "hi");
	data.s2 = ft_get_stdout(pfd, &save_stdout);
	ret = 0;
	if (data.r1 != data.r2)
		ret = -1;
	if (ft_strcmp(data.s1, data.s2))
		ret = -1;
	ft_strdel(&data.s1);
	ft_strdel(&data.s2);
	return (ret);
}
