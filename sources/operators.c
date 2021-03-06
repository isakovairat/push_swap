#include "../includes/push_swap.h"

void	operation_swap(t_list **top)
{
	t_list	*temp;

	if (*top && (*top)->next)
	{
		temp = (*top)->next;
		(*top)->next = temp->next;
		temp->next = *top;
		*top = temp;
	}
}

void	operation_push(t_list **dest, t_list **source)
{
	t_list	*temp;

	if (*source)
	{
		temp = (*source)->next;
		ft_lstadd(dest, *source);
		*source = temp;
	}
}

void	operation_rotate(t_list **top)
{
	t_list	*temp;
	t_list	*last;

	if (!*top || !(*top)->next)
		return ;
	temp = *top;
	last = temp->next;
	while (last->next)
		last = last->next;
	*top = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	operation_reverse_rotate(t_list **top)
{
	t_list	*temp;
	t_list	*last;

	if (!*top || !(*top)->next)
		return ;
	temp = *top;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	ft_lstadd(top, last);
}

void	double_operation(t_list **stack_a, t_list **stack_b, \
			void (*f)(t_list **))
{
	f(stack_a);
	f(stack_b);
}
