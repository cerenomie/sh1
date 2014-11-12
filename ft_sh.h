/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 12:56:27 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/12 16:34:26 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct			s_params
{
	char				**av;
	int					ac;
	char				**env;
	char				*v_home;
	char				*v_path;
	char				*v_logname;
}						t_params;

/*
** environmnt params
*/
t_params				*ft_get_params(int ac, char **av, char **env);
void					ft_parse_env(t_params *p);

/*
** ft_read.c
*/
int						ft_process_loop(t_params *p);
int						ft_read_action(int *brk, char *action, t_params *p);
int						ft_process_builtin(int *brk, char *action, t_params *p);
int						ft_process_search_exec(char *action, t_params *p);
int						ft_exec_bin(char *bin, char **args, t_params *p);

/*
** env builtin functions
*/
int						ft_add_env(char *action, t_params *p);
int						ft_rm_env(char *action, t_params *p);
void					ft_print_env(t_params *p);
int						ft_add_or_replace_key(t_params *p, char *key,
		char *value);
int						ft_key_exists(char **env, char *key);
int						ft_get_env_count(char **env);
int						ft_rm_key(t_params *p, char *key);
char					*ft_get_good_path(char *exe, t_params *p);

/*
** cd builtin functions
*/
int						ft_cd(char *a, t_params *p);

/*
** ft_shprint.c
*/
void					ft_print_home(t_params *p);
void					ft_print_error(char *err, char *name);

/*
** Errors management
*/
int						ft_is_file_error(char *path);
int						ft_is_dir_error(char *path);
int						ft_is_readable_error(char *path);
int						ft_is_good_path(char *path, char *name);

/*
** Access utils functions(ft_shaccess.c)
*/
int						ft_exists(char *path);
int						ft_is_dir(char *path);
int						ft_can_read(char *path);
int						ft_can_write(char *path);
int						ft_can_exec(char *path);

/*
** functions
*/

void					ft_bzero(void *s, size_t n);
void					ft_putchar(char c);
void					*ft_memalloc(size_t size);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					ft_memdel(void **ap);
void					ft_putendl(char const *s);
void					ft_putstr(char const *str);
void					ft_putstr_fd(char const *str, int fd);
void					*ft_realloc(void *ptr, size_t old, size_t size);
void					ft_add_line(char **line, char **buf, long len);
void					ft_loop(int const *fd, char **line, char **buf,
		long *res);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putchar_fd(char c, int fd);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t n);
char					**ft_strsplit(char const *s, char c);
char					*ft_strsub(const char *s, unsigned int start,
		size_t len);
char					*ft_strtrim(char const *s);
char					*ft_strcat(char *s1, const char *s2);
int						ft_isblank(int c);
int						get_next_line(int const fd, char **line);
int						ft_strpos(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
size_t					ft_strlen(const char *s);
int						count_words(const char *str, char c);
char					*ft_strndup(const char *src, int n);
size_t					word_len(const char *str, char c);

#endif
