#include "get_next_line.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t n;

	n = 0;
	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[n] && n < (dstsize - 1))
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (src_len);
}

size_t		ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	new_s = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new_s)
		return (NULL);
	p = new_s;
	while (*s1)
		*new_s++ = *s1++;
	while (*s2)
		*new_s++ = *s2++;
	*new_s = '\0';
	return (p);
}

char		*ft_strzchr(char *s, int c, int i)
{
	char a;

	if (!s)
		return (NULL);
	a = (char)c;
	while (*s)
	{
		if (*s == a)
		{
			if (i == 0)
				*s = 0;
			return ((char *)s++);
		}
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (NULL);
}
