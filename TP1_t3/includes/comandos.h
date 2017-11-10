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
    * Método por meio do qual é solicitada a execução do comando.
    */

    virtual void executar(ILNGerente*) = 0;

    /**
    * Método destrutor virtual.
    */

    virtual ~ComandoIUGerente(){}
};

/**
* Encapsulamento do comando de Inclusão de livros.
*/

class ComandoIUGerenteIncluir:public ComandoIUGerente {

public:

    /**
    * Método por meio do qual é solicitada a execução do comando.
    */

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Remoção de livros.
*/

class ComandoIUGerenteRemover:public ComandoIUGerente {

    /**
    * Método por meio do qual é solicitada a execução do comando.
    */

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Exibir Biblioteca.
*/

class ComandoIUGerenteExibir_Biblioteca:public ComandoIUGerente {

    /**
    * Método por meio do qual é solicitada a execução do comando.
    */

    void executar(ILNGerente*);
};


/**
* Encapsulamento do comando de Pesquisa de usuarios.
*/

class ComandoIUGerentePesquisar:public ComandoIUGerente {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNGerente*);
};

/**
* Encapsulamento do comando de Edição de livros.
*/

class ComandoIUGerenteFazer_Resenha:public ComandoIUGerente {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNGerente*);
};


#endif // COMANDOS_H_INCLUDED

