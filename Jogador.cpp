#include <iostream>
#include "Jogador.h"

// Construtor
Jogador::Jogador(int id, int quantidadeDinheiro, std::string nome, int posicao, std::string path) {
	_id = id;
	_quantidadeDinheiro = quantidadeDinheiro;
	_nome = nome;
	_posicao = posicao;
	_path = path;
	_preso = 0;
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

void Jogador::set_posicao(int posicao)
{
	this->_posicao = posicao;
}

void Jogador::set_path(int path)
{
	this->_path = path;
}

void Jogador::set_preso(int i) {
	this->_preso = i;
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

int Jogador::get_posicao()
{
	return _posicao;
}

std::string Jogador::get_path() {
	return this->_path;
}

int Jogador::get_preso() {
	return this->_preso;
}

//Outros metodos
void Jogador::receber_dinheiro(int quantidade) {
	this->set_quantidadeDinheiro(this->get_quantidadeDinheiro() + quantidade);
}

void Jogador::pagar(int quantidade) throw(ExcecaoJogador) {
	this->set_quantidadeDinheiro(this->get_quantidadeDinheiro() - quantidade);
	if (this->get_quantidadeDinheiro() <= 0)
	{
		this->set_quantidadeDinheiro(0);
		throw ExcecaoJogador();
	}
}

// Destrutor
Jogador::~Jogador() {}