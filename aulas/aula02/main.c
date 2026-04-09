#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){
Agenda agenda = cria_agenda(10);
Contato contato;
strcpy(contato.name, "jose");
strcpy(contato.telefone, "99999-9999");
adicionar_contato(&agenda, contato);
listar_contatos(&agenda);

Contato outro;
strcpy(outro.name, "maria");
strcpy(outro.telefone,"88888-8888");
adicionar_contato(&agenda, outro);
listar_contatos(&agenda);

return 0;

}
