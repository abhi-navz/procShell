#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

int main()
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while(1)
    {
        printf("ProcShell> ");

        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if(strlen(input) == 0)
        {
            continue;
        }

        if(strcmp(input, "exit") == 0)
        {
            break;
        }

        int i = 0;

        char *token = strtok(input, " ");

        while(token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        pid_t pid = fork();

        if(pid == 0)
        {
            execvp(args[0], args);

            perror("execvp");
            exit(1);
        }
        else if(pid > 0)
        {
            waitpid(pid, NULL, 0);
        }
        else
        {
            perror("fork");
        }
    }

    return 0;
}