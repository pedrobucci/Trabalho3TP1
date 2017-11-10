#include "stubs.h"

// Definições de método da classe stub do controlador da lógica de negócio de autenticação.

Resultado StubLNAutenticacao::autenticar( ApelidoTP1& apelido, SenhaTP1& senha) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::autenticar" << endl ;

    cout << "Apelido = " << apelido.getValor() << endl ;
    cout << "Senha   = " << senha.getValor() << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matrícula.


    if(apelido.getValor() == TRIGGER_FALHA)
            resultado.setValor(ResultadoAutenticacao::FALHA);
    else
    if(apelido.getValor() == TRIGGER_ERRO_SISTEMA)
            throw "Erro estranho e não previsto";
    else
        resultado.setValor(ResultadoAutenticacao::SUCESSO);

    return resultado;
}

// Definições de método da classe stub do controlador da lógica de negócio de gerente.

Resultado StubLNGerente::incluir(Livro &livro){

    // Apresentar dados recebidos.

    cout << endl << "StubLNGerente::incluir" << endl ;

    Resultado resultado;

    resultado.setValor(Resultado::SUCESSO);

    // Diferentes comportamentos dependendo do valor da matrícula.

    if(livro.getTitulo() == TRIGGER_FALHA)
        resultado.setValor(ResultadoAutenticacao::FALHA);
    else
    if(livro.getTitulo() == TRIGGER_ERRO_SISTEMA)
        throw "Erro de sistema";
    else
        resultado.setValor(ResultadoAutenticacao::SUCESSO);


    return resultado;
}

Resultado StubLNGerente::remover(Livro& livro){

    // Apresentar dados recebidos.

    cout << endl << "StubLNGerente::remover" << endl ;

    Resultado resultado;

    resultado.setValor(Resultado::SUCESSO);

    // Diferentes comportamentos dependendo do valor da matrícula.

    if(livro.getTitulo() == TRIGGER_FALHA)
            resultado.setValor(ResultadoAutenticacao::FALHA);
    else
    if(livro.getTitulo() == TRIGGER_ERRO_SISTEMA)
            throw "Erro de sistema";
    else
            resultado.setValor(ResultadoAutenticacao::SUCESSO);

    return resultado;
}

ResultadoUsuario StubLNGerente::pesquisar(ApelidoTP1 &apelido) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNGerente::pesquisar" << endl ;

    ResultadoUsuario resultado;

    resultado.setValor(Resultado::SUCESSO);

    // A seguir devem ser implementados os diferentes comportamentos.

    // Sucesso.

    // Falha.

    // Erro de sistema.

    return resultado;
}

Resultado StubLNGerente::editar(Usuario &usuario) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNGerente::Fazer_Resenha" << endl ;

    Resultado resultado;

    resultado.setValor(Resultado::SUCESSO);

    // A seguir devem ser implementados os diferentes comportamentos.

    // Sucesso.

    // Falha.

    // Erro de sistema.

    return resultado;
}
