#ifndef INF112_CASAS_ESPECIAIS_H
#define INF112_CASAS_ESPECIAIS_H

#include <iostream>
#include "Casa.h"
#include "Jogador.h"

class CasasEspeciais : public Casa
{
public:
	//Construtores
	CasasEspeciais(std::string nome, int posicao, std::string path);

	//Funcoes
	virtual void executa(Jogador jogador);
	void funcaoVaParaOXadrez(Jogador jogador);
	void funcaoRestituicao(Jogador jogador);
	void funcaoImposto(Jogador jogador);

	//Destrutor
	~CasasEspeciais();
};

#endif