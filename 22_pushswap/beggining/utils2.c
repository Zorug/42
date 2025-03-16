# include "push_swap.h"

void    free_split(char **argv, bool flag_splt, int word_pos)
{
    if (flag_splt == true)
	{
		while (--word_pos >= 0)
			free(argv[word_pos]);
		free(argv);
	}
}

bool	error_repeat(char **argv, bool flag_splt)
{

}

bool	error_limits(char **argv, bool flag_splt)
{

}

bool	error_syntax(char **argv, bool flag_splt)
{

}
