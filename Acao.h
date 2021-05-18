#ifndef INF112_ACAO_H
#define INF112_ACAO_H

#include <iostream>
#include "CasasNegociaveis.h"

class Acao : public CasasNegociaveis
{
private:
	double _indiceDeMultiplicacao;

public:
	//Construtor
	Acao(std::string nome, int posicao, std::string path, int valor_compra, double indiceDeMultiplicacao);
	
    virtual void efetua_cobranca(Jogador * jogador, Jogador * proprietario, float i) override;

	//Setters
	void set_indiceDeMultiplicacao(double indiceDeMultiplicacao);

	//Getters
	double get_indiceDeMultiplicacao();

	//Destrutor
	~Acao();
};

#endif