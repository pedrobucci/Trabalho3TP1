#ifndef RESULTADO_H_INCLUDED
#define RESULTADO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <string>


using namespace std;


/**
* Classe pai de todas as classes relacionadas a resultados de validações de dados
*/

class Resultado {

protected:
    int valor;

public:

    const static int SUCESSO = 1;
    const static int FALHA   = 0;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

/**
* Classe responsavel por encapsular o resultado de validação de autenticações
*/


class ResultadoAutenticacao:public Resultado {

private:
    ApelidoTP1 apelido;

public:
    void setApelido(ApelidoTP1 apelido){      // passagem por referência.
        this->apelido = apelido;
    }

    ApelidoTP1 getApelido() const {
        return apelido;
    }
};

/**
* Classe responsavel por encapsular resultados de autenticações de usuarios
*/


class ResultadoUsuario:public Resultado {

private:
    Usuario usuario;

public:
    void setUsuario(Usuario usuario){      // passagem por referência.
        this->usuario = usuario;
    }

    Usuario getUsuario() const {
        return usuario;
    }
};


#endif // RESULTADO_H_INCLUDED
