#include <iostream>
#include "Acao.h"

// Construtor
Acao::Acao(std::string nome, int posicao, std::string path, int valor_compra, double indiceDeMultiplicacao) :
	CasasNegociaveis(nome, posicao, path, valor_compra), _indiceDeMultiplicacao(indiceDeMultiplicacao) {}

void Acao::efetua_cobranca(Jogador * jogador, Jogador * proprietario, float i) {
	srand(time(NULL));
	int sorte = this->_indiceDeMultiplicacao * ((rand() % 12) + 1.0);
	if (jogador->get_quantidadeDinheiro() <= sorte) {
		proprietario->receber_dinheiro(jogador->get_quantidadeDinheiro());
		jogador->pagar(jogador->get_quantidadeDinheiro());
	}
	else {
		jogador->pagar(sorte);
		proprietario->receber_dinheiro(sorte);
	}
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