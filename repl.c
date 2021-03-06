#include <stdio.h>
#include <stdlib.h>

/* Caso estivermos compilando no windows, compile estas funcoes */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Funcao imitadora readline */
char* readline(char* prompt) 
  {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
  }

/* Funcao imitadora add_history */
void add_history(char* unused) {}

#else
#include <editline.h>
#endif

int main()
  {

    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit");
    puts("Status: development\n");

    while (1) {

      /* Now in either case readline will be correctly defined */
      char* input = readline("lispy > ");
      add_history(input);

      printf("%s\n", input);
      free(input);

    }

    return 0;

  }
