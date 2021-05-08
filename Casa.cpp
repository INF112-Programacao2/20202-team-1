#include <iostream>
#include "Casa.h"

// Construtor
Casa::Casa(std::string nome, int posicao, std::string path) {
	_nome = nome;
	_posicao = posicao;
	_path = path;
	_x = 0;
	_y = 0;
}

// Setters
void Casa::set_nome(std::string nome) {
	this->_nome = nome;
}

void Casa::set_posicao(int posicao) {
	this->_posicao = posicao;
}

void Casa::set_x(int x)
{
	this->_x = x;
}

void Casa::set_y(int y)
{
	this->_y = y;
}

void Casa::set_path(std::string path) {
	this->_path = path;
}

// Getters 
std::string Casa::get_nome() {
	return this->_nome;
}

int Casa::get_posicao() {
	return this->_posicao;
}

int Casa::get_x()
{
	return this->_x;
}

int Casa::get_y()
{
	return this->_y;
}

std::string Casa::get_path() {
	return this->_path;
}

// Destrutor
Casa::~Casa() {}