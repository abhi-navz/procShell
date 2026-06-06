#include <stdio.h>
#include <string.h>

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

        printf("Parsed Command:\n");

        for(int j = 0; args[j] != NULL; j++)
        {
            printf("%s\n", args[j]);
        }
    }

    return 0;
}