#include "Imovel.h"
#include <iostream>

//construtor
Imovel::Imovel(std::string nome, int posicao, std::string path, int valor_compra, int valor_aluguel) :
    CasasNegociaveis(nome, posicao, path, valor_compra), _valor_aluguel(valor_aluguel) {}

//Destrutor
Imovel::~Imovel() {}

//funcoes
void Imovel::cobrar() {}

void Imovel::efetua_cobranca(Jogador * jogador, Jogador * proprietario, float i) {
	if (jogador->get_quantidadeDinheiro() <= (this->_valor_aluguel * i)) {
		proprietario->receber_dinheiro(jogador->get_quantidadeDinheiro());
		jogador->pagar(jogador->get_quantidadeDinheiro());
	}
	else {
		jogador->pagar(this->_valor_aluguel * i);
		proprietario->receber_dinheiro(this->_valor_aluguel * i);
	}
}

// Setters
void Imovel::set_valor_aluguel(int valor_aluguel) {
	this->_valor_aluguel = valor_aluguel;
}

// Getters 
int Imovel::get_valor_aluguel() {
	return this->_valor_aluguel;
}