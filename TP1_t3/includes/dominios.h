#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

/**
 * @file   ApelidoTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Aceita no maximo 5 caracteres sendo estes letras de a-z ou A-Z.
 */

class ApelidoTP1
{
    private:
        char valor[6];
        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o Nome a ser validado no metodo
         * @param c Apelido
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe ApelidoTP1, que da um set em um valor valido(default)
         */
        ApelidoTP1();

        /**
         * @brief Retorna um valor, no caso o Apelido
         */
         //tirei ponteiro
        char* getValor();

        /**
         * @brief seta um apelido
         * @param c
         */
        void setValor(const char *c);

};






/**
 * @file   CodigoTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Aceita exatos 5 caracteres sendo estes algarismos de 0-9.
 */

class CodigoTP1
{
    private:
        char valor[6];
        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o Codigo a ser validado no metodo
         * @param c
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe CodigoTP1, que da um set em um valor valido(default)
         */
        CodigoTP1();
        /**
         * @brief Retorna um valor, no caso o codigo
         */
        char* getValor();
        /**
         * @brief seta um codigo
         * @param c
         */
        void setValor(const char* c);

};





#include <string>

/**
 * @file   Genero_litTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  O genero literario é visto pelo programador como um numero de 0-5, sendo 0 um numero reservado.
 * 	   Cada numero esta relacionado a um genero, e são eles:
 *	   [0]********** [1]EPOPEIA [2]NOVELA [3]CONTO [4]ENSAIO [5]ROMANCE
 */


class Genero_litTP1
{
    private:
        std::string valor;
        /**
         * Metodo validar, recebe como parametro um inteiro, que representa o genero literario, a ser validado
         * @param opt
         */
        int validar(int opt);

    public:
    	/**
         * @brief Construtor da classe Genero_litTP1, que da um set em um valor valido(default)
         */
        Genero_litTP1();
        /**
         * @brief Retorna um valor, no caso o genero literario
         */
        std::string getValor();
        /**
         * @brief seta um valor que representa o genero literario
         * @param opt
         */
        void setValor(int opt);
};






/**
 * @file   DataTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Uma data é formada por:
 *	   uma variavel dia que deve ser um valor entre 1 e 31,
 *	   uma variavel mes que deve ser um valor entre 1 e 12,
 *	   uma variavel ano que deve ser um valor entre 0 a 99.
 *	   se ao menos um desses valores for invalido então a data tambem sera invalida.
 *
 */

class DataTP1
{
    private:
        int dia;
        int mes;
        int ano;

        /**
         * @brief seta um dia
         * @param d
         */
        void setDia(int d);
        /**
         * @brief seta um mes
         * @param m
         */
        void setMes(int m);
        /**
         * @brief seta um ano
         * @param c
         */
        void setAno(int a);

    public:
        /**
         * @brief Construtor da classe DataTP1, para quando nao for passado nenhum parametro, setando tudo com 1
         */
        DataTP1();

        /**
         * @brief Construtor da classe DataTP1, que seta, dia, mes e ano com os parametros passados respectivamente
         * @param d - dia
         * @param m - mes
         * @param a - ano
         */
        DataTP1(int d, int m, int a);

        /**
         * @brief chama os metodos de set, do dia, mes e ano respectivamente
         * @param d - dia
         * @param m - mes
         * @param a - ano
         */
        void setValor(int d, int m, int a);

        /**
         * @brief Retorna um inteiro, no caso o Dia
         */
        int getDia();
        /**
         * @brief Retorna um inteiro, no caso o Mes
         */
        int getMes();
        /**
         * @brief Retorna um inteiro, no caso o Ano
         */
        int getAno();

};






/**
 * @file   NomeTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Aceita apenas letras de a-z ou A-z, espaços em branco(' '), e pontos ('.').
 * 	   Não pode ultrapassar 15 caracteres.
 */

class NomeTP1
{
    private:
    	/**
    	 * @param valor vetor como tamanho maximo valido para um nome
    	 */
        char valor[16];
        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o Nome a ser validado no metodo
         * @param c
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe NomeTP1, que da um set em um valor valido(default)
         */
        NomeTP1();

        /**
         * @brief Retorna um valor, no caso o Nome
         */
        char* getValor();

        /**
         * @brief seta um nome, apos ter sido validado, e passa para o @param char
         * @param c
         */
        void setValor(const char *c);

};








/**
 * @file   SenhaTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Aceita no máximo 4 caracteres sem repetições. Devem ser letras de a-z ou A-Z.
 */


class SenhaTP1
{
    private:
        char valor[5];

        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o Senha a ser validado no metodo
         * @param c
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe SenhaTP1, que da um set em um valor valido(default)
         */
        SenhaTP1();

        /**
         * @brief Retorna um valor, no caso o Senha
         */
        char* getValor();

        /**
         * @brief seta uma senha
         * @param c
         */
        void setValor(const char *c);

};





/**
 * @file   TelefoneTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Deve conter exatamente 11 caracteres. Esses caracteres devem ser números de 0-9.
 */

class TelefoneTP1
{
    private:
        char valor[12];

        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o Telefone a ser validado no metodo
         * @param c
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe TelefoneTP1, que da um set em um valor valido(default)
         */
        TelefoneTP1();

        /**
         * @brief Retorna um valor, no caso o Telefone
         */
        char* getValor();

        /**
         * @brief seta um telefone
         * @param c
         */
        void setValor(const char *c);

    protected:

};







/**
 * @file   TextoTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Um titulo pode conter qualquer caractere contanto que a string recebida não ultrapasse o tamanho 40.
 */


class TextoTP1
{
    private:
        char valor[41];

    public:
        /**
         * @brief Construtor da classe TextoTP1, que da um set em um valor valido(default)
         */
        TextoTP1();
        /**
        * @brief valida um texto
        * @param c
        */
        int validar(const char *c);
        /**
         * @brief seta um texto
         * @param c
         */
        void setValor(const char *c);
        /**
         * @brief Retorna um valor, no caso o texto
         */
        char* getValor();

};





/**
 * @file   TituloTP1.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Aceita qualquer caractere contanto que não existam 2 'espaços' seguidos. Também não pode conter mais de 20 caracteres.
 */


class TituloTP1
{
    private:
        char valor[21];
        /**
         * Metodo validar, recebe como parametro um ponteiro c, que é o titulo a ser validado no metodo
         * @param c
         */
        int validar(const char *c);

    public:
    	/**
         * @brief Construtor da classe TituloTP1, que da um set em um valor valido(default)
         */
        TituloTP1();

        /**
         * @brief Retorna um valor, no caso o Titulo
         */
        char* getValor();
        /**
         * @brief seta um titulo
         * @param c
         */
        void setValor(const char *c);
};









#endif // DOMINIOS_H_INCLUDED
