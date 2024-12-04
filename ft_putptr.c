
#include "ft_printf.h"

void    write_ptr(uint_ptr_t p)
{
    if (p <= 9)
        ft_putchar('0' + p);
    else if (p <= 15)
        ft_putchar('a' + p - 10);
    else
    {
        write_ptr(p / 16);
        write_ptr(p % 16);
    }
}

int get_len_ptr(uint_ptr_t p)
{
    int i;

    i = 0;
    while (p != 0)
    {
        p = p / 16;
        i++;
    }
    return (i);
}


int ft_putptr(uint_ptr_t p)
{
    int i;

    i = write(1, "0x", 2);
    if (p == 0)
        i += write(1, "0", 1);
    else
    {
        write_ptr(p);
        i += get_len_ptr(p);
    }
    return (i);
}