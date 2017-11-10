#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"

/**
* Classe que rege a coleta de informa��es e a verifica��o de disponibilidade para se criar a conta
* com tais dados.
*/

class Criar_Conta:public ICria_Conta{

    /**
    * atributo que define a camada de servi�o dessa classe.
    */

    ILNCriar_Conta *ctrlLNCriar_Conta;

public:

    /**
    * CRIAR recolhe e trata dados do usuario.
    * SETLNCRIARCONTA "seta" a l�gica de negocios por tr�s dessa classe.
    */

    int criar();
    inline void setLNCriar_Conta( ILNCriar_Conta* ctrl) { this->ctrlLNCriar_Conta = ctrl; }

};

class CntrIUAutenticacao:public IUAutenticacao {

private:

    /**
    * Refer�ncia para servidor.
    */

    ILNAutenticacao *cntrLNAutenticacao;

public:

    /**
    * AUTENTICAR pede e trata dados do usuario.
    * SETCNTRLNAUTENTICACAO a l�gica de negocios por tr�s dessa classe.
    */

    ResultadoAutenticacao autenticar();
    void setCntrLNAutenticacao(ILNAutenticacao*);
};
    /**
    * M�todo por meio do qual � estabelecido relacionamento com o servidor (classe que serve).
    */
void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}


class CntrIUGerente:public IUGerente {

private:

    /**
    * constantes que definem as a��es que um usuario pode tomar.
    */

    const static int INCLUIR_LIVRO     = 1;
    const static int REMOVER_LIVRO     = 2;
    const static int EXIBIR_BIBLIOTECA = 3;
    const static int PESQUISAR_USUARIO = 4;
    const static int FAZER_RESENHA     = 5;
    const static int RETORNAR          = 6;

    /**
    * Refer�ncia para servidor.
    */

    ILNGerente *cntrLNGerente;


public:

    /**
    * M�todo previsto na interface por meio do qual � solicitada execu��o da controladora.
    */

    void executar(const ApelidoTP1&);

    /**
    * M�todo por meio do qual � estabelecido relacionamento com o servidor.
    */
    void setCntrLNGerente(ILNGerente *cntrLNGerente){
        this->cntrLNGerente = cntrLNGerente;
    }

};

#endif // CONTROLADORAS_H_INCLUDED
