#pragma once
#include "CasasNegociaveis.h"

class Imovel : public CasasNegociaveis
{
private:
    int _valor_aluguel;
public:
    Imovel(std::string nome, int posicao, std::string path, int valor_compra, int valor_aluguel);
    ~Imovel();
    //metodos de imovel
    void cobrar();

    virtual void efetua_cobranca(Jogador jogador, Jogador proprietario) override;

	//Setters
	void set_valor_aluguel(int valor);

	//Getters
	int get_valor_aluguel();
};