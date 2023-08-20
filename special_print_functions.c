#include "main.h"

/**
 * print_range - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_range(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += custom_putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * reverse_print - prints string in reverse
 * @args: string
 * @params: the parameter settings struct
 *
 * Return: number bytes printed
 */
int reverse_print(va_list args, param_t *params)
{
	int len, sum = 0;
	char *str = va_arg(args, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += custom_putchar(*str);
	}
	return (sum);
}
