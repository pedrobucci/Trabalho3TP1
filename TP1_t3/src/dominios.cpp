#include <iostream>

#include "dominios.h"


ApelidoTP1::ApelidoTP1()
{
    setValor("xxxxx");
}

int ApelidoTP1::validar(const char *c)
{
    int i;

    for(i = 0; ((i < 5) && (c[i] != '\0') && (((c[i] > 64) && (c[i] < 91)) || ((c[i] > 96)&&(c[i] < 123)))); i++);

    if(c[i] == '\0')
    {
        return 1;
    }
    else
        throw "APELIDO INVALIDO\n";
}

char* ApelidoTP1::getValor()
{
    return valor;
}

void ApelidoTP1::setValor(const char* c)
{
    int i;
    try
    {
        validar(c);
        for(i = 0; ((i < 5)&&(c[i] != '\0')); i++)
        {
            valor[i] = c[i];
        }
        valor[5] = '\0';
        valor[i] = '\0';
    }
    catch(const char* e)
    {
        throw e;
    }
}


/**************************************************************************************************************************/


CodigoTP1::CodigoTP1()
{
    setValor("00000");
}

int CodigoTP1::validar(const char *c)
{
    int i;

    for(i = 0; ((i < 5) && (c[i] != '\0') && (c[i] > 47) && (c[i] < 58)); i++);

    if((c[i] == '\0')&&(i == 5))
        return 1;
    else
        throw "CODIGO INVALIDO\n";
}



char* CodigoTP1::getValor()
{
    return valor;
}



void CodigoTP1::setValor(const char *c)
{
    int i;

    try
    {
        validar(c);

        for(i = 0; ((i < 5) && (c[i] != '\0')); i++)
        {
            valor[i] = c[i];
        }
        valor[5] = '\0';
        valor[i] = '\0';

    }
    catch(const char *e)
    {
        throw e;
    }
}


/**************************************************************************************************************************/


DataTP1::DataTP1()
{
    setDia(1);
    setMes(1);
    setAno(1);
}

DataTP1::DataTP1(int d, int m, int a)
{
    setDia(d);
    setMes(m);
    setAno(a);
}

void DataTP1::setValor(int d, int m, int a)
{
    try
    {
        setDia(d);
        setMes(m);
        setAno(a);
    }
    catch(const char *)
    {
        throw;
    }
}



void DataTP1::setDia(int d)
{
    try
    {
        if((d > 31) || (d < 1))
            throw "DATA INVALIDA\n";

        dia = d;
    }
    catch(const char *e)
    {
        throw e;
    }
}
void DataTP1::setMes(int m)
{
    try
    {
        if((m > 12) || (m < 1))
            throw "DATA INVALIDA\n";

        mes = m;
    }
    catch(const char *e)
    {
        std::cerr << ">>>>>>>>>>>>>>> ERRO:" << e << std::endl;
        throw;
    }
}
void DataTP1::setAno(int a)
{
    try
    {
        if((a > 99) || (a < 00))
            throw "DATA INVALIDA\n";

        ano = a;
    }
    catch(const char *e)
    {
        std::cerr << ">>>>>>>>>>>>>>> ERRO: " << e << std::endl;
        throw;
    }
}
int DataTP1::getDia()
{
    return dia;
}

int DataTP1::getMes()
{
    return mes;
}

int DataTP1::getAno()
{
    return ano;
}


/**************************************************************************************************************************/


Genero_litTP1::Genero_litTP1()
{
    //[0]xxxxxxxxxx     [1]EPOPEIA    [2]NOVELA    [3]CONTO    [4]ENSAIO     [5]ROMANCE
    setValor(0);
}

int Genero_litTP1::validar(int opt)
{
    if((opt > -1) && (opt < 6))
        return 1;
    else
        throw "GENERO LITERARIO INVALIDO\n";
}


std::string Genero_litTP1::getValor()
{
    return valor;
}


void Genero_litTP1::setValor(int opc)
{
    try
    {
        validar(opc);

        switch(opc)
        {
            case 0:
                valor = "xxxxxxxxxx";
            break;

            case 1:
                valor = "EPOPEIA";
            break;


            case 2:
                valor = "NOVELA";
            break;


            case 3:
                valor = "CONTO";
            break;


            case 4:
                valor = "ENSAIO";
            break;


            case 5:
                valor = "ROMANCE";
            break;
        }
    }
    catch(const char *e)
    {
        throw e;
    }
}


/**************************************************************************************************************************/


NomeTP1::NomeTP1()
{
    setValor("xxxxxxxxxxxxxxx");
}

int NomeTP1::validar(const char *c)
{
    int i;

    for(i = 0; (
                (i < 15)&&(c[i] != '\0') &&
                ((c[i] == 32) || (c[i] == 46) || ((c[i]>64)&&(c[i]<91)) || ((c[i]>96)&&(c[i]<123)) )
                                                                                    ); i++);
    if(c[i] == '\0')
        return 1;
    else
        throw "VALOR NOME INVALIDO\n";

}

char* NomeTP1::getValor()
{
    return valor;

}

void NomeTP1::setValor(const char *c)
{
    int i;
    try
    {
        validar(c);
        for(i = 0; ((i < 15)&&(c[i] != '\0')); i++)
        {
            valor[i] = c[i];
        }
        valor[15] = '\0';
        valor[i] = '\0';
    }
    catch(const char* e)
    {
        throw e;
    }

}


/**************************************************************************************************************************/


SenhaTP1::SenhaTP1()
{
    setValor("abcd");
}

int SenhaTP1::validar(const char *c)
{
    int i, j;

    for(i = 0; ((i < 4) && (c[i] != '\0') && (((c[i] > 64) && (c[i] < 91)) || ((c[i] > 96)&&(c[i] < 123)))); i++)
    {
        for(j = 0; j < i; j++)
        {
            if(c[j] == c[i])
                i += 5;
        }
    }
    if((c[i] == '\0') && (i < 5))
        return 1;
    else
        throw "FORMATO DE SENHA INVALIDO\n";
}

char* SenhaTP1::getValor()
{
    return valor;
}

void SenhaTP1::setValor(const char *c)
{
    int i;

    try
    {
        validar(c);

        for(i = 0; ((i < 4)&&(c[i] != '\0')); i++)
        {
            valor[i] = c[i];
        }
        valor[5] = '\0';
        valor[i] = '\0';
    }
    catch(const char *e)
    {
        throw e;
    }
}


/**************************************************************************************************************************/


TelefoneTP1::TelefoneTP1()
{
    setValor("00000000000");
}


int TelefoneTP1::validar(const char* c)
{
    int i;

    for(i = 0; (i < 11) && (c[i] != '\0') && (c[i] > 47) && (c[i] < 58); i++);

    if((i == 11)&&(c[i] == '\0'))
        return 1;
    else
        throw "NUMERO DE TELEFONE INVALIDO\n";
}

char* TelefoneTP1::getValor()
{
    return valor;
}

void TelefoneTP1::setValor(const char* c)
{
    int i;
    try
    {
        validar(c);

        for(i = 0; (i < 11)&&(c[i] != '\0'); i++)
        {
            valor[i] = c[i];
        }
        valor[11] = '\0';
        valor[i] = '\0';
    }
    catch(const char* e)
    {
        throw e;
    }
}


/**************************************************************************************************************************/


TextoTP1::TextoTP1()
{
    setValor("xxxxxx xxxxxx xxx xxxxxx xxxxxx");
}

int TextoTP1::validar(const char *c)
{
    int i;

    for(i = 0; ((i < 40)&&(c[i] != '\0')); i++);
    if((i == 0)||(c[i] != '\0'))
        throw "TEXTO INVALIDO\n";
    return 0;
}

void TextoTP1::setValor(const char *c)
{
    int i;
    try
    {
    validar(c);

    for(i = 0; ((i < 40)&&(c[i] != '\0')); i++)
    {
        valor[i] = c[i];
    }
    valor[40] = '\0';
    valor[i] = '\0';
    }
    catch(const char *e)
    {
        throw e;
    }
}


char* TextoTP1::getValor()
{
    return valor;
}

/**************************************************************************************************************************/


TituloTP1::TituloTP1()
{
    setValor("xxxxxxxxxxxxxxxxxxxx");
}

int TituloTP1::validar(const char *c)
{
    int i;

    for(i = 0; ((i < 20) && (c[i] != '\0') && !((c[i] == ' ')&&(c[i-1] == ' '))); i++);

    if(c[i] == '\0')
        return 1;
    else
        throw "TITULO INVALIDO\n";
}


char* TituloTP1::getValor()
{
    return valor;
}

void TituloTP1::setValor(const char *c)
{
    int i;

    try
    {
        validar(c);

        for(i = 0; ((i < 20) && (c[i] != '\0')); i++)
        {
            valor[i] = c[i];
        }
        valor[20] = '\0';
        valor[i] = '\0';

    }
    catch(const char *e)
    {
        throw e;
    }
}

