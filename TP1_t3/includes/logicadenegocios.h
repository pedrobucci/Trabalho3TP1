#ifndef LOGICADENEGOCIOS_H_INCLUDED
#define LOGICADENEGOCIOS_H_INCLUDED

#include <iostream>
#include "Banco_de_dados.h"
#include "interfaces.h"

/**
* Definição da lógica de negócios do modulo de criação de conta
*/

class LNCriar_Conta: public ILNCriar_Conta {
    private:

        Banco_de_Dados *oraculo;

        const static int SEM_ERRO = 1;
        const static int COM_ERRO = 0;

    public:
        /**
        * adiciona um usuario no banco de dados.
        */

        void adicionar_no_BD( Usuario usuario );

        /**
        * VERIFICAR retorna 0 (erro) se encontrar esse apelido ja registrado. 1 caso contrario.
        * SET_BD "encaixa" o banco de dados requisitado no modulo de criação de contas.
        */

        int verificar_BD( char* apelido );
        void set_BD( Banco_de_Dados *oraculo ) { this->oraculo = oraculo; };
};



/**
* Definição da lógica de negócios do modulo de autenticação de usuario
*/

class LNAutenticacao:public ILNAutenticacao{
private:
    Banco_de_Dados *oraculo;

public:
    /**
    * Declaração de método previsto na interface.
    */
    Resultado autenticar( ApelidoTP1& apelido, SenhaTP1& senha);
    void set_BD( Banco_de_Dados *oraculo ) { this->oraculo = oraculo; };
};



/**
* Definição da lógica de negócios do modulo de gerenciamento de conta
*/

class LNGerente:public ILNGerente{

    Banco_de_Dados *oraculo;
    Usuario *usuario;

public:

    Resultado incluir(Livro&, int pos);
    Resultado remover(int pos);
    void exibir_estante();
    ResultadoUsuario pesquisar(ApelidoTP1&);
    Resultado fazer_resenha(Usuario&);

    void set_BD( Banco_de_Dados *oraculo ) { this->oraculo = oraculo; };
    void set_gerente( ApelidoTP1 apelido );
};

#endif // LOGICADENEGOCIOS_H_INCLUDED
