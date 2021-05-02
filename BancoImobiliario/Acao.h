#ifndef INF112_ACAO_H
#define INF112_ACAO_H

#include <iostream>
#include "CasasNegociaveis.h"

class Acao : CasasNegociaveis
{
private:
	double _indiceDeMultiplicacao;

public:
	//Construtor
	Acao(std::string nome, int posicao, int valor_hipoteca, int valor_compra, int proprietario, double indiceDeMultiplicacao);

	//Setters
	void set_indiceDeMultiplicacao(double indiceDeMultiplicacao);

	//Getters
	double get_indiceDeMultiplicacao();

	//Destrutor
	~Acao();
};

#endif