
#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "get_next_line.h"

typedef struct		s_params
{
	char				**av;
	int				ac;
	char				**env;
	char				*v_home;
	char				*v_path;
	char				*v_logname;
}					t_params;

/*
** environmnt params
*/
t_params				*ft_get_params(int ac, char **av, char **env);
void					ft_parse_env(t_params *p);

/*
** ft_shread.c
*/
int					ft_sh_process_loop(t_params *p);
int					ft_read_action(int *brk, char *action, t_params *p);
int					ft_process_builtin(int *brk, char *action, t_params *p);
int					ft_process_search_exec(char *action, t_params *p);
int					ft_exec_bin(char *bin, char **args, t_params *p);

/*
** env builtin functions
*/
int					ft_add_env(char *action, t_params *p);
int					ft_rm_env(char *action, t_params *p);
void					ft_print_env(t_params *p);
int					ft_add_or_replace_key(t_params *p, char *key, char *value);
int					ft_key_exists(char **env, char *key);
int					ft_get_env_count(char **env);
int					ft_rm_key(t_params *p, char *key);
char					*ft_get_good_path(char *exe, t_params *p);

/*
** cd builtin functions
*/
int					ft_cd(char *a, t_params *p);

/*
** ft_shprint.c
*/
void					ft_print_home(t_params *p);
void					ft_print_error(char *err, char *name);

/*
** Errors management
*/
int					ft_is_file_error(char *path);
int					ft_is_dir_error(char *path);
int					ft_is_readable_error(char *path);
int					ft_is_good_path(char *path, char *name);

/*
** Access utils functions(ft_shaccess.c)
*/
int					ft_exists(char *path);
int					ft_is_dir(char *path);
int					ft_can_read(char *path);
int					ft_can_write(char *path);
int					ft_can_exec(char *path);

#endif /* !FT_SH_H */
