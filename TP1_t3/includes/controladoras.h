#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"

/**
* Classe que rege a coleta de informações e a verificação de disponibilidade para se criar a conta
* com tais dados.
*/

class Criar_Conta:public ICria_Conta{

    /**
    * atributo que define a camada de serviço dessa classe.
    */

    ILNCriar_Conta *ctrlLNCriar_Conta;

public:

    /**
    * CRIAR recolhe e trata dados do usuario.
    * SETLNCRIARCONTA "seta" a lógica de negocios por trás dessa classe.
    */

    int criar();
    inline void setLNCriar_Conta( ILNCriar_Conta* ctrl) { this->ctrlLNCriar_Conta = ctrl; }

};

class CntrIUAutenticacao:public IUAutenticacao {

private:

    /**
    * Referência para servidor.
    */

    ILNAutenticacao *cntrLNAutenticacao;

public:

    /**
    * AUTENTICAR pede e trata dados do usuario.
    * SETCNTRLNAUTENTICACAO a lógica de negocios por trás dessa classe.
    */

    ResultadoAutenticacao autenticar();
    void setCntrLNAutenticacao(ILNAutenticacao*);
};
    /**
    * Método por meio do qual é estabelecido relacionamento com o servidor (classe que serve).
    */
void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}


class CntrIUGerente:public IUGerente {

private:

    /**
    * constantes que definem as ações que um usuario pode tomar.
    */

    const static int INCLUIR_LIVRO     = 1;
    const static int REMOVER_LIVRO     = 2;
    const static int EXIBIR_BIBLIOTECA = 3;
    const static int PESQUISAR_USUARIO = 4;
    const static int FAZER_RESENHA     = 5;
    const static int RETORNAR          = 6;

    /**
    * Referência para servidor.
    */

    ILNGerente *cntrLNGerente;


public:

    /**
    * Método previsto na interface por meio do qual é solicitada execução da controladora.
    */

    void executar(const ApelidoTP1&);

    /**
    * Método por meio do qual é estabelecido relacionamento com o servidor.
    */
    void setCntrLNGerente(ILNGerente *cntrLNGerente){
        this->cntrLNGerente = cntrLNGerente;
    }

};

#endif // CONTROLADORAS_H_INCLUDED
