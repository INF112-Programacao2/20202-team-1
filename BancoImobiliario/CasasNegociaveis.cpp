#include <iostream>
#include "CasasNegociaveis.h"

// Construtor
CasasNegociaveis::CasasNegociaveis(std::string nome, int posicao, int valor_hipoteca, int valor_compra, int proprietario) : Casa(nome, posicao), _valor_hipoteca(valor_hipoteca), _valor_compra(valor_compra), _proprietario(proprietario) {}

// Setters
void CasasNegociaveis::set_proprietario(int proprietario) {
	this->_proprietario = proprietario;
}

// Getters 
int CasasNegociaveis::get_valor_hipoteca() {
	return this->_valor_hipoteca;
}

int CasasNegociaveis::get_valor_compra() {
	return this->_valor_compra;
}
int CasasNegociaveis::get_proprietario() {
	return this->_proprietario;
}

//Funcoes
void CasasNegociaveis::efetua_venda() {};
void CasasNegociaveis::efetua_hipoteca() {};
void CasasNegociaveis::efetua_cobranca() {}

//Destrutor
CasasNegociaveis::~CasasNegociaveis() {};