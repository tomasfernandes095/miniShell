#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char *input;

    (void)argc;
    (void)argv;
    (void)envp;
    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
        {
            printf("exit\n");
            break ;
        }
        if (*input)
            add_history(input);
        printf("Escreveste: %s\n", input);
        free(input);
    }
    return (0);
}