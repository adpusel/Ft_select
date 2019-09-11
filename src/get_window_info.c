/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:55:12 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 10:14:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "libft.h"
#include "ft_select.h"

void	get_window_info(struct s_display *display)
{
	display->wcol = tgetnum("co");
	display->wrow = tgetnum("li");
}

void	get_list_info(struct s_display *display, struct s_select *list, int nb)
{
	display->colsize = 0;
	while (nb)
	{
		--nb;
		if (list[nb].len > display->colsize)
			display->colsize = list[nb].len;
	}
}

_Bool	it_doesnt_fit(struct s_display *display, int nb)
{
	if ((nb - 1) / display->wrow <= display->wcol / display->colsize)
		return (0);
	else
		return (1);
}

void	checkfits(struct s_display *display, int argc)
{
	if (it_doesnt_fit(display, argc - 1))
	{
		ft_dprintf(STDERR_FILENO, "Cannot display list, screen too small\n");
		exit(1);
	}
}
