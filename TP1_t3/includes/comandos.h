#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

/**
* Classe que liga o gerente aos comandos.
*/

class ComandoIUGerente {

public:

    /**
    * M�todo por meio do qual � solicitada a execu��o do comando.
    */

    virtual void executar(ILNGerente*) = 0;

    /**
    * M�todo destrutor virtual.
    */

    virtual ~ComandoIUGerente(){}
};

/**
* Encapsulamento do comando de Inclus�o de livros.
*/

class ComandoIUGerenteIncluir:public ComandoIUGerente {

public:

    /**
    * M�todo por meio do qual � solicitada a execu��o do comando.
    */

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Remo��o de livros.
*/

class ComandoIUGerenteRemover:public ComandoIUGerente {

    /**
    * M�todo por meio do qual � solicitada a execu��o do comando.
    */

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Exibir Biblioteca.
*/

class ComandoIUGerenteExibir_Biblioteca:public ComandoIUGerente {

    /**
    * M�todo por meio do qual � solicitada a execu��o do comando.
    */

    void executar(ILNGerente*);
};


/**
* Encapsulamento do comando de Pesquisa de usuarios.
*/

class ComandoIUGerentePesquisar:public ComandoIUGerente {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Edi��o de livros.
*/

class ComandoIUGerenteFazer_Resenha:public ComandoIUGerente {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNGerente*);
};


#endif // COMANDOS_H_INCLUDED

