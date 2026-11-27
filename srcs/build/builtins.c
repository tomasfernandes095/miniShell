#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

int is_builtin(char *cmd)
{
    if (!cmd)
        return (0);
    return (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0 ||
            strcmp(cmd, "cd") == 0 || strcmp(cmd, "help") == 0 ||
            strcmp(cmd, "clear") == 0);
}

int execute_builtin(char **args)
{
    // A) exit ou quit
    if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0)
    {
        printf("A terminar myshell...\n");
        exit(0);
    }
    // B) cd [directoria]
    else if (strcmp(args[0], "cd") == 0)
    {
        char *path = args[1];
        if (path == NULL) // Se não indicar diretoria, vai para HOME
            path = getenv("HOME");
        if (chdir(path) != 0)
            perror("myshell: cd");
    }
    // C) help
    else if (strcmp(args[0], "help") == 0)
    {
        printf("=== MyShell - Ajuda ===\n");
        printf("Comandos internos:\n");
        printf("  cd [dir]   - Muda de diretoria (sem argumentos vai para HOME)\n");
        printf("  help       - Mostra esta mensagem de ajuda\n");
        printf("  clear      - Limpa o ecra\n");
        printf("  exit/quit  - Sai do shell\n");
        printf("Qualquer outro comando sera executado pelo sistema operativo.\n");
    }
    // D) clear
    else if (strcmp(args[0], "clear") == 0)
    {
        printf("\033[H\033[J"); // Código ANSI para limpar o terminal
    }
    return (1);
}