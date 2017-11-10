#ifndef BANCO_DE_DADOS_PEDROH_H
#define BANCO_DE_DADOS_PEDROH_H

#include <vector>
#include "entidades.h"
#include "resultado.h"
#include "interfaces.h"

class Banco_de_dados_PedroH:public Banco_de_Dados {
    private:
        /**
        * o "VETOR DE USUARIOS" é usado pelos modulos de criação autenticação e de gerenciamento de conta
        * a "ESTANTE VIRTUAL GLOBAL" é usada no modulo de "gerenciamento de conta" e na pesquisa de por livros
        */
        std::vector<Usuario> vetor_de_usuarios;
        std::vector<Livro> estante_virtual_global;

    public:

        /**
        * PROCURAR apenas verifica se o apelido ja foi registrado
        * PROCURAR E USAR busca o apelido e retorna sua posição
        * AUTENTICAR verifica se o apelido e a senha inseridos realmente pertencem a algum usuario
        * INCLUIR NA BIBLIOTECA GLOBAL acrescenta um novo livro a biblioteca caso não exista um com
        * codigo similar. caso constrario, nao faz nada..
        */
        int procurar( char* apelido );
        Usuario* procurar_e_usar( char* apelido );
        int autenticar( char* apelido, char* senha );
        Resultado incluir_na_biblioteca_global( Livro livro );
        void addUsuario( Usuario usuario ) { vetor_de_usuarios.push_back( usuario ); };
};


#endif // BANCO_DE_DADOS_PEDROH_H
