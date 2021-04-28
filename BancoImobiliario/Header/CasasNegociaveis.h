#ifndef INF112_CASAS_NEGOCIAVEIS_H
#define INF112_CASAS_NEGOCIAVEIS_H

#include <iostream>
#include "./Header/Casa.h"

class CasasNegociaveis : public Casa
{
private:
	int _valor_hipoteca;
	int _valor_compra;
    int _proprietario;

public:
	//Construtor
	CasasNegociaveis(std::string nome, int posicao, int valor_hipoteca, int valor_compra, int proprietario);

	//Setters
    void set_proprietario(int proprietario);

	//Getters
	int get_valor_hipoteca();
	int get_valor_compra();
    int get_proprietario();

    //Funcoes
    void efetua_venda ();
    void efetua_hipoteca ();
    virtual void efetua_cobranca ();
	//Destrutor
	~CasasNegociaveis();
};

#endif