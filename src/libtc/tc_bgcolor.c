#include <curses.h>
#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

/*
** curses_color is a color defined via macros in curses.h, e.g. COLOR_GREEN
*/

int	tc_bgcolor(int curses_color)
{
	char *ab_cap;

	if (!(ab_cap = tgetstr("AB", NULL)))
		return (1);
	else if (tputs(tparm(ab_cap, curses_color), 1, tc_output))
		return (1);
	else
		return (0);
}
