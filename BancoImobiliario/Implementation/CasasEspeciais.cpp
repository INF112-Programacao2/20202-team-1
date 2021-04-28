#include <iostream>
#include "./Header/CasasEspeciais.h"

// Construtor
CasasEspeciais::CasasEspeciais(std::string nome, int posicao, std::string tipo): Casa (nome, posicao), _tipo(tipo) {}

// Setters
void CasasEspeciais::set_tipo(std::string tipo) {
	this->_tipo = tipo;
}


// Getters 
std::string CasasEspeciais::get_tipo() {
	return this->_tipo;
}

void CasasEspeciais:: executa(){}

