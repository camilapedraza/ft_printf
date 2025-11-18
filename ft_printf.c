/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:47:00 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/18 21:21:37 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"


static int is_escape(const char *str, int *index)
{
    // improve this check: if chars following % and before next %:
	// - are IN the FLAG char set (0123456789-.# +)
	// - are NOT in the flag set (cspdiuxX)
	// index needs to increase by that many chars and single % is printed

	// if chars break fules (NOT a flag, or ORDER wrong) print chars as normal
	// but careful: certain combinations might still activate formatting
	// example: "abcdef%-0 -w#%12345" the -0 part is not printed, the space is!

	if (str[(*index) + 1] == '%')
    {
        write(1, "%", 1);
        (*index) += 2;
        return (1)
    }
    return (0);
}
// cspdiuxX%
// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// p The void * pointer argument has to be printed in hexadecimal format.
// 		so: %#x
// d Prints a decimal (base 10) number.
// i Prints an integer in base 10.
// u Prints an unsigned decimal (base 10) number.
// x Prints a number in hexadecimal (base 16) lowercase format.
// X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
// %[argument$][flags][width][.precision][length modifier]conversion
// BONUS 1: Manage any combination of the following flags: ’-0.’ and 
// the field minimum width under all conversions.
// '0' csp blank-padded and diuxX 0-padded (left padding for both)
// '-' output (padded with blanks on right) check field boundary
//		'-' overrides '0' flag
// '.' optional precision: followed by decimal or * (next arg)
// 		'.' without followup means ZERO. Negative means no precision.
//		'.' decimal/arg = min printed digits for diuxX or max chars for s
// 'n' non-zero decimal digit specifing minimum field width.
//		if converted value has fewer chars than fw, it is padded with spaces
//		(on the left, unless the left adjustment flag is used ('-')
// BONUS 2:  Manage all the following flags: ’# +’
// '#' additional specifiers for conversions!:
//     0x or 0X prefix for x and X flags respectively
// ' ' A blank should be left before a positive number
// '+' for signed conversions only: display + or - (overrides space flag)




static void parse_spec(const char *str, int *index, va_list args)
{
	// check flags first?
	//	or check to see if a conversion speficier is present?
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int		index;

	index = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] != '%')
			write(1, &str[index++], 1);
		else
			if (!is_escape(str, &index))
				parse_spec(str, &index, args);
	}
	va_end(args);
	return (index);
}
