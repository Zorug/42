/*If c is an uppercase letter, tolower() returns its 
lowercase  equivalent,  if  a  lowercase  representation 
exists in the current locale. Otherwise, it returns c. 
A65 Z90*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*The value returned is that of the converted letter, 
or c if the  conversion was not possible.*/