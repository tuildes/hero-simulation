#include "principal.h"

// Sendo um objeto de apenas informações
typedef struct objeto_evento evento;
struct objeto_evento {
    
    int tempo;
    int tipo;
    char mensagem[150];

};