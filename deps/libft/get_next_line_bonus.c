/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:33 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/22 05:42:40 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_bonus.c
 * @dontinclude get_next_line_bonus.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"
#include "get_next_line_bonus.h"

/**
 * @brief Allocate and return a new string of size <tt>len + 1</tt> containing
 * @p len characters from string pointed to by @p s1, allocate a new string
 * containing the remainder of the string pointed to by @p s1, free the
 * original, and set address at @p s1 to point to the remainder string.
 * 
 * @param s1 Pointer to address of string to consume from
 * @param len Number of characters to consume
 * @retval char* Allocated consumed section of @p *s1
 */
static char	*consume_and_resize(char **s1, size_t len)
{
	size_t	new_s1_len;
	char	*new_s1;
	char	*s2;

	s2 = malloc(len + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, *s1, len);
	s2[len] = '\0';
	new_s1_len = ft_strlen(*s1 + len);
	new_s1 = 0;
	if (new_s1_len)
	{
		new_s1 = malloc(new_s1_len + 1);
		if (!new_s1)
		{
			free(s2);
			return (0);
		}
		ft_memcpy(new_s1, *s1 + len, new_s1_len + 1);
	}
	free(*s1);
	*s1 = new_s1;
	return (s2);
}

/**
 * @brief Find the first newline in string @p s and
 * write its index + 1 into @p len
 * 
 * @param[in] s Null-terminated string to search
 * @param[out] len Pointer to size_t integer into which the position index of
 * the newline + 1 is written
 * @retval size_t @p len
 */
static size_t	find_line_end(char *s, size_t *len)
{
	*len = 0;
	if (!s)
		return (0);
	while (s[*len])
	{
		if (s[(*len)++] == '\n')
			return (*len);
	}
	return (*len = 0);
}

/**
 * @brief Reading from @p fd, fill and / or allocate line buffer at
 * @p line_buf, set @p first_line_len to the length of the first
 * segment ending with a newline or EOF
 * 
 * @param[in] fd Integer file descriptor to read from
 * @param[in, out] line_buf Pointer to address of allocated memory to fill.
 * Address at @p *line_buf may be NULL
 * @param[in, out] first_line_len Pointer to size_t integer into which the
 * length of the first line is written
 * @retval size_t @p first_line_len
 */
static size_t	fill_line_buf(int fd, char **line_buf, size_t *first_line_len)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	read_len;
	char	*old;

	read_len = BUFFER_SIZE;
	while (!find_line_end(*line_buf, first_line_len) && read_len == BUFFER_SIZE)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len < 0)
			return (*first_line_len = 0);
		read_buf[read_len] = '\0';
		if (!*line_buf)
			*line_buf = ft_strdup(read_buf);
		else
		{
			old = *line_buf;
			*line_buf = ft_strjoin(*line_buf, read_buf);
			free(old);
		}
		if (!*line_buf)
			return (*first_line_len = 0);
	}
	if (read_len != BUFFER_SIZE && !*first_line_len)
		*first_line_len = ft_strlen(*line_buf);
	return (*first_line_len);
}

/**
 * @brief Return the next segment of text ending in a
 * newline or EOF from file descriptor @p fd
 * 
 * @param[in] fd Integer file descriptor to read from
 * @retval char* Freeable, null-terminated string on success, or @p NULL
 * if error or nothing to read
 */
char	*get_next_line(int fd)
{
	static char		*line_buf[MAX_FD + 1] = {0};
	size_t			first_line_len;
	char			*out;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (0);
	fill_line_buf(fd, line_buf + fd, &first_line_len);
	if (!first_line_len)
	{
		if (line_buf[fd])
			free(line_buf[fd]);
		return (line_buf[fd] = 0);
	}
	out = consume_and_resize(line_buf + fd, first_line_len);
	if (!out)
	{
		free(line_buf[fd]);
		line_buf[fd] = 0;
	}
	return (out);
}
