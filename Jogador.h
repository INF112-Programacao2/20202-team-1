#ifndef INF112_JOGADOR_H
#define INF112_JOGADOR_H

#include <iostream>
#include "JogadorException.h"

class Jogador
{
private:
	int _id, _quantidadeDinheiro, _posicao;
	int _preso;
	std::string _nome, _path;

public:
	//Construtor
	Jogador(int id, int quantidadeDinheiro, std::string nome, int posicao, std::string path);

	//Setters
	void set_id(int id);
	void set_quantidadeDinheiro(int quantidadeDinheiro);
	void set_nome(int nome);
	void set_posicao(int posicao);
	void set_path(int path);
	void set_preso(int i);

	//Getters
	int get_id();
	int get_quantidadeDinheiro();
	std::string get_nome();
	int get_posicao();
	std::string get_path();
	int get_preso();

	//Outros metodos
	void receber_dinheiro(int quantidade);
	void pagar(int quantidade) throw(ExcecaoJogador);

	//Destrutor
	~Jogador();
};

#endif