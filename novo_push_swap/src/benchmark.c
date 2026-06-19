#include "push_swap.h"

void	print_disorder(float disorder)
{
	const float	disorder_percent = disorder * 100;

	ft_putstr_fd("[bench] disorder: ", STDERR_FILENO);
	ft_putnbr_fd(disorder_percent, 2),
	ft_putchar_fd('.', STDERR_FILENO);
	ft_putnbr_fd((int)(disorder_percent * 100) % 100, STDERR_FILENO);
	ft_putstr_fd("%\n", STDERR_FILENO);
}

void	print_strategy(float disorder, int algorithm_selected)
{
	char	*strategy;
	char	*complexity;

	strategy = "Simple";
	complexity = "O(n²)";
	if (algorithm_selected == SIMPLE)
	{
		strategy = "Simple";
		complexity = "O(n²)";
	}
	else if (algorithm_selected == MEDIUM)
	{
		strategy = "Medium";
		complexity = "O(n√n)";
	}
	else if (algorithm_selected == COMPLEX)
	{
		strategy = "Complex";
		complexity = "O(nlog(n))";
	}
	else if (algorithm_selected == ADAPTIVE)
	{
		strategy = "Adaptative";
		if (disorder < 0.2)
			complexity = "O(n²)";
		else if (disorder < 0.5)
			complexity = "O(n√n)";
		else
			complexity = "O(nlog(n))";
	}
	ft_putstr_fd("[bench] strategy: ", STDERR_FILENO);
	ft_putstr_fd(strategy, STDERR_FILENO);
	ft_putstr_fd(" / ", STDERR_FILENO);
	ft_putstr_fd(complexity, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_total(t_bench bench)
{
	const int	total = bench.sa_ops + bench.sb_ops + bench.ss_ops
		+ bench.pa_ops + bench.pb_ops
		+ bench.ra_ops + bench.rb_ops + bench.rr_ops
		+ bench.rra_ops + bench.rrb_ops + bench.rrr_ops;

	ft_putstr_fd("[bench] total_ops: ", STDERR_FILENO);
	ft_putnbr_fd(total, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_operation(char *operation, int num)
{
	const char	*num_str = ft_itoa(num);
	const int	num_str_size = ft_strlen(num_str);

	if (ft_strlen(operation) < 3)
		ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd(operation, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (num_str_size < 5)
		ft_putchar_fd(' ', STDERR_FILENO);
	if (num_str_size < 4)
		ft_putchar_fd(' ', STDERR_FILENO);
	if (num_str_size < 3)
		ft_putchar_fd(' ', STDERR_FILENO);
	if (num_str_size < 2)
		ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd((char *)num_str, STDERR_FILENO);
	ft_putstr_fd("  ", STDERR_FILENO);
}

void	print_ops(t_bench bench)
{
	ft_putstr_fd("[bench] ", STDERR_FILENO);
	print_operation("sa", bench.sa_ops);
	print_operation("sb", bench.sb_ops);
	print_operation("ss", bench.ss_ops);
	print_operation("pa", bench.pa_ops);
	print_operation("pb", bench.pb_ops);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd("[bench] ", STDERR_FILENO);
	print_operation("ra", bench.ra_ops);
	print_operation("rb", bench.rb_ops);
	print_operation("rr", bench.rr_ops);
	print_operation("rra", bench.rra_ops);
	print_operation("rrb", bench.rrb_ops);
	print_operation("rrr", bench.rrr_ops);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_benchmark(t_bench bench, int algorithm_selected, float disorder)
{
	print_disorder(disorder);
	print_strategy(disorder, algorithm_selected);
	print_total(bench);
	print_ops(bench);
}
