#include "cs392_exec.h"

// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

char **parse_command(char *input)
{
	char **parsed_commands = malloc(sizeof(char*) * 100);
	int i;
	for (i = 0; input != NULL; i++)
	{
		parsed_commands[i] = input;
		input = strtok(NULL, " ");
	}
	parsed_commands[i] = NULL;
	return parsed_commands;
}

int get_length(char **command)
{
	int i = 0;
	while (command[i] != NULL)
	{
		i++;
	}
	return i;
}

void exec(char *args)
{

	char *fst = strtok(args, "|");
	char *snd = strtok(NULL, "|");

	char **fst_command = parse_command(fst);
	char **snd_command = parse_command(snd);
	int snd_command_length = get_length(snd_command);

	int fd1[2];

	if (snd_command_length != 0 && pipe(fd1) == 0)
	{
		perror("error");
		exit(1);
	}

	pid_t pid, child;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	//child
	else if (pid == 0)
	{
		if (snd_command_length != 0)
		{
			close(fd1[0]);
			dup2(fd1[1], 0);
			close(fd1[1]);
		}
		execvp(fst_command[0], fst_command);
		return;
	}

	waitpid(pid, NULL, 0);
	if (snd_command_length != 0)
	{
		child = fork();
		if (child < 0)
		{
			perror("fork");
		}
		else if (child == 0)
		{
			close(fd1[1]);
			int size = 100;
			snd_command[snd_command_length] = malloc(sizeof(char) * 100);
			while (read(fd1[0], snd_command[snd_command_length], 100) != 0) {
				// reallocate if past buffer
				size += 100;
				snd_command[snd_command_length] = realloc(snd_command[snd_command_length], size);
				if (!snd_command[snd_command_length]) {
					fprintf(stderr, "Memory allocation error\n");
       		exit(EXIT_FAILURE);
				}
			}
			close(fd1[0]);
			snd_command[snd_command_length + 1] = NULL;
			execvp(snd_command[0], snd_command);
			free(snd_command[snd_command_length]);
			return;
		}
		waitpid(child, NULL, 0);
	}

	free(fst_command);
	free(snd_command);
	close(fd1[0]);
	close(fd1[1]);
}
