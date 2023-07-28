/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:36 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/28 15:09:48 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_signal(int sig)
{

}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_handler = &handle_signal;
	// sa.sa_flags = SA
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%i\n", pid);
	pause();
	return (0);
}
