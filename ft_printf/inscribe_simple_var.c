/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe_simple_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	inscribe_c_var(va_list *aprtf, t_info *list)
{
	int		cur_arg;

	cur_arg = va_arg(*aprtf, int);
	list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
	list->converted_string[list->nb_c_written++] = cur_arg;
	return ;
}

void	inscribe_C_var(va_list *aprtf, t_info *list)
{
	int		cur_arg;

	cur_arg = va_arg(*aprtf, wchar_t);
	list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
	list->converted_string[list->nb_c_written++] = cur_arg;
	return ;
}

void	inscribe_s_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	char	*cur_arg;
	int 	i;
	int		y;

	cur_arg = va_arg(*aprtf, char*);
	if (flag->precision && flag->precision <= (int)ft_strlen(cur_arg))
		i = flag->precision;
	else
		i = ft_strlen(cur_arg);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = cur_arg[y++];
	return ;
}

void	inscribe_S_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	wchar_t		*cur_arg;
	int 		i;
	int 		y;

	cur_arg = va_arg(*aprtf, wchar_t*);
	if (flag->precision && flag->precision <= (int)ft_strlen_wchart(cur_arg))
		i = flag->precision;
	else
		i = ft_strlen_wchart(cur_arg);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = (char)cur_arg[y++];
	return ;
}

void	inscribe_di_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	int		cur_arg_int;
	char	*cur_arg_string;
	int 	i;
	int 	y;

	cur_arg_int = va_arg(*aprtf, int);
	cur_arg_string = ft_itoa(cur_arg_int);
	if ((i = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(printf_precision(flag, i), cur_arg_string);
	cur_arg_string = add_wof_to_cur_arg_string(cur_arg_string, flag);
	i = ft_strlen(cur_arg_string);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	ft_strdel(&cur_arg_string);
	return ;
}