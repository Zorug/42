#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

int ft_printf(const char *format, ...) {
	va_list args;
	va_start(args, format); //initialize the argument list

	while(*format) {
		if(*format == '%' && *(format + 1)) { // found a format specifier
			format++;
			if(*format == 'd') { // handle %d
				int value = va_arg(args, int); //Extract an int
				printf("%d", value); // print it (or implement custom logic)
			}
			else if (*format == 's') { //handle with %s
				char *str = va_arg(args, char *); // Extract a string
				printf("%s", str); // print it
			}
		}
		else {
			ft_putchar(*format); //print plain characters
		}
		format++;
	}

	va_end(args); // Clean up
	return 0;
}

int main() {
	ft_printf("Hello %s! You have send %d new messages.\n", "Alice", 5);
	return 0;
}