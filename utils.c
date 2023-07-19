#include "philo.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > INT_MAX)
	{
		print_error("Number of the philos are greater than INT_MAX");
		return (0);
	}
	return ((int)(n));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_y;
	const char	*src_y;

	dst_y = dst;
	src_y = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst_y[i] = src_y[i];
		i++;
	}
	return (dst);
}