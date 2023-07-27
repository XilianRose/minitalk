/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:36 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/27 14:17:27 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_printf("%i\n", pid);
	return (0);
}
