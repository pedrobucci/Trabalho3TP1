#include "iostream"

#include "entidades.h"


using namespace std;


Resenha::Resenha(const char *au, const char *t, int d, int m, int a)
{
    try
    {
        setAutor(au);
        setTitulo(t);
        setData(d, m, a);
    }
    catch(const char* e)
    {
        setTitulo("xxxxxxxxxxxxxxxxxxxx");
        setAutor("xxxxxxxxxxxxxxx");
        setData(1, 1, 1);
    }
}


void Resenha::status()
{
    cout << "****** STATUS RESENHA" << endl;
    cout << "****** titulo: " << titulo.getValor() << endl;
    cout << "****** autor: " << autor.getValor() << endl;
    cout << "****** data: " << data.getDia() << "/ " << data.getMes() << "/ " << data.getAno() << endl << endl;
    cout << "****** texto:\n" << texto.getValor() << endl;
}


void Resenha::setAutor(const char *au)
{
    autor.setValor(au);
}

void Resenha::setTitulo(const char *t)
{
    titulo.setValor(t);
}

void Resenha::setData(int d, int m, int a)
{
    data.setValor(d, m, a);
}

void Resenha::setTexto(const char *te)
{
    texto.setValor(te);
}


























Livro::Livro()
{

}

Livro::Livro(const char *t, const char *au, int d, int m, int a, const char *c, int g)
{
    try
    {
        setTitulo(t);
        setAutor(au);
        setData(d, m, a);
        setCodigo(c);
        setGenero_literario(g);
    }
    catch(const char* e)
    {
        setTitulo("xxxxxxxxxxxxxxxxxxxx");
        setAutor("xxxxxxxxxxxxxxx");
        setData(1, 1, 1);
        setCodigo("00000");
        setGenero_literario(0);
        throw;
    }
}


void Livro::status()
{
    cout << "****** STATUS DO LIVRO:" << endl;
    cout << "****** tilulo: " << titulo.getValor() << endl;
    cout << "****** autor: " << autor.getValor() << endl;
    cout << "****** data: " << data.getDia() << "/ " << data.getMes() << "/ " << data.getAno() << endl;
    cout << "****** codigo: " << codigo.getValor() << endl;
    cout << "****** genero literario: " << genero_literario.getValor() << endl;
}


void Livro::setTitulo(const char *c)
{
    titulo.setValor(c);
}

void Livro::setAutor(const char *au)
{
    autor.setValor(au);
}

void Livro::setData(int d, int m, int a)
{
    data.setValor(d, m, a);
}

void Livro::setCodigo(const char *c)
{
    codigo.setValor(c);
}

void Livro::setGenero_literario(int g)
{
    genero_literario.setValor(g);
}




















Usuario::Usuario()
{

}

Usuario::Usuario(const char *nome, const char *apelido, const char *telefone, const char *senha)
{
    try
    {
        this->nome.setValor(nome);
        this->apelido.setValor(apelido);
        this->telefone.setValor(telefone);
        this->senha.setValor(senha);
    }
    catch(const char* e)
    {
        this->nome.setValor("xxxxxxxxxxxxxxx");
        this->apelido.setValor("xxxxx");
        this->telefone.setValor("00000000000");
        this->senha.setValor("abcd");
    }
}

void Usuario::status()
{
    cout << "****** STATUS DO USUARIO:" << endl;
    cout << "****** nome    : " << nome.getValor() << endl;
    cout << "****** apelido : " << apelido.getValor() << endl;
    cout << "****** telefone: " << telefone.getValor() << endl;
    cout << "****** senha   : " << senha.getValor() << endl;
}

void Usuario::setNome(const char *c)
{
    nome.setValor(c);
}

void Usuario::setApelido(const char *c)
{
    apelido.setValor(c);
}

void Usuario::setTelefone(const char *c)
{
    telefone.setValor(c);
}

void Usuario::setSenha(const char *c)
{
    senha.setValor(c);
}




char* Usuario::getNome()
{
    return nome.getValor();
}

char* Usuario::getApelido()
{
    return apelido.getValor();
}

char* Usuario::getTelefone()
{
    return telefone.getValor();
}

char* Usuario::getSenha()
{
    return senha.getValor();
}

void Usuario::addLivro(int i, const char *t, const char *au, int d, int m, int a, const char *c, int g)
{
    int j;
    std::string autor = estante[i].getAutor();

    if((i > 9)||(i < 0))
        throw "POSICAO DA ESTANTE INVALIDA\n";
    if((estante[i].getCodigo() != "00000") && (autor != "xxxxxxxxxxxxxxx"))
        throw "POSICAO OCUPADA NA ESTANTE";
    for(j = 0; j < 10; j++)
    {
        if(estante[j].getCodigo() == c)
                throw "EXEMPLAR JA FOI ADICIONADO\n";
    }

    estante[i].setTitulo(t);
    estante[i].setAutor(au);
    estante[i].setData(d, m, a);
    estante[i].setCodigo(c);
    estante[i].setGenero_literario(g);
}

void Usuario::removeLivro(int i)
{
    try
    {
        if((i > 9)||(i < 0))
            throw "POSICAO DA ESTANTE INVALIDA\n";

        estante[i].setTitulo("xxxxxxxxxxxxxxxxxxxx");
        estante[i].setAutor("xxxxxxxxxxxxxxx");
        estante[i].setData(1, 1, 1);
        estante[i].setCodigo("00000");
        estante[i].setGenero_literario(0);
    }
    catch(const char *e)
    {
        std::cerr << ">>>>>>>>>>>>>>> ERRO: " << e << endl;
    }
}

void Usuario::verEstante()
{
    int i;

    for(i = 0; i < 10; i++)
    {
        std::cout << "\n\n";
        estante[i].status();
        std::cout << "\n\n";
    }
}
