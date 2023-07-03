# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

void	*hola(void *arg)
{
	char	*msg = "Hola";
	int		i;

	i = 0;
	while (i < strlen(msg))
	{
		printf(" %c", msg[i]);
		fflush(stdout);
		usleep(1000000000);
		i++;
	}
	return (NULL);
}

void	*mundo(void *arg)
{
	char	*msg = "mundo";
	int		i;

	i = 0;
	while (i < strlen(msg))
	{
		printf(" %c", msg[i]);
		fflush(stdout);
		usleep(1000000000);
		i++;
	}
	return (NULL);
}

void	*slowprint(void *arg)
{
	char	*msg;
	int		i;

	msg = (char *)arg;
	i = 0;
	while (i < strlen(msg))
	{
		printf(" %c", msg[i]);
		fflush(stdout);
		usleep(1000000);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	h1;
	pthread_t	h2;

	pthread_create(&h1, NULL, slowprint, (void *)mundo);
	pthread_create(&h2, NULL, slowprint, (void *)hola);
	pthread_join(h1, NULL);
	pthread_join (h2, NULL);
	printf("Fin\n");
}