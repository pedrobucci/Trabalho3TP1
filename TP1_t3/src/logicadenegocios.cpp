#include "logicadenegocios.h"

void LNCriar_Conta::adicionar_no_BD( Usuario usuario ){

    oraculo->addUsuario( usuario );
}

int LNCriar_Conta::verificar_BD( char* apelido ){

    if(oraculo->procurar( apelido ))
        return COM_ERRO;
    else
        return SEM_ERRO;
}

Resultado LNAutenticacao::autenticar( ApelidoTP1& apelido, SenhaTP1& senha) {

// Apresentar dados recebidos.

    cout << endl << "Autenticacao:" << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor do apelido.

    if(oraculo->autenticar(apelido.getValor(), senha.getValor()))
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    else
        resultado.setValor(ResultadoAutenticacao::FALHA);

    return resultado;
}


void LNGerente::set_gerente( ApelidoTP1 apelido ){

    try
    {

        this->usuario = oraculo->procurar_e_usar( apelido.getValor() );
    }
    catch(const char* e)
    {
        throw e;
    }
}


Resultado LNGerente::incluir(Livro &livro, int pos){

    // Apresentar dados recebidos.
    int genero;

    Resultado resultado;
    //problemas com tipagem do genero literario... eazy peazy lemon squeezy
    if(livro.getGenero_lit() == "EPOPEIA"){
        genero = 1;
    }else
    if(livro.getGenero_lit() == "NOVELA"){
        genero = 2;
    }else
    if(livro.getGenero_lit() == "CONTO"){
        genero = 3;
    }else
    if(livro.getGenero_lit() == "ENSAIO"){
        genero = 4;
    }else
    if(livro.getGenero_lit() == "ROMANCE"){
        genero = 5;
    }else
        genero = 0;

    resultado.setValor(Resultado::SUCESSO);

    usuario->addLivro(pos, livro.getTitulo(), livro.getAutor(), livro.getDia(), livro.getMes(), livro.getAno(), livro.getCodigo().c_str(), genero);
    oraculo->incluir_na_biblioteca_global(livro);

    return resultado;
}

Resultado LNGerente::remover(int pos){

    Resultado resultado;

    resultado.setValor(Resultado::SUCESSO);

    // chamada da operacao

    usuario->removeLivro( pos );

    return resultado;
}

void LNGerente::exibir_estante() {

    usuario->verEstante();

}

ResultadoUsuario LNGerente::pesquisar(ApelidoTP1 &apelido) {

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

Resultado LNGerente::fazer_resenha(Usuario &usuario) {

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
