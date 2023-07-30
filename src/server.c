/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:36 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/30 15:52:05 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	binary_to_char(char *binary_c)
{
	int	c;
	int	i;
	int	value;

	c = 0;
	i = ft_strlen(binary_c) - 1;
	value = 1;
	while (i >= 0)
	{
		if (binary_c[i] == '1')
			c = c + value;
		value = value * 2;
		i--;
	}
	return ((char)c);
}

static void	addto_str(char binary)
{
	static char	binary_c[9];
	static int	i;
	char		c;

	binary_c[i] = binary;
	i++;
	if (i == 8)
	{
		c = binary_to_char(binary_c);
		ft_printf("%c", c);
		i = 0;
	}
}

static void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		addto_str('1');
	else if (sig == SIGUSR2)
		addto_str('0');
}

	// sigemptyset(&sa.sa_mask);
	// sigaddset(&sa.sa_mask, SIGUSR1);
	// sigaddset(&sa.sa_mask, SIGUSR2);

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = &handle_signal;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("%i\n", pid);
	while (1)
		pause();
	return (0);
}
