#ifndef INF112_CASAS_ESPECIAIS_H
#define INF112_CASAS_ESPECIAIS_H

#include <iostream>
#include "Casa.h"

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
    virtual void executa();

	//Destrutor
	~CasasEspeciais();
};

#endif