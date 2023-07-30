/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:57 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/30 12:58:30 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*char_to_binary(char c)
{
	char	*res;
	int		ascii;
	int		i;

	res = ft_calloc(8 + 1, sizeof(char));
	if (!res)
		exit (1);
	ascii = (int)c;
	i = 7;
	while (ascii > 0)
	{
		if (ascii % 2 == 1)
			res[i] = '1';
		else
			res[i] = '0';
		ascii = ascii / 2;
		i--;
	}
	while (i >= 0)
	{
		res[i] = '0';
		i--;
	}
	return (res);
}

static int	send_signals(char *binary_c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (binary_c[i] == '1')
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else if (binary_c[i] == '0')
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		usleep(8);
		i++;
	}
	my_freestr(binary_c);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*binary_c;
	int		len;
	int		i;

	if (argc != 3)
		exit(1);
	str = argv[2];
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		binary_c = char_to_binary(str[i]);
		send_signals(binary_c, argv[1]);
		i++;
	}
	return (0);
}
