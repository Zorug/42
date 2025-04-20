
#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <unistd.h>     // read, write, fork, pipe, dup, dup2, access, execve, close, unlink
# include <stdlib.h>     // malloc, free, exit
# include <fcntl.h>      // open, O_RDONLY, O_CREAT, etc.
# include <sys/wait.h>   // wait, waitpid, macros WEXITSTATUS etc.
# include <sys/types.h>  // usado com wait, pid_t
# include <stdio.h>      // perror
# include <string.h>     // strerror, (às vezes strlen, etc.)


typedef struct s_pipex
{
    int		fd_infile;		// Arquivo de entrada (file1)
							// open(argv[1], O_RDONLY)

	int		fd_outfile;		// descritor de arquivo file2

	char	*path_cmd1;		// Caminho absoluto do comando 1
							// /bin/ls, /usr/bin/grep, etc.

	char	*path_cmd2; 	// executável do segundo comando

	char	**args_cmd1;	// Argumentos de cmd1
							// { "grep", "banana", NULL }

	char	**args_cmd2;	// vetor de argumentos do cmd2
}   t_pipex;

typedef enum	e_args
{
	PROGRAM,	// argv[0] → o próprio nome do programa (./pipex)
	INFILE,		// argv[1] → o arquivo de entrada (file1)
	CMD1,		// argv[2] → o primeiro comando (cmd1)
	CMD2,		// argv[3] → o segundo comando (cmd2)
	OUTFILE		// argv[4] → o arquivo de saída (file2)
}	t_args;

typedef enum	e_errors
{
	NO_COMAND = 0,
	NO_FILE = 2,
	BAD_FD = 9
}	t_errors;

// error_handling.c
void	ft_free_memory(char **path, char *path_command);
void	ft_free_array(char **array);
int		ft_error(char *error_message);

// ft_split_mod.c
char	*get_string(const char *s);
void	clean_words(int words, char **array);
char	**ft_split_mod(char *s);

// ft_split_utils.c
int		ft_countword(const char *input);
int		array_size(char **array);
char	*remove_backslashes(char *s);
char	**remove_scape_symbol(char **s);

// get_path.c
char	*ft_get_path_aux(char **envp);
char	*ft_check_command_location(char *command, char *path_i);
char	*find_path(char *path_aux, char *command);
char    *get_path(char *command, char **envp);

// main.c
void	init_pipex(t_pipex *pipex);
void	check_args(t_pipex *pipex, char **argv, char **envp);

// parcing_utils.c
int		is_only_spaces(const char *str);
void	copy_non_space_strings(char **dest, char **src);
void	remove_spaces(char **array);

// pipex_utils.c
void	setup_infile(t_pipex *pipex, char **argv);

// pipex.c
void    ft_exec(t_pipex *pipex, char **envp, char **argv);

// utils_1.c
void	ft_putstr_fd(char *s, int fd);




#endif