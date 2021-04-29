#include <iostream>
#include "Jogador.h"

// Construtor
Jogador::Jogador(int id, int quantidadeDinheiro, std::string nome) {
	_id = id;
	_quantidadeDinheiro = quantidadeDinheiro;
	_nome = nome;
}

// Setters
void Jogador::set_id(int id) {
	this->_id = id;
}

void Jogador::set_quantidadeDinheiro(int quantidadeDinheiro) {
	this->_quantidadeDinheiro = quantidadeDinheiro;
}

void Jogador::set_nome(int nome) {
	this->_nome = nome;
}

// Getters 
int Jogador::get_id() {
	return this->_id;
}

int Jogador::get_quantidadeDinheiro() {
	return this->_quantidadeDinheiro;
}

std::string Jogador::get_nome() {
	return this->_nome;
}

//Outros metodos
void Jogador::receber_dinheiro(int quantidade) {
	this->set_quantidadeDinheiro(this->get_quantidadeDinheiro() + quantidade);
}

int Jogador::pagar(int quantidade) {
	this->set_quantidadeDinheiro(this->get_quantidadeDinheiro() - quantidade);
}

// Destrutor
Jogador::~Jogador() {}