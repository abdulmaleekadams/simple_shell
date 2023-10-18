#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/**
 * struct command_s - singly linked list
 * @path: the path.
 * @args: the args.
 * @tmp: the tmp.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for command.
 */
typedef struct command_s
{
	char *path;
	char **args;
	char *tmp;
	struct command_s *next;
} command_t;

/**
 * struct alias_s - singly linked list
 * @name: the nmae.
 * @value: the value.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure
 * for alias.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/**
 * struct env_s - singly linked list
 * @name: the name.
 * @value: the value.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for env.
 */
typedef struct env_s
{
	char *name;
	char *value;
	struct env_s *next;
} env_t;

/**
 * struct global_s - global variable.
 * @commands: the commands.
 * @env: the env.
 * @alias: the alias.
 * @exit_code: the exit code.
 * @pid: the pid.
 * @name: the name.
 * @envp: the envp.
 * @cmd: the cmd.
 * @left: the left.
 * @n: the line num.
 * @fd: the fd.
 *
 * Description: global variable.
 */
typedef struct global_s
{
	command_t *commands;
	env_t *env;
	alias_t *alias;
	int exit_code;
	pid_t pid;
	char *name;
	char **envp;
	char *cmd;
	char *left;
	int n;
	int fd;
} global_t;

# define BUFFER_SIZE 1024

/**
 * Function Prototypes
 */
char *var_re(char *ptr, global_t *global);
size_t _strlen(const char *s);
char *_strdup(const char *s1);
int _strcmp(const char *str1, const char *str2, size_t n);
void putnbr_fd(int n, int fd);
char *_itoa(int n);
int _atoi(char *s);
char *_strjoin(char *s1, char *s2);
void my_exit(char **cmd, global_t *global);
int is_num(char *str);
void handler(int sig);
int main(int ac, char **av, char **env);
char *_strjoin(char *s1, char *s2);
static char **m_error(char **arr);
static int ft_count_words(char const *str, char charset);
static int ft_word_len(char const *str, char charset);
static char *ft_word_grep(char const *str, char charset);
char **split(char const *s, char c);
void _alias(char **cmd, global_t *global);
char *alias_search(char *str, global_t *global);
alias_t *aliasSearch(char *str, global_t *global);
char *alias(char *ptr, global_t *global);
char *str_copy1(char *str, int *idx, char a);
int print(char *str, int fd, int new);
void env(char **cmd, global_t *global);
char *remove_comments(char *ptr, global_t *global, int fd);
int print_error(char *cmd, char *msg, global_t *global);
int exec_builtin(char **args, global_t *global);
void init_env(char **envp, gloaba_t *global);
char *env_search(char *str, global_t *global);
env_t *envsearch(char *str, global_t *global);
void free_all(global_t *global);
void free_env(global_t *global);
void free_alias(global_t *global);
void free_commands(global_t *global);
void executing(global_t *global);
void exec_binary(command_t *command, global_t *global);
void get_paths(global_t *global);
char *get_path(char *str, global_t *global);
void get_commands(char *ptr, global_t *global);
static char *all(int fd, char *left);
static char *get_line(char *line);
static char *ft_left(char *line);
char *_getline(int fd, global_t *global);
void *my_memcpy(void *dst, const void *src, size_t n);
size_t my_strlen(const char *s);
char *my_strjoin(char *s1, char *s2);
char *my_strchr(const char *s, int c);
void exec_logical_operators(char **str, global_t *global);
char **advanced_split(char *str, global_t *global);
char *copy_str(char *str, int *index);
int count_words(char *str, global_t *global);
int is_lo_op(char *str);
void lstadd_back_env(env_t **lst, env_t *new);
void lstadd_back_command(command_t **lst, command_t *new);
void lstadd_back_alias(alias_t **lst, alias_t *new);
void _setenv(char **cmd, global_t *global);
void _unsetenv(char **cmd, global_t *global);
void help_cd(char **cmd, global_t *global);
void help_cd2(char **cmd, global_t *global);
void cd(char **cmd, global_t *global);

#endif
