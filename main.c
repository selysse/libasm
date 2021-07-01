#include "libasm.h"

void	strlen_test()
{
	char	*str;

	printf("\n---Test strlen---\n");

	str = "";
	printf("\n---Test1---\n\n");
	printf("Len is %lu = %d", strlen(str), ft_strlen(str));
	printf("\n\n---Test2---\n\n");
	str = "Helloworld";
	printf("Len is %lu = %d", strlen(str), ft_strlen(str));
	printf("\n\n---Test3---\n\n");
	str = "Make sure both nasm and gcc are installed. Save one of the following programs as hello.asm, depending on your machine platform. Then run the program according to the given instructions.";
	printf("Len is %lu = %d", strlen(str), ft_strlen(str));
	printf("\n");
}

void    strcpy_test()
{
	char    *str;
	char	buf[10] = "XXXXX";
	char	buf1[10] = "XXXXX";

	str = "";
	printf("\n---Test strcpy---\n");
	printf("\n---Test1---\n\n");
	printf("Copy %s %s\n", str, buf);
	printf("Copy %s %s\n", str, buf1);
	printf("%s = %s", strcpy(buf, str), ft_strcpy(buf1, str));
	printf("\n\n---Test2---\n\n");
	str = "gselyse";
	printf("Copy %s %s\n", str, buf);
	printf("Copy %s %s\n", str, buf1);
	printf("%s = %s", strcpy(buf, str), ft_strcpy(buf1, str));
	printf("\n\n---Test3---\n\n");
	char	buf2[186];
	char	buf3[186];
	str = "Make sure both nasm and gcc are installed. Save one of the following programs as hello.asm, depending on your machine platform. Then run the program according to the given instructions.";
	printf("Copy %s %s\n", str, buf2);
	printf("Copy %s %s\n", str, buf3);
	printf("%s = %s", strcpy(buf2, str), ft_strcpy(buf3, str));
	printf("\n");
}

void    strcmp_test()
{
	char	*str_null;
	char	*str;
	char	*str_l;

	str_null = "";
	str = "Helloworld";
	str_l = "Make sure both nasm and gcc are installed. Save one of the following programs as hello.asm, depending on your machine platform. Then run the program according to the given instructions.";
	printf("\n---Test strcmp---\n");
	printf("\n---Test1---\n\n");
	printf("Value is %d = %d", strcmp(str_null, str_null), ft_strcmp(str_null, str_null));
	printf("\n\n---Test2---\n\n");
	printf("Value is %d = %d", strcmp(str_null, str), ft_strcmp(str_null, str));
	printf("\n\n---Test3---\n\n");
	printf("Value is %d = %d", strcmp(str, str_null), ft_strcmp(str, str_null));
	printf("\n\n---Test4---\n\n");
	printf("Value is %d = %d", strcmp(str, str_l), ft_strcmp(str, str_l));
	printf("\n\n---Test5---\n\n");
	printf("Value is %d = %d\n\n", strcmp(str_l, str), ft_strcmp(str_l, str));
	printf("\n\n---Test6---\n\n");
	printf("Value is %d = %d\n\n", strcmp("s", "s"), ft_strcmp("s", "s"));
}

void		write_test()
{	
	int		fd;
	char	*str;
	int		i;
	int		x;


	printf("\n---Test write---\n");
	printf("\n---Test1---\n\n");

	str = "Helloworld\n";
	i = write(1, str, strlen(str));
	x = ft_write(1, str, ft_strlen(str));
	printf("Value is %d = %d", i, x);

	printf("\n\n---Test2---\n\n");

	str = "";
	i = write(1, str, strlen(str));
	x = ft_write(1, str, ft_strlen(str));
	printf("Value is %d = %d", i, x);
	
	printf("\n\n---Test3---\n\n");

	errno = 0;
	str = "Helloworld\n";
	fd = open("text.txt", O_RDWR);
	printf("errno - %d\n", errno);
	printf("Writing . . .\n");
	i = write(fd, str, strlen(str));
	printf("errno - %d\n", errno);
	if (errno == 0)
		printf("Success!\n");

	errno = 0;
	printf("\nerrno - %d\n", errno);
	printf("Writing . . .\n");    
	i = ft_write(fd, str, strlen(str));
	printf("errno - %d\n", errno);
	if (errno == 0)
		printf("Success!");
	close(fd);

	printf("\n\n---Test4---\n\n");

	str = "HelloWorld\n";
	errno = 0;
	printf("errno - %d\n", errno);
	printf("Writing . . .\n");
	i = write(-1, str, strlen(str));
	printf("errno - %d\n", errno);
	printf("Error - %s\n", strerror(errno));

	errno = 0;
	printf("\nerrno - %d\n", errno);
	printf("Writing . . .\n");    
	i = ft_write(-1, str, strlen(str));
	printf("errno - %d\n", errno);
	printf("Error - %s\n\n", strerror(errno));
}

void        read_test()
{	
	int		fd;
	char	str[8] = "gselyse";
	int		i;
	int		x;

	printf("\n---Test read---\n");;
	
	printf("\n---Test1---\n\n");

	printf("buffer - %s\n", str);
	x = ft_read(0, &str, 5);
	printf("\nbuffer - %s\n", str);
	printf("Value is: %d\n\n", x);
	
	printf("---Test2---\n\n");

	fd = open("test.txt", O_RDWR);
	printf("string - %s\n", str);
	printf("Reading . . .\n");
	x = ft_read(fd, str, 5);
	printf("Value is: %d\n\n", x);
	if (x == -1)
	{
		printf("errno - %d\n", errno);
		printf("Error - %s\n\n", strerror(errno));
	}
	else
		printf("string - %s\n\n", str);
	close(fd);
	printf("\n---Test3---\n\n");
	errno = 0;
	printf("errno - %d\n", errno);
	printf("Reading . . .\n");
	i = read(-1, str, 5);
	printf("errno - %d\n", errno);
	printf("Error - %s\n", strerror(errno));
	errno = 0;
	printf("errno - %d\n", errno);
	printf("Writing . . .\n");
	i = ft_read(-1, str, strlen(str));
	printf("errno - %d\n", errno);
	printf("Error - %s\n\n", strerror(errno));
}

void    strdup_test()
{
	char	*str_null;
	char	*str;
	char	*str_l;

	str_null = " ";
	str = "Helloworld";
	str_l = "Make sure both nasm and gcc are installed. Save one of the following programs as hello.asm, depending on your machine platform. Then run the program according to the given instructions.";
	
	printf("\n---Test strdup---\n");
	printf("\n---Test1---\n\n");
	printf("String is '%s' = '%s'", strdup(str_null), ft_strdup(str_null));
	printf("\n\n---Test2---\n\n");
	printf("String is %s = %s", strdup(str), ft_strdup(str));
	printf("\n\n---Test3---\n\n");
	printf("String is %s = %s\n\n", strdup(str_l), ft_strdup(str_l));
}

int		main()
{
	strlen_test();
	strcpy_test();
	strcmp_test();
	write_test();
	read_test();
	strdup_test();
	return (0);
}
