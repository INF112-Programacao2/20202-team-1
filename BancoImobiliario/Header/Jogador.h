#ifndef INF112_JOGADOR_H
#define INF112_JOGADOR_H

#include <iostream>

class Jogador
{
private:
	int _id, _quantidadeDinheiro;
	std::string _nome;

public:
	//Construtor oii ana!!
	Jogador(int id, int quantidadeDinheiro, std::string nome);

	//Setters
	void set_id(int id);
	void set_quantidadeDinheiro(int quantidadeDinheiro);
	void set_nome(int nome);

	//Getters
	int get_id();
	int get_quantidadeDinheiro();
	std::string get_nome();

	//Outros metodos
	void receber_dinheiro(int quantidade);
	int pagar(int quantidade);

	//Destrutor
	~Jogador();
};

#endif