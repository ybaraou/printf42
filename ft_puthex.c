void    writehex(unsigned int n, char c)
{
    if (n <= 9)
        ft_putchar('0' + n);
    else if (n <= 15)
    {
        if (c == 'x')
            ft_putchar('a' + n - 10);
        else
            ft_putchar('A' + n - 10);
    }
    else
    {
        writehex(n / 16, c);
        writehex(n % 16, c);
    }
}


int get_len_hex(unsigned int n)
{
    int i;

    i = 1;
    while (n > 15)
    {
        n = n / 16;
        i++;
    }
    return (i);
}

int ft_puthex(unsigned int n, char c)
{
    int count;

    writehex(n, c);
    count = get_len_hex(n);
    return (count);
}