#include <iostream>
#include "./Header/Acao.h"

// Construtor
Acao::Acao(double indiceDeMultiplicacao) {
	_indiceDeMultiplicacao = indiceDeMultiplicacao;
}

// Setters
void Acao::set_indiceDeMultiplicacao(double indiceDeMultiplicacao) {
	this->_indiceDeMultiplicacao = indiceDeMultiplicacao;
}

// Getters 
double Acao::get_indiceDeMultiplicacao() {
	return this->_indiceDeMultiplicacao;
}

// Destrutor
Acao::~Acao() {}