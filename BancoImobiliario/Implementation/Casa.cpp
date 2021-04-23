#include <iostream>
#include "./Header/Casa.h"

// Construtor
Casa::Casa(std::string nome, int posicao) {
	_nome = nome;
	_posicao = posicao;
}

// Setters
void Casa::set_nome(std::string nome) {
	this->_nome = nome;
}

void Casa::set_posicao(int posicao) {
	this->_posicao = posicao;
}

// Getters 
std::string Casa::get_nome() {
	return this->_nome;
}

int Casa::get_posicao() {
	return this->_posicao;
}

// Destrutor
Casa::~Casa(){}