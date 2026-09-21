#include <stdio.h>
#include <stdlib.h>
#include "../includes/clshell.h"

int main()
{
    cls_loop();

    return EXIT_SUCCESS;
}

void cls_loop()
{
    char *line;
    int status = 1;

    do {
        printf("> ");
        line = cls_read_line();
        printf("O usuário digitou isso > %s\n", line);

    } while (status);
}

char* cls_read_line()
{
    int bufsize = CLS_BUFSIZE;
    char* buffer = malloc(bufsize * sizeof(char));
    int c;

    if (buffer == NULL) {
        fprintf(stderr, "Não foi possivel alocar memória.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < bufsize; i++) {
        c = getchar();

        if (c != EOF && c != '\n') {
            buffer[i] = c;
        } else {
            buffer[i] = '\0';
            break;
        }

        if (i >= bufsize)
        {
            fprintf(stderr, "Buffer excedeu o limite suportado.");
            exit(EXIT_FAILURE);
        }
    }

    return buffer;
}
