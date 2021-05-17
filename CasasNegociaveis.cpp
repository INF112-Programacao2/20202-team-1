#include <iostream>
#include "CasasNegociaveis.h"

// Construtor
CasasNegociaveis::CasasNegociaveis(std::string nome, int posicao, std::string path, int valor_compra) :
	Casa(nome, posicao, path), _valor_compra(valor_compra), _proprietario(-1) {}

// Setters
void CasasNegociaveis::set_proprietario(int proprietario) {
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

//Funcoes
void CasasNegociaveis::efetua_compra(Jogador * jogador) {
	jogador->pagar(this->get_valor_compra());
};

/*void CasasNegociaveis::efetua_hipoteca() {

};*/

//Destrutor
CasasNegociaveis::~CasasNegociaveis() {};