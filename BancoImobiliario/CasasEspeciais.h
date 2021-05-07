#ifndef INF112_CASAS_ESPECIAIS_H
#define INF112_CASAS_ESPECIAIS_H

#include <iostream>
#include "Casa.h"
#include "Jogador.h"

class CasasEspeciais : public Casa
{
private:
	std::string _tipo;

public:
	//Construtor
	CasasEspeciais(std::string nome, int posicao, std::string tipo);

	//Setters
	void set_tipo(std::string tipo);

	//Getters
	std::string get_tipo();

    //Funcoes
    virtual void executa(Jogador jogador);
	void funcaoVaParaOXadrez(Jogador jogador);
	void funcaoRestituicao(Jogador jogador);
	void funcaoImposto(Jogador jogador);
	void funcaoNoticia(Jogador jogador);

	//Destrutor
	~CasasEspeciais();
};

#endif