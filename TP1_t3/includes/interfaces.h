#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "resultado.h"
#include "dominios.h"
#include "entidades.h"



/**
* Classe de interface que padroniza as a��es de um banco de dados.
*/

class Banco_de_Dados
{

 public:

/**
* PROCURAR apenas verifica se o apelido ja foi registrado
* PROCURAR E USAR busca o apelido e retorna sua posi��o
* AUTENTICAR verifica se o apelido e a senha inseridos realmente pertencem a algum usuario
* INCLUIR NA BIBLIOTECA GLOBAL acrescenta um novo livro a biblioteca caso n�o exista um com
* codigo similar. caso constrario, nao faz nada..
*/
    virtual int procurar( char* apelido ) = 0;
    virtual Usuario* procurar_e_usar( char* apelido ) = 0;
    virtual int autenticar( char* apelido, char* senha ) = 0;
    virtual Resultado incluir_na_biblioteca_global( Livro livro ) = 0;

    virtual void addUsuario( Usuario usuario ) = 0;

    virtual ~Banco_de_Dados() {};
};



/**
* Classe de interface para classes de servi�o de cria��o de conta
*/

class ILNCriar_Conta
{
    public:
        ILNCriar_Conta() {}

        virtual void adicionar_no_BD( Usuario usuario ) = 0;
        virtual int verificar_BD( char* apelido ) = 0;
        virtual void set_BD( Banco_de_Dados* ) = 0;

        /**
        * M�todo destrutor virtual.
        */

        virtual ~ILNCriar_Conta() {};
};

/**
* Classe de interface para classes de servi�o de autentica��o
*/


class ILNAutenticacao {
public:

    /**
    * M�todo por meio do qual � solicitado o servi�o.
    */

    virtual Resultado autenticar(ApelidoTP1& apelido, SenhaTP1& senha) = 0;
    virtual void set_BD( Banco_de_Dados *oraculo ) = 0;

    /**
    * M�todo destrutor virtual.
    */
    virtual ~ILNAutenticacao(){}
};

/**
* Classe de interface que padroniza as a��es de um gerente(o Usuario nesse caso).
*/

class ILNGerente {

public:

    /**
    * M�todos por meio dos quais s�o solicitados os servi�os.
    */

    virtual Resultado incluir(Livro&, int pos) = 0;
    virtual Resultado remover(int pos) = 0;
    virtual void exibir_estante() = 0;
    virtual ResultadoUsuario pesquisar(ApelidoTP1&) = 0;
    virtual Resultado fazer_resenha(Usuario&) = 0;

    virtual void set_BD(Banco_de_Dados *) = 0;
    virtual void set_gerente( ApelidoTP1 apelido) = 0;

    /**
    * M�todo destrutor virtual.
    */

    virtual ~ILNGerente(){}
};





















class ICria_Conta
{
    public:

        virtual int criar() = 0;
        virtual void setLNCriar_Conta( ILNCriar_Conta* ) = 0;

        virtual ~ICria_Conta() {}
};

class IUAutenticacao {
public:

    /**
    * AUTENTICAR � o m�todo por meio do qual � solicitado o servi�o.
    * SETCNTRLNAUTENTICACAO estabelece a liga��o com a controladora na camada de servi�o.
    */

    virtual ResultadoAutenticacao autenticar() = 0;
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;

    /**
    * M�todo destrutor virtual.
    */
    virtual ~IUAutenticacao(){}
};

class IUGerente {
public:

    /**
    * M�todo por meio do qual � solicitado o servi�o.
    */

    virtual void executar(const ApelidoTP1&) = 0;

    /**
    * M�todo por meio do qual � estabelecida liga��o (link) com a controladora de neg�cio.
    */

    virtual void setCntrLNGerente(ILNGerente *) = 0;

    /**
    * M�todo destrutor virtual.
    */
    virtual ~IUGerente(){}
};
#endif // INTERFACES_H_INCLUDED
