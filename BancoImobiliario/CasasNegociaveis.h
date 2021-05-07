#ifndef INF112_CASAS_NEGOCIAVEIS_H
#define INF112_CASAS_NEGOCIAVEIS_H

#include <iostream>
#include "Casa.h"
#include "Jogador.h"

class CasasNegociaveis : public Casa
{
private:
	//int _valor_hipoteca;
	int _valor_compra;
	int _valor_aluguel;
    int _proprietario;

public:
	//Construtor
	CasasNegociaveis(std::string nome, int posicao, int valor_compra, int valor_aluguel, int proprietario);

	//Setters
    void set_proprietario(int proprietario);
	void set_valor_aluguel(int valor);
	void set_valor_compra(int valor);

	//Getters
	//int get_valor_hipoteca();
	int get_valor_compra();
	int get_valor_aluguel();
    int get_proprietario();

    //Funcoes
	virtual void efetua_compra (Jogador jogador);
	//virtual void efetua_hipoteca ();
    virtual void efetua_cobranca (Jogador jogador, Jogador proprietario);
	//Destrutor
	~CasasNegociaveis();
};

#endif