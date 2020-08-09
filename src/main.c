/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

int main() {
  int j=0;
  int i=0;
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);
  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {
	if (buffer_entrada[i]>='A' && buffer_entrada[i]<='Z'){
	    if ((buffer_entrada[i]-'A')<(senha[j]-'A'))
		buffer_saida[i] = 'A' + (buffer_entrada[i]-'A'+26)-(senha[j]-'A');
	    else
		buffer_saida[i] = 'A' + (buffer_entrada[i]-'A')-(senha[j]-'A');
	}
	else
		buffer_saida[i] = buffer_entrada[i];
	j++;
	if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
