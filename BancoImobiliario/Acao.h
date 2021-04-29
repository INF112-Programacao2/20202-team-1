#ifndef INF112_ACAO_H
#define INF112_ACAO_H

#include <iostream>

class Acao
{
private:
	double _indiceDeMultiplicacao;

public:
	//Construtor
	Acao(double indiceDeMultiplicacao);

	//Setters
	void set_indiceDeMultiplicacao(double indiceDeMultiplicacao);

	//Getters
	double get_indiceDeMultiplicacao();

	//Destrutor
	~Acao();
};

#endif