#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"
#include "resultado.h"
#include <iostream>

using namespace std;

/*
* O ILNCriar-Conta é um stub que representa o modulo de verificação de Contas de Usuario retornando
* um valor que indica se uma nova conta pode ser criada.
*/

class LNCriar_Conta: public ILNCriar_Conta {
    private:
        const static int SEM_ERRO = 1;
        const static int COM_ERRO = 0;

    public:
        /*
        * metodo que faz a verificaçao descrita
        */

        int verificar_BD( char* apelido ) { return SEM_ERRO; }
};

/*
* classe stub que representa o serviço de autenticação de conta
*/


class StubLNAutenticacao:public ILNAutenticacao{

public:

    /*
    * Definições de valores a serem usados como gatilhos para notificações de erros.
    */

    const char* TRIGGER_FALHA        = "erro";
    const char* TRIGGER_ERRO_SISTEMA = "ERRO";

    /*
    * Declaração de método previsto na interface.
    */

    Resultado autenticar( ApelidoTP1& apelido, SenhaTP1& senha);
};

/*
* Declaração de classe stub da interface ILNGerente. Responsavel por administrar as ações do gerente(o Usuario)
*/

class StubLNGerente:public ILNGerente{

public:

    const char* TRIGGER_FALHA        = "erro";
    const char* TRIGGER_ERRO_SISTEMA = "ERRO";

    /*
    * Definições de valores a serem usados como gatilhos para notificações de erros.
    */

    Resultado incluir(Livro&);
    Resultado remover(Livro&);
    ResultadoUsuario pesquisar(ApelidoTP1&);
    Resultado editar(Usuario&);
};

#endif // STUBS_H_INCLUDED
