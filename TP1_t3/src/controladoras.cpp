#include <iostream>
#include <string>


#include "controladoras.h"
#include "dominios.h"
#include "comandos.h"
#include "entidades.h"


using namespace std;


int Criar_Conta::criar() {

    Usuario usuario;
    NomeTP1 nome;
    ApelidoTP1 apelido;
    TelefoneTP1 telefone;
    SenhaTP1 senha;

    std::string c;

    std::cout << "****** Criar Conta ***" << std::endl;
    while(true){
        std::cout << "***" << std::endl;
        try{
            std::cout << "*** Nome Usuario: ";
            getline(std::cin, c);
            usuario.setNome(c.c_str());

            std::cout << "*** Apelido: ";
            getline(std::cin, c);
            usuario.setApelido(c.c_str());

            std::cout << "*** Telefone: ";
            getline(std::cin, c);
            usuario.setTelefone(c.c_str());

            std::cout << "*** Senha: ";
            getline(std::cin, c);
            usuario.setSenha(c.c_str());

            break;
        }
        catch(const char* e){
            std::cerr << "ERRO: " << e << std::endl;
        }
    }

    if(ctrlLNCriar_Conta->verificar_BD( usuario.getApelido() ))
    {
        ctrlLNCriar_Conta->adicionar_no_BD( usuario );

        return 1;
    }
    else
    {
        return 0;
    }

}





ResultadoAutenticacao CntrIUAutenticacao::autenticar() {

    ResultadoAutenticacao resultadoAutenticacao;
    Resultado resultado;
//CUIDADO!! não mudar ordem das declarações de senha e apelido, bug estranho!!! s o b r e n a t u r a l
    SenhaTP1 senha;
    ApelidoTP1 apelido;
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! s o b r e n a t u r a l
    string entrada;

    // Solicitar matricula e senha.

    while(true) {

        try {
            cout << "Apelido : ";
            getline(cin, entrada);
            apelido.setValor(entrada.c_str());
            cout << "Senha   : ";
            getline(cin, entrada);
            senha.setValor(entrada.c_str());
            break;
        }
        catch (...) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    // Solicitar autenticação.

    resultado = cntrLNAutenticacao->autenticar(apelido, senha);

    // Informar resultado da autenticação.

    if(resultado.getValor() == ResultadoAutenticacao::FALHA){
        cout << endl << "Falha na autenticacao." << endl;
    }

    resultadoAutenticacao.setValor(resultado.getValor());
    resultadoAutenticacao.setApelido(apelido);

    return resultadoAutenticacao;
}



void CntrIUGerente::executar(const ApelidoTP1 &apelido) {

    ComandoIUGerente *comando;

    try{
        cntrLNGerente->set_gerente( apelido );
    }catch(const char* e){
        cerr << e;
    }

    int opcao;

    while(true){

        // Ilustra limpeza de tela.

        // system("CLS");

        // Apresentar as opções.

        cout << endl << "********* Pagina Usuario *********." << endl << endl;

        cout << "Incluir Livro    - " << INCLUIR_LIVRO << endl;
        cout << "Remover Livro    - " << REMOVER_LIVRO << endl;
        cout << "Exibir Biblioteca- " << EXIBIR_BIBLIOTECA << endl;
        cout << "Pesquisar Usuario- " << PESQUISAR_USUARIO << endl;
        cout << "Fazer Resenha    - " << FAZER_RESENHA << endl;
        cout << "Retornar         - " << RETORNAR << endl << endl;
        cout << "**************** > ";

        cin >> opcao;

        std::string limpa;
        getline(cin, limpa);

        switch(opcao){
            case INCLUIR_LIVRO:     comando = new ComandoIUGerenteIncluir();
                            comando->executar(cntrLNGerente);
                            delete comando;
                            break;
            case REMOVER_LIVRO:     comando = new ComandoIUGerenteRemover();
                            comando->executar(cntrLNGerente);
                            delete comando;
                            break;
            case EXIBIR_BIBLIOTECA: comando = new ComandoIUGerenteExibir_Biblioteca();
                            comando->executar(cntrLNGerente);
                            delete comando;
                            break;
            case PESQUISAR_USUARIO: comando = new ComandoIUGerentePesquisar();
                            comando->executar(cntrLNGerente);
                            delete comando;
                            break;
            case FAZER_RESENHA:     comando = new ComandoIUGerenteFazer_Resenha();
                            comando->executar(cntrLNGerente);
                            delete comando;
                            break;
        }

        if(opcao == RETORNAR){
            break;
        }

    }

    return;
}

