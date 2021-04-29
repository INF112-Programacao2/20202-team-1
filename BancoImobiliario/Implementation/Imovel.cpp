#include "./Header/Imovel.h"
#include <iostream>

//construtor
Imovel::Imovel(std::string nome, int posicao, int valor_hipoteca, int valor_compra, int proprietario) : CasasNegociaveis(nome,posicao,valor_hipoteca,valor_compra,proprietario){}
//Destrutor
Imovel::~Imovel(){}

//getters
double Imovel::get_valor_por_casa()
{
    return this->valor_por_casa;
}
int Imovel::get_aluguel()
{
    return this->aluguel;
}
int Imovel::get_valor_1_casa()
{
    return this->valor_1_casa;
}
int Imovel::get_valor_2_casas()
{
    return this->valor_2_casas;
}
int Imovel::get_valor_3_casas()
{
    return this->valor_3_casas;
}
int Imovel::get_valor_4_casas()
{
    return this->valor_4_casas;
}
int Imovel::get_valor_5_casas()
{
    return this->valor_5_casas;
}
int Imovel::get_valor_hotel()
{
    return this->valor_hotel;
}
int Imovel::get_num_casas()
{
    return this->num_casas;
}

//setters
void Imovel::set_valor_por_casa(double){

}
void Imovel::set_aluguel(int aluguel){
    this->aluguel = aluguel;
}
void Imovel::set_valor_1_casa(int valor_1_casa){
    this->valor_1_casa = valor_1_casa;
}
void Imovel::set_valor_2_casas(int valor_2_casas){
    this->valor_2_casas = valor_2_casas;
}
void Imovel::set_valor_3_casas(int valor_3_casas){
    this->valor_3_casas = valor_3_casas;
}
void Imovel::set_valor_4_casas(int valor_4_casas){
    this->valor_4_casas = valor_4_casas;
}
void Imovel::set_valor_5_casas(int valor_5_casas){
    this->valor_5_casas = valor_5_casas;
}
void Imovel::set_valor_hotel(int valor_hotel){
    this->valor_hotel = valor_hotel;
}
void Imovel::set_num_casas(int num_casas){
    this->num_casas = num_casas;
}

//funcoes
void Imovel::upgrade(){}
void Imovel::cobrar(){}