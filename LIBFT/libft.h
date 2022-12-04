/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:19:32 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:00 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*					PRINTF					*/

int		ft_putstr_cust(const char *s, int fd);
int		ft_putchar_cust(unsigned char c, int fd);
int		ft_put_itoa_hex(size_t nb, char *base_hex);
char	*ft_create_str(int final_size);
size_t	ft_pow(int nbr_base, int p);
size_t	ft_strlen(const char *s);

int		ft_putnbr_cust(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
int		ft_put_uitoa_hex(unsigned int nb, char *base_hex);
int		ft_ustrlen_int(unsigned int n);
int		ft_printf(const char *format, ...);
int		count_len(size_t nb, int nbr_base);

/*				GNL						*/


size_t	ft_strlen_gnl(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *str, unsigned int start, size_t len);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_calloc_gnl(size_t count, size_t size);

/*				FdF				*/

long long int	ft_atoi_base(char *str, char *base);
long long int	ft_pow_long(long long int nbr_base, int p);

/*				Fcking Malloc		*/

void ft_free(void *ptr, int size);

/*				Utils_no_libft			*/

int	ft_isspace(char str);
//convert_base(piscine) //TODO: refactor

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(long long int nb, char *base_to);
char	*ft_create_str(int final_size);
char	*entry_zero(char *base_to);
long long int	ft_pow2(long long int nbr_base, int p);
int	is_allowed(char *base);

#endif
