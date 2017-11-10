#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"






/**
 * @file   Resenha.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  A resenha representa uma das 3 entidades do programa.
 * 	   Uma resenha contém um autor, um titulo, uma data (de publicacao) e obviamente um texto.
 * 	   para exibir as informacoes a respeito de uma resenha, existe o metodo status.
 */

class Resenha
{
    private:
        NomeTP1 autor;
        TituloTP1 titulo;
        DataTP1 data;
        TextoTP1 texto;

    public:
        /**
         * @brief Construtor da classe Livro, sem parametros
         */
        Resenha();
        /**
         * @brief Construtor da classe Usuario, que seta o titulo, autor, data, codigo e genero literario
         * @param au
         * @param t
         * @param d
         * @param m
         * @param a
         */
        Resenha(const char *au, const char *t, int d, int m, int a);
        void status();

        /**
         * @brief seta um autor
         * @param au
         */
        void setAutor(const char *au);
        /**
         * @brief seta um titulo
         * @param t
         */
        void setTitulo(const char *t);
        /**
         * @brief seta uma data
         * @param d
         * @param m
         * @param a
         */
        void setData(int d, int m, int a);
        /**
         * @brief seta um texto
         * @param c
         */
        void setTexto(const char *c);

};










/**
 * @file   Livro.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  O livro é uma das 3 entidades do programa.
 * 	   Um livro possui um titulo, um autor, uma data (de publicacao), um codico e um genero literario.
 * 	   Para exibir informacoes a respeito de um livro, utilizar o metodo status.
 */

class Livro
{
    private:
        TituloTP1 titulo;
        NomeTP1 autor;
        DataTP1 data;
        CodigoTP1 codigo;
        Genero_litTP1 genero_literario;

    public:
        /**
         * @brief Construtor da classe Livro, sem parametros
         */
        Livro();
        /**
         * @brief Construtor da classe Usuario, que seta o titulo, autor, data, codigo e genero literario
         * @param t
         * @param au
         * @param d
         * @param g
         */
        Livro(const char *t, const char *au, int d, int m, int a, const char *c, int g);
        void status();

        /**
         * @brief seta um valor que representa o titulo
         * @param c
         */
        void setTitulo(const char *c);
        /**
         * @brief seta um valor que representa o autor
         * @param c
         */
        char* getTitulo() {return titulo.getValor(); }
        /**
         * @brief seta um valor que representa o autor
         * @param c
         */
        void setAutor(const char *au);

        char* getAutor() {return autor.getValor(); }
        /**
         * @brief seta um valor que representa o data
         * @param d
         * @param m
         * @param a
         */
        void setData(int d, int m, int a);

        int getDia() { return data.getDia(); }
        int getMes() { return data.getMes(); }
        int getAno() { return data.getAno(); }
        /**
         * @brief seta um valor que representa o codigo
         * @param c
         */
        void setCodigo(const char *c);
        /**
         * @brief seta um valor que representa o genero literario
         * @param c
         */
        void setGenero_literario(int g);

        std::string getGenero_lit() { return genero_literario.getValor(); }
        /**
         * @brief Retorna uma string com o valor armazenado no objeto codigo
         */
        std::string getCodigo() { return codigo.getValor(); }

};












/**
 * @file   Usuario.h
 * @Author Gabriel / Pedro
 * @date   Setembro, 2017
 * @brief  Essa classe representa uma das 3 entidades principais do programa
 *	   um usuario possui um nome, um apelido, um telefone, uma senha e uma
 *	   estante" com capacidade para dez livros. Para exibir todas as informações
 *	   de um usuario, utilizar os metodos status e verEstante.
 */

class Usuario
{
    private:
        NomeTP1 nome;
        ApelidoTP1 apelido;
        TelefoneTP1 telefone;
        SenhaTP1 senha;
        Livro estante[10];

    public:
        /**
         * @brief Construtor da classe Usuario, sem parametros
         */
        Usuario();
        /**
         * @brief Construtor da classe Usuario, que seta o nome, apelido, telefone e senha, respectivamente
         * @param nome
         * @param apelido
         * @param telefone
         * @param senha
         */
        Usuario(const char *nome, const char *apelido, const char *telefone, const char *senha);

        /**
         * @brief mostra na tela os dados do usuario
         */
        void status();
        /**
         * @brief seta um nome
         * @param c
         */
        void setNome(const char *c);
        /**
         * @brief seta um apelido
         * @param c
         */
        void setApelido(const char *c);
        /**
         * @brief seta um telefone
         * @param c
         */
        void setTelefone(const char *c);
        /**
         * @brief seta uma senha
         * @param c
         */
        void setSenha(const char *c);

        void addLivro(int i, const char *t, const char *au, int d, int m, int a, const char *c, int g);
        void removeLivro(int i);
        void verEstante();

        /**
         * @brief Retorna um nome
         */
        char* getNome();
        /**
         * @brief Retorna um apelido
         */
        char* getApelido();
        /**
         * @brief Retorna um telefone
         */
        char* getTelefone();
        /**
         * @brief Retorna uma senha
         */
        char* getSenha();

};

#endif // ENTIDADES_H_INCLUDED
