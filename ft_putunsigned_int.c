int	get_len(unsigned int c)
{
	int			len;

	len = 1;
	while (c > 9)
	{
		c /= 10;
		len++;
	}
	return (len);
}

char	*convert_to_char(unsigned int num)
{
	int		len;
	char	*res;

	len = get_len(num);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (res);
}

int ft_putunsigned_int(unsigned int n)
{
    char    *s;
    int     count;

    s = convert_to_char(n);
    count = ft_putstr(s);
    free(s);
    return (count);
}