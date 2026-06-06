#include <stdio.h>

int main()
{
    char input[1024];

    while(1)
    {
        printf("ProcShell> ");

        fgets(input, sizeof(input), stdin);

        printf("You entered: %s", input);
    }

    return 0;
}