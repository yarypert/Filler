#include "../includes/filler.h"

int main(int argc, char **argv)
{
int ppos_x = ft_atoi(argv[1]);
int ppos_y = ft_atoi(argv[2]);
int epos_x = ft_atoi(argv[3]);
int epos_y = ft_atoi(argv[4]);

	if (epos_x <= ppos_x && epos_y < ppos_y)
		ft_putnbr(1);
		if (epos_x > ppos_x && epos_y <= ppos_y)
		ft_putnbr(2);
	if (epos_x < ppos_x && epos_y >= ppos_y)
		ft_putnbr(3);
	if (epos_x >= ppos_x && epos_y > ppos_y)
		ft_putnbr(4);
}
