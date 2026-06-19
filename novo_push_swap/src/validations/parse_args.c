#include "push_swap.h"

int	set_flag(t_options *options, int flag)
{
	if (flag != BENCH)
	{
		if (options->algorithm_selected != NONE)
			return (ERROR);
		options->algorithm_selected = flag;
		return (SUCCESS);
	}

	if (options->bench_mode != FALSE)
		return (ERROR);
	options->bench_mode = TRUE;

	return (SUCCESS);
}

int	parse_flags(char *str, t_options *options)
{
	int			status;
	const int	str_size = ft_strlen(str);

	if (ft_strncmp(str, "--simple", str_size) == 0)
		status = set_flag(options, SIMPLE);
	else if (ft_strncmp(str, "--medium", str_size) == 0)
		status = set_flag(options, MEDIUM);
	else if (ft_strncmp(str, "--complex", str_size) == 0)
		status = set_flag(options, COMPLEX);
	else if (ft_strncmp(str, "--adaptative", str_size) == 0)
		status = set_flag(options, ADAPTIVE);
	else if (ft_strncmp(str, "--bench", str_size) == 0)
		status = set_flag(options, BENCH);
	else
		status = ERROR;

	return (status);
}

int	parse_int(char *str, int *val_out)
{
	int		i;
	int		sign;
	long 	num;

	i = 0;
	num = 0;
	sign = 1;
	*val_out = 0;

	if (!str[0])
		return (ERROR);

	if (str[0] == '-' && str[1])
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+' && str[1])
		i++;

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ERROR);
		num = (str[i] - '0') + (num * 10);
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && -num < INT_MIN))
			return (ERROR);
		i++;
	}

	*val_out = num * sign;
	return (SUCCESS);
}

int	parse_args(int argc, char **argv, t_options *options, t_list **stack)
{
	int	i;
	int	num;
	int	status;

	i = 1;
	status = SUCCESS;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			status = parse_flags(argv[i], options);
			if (status == ERROR)
				break;
			i++;
			continue;
		}

		status = parse_int(argv[i], &num);
		if (status == SUCCESS && lst_contains(*stack, num) == 1)
			status = ERROR;
		if (status == ERROR)
			break;

		ft_lstadd_back(stack, create_node(num));

		i++;
	}

	if (status == ERROR)
		ft_lstclear(stack, free);

	if (options->algorithm_selected == NONE)
		options->algorithm_selected = ADAPTIVE;

	return (status);
}
