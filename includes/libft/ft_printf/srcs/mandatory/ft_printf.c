/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:28:29 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/mandatory/ft_printf.c
 * @dontinclude srcs/mandatory/ft_printf.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../../../libft.h"
#include "utils/utils.h"
#include <stdarg.h>

int	handle_sequence(const char **format, va_list args, int *fd, int total);

/**
 * @brief Process a section of the format string, whether it contains text
 * to print and / or format specifiers.
 * 
 * @param[in, out] format Pointer to address of format string.
 * @param[in, out] args Instance of variable argument list for the
 * @ref ft_printf call.
 * @param[in, out] fd File descriptor to write on.
 * @param[in, out] total Total number of characters written so far.
 */
static void	do_segment(const char **format, va_list args, int *fd, int *total)
{
	char	*seq_start;
	int		print_len;

	seq_start = ft_strchr(*format, '%');
	if (!seq_start)
		print_len = ft_strlen(*format);
	else
		print_len = seq_start - *format;
	if (print_len && seq_start != *format
		&& !wrap_err(write(*fd, *format, print_len), total))
		return ;
	*format += print_len;
	if (seq_start)
	{
		(*format)++;
		wrap_err(handle_sequence(format, args, fd, *total), total);
	}
}

/**
 * @brief Prints and formats a variable set of arguments.
 * 
 * The format for a specifier is as follows:  
 * `%[flags][width][precision][length]specifier`
 * 
 * <table>
 *  <tr>
 *    <th>Specifier
 *    <th>Function
 *    <th>Example
 *  <tr>
 *    <td>d or i
 *    <td>Signed decimal integer
 *    <td>-42
 *  <tr>
 *    <td>u
 *    <td>Unsigned decimal integer
 *    <td>42
 *  <tr>
 *    <td>o
 *    <td>Unsigned octal
 *    <td>52
 *  <tr>
 *    <td>x
 *    <td>Unsigned hexadecimal integer
 *    <td>2a
 *  <tr>
 *    <td>X
 *    <td>Unsigned uppercase hexadecimal integer
 *    <td>2A
 *  <tr>
 *    <td>c
 *    <td>Character
 *    <td>*
 *  <tr>
 *    <td>s
 *    <td>String of characters
 *    <td>Forty-two
 *  <tr>
 *    <td>p
 *    <td>Pointer address
 *    <td>0x2a
 *  <tr>
 *    <td>%
 *    <td>A % chracter
 *    <td>%
 *  <tr>
 *    <td>n
 *    <td>Nothing is printed.  
 * The corresponding argument must be a pointer to a signed integer, 
 * which will be set to the number of characters written so far.
 *    <td>
 *  <tr>
 *    <td>>
 *    <td>Nothing is printed.  
 * The corresponding argument must be a signed integer representing the
 * file descriptor to redirect any remaining output during this call to.
 *    <td>
 * </table>
 * 
 * <table>
 * 	<tr>
 *    <th>Flag
 *    <th>Specifiers
 *    <th>Description
 *  <tr>
 *    <td>-
 *    <td>All <sup>1</sup>
 *    <td>Left-justify padding instead of right-justifying.
 *  <tr>
 *    <td>+
 *    <td>d i
 *    <td>Preceed numbers with a + sign if they are not negative.
 *  <tr>
 *    <td>(space)
 *    <td>d i
 *    <td>Preceed numbers with a space if no sign is to be written.
 *  <tr>
 *    <td>#
 *    <td>o x X
 *    <td>If non-zero, preceed values for \b o, \b x, or \b X specifiers with
 * 0, 0x, or 0X respectively.
 *  <tr>
 *    <td>0
 *    <td>All <sup>1</sup>
 *    <td>Pad with zeroes instead of spaces. Cannot be mixed with precision
 * or left-justification.
 *  <tr>
 *    <td>_
 *    <td>All <sup>1</sup>
 *    <td>Pad with custom string, the address of which is provided in the next
 * function argument. Cannot be mixed with precision or left-justification if
 * used on used with \b d, \b i, \b o, \b u, \b x, or \b X.
 * </table>
 * <sup>1</sup> With the exception of the \b n and \b > specfiers, as they do
 * not print anything.
 * 
 * <table>
 * 	<tr>
 *    <th>Width
 *    <th>Description
 *  <tr>
 *    <td>(number)
 *    <td>Minimum number of characters to print. Pads to reach this number.
 *  <tr>
 *    <td>*
 *    <td>The minimum width should be retrieved from the next function argument.
 * </table>
 * 
 * <table>
 * 	<tr>
 *    <th>.precision
 *    <th>Description
 *  <tr>
 *    <td>.number
 *    <td>For \b d, \b i, \b o, \b u, \b x, or \b X, the minimum number of
 * digits to write. If the value is shorter than this number, it is padded with
 * leading zeros. For a precision of 0, nothing is written if the value is 0.
 * 
 * For \b s, the maximum number of characters to be printed.
 *  <tr>
 *    <td>*
 *    <td>The precision should be retrieved from the next function argument.
 * </table>
 * 
 * <table>
 * 	<tr>
 *    <td><th colspan="7">Specifiers
 * 	<tr>
 *    <th>Length
 *    <td>d i
 *    <td>u o x X
 *    <td>c
 *    <td>s
 *    <td>p
 *    <td>n
 *    <td>>
 *  <tr>
 *    <td>(none)
 *    <td>int
 *    <td>unsigned int
 *    <td>int
 *    <td>char *
 *    <td>void *
 *    <td>int *
 *    <td>int
 *  <tr>
 *    <td>hh
 *    <td>char
 *    <td>unsigned char<td colspan="3">
 *    <td>signed char *
 *    <td>
 *  <tr>
 *    <td>h
 *    <td>short
 *    <td>unsigned short<td colspan="3">
 *    <td>short *
 *    <td>
 *  <tr>
 *    <td>l
 *    <td>long
 *    <td>unsigned long<td colspan="3">
 *    <td>long *
 *    <td>
 *  <tr>
 *    <td>ll
 *    <td>long long
 *    <td>unsigned long long<td colspan="3">
 * 
 *    <td>long long *
 *    <td>
 *  <tr>
 *    <td>j
 *    <td>intmax_t
 *    <td>uintmax_t<td colspan="3">
 *    <td>intmax_t *
 *    <td>
 *  <tr>
 *    <td>z<td colspan="2">size_t<td colspan="3">
 *    <td>size_t *
 *    <td>
 *  <tr>
 *    <td>t<td colspan="2">ptrdiff_t<td colspan="3">
 *    <td>ptrdiff_t *
 *    <td>
 * </table>
 * 
 * @param[in] format Null terminated string containing text to print and,
 * optionally, conversion specifiers and subspecifiers.
 * See extended description.
 * @param[in, out] ... Variable amount of arguments of various types,
 * dependent on the @p format.
 * @retval int Number of characters printed, or @p -1 if an error occurs.
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		fd;

	if (!format)
		return (-1);
	fd = STDOUT_FILENO;
	va_start(args, format);
	total = 0;
	while (total > -1 && *format)
		do_segment(&format, args, &fd, &total);
	va_end(args);
	return (total);
}
