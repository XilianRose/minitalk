/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 14:05:36 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/30 13:06:43 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)

	if (sig == SIGUSR2)

}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("%i\n", pid);
	pause();
	return (0);
}
