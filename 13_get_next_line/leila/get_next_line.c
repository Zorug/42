int main(void)
{
	int fd;
	char *str;

	fd = open("test.txt", 0_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	//printf("%s", str);
	close(fd);
	return (0);
}