/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:57 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/28 14:25:07 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*char_to_binary(char c)
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

int	send_signals(char *binary_c)
{

}

int	main(int argc, char **argv)
{
	char	*str;
	int		len;
	int		i;

	if (argc != 3)
		exit(1);
	str = argv[2];
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_printf("%s ", char_to_binary(str[i]));
		i++;
	}
	return (0);
}
