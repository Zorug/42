#include <stdbool.h>
#include <stdio.h>

bool find_in_base(const char *hex_base, char c)
{
	while (*hex_base)
	{
		//printf("%c\n",*hex_base);
		if (c >= 'A' && c <= 'F')
			return true;
		else if (*hex_base == c)
			return true;
		hex_base++;
	}
	return false;
}

int pos_in_base(const char *hex_base, const char *hex_base_high, char c)
{
	int i = 0;
	//printf("@@@@\n");
	while (hex_base[i] && hex_base_high[i])
	{
		if (hex_base[i] == c)
			return i;
		else if (hex_base_high[i] == c)
			return i;
		i++;
	}
	return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	const char *hex_base, *hex_base_high;
	int sign = 1;
	int num = 0;
	hex_base = "0123456789abcdef";
	hex_base_high = "0123456789ABCDEF";
	int base_value;
	int str_size = 0;

	while(str[str_size])
		str_size++;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	//printf("Teste\n");
	while (find_in_base(hex_base, *str) == true && *str)
	{
		//printf("<>\n");
		base_value = pos_in_base(hex_base, hex_base_high, *str);
		num = num * str_base + base_value;
		//printf("!%d!\n", num);
		str++;
	}
	//printf("TESSSS\n");
	return (num*sign);
}

/*int main()
{
	const char *str;
	int str_base = 2;

	str = "1111101";
	printf("%d\n", ft_atoi_base(str, str_base));
}*/