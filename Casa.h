#ifndef INF112_CASA_H
#define INF112_CASA_H

#include <iostream>

class Casa
{
private:
	std::string _nome;
	int _posicao, _x, _y;
	std::string _path;

public:
	//Construtor
	Casa(std::string nome, int posicao, std::string path);

	//Setters
	void set_posicao(int posicao);
	void set_x(int x);
	void set_y(int y);
	void set_nome(std::string nome);
	void set_path(std::string path);

	//Getters
	int get_posicao();
	int get_x();
	int get_y();
	std::string get_nome();
	std::string get_path();

	//Destrutor
	virtual ~Casa();
};

#endif