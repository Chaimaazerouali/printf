#include "main.h"
/**
 * display_binary - Print unsigned binary number.
 * @args: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int display_binary(va_list args, param_t *params)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = num_convert(num, 2, UNSIGNED_CONV, params);
	int count = 0;

	if (params->hashtag && num)
		*--str = '0';
	params->isUnsigned = 1;
	return (count += print_num_str(str, params));
}

/**
 * display_octal - Print unsigned octal numbers.
 * @args: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int display_octal(va_list args, param_t *params)
{
	unsigned long val;
	char *str;
	int count = 0;

	if (params->lMod)
		val = (unsigned long)va_arg(args, unsigned long);
	else if (params->hMod)
		val = (unsigned short int)va_arg(args, unsigned int);
	else
		val = (unsigned int)va_arg(args, unsigned int);

	str = num_convert(val, 8, UNSIGNED_CONV, params);

	if (params->hashtag && val)
		*--str = '0';
	params->isUnsigned = 1;
	return (count += print_num_str(str, params));
}
