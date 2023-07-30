/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:57 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/30 16:03:51 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*char_to_bin(char c)
{
	char	*bin_str;
	int		ascii;
	int		i;

	bin_str = ft_calloc(8 + 1, sizeof(char));
	if (!bin_str)
		exit (1);
	ascii = (int)c;
	i = 7;
	while (ascii > 0)
	{
		if (ascii % 2 == 1)
			bin_str[i] = '1';
		else
			bin_str[i] = '0';
		ascii = ascii / 2;
		i--;
	}
	while (i >= 0)
	{
		bin_str[i] = '0';
		i--;
	}
	return (bin_str);
}

static int	send_signal(char *bin_str, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bin_str[i] == '1')
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else if (bin_str[i] == '0')
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		usleep(42);
		i++;
	}
	my_freestr(bin_str);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*bin_str;
	int		pid;
	int		i;

	if (argc != 3)
		exit(1);
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bin_str = char_to_bin(argv[2][i]);
		send_signal(bin_str, pid);
		i++;
	}
	exit(0);
}
