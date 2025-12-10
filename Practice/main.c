#include "gnl.h"
// -I./libft -L./libft -lft

int main()
{
    int 	fd;
	char	*buffer;
	const char	*filename = "poem0.txt";
	int		idx;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
	{
        perror("### Error opening file ###"); 
        return EXIT_FAILURE;
    }
    printf("***Successfully opened %s (fd: %d)***\n\n", filename,fd);

	idx = 0;
	// buffer = get_next_line(fd);
	while ((buffer = get_next_line(fd)) && idx < 30) //idx < 20)
	{
		// buffer = get_next_line(fd);
		printf("m%d|%s|", idx, buffer);
		free(buffer);
		idx++;
	}

    if (close(fd) == -1) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }
    printf("	*** File 'example.txt' closed successfully. ***\n");
    return EXIT_SUCCESS;
}