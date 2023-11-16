#include "main.h"

/**
 * _printf - printf
 * @format: format string
 * Return: formatted string
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	fmt_spec symbol_matrix[] = {
		{'c', _char}, {'s', _string},
		{'d', _dec}, {'i', _int},
		{'\0', NULL}
	};

	va_start(args, format);
	count = 0;
	if (format != NULL)
	{
		if (_format(format, &count, symbol_matrix, args) == -1)
			return (-1);
	}
	else
		return (-1);

	va_end(args);
	return (count);
}

/**
 * _format - format string
 * @format: format string
 * @count: counter
 * @symbol_matrix: symbol matrix
 * @args: arguments
 * Return: 0 success, -1 error
*/

int _format(const char *format, int *count,
	fmt_spec symbol_matrix[], va_list args)
{
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			(*count)++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format_check(format[i], symbol_matrix, args, count) == -1)
			{
				_putchar('%');
				_putchar(format[i]);
				(*count) += 2;
			}
		}
	}
	return (0);
}

/**
 * format_check - format check
 * @symbol: symbol
 * @symbol_matrix: symbol matrix
 * @args: arguments
 * @count: counter
 * Return: -1 if error, 0 if no error
*/

int format_check(char symbol, fmt_spec symbol_matrix[],
	va_list args, int *count)
{
	int row;

	if (symbol == '%')
	{
		_putchar(symbol);
		(*count)++;
		return (0);
	}

	for (row = 0; symbol_matrix[row].symbol != '\0'; row++)
	{
		if (symbol == symbol_matrix[row].symbol)
		{
			symbol_matrix[row].func_ptr(args, count);
			return (0);
		}
	}
	return (-1);
}

/**
 * _char - char print function
 * @args: argument list
 * @count: count parameter
*/

void _char(va_list args, int *count)
{
	char character;

	character = va_arg(args, int);
	_putchar(character);
	(*count)++;
}

/**
* _dec - decimal specifier
* @args: argument list
* @count: argument count
* Return: void
*/

void _dec(va_list args, int *count)
{
	int dec, i, j, num_len;
	unsigned int num, pos_num;
	char *digits;

	dec = va_arg(args, int);
	if (dec < 0)
		pos_num  = dec * -1;
	else
		pos_num = dec;
	num = pos_num;
	num_len = 0;
	while (pos_num / 10 != 0)
	{
		num_len++;
		pos_num = pos_num / 10;
	}
	num_len++;
	digits = malloc(sizeof(char) * num_len + 1);
	if (digits == NULL)
		return;

	j = 0;
	while (num / 10 != 0)
	{
		digits[j] = (num % 10) + '0';
		num = num / 10;
		j++;
	}
	digits[j] = (num % 10) + '0';
	if (dec < 0)
	{
		_putchar('-');
		(*count)++;
	}
	for (i = j; i >= 0; i--)
	{
		_putchar(digits[i]);
		(*count)++;
	}
	free(digits);
}
