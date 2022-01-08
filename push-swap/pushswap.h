/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:49:09 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 10:31:03 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const	char *s);
char	*ft_strchr(const char *s, int c);
t_stack	**stack_init(t_stack **s);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	fillstack(t_stack **a, t_stack **b, int ac, char **av);
void	freestack(t_stack **s);
int		stacksize(t_stack *lst);
void	pa(t_stack **a, t_stack **b, char c);
void	pb(t_stack **a, t_stack **b, char c);
void	sa(t_stack **s, char c);
void	sb(t_stack **s, char c);
void	ss(t_stack **a, t_stack **b, char c);
void	ra(t_stack **s, char c);
void	rb(t_stack **s, char c);
void	rr(t_stack **a, t_stack **b, char c);
void	rra(t_stack **s, char c);
void	rrb(t_stack **s, char c);
void	rrr(t_stack **a, t_stack **b, char c);
void	sorting(t_stack **a, t_stack **b);
int		get_max(t_stack **a);
int		get_min_index(t_stack **a);
int		get_index(t_stack **a, int data);
int		check_sorted(t_stack **a);
int		*sorted_table(t_stack **a);
void	push_inferior(t_stack **a, t_stack **b, int key_nbr);
void	push_superior(t_stack **a, t_stack **b, int to_push);
void	approximity(t_stack **a, t_stack **b, int j);
void	freetab(char **tab);
void	freeall(char **tab, char *t, t_stack **a, t_stack **b);

#endif
