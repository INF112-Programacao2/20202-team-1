#ifndef INF112_CASA_H
#define INF112_CASA_H

#include <iostream>

class Casa
{
private:
	std::string _nome;
	int _posicao;

public:
	//Construtor
	Casa(std::string nome, int posicao);

	//Setters
	void set_posicao(int posicao);
	void set_nome(std::string nome);

	//Getters
	int get_posicao();
	std::string get_nome();

	//Destrutor
	~Casa();
};

#endif