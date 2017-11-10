#include <iostream>

#include "Banco_de_dados.h"
#include "interfaces.h"
#include "logicadenegocios.h"
#include "controladoras.h"

#define START 0 //inicia o loop
#define CRIAR 1
#define LOGAR 2
#define TCHAU 3
#define SHAME 4 //uma gambiarra

using namespace std;

int main()
{
    /*
    * a variavel 'op' (OPÇÃO) inicia o loop do programa e controla seus estados.
    * a variavel 'limpa' auxilia na limpeza de buffers, para que uma entrada (de strings) não invada outra.
    */
    int op = START;
    std::string limpa;
    /*
    * ***************************************************************************************************
    */

    /*
    * declarações dos modulos da camada de apresentação, e dos modulos stubs que representam a camada de
    * serviços
    */
    Banco_de_Dados *ruvik = new Banco_de_dados_PedroH();

    ICria_Conta *cntrlCria_Conta = new Criar_Conta();
    ILNCriar_Conta *cntrlLNCriar_Conta = new LNCriar_Conta();
    cntrlLNCriar_Conta->set_BD( ruvik );

    IUAutenticacao *cntrIUAutenticacao = new CntrIUAutenticacao();
    ILNAutenticacao *cntrlLNAutenticacao = new LNAutenticacao();
    cntrlLNAutenticacao->set_BD( ruvik );

    IUGerente *cntrIUGerente = new CntrIUGerente();
    ILNGerente *cntrlLNGerente = new LNGerente();
    cntrlLNGerente->set_BD( ruvik );

    cntrlCria_Conta->setLNCriar_Conta(cntrlLNCriar_Conta);
    cntrIUAutenticacao->setCntrLNAutenticacao(cntrlLNAutenticacao);
    cntrIUGerente->setCntrLNGerente(cntrlLNGerente);
    /*
    * ***************************************************************************************************
    */

    /*
    * loop que representa o programa e todos os seus estados
    */
    while(op != TCHAU){
        while((op != CRIAR) && (op != LOGAR) && (op != TCHAU)){
                std::cout << "********* Bem Vindo *********" << endl;
                std::cout << "****** [1]criar conta" << endl;
                std::cout << "****** [2]logar" << endl;
                std::cout << "****** [3]sair" << endl;
                std::cout << endl << "****** > ";

                std::cin >> op;
                std::getline(cin, limpa);
        }

        switch(op){

            case 1:{
                if(cntrlCria_Conta->criar()){
                    std::cout << endl << "conta criada com sucesso!" << endl;
                }
                else
                    std::cout << endl << "deu ruim na criacao de conta" << endl;
                op = SHAME;
            }break;



            case 2:{

                ResultadoAutenticacao result;
                result = cntrIUAutenticacao->autenticar();

                if(result.getValor() == result.SUCESSO){
                    std::cout << endl << "conta autenticada com sucesso!" << endl;
                    cntrIUGerente->executar(result.getApelido());
                }else
                    std::cout << endl << "deu ruim na autenticacao" << endl;

                op = SHAME;
            }break;



            case 3:
                std::cout << "********* Tchau *********" << endl;
            break;

        }
    }


    return 0;
}
