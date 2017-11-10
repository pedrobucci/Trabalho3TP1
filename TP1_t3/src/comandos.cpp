#include<string>

#include "comandos.h"



using namespace std;



// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIUGerenteIncluir::executar(ILNGerente* cntrLNGerente){

    Livro *livro;
    std::string titulo, autor, codigo;
    int dia, mes, ano, genero_lit;
    // C�digo de intera��o com o usu�rio.

    while(true){
        try{
            cout << "titulo do exemplar a ser adicionado: ";
            std::getline(cin, titulo);

            cout << "autor do exemplar a ser adicionado: ";
            std::getline(cin, autor);

            cout << "dia de publicacao: ";
            cin >> dia;

            cout << "mes de publicacao: ";
            cin >> mes;

            cout << "ano de publicacao: ";
            cin >> ano;
            std::getline(cin, codigo);

            cout << "insira um codigo para esse exemplar: ";
            std::getline(cin, codigo);

            cout << "genero literario: " << endl;
            cout << "[0]nao sei [1]epopeia [2]novela [3]conto [4]ensaio [5]romance" << endl << ">";
            cin >> genero_lit;

            livro = new Livro(titulo.c_str(), autor.c_str(), dia, mes, ano, codigo.c_str(), genero_lit);

            break;
        }
        catch(...){
            cout << "Dado inserido com formato incorreto, tente de novo.. ." << endl;
            std::getline(cin, autor);
        }
    }
    while(true){
        try{
            int pos;
            cout << "posicao na estante:" << endl << "[numero de 1 a 10][inserir -1 para cancelar]" << endl << ">";
            cin >> pos;

            if(pos == -1)
            break;

            cntrLNGerente->incluir( *livro , pos-1 );

            break;
        }catch(const char *e)
        {
            std::cerr << e << endl;
        }
    }
}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIUGerenteRemover::executar(ILNGerente* cntrLNGerente){

    // C�digo de intera��o com o usu�rio.
    //*char limpa;
    int valor;


    while(true){
        try{
            cout << "posicao da estante a ser esvaziada: ";
            //getline(cin, limpa);
            cin >> valor;

            break;
        }
        catch(...){
            cout << "Titulo com formato incorreto" << endl;
        }
    }

    // Solicitar servi�o.
    cntrLNGerente->remover( valor-1 );
}

void ComandoIUGerenteExibir_Biblioteca::executar(ILNGerente* cntrLNGrente){

    cntrLNGrente->exibir_estante();

}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIUGerentePesquisar::executar(ILNGerente* cntrLNGerente){

    ResultadoUsuario resultado;

    ApelidoTP1 apelido;

    // A seguir incluir c�digo de intera��o com o usu�rio.

    // C�digo de intera��o com o usu�rio.

    // Solicitar servi�o.


    resultado = cntrLNGerente->pesquisar(apelido);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIUGerenteFazer_Resenha::executar(ILNGerente* cntrLNGerente){

    Resultado resultado;

    Usuario usuario;

    // A seguir incluir c�digo de intera��o com o usu�rio.

    // C�digo de intera��o com o usu�rio.

    // Solicitar servi�o.


    resultado.setValor(Resultado::SUCESSO);

    cntrLNGerente->fazer_resenha(usuario);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

}
