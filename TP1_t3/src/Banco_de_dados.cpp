#include <iostream>
#include "Banco_de_dados.h"


using namespace std;


int Banco_de_dados_PedroH::procurar( char* apelido )
{
    int encontrou = 0;
    int i = 0;
    string a = apelido;
    string a2;

    while(i < static_cast<int>(vetor_de_usuarios.size())){
        a2 = vetor_de_usuarios.at(i).getApelido();

        if(a == a2)
            encontrou = 1;

        i+=1;
    }

    return encontrou;
}
Usuario* Banco_de_dados_PedroH::procurar_e_usar( char* apelido )
{

    int i = 0;
    string a = apelido;
    string a2;

    while(i < static_cast<int>(vetor_de_usuarios.size())){
        a2 = vetor_de_usuarios.at(i).getApelido();

        if(a == a2)
            return &vetor_de_usuarios.at(i);

        i+=1;
    }

    throw "usuario não existe";

}



int Banco_de_dados_PedroH::autenticar(char* apelido, char* senha)
{
    int encontrou = 0;
    int i = 0;
    string a = apelido;
    string s = senha;
    string a2;
    string s2;

    while(i < static_cast<int>(vetor_de_usuarios.size())){
        a2 = vetor_de_usuarios.at(i).getApelido();
        s2 = vetor_de_usuarios.at(i).getSenha();

        if((a == a2) && (s == s2))
            encontrou = 1;

            i+=1;
    }

    return encontrou;
}

Resultado Banco_de_dados_PedroH::incluir_na_biblioteca_global( Livro livro ) {
    Resultado resultado;
    resultado.setValor(resultado.SUCESSO);
    int i;

    //pesquisa se ja existe o livro na biblioteca
    i = 0;
    while(i < static_cast<int>( estante_virtual_global.size() )){
        std::cout << "ooooooooooooooo\n";
        if( estante_virtual_global[i].getCodigo() == livro.getCodigo() ){
            resultado.setValor(resultado.FALHA);
            return resultado;
        }
        i+=1;
    }

    estante_virtual_global.push_back(livro);

    return resultado;
}
