#include <iostream>
#include "Acao.h"

// Construtor
Acao::Acao(std::string nome, int posicao, std::string path, int valor_hipoteca, int valor_compra, int proprietario, double indiceDeMultiplicacao) :
	CasasNegociaveis(nome, posicao, path, valor_hipoteca, valor_compra, proprietario), _indiceDeMultiplicacao(indiceDeMultiplicacao) {}

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