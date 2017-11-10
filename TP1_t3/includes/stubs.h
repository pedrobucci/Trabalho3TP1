#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"
#include "resultado.h"
#include <iostream>

using namespace std;

/*
* O ILNCriar-Conta � um stub que representa o modulo de verifica��o de Contas de Usuario retornando
* um valor que indica se uma nova conta pode ser criada.
*/

class LNCriar_Conta: public ILNCriar_Conta {
    private:
        const static int SEM_ERRO = 1;
        const static int COM_ERRO = 0;

    public:
        /*
        * metodo que faz a verifica�ao descrita
        */

        int verificar_BD( char* apelido ) { return SEM_ERRO; }
};

/*
* classe stub que representa o servi�o de autentica��o de conta
*/


class StubLNAutenticacao:public ILNAutenticacao{

public:

    /*
    * Defini��es de valores a serem usados como gatilhos para notifica��es de erros.
    */

    const char* TRIGGER_FALHA        = "erro";
    const char* TRIGGER_ERRO_SISTEMA = "ERRO";

    /*
    * Declara��o de m�todo previsto na interface.
    */

    Resultado autenticar( ApelidoTP1& apelido, SenhaTP1& senha);
};

/*
* Declara��o de classe stub da interface ILNGerente. Responsavel por administrar as a��es do gerente(o Usuario)
*/

class StubLNGerente:public ILNGerente{

public:

    const char* TRIGGER_FALHA        = "erro";
    const char* TRIGGER_ERRO_SISTEMA = "ERRO";

    /*
    * Defini��es de valores a serem usados como gatilhos para notifica��es de erros.
    */

    Resultado incluir(Livro&);
    Resultado remover(Livro&);
    ResultadoUsuario pesquisar(ApelidoTP1&);
    Resultado editar(Usuario&);
};

#endif // STUBS_H_INCLUDED
