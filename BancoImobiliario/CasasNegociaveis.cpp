#include <iostream>
#include "CasasNegociaveis.h"

// Construtor
CasasNegociaveis::CasasNegociaveis(std::string nome, int posicao, int valor_compra, int valor_aluguel, int proprietario) :
	Casa(nome, posicao), _valor_compra(valor_compra), _valor_aluguel(valor_aluguel), _proprietario(proprietario) {}

// Setters
void CasasNegociaveis::set_proprietario(int proprietario) {
	this->_proprietario = proprietario;
}

void CasasNegociaveis::set_valor_aluguel(int proprietario) {
	this->_proprietario = proprietario;
}

void CasasNegociaveis::set_valor_compra(int proprietario) {
	this->_proprietario = proprietario;
}

// Getters 
/*int CasasNegociaveis::get_valor_hipoteca() {
	return this->_valor_hipoteca;
}*/
int CasasNegociaveis::get_proprietario() {
	return this->_proprietario;
}

int CasasNegociaveis::get_valor_compra() {
	return this->_valor_compra;
}

int CasasNegociaveis::get_valor_aluguel() {
	return this->_valor_compra;
}

//Funcoes
void CasasNegociaveis::efetua_compra(Jogador jogador) {
	jogador.pagar(this->get_valor_compra());
};

/*void CasasNegociaveis::efetua_hipoteca() {

};*/

void CasasNegociaveis::efetua_cobranca(Jogador jogador, Jogador proprietario) {
	jogador.pagar(this->get_valor_aluguel());
	proprietario.receber_dinheiro(this->get_valor_aluguel());
};

//Destrutor
CasasNegociaveis::~CasasNegociaveis() {};