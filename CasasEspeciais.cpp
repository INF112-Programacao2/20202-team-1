#include <iostream>
#include "CasasEspeciais.h"
//Casas especiais: noticias, feriado, xadrez, "va para o xadrez", "Restituicao +2000", "Imposto -2000"
// Construtor
CasasEspeciais::CasasEspeciais(std::string nome, int posicao, std::string path, std::string tipo) : Casa(nome, posicao, path), _tipo(tipo) {}

// Setters
void CasasEspeciais::set_tipo(std::string tipo) {
	this->_tipo = tipo;
}


// Getters 
std::string CasasEspeciais::get_tipo() {
	return this->_tipo;
}

void CasasEspeciais::executa(Jogador jogador) {
	//Conferir número das casas
	if (jogador.get_posicao() == 14) {
		funcaoRestituicao(jogador);
	}
	else if (jogador.get_posicao() == 27) {
		funcaoVaParaOXadrez(jogador);
	}
	else if (jogador.get_posicao() == 21) {
		funcaoImposto(jogador);
	}
}

//Retorna o valor da casa do xadrez
void CasasEspeciais::funcaoVaParaOXadrez(Jogador jogador)
{
	jogador.set_posicao(9);
}

//Retorna 2000 para o dinheiro do jogador 
void CasasEspeciais::funcaoRestituicao(Jogador jogador)
{
	jogador.receber_dinheiro(2000);
}

//Retorna -2000 para o dinheiro do jogador 
void CasasEspeciais::funcaoImposto(Jogador jogador)
{
	jogador.pagar(2000);
}

CasasEspeciais::~CasasEspeciais() {};
