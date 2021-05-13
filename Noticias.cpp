#include "Noticias.h"
#include <cstdlib>
#include <time.h>

//Construtor
Noticias::Noticias(std::string nome, int posicao, std::string path) : CasasEspeciais(nome, posicao, path), _valor(0), _texto("") {}
//Destrutor
Noticias::~Noticias() {}

//getters
int Noticias::get_valor() 
{

	return this->_valor;
}

std::string Noticias::get_texto()
{
	return this->_texto;
}

//setters
void Noticias::set_valor(int valor) {
	this->_valor = valor;
}

void Noticias::set_texto(std::string texto)
{
	this->_texto = texto;
}

//metodos
void Noticias::executar_noticia() {
	int carta;
	srand(time(NULL));
	carta = (rand() % 31);
	if (carta == 0) {
		set_valor(800);
		set_texto("Parabens! Voce ganhou 1 premio no PIC Itau!");
	}
	else if (carta == 1) {
		set_valor(1500);
		set_texto("Com o cartao de credito MasterCard voce tem muitos beneficios para aproveitar!");
	}
	else if (carta == 2) {
		set_valor(1500);
		set_texto("Com o cartao de debito da MasterCard voce tem muito mais seguranca!");
	}
	else if (carta == 3) {
		set_valor(800);
		set_texto("Voce participou de um concurso cultural da TAM Viagens e agora vai conhecer o litoral brasileiro!");
	}
	else if (carta == 4) {
		set_valor(600);
		set_texto("Voce passou nos testes para fazer o novo comercial dos produtos de beleza Nivea!");
	}
	else if (carta == 5) {
		set_valor(1500);
		set_texto("Com o cartao de credito MasterCard voce tem muitos beneficios para aproveitar!");
	}
	else if (carta == 6) {
		set_valor(1000);
		set_texto("Seu carro foi roubado, mais voce tinha seguro auto Itau.");
	}
	else if (carta == 7) {
		set_valor(1500);
		set_texto("Com o cartao de credito MasterCard voce tem muitos beneficios para aproveitar!");
	}
	else if (carta == 8) {
		set_valor(500);
		set_texto("Seu carro foi roubado, mais voce tinha seguro auto Itau.");
	}
	else if (carta == 9) {
		set_valor(500);
		set_texto("Seu carro foi roubado, mais voce tinha seguro auto Itau.");
	}
	else if (carta == 10) {
		set_valor(450);
		set_texto("Ganhou um roteiro TAM Viagens! Escolha o lugar de sua preferencia e faça as malas!");
	}
	else if (carta == 11) {
		set_valor(200);
		set_texto("Voce acumulou pontos no Km de vantagens e pode trocar por combustivel nos Postos Ipiranga e lanches no AmPm.");
	}
	else if (carta == 12) {
		set_valor(1000);
		set_texto("Voce carregou seu celular e ganhou ainda mais creditos!");
	}
	else if (carta == 13) {
		set_valor(500);
		set_texto("Parabens! Voce ganhou a promocao do Mundo Nivea e recebeu todos os produtos Nivea na sua casa!");
	}
	else if (carta == 14) {
		set_valor(1500);
		set_texto("Com o cartao de credito MasterCard voce tem muitos beneficios para aproveitar!");
	}
	else if (carta == 15) {
		set_valor(1000);
		set_texto("Voce comprou um carro Fiat e vai economizar combustivel e manutencao.");
	}
	else if (carta == 16) {
		set_valor(750);
		set_texto("Voce ganhou um concurso de personalizacao de carros com o seu Novo Fiat UNO.");
	}
	else if (carta == 17) {
		set_valor(1500);
		set_texto("O jogo ainda nao tem suporte para o que essa carta queria, entao voce processou o Julio e ganhou!");
	}
	else if (carta == 18) {
		set_valor(0);
		set_texto("Va para o xadrez!");
	}
	else if (carta == 19) {
		set_valor(-300);
		set_texto("Pagou caro pela troca de oleo!");
	}
	else if (carta == 20) {
		set_valor(-800);
		set_texto("Voce participou de um concurso cultural da TAM Viagens e agora vai conhecer o litoral brasileiro!");
	}
	else if (carta == 21) {
		set_valor(-500);
		set_texto("Adquiriu um roteiro Ecoturismo, e gostou tanto da viagem que decidiu estender por mais 2 dias.");
	}
	else if (carta == 22) {
		set_valor(-90);
		set_texto("Chegou a nova linha de produtos Nivea! Voce ja esta na fila para comprar!");
	}
	else if (carta == 23) {
		set_valor(-300);
		set_texto("Voce tomou uma multa por poluir o meio ambiente!");
	}
	else if (carta == 24) {
		set_valor(-150);
		set_texto("A sua operadora de celular nao tem sinal no local! Para telefonar pague");
	}
	else if (carta == 25) {
		set_valor(-1000);
		set_texto("Voce estacionou seu carro em local proibido.");
	}
	else if (carta == 26) {
		set_valor(-250);
		set_texto("Como o seu MasterCard voce pode dividir aquele pagamento e pagar agora apenas esta primeira parcela.");
	}
	else if (carta == 27) {
		set_valor(-500);
		set_texto("Voce vai abrir a sua loja e nao podem faltar os produtos Nivea!");
	}
	else if (carta == 28) {
		set_valor(200);
		set_texto("Voce acumulou pontos no Km de vantagens e pode trocar por combustivel nos Postos Ipiranga e lanches no AmPm.");
	}
	else if (carta == 29) {
		set_valor(-220);
		set_texto("As tarifas da sua operadora de celular estao muito altas.");
	}
	else if (carta == 30) {
		set_valor(-200);
		set_texto("Preocupado com o futuro, voce colocou dinheiro na sua previdencia Itau.");
	}
	else if (carta == 31) {
		set_valor(-500);
		set_texto("O posto que voce abasteceu tinha gasolina adulterada! Para consertar o carro,");
	}
	else if (carta == 32) {
		set_valor(-200);
		set_texto("Chegou o feriado, e voce decidiu fazer uma viagem a Praia com a Família.");
	}
	else if (carta == 33) {
		set_valor(-1000);
		set_texto("Voce investiu em fundos do Itau.");
	}
	else if (carta == 34) {
		set_valor(-400);
		set_texto("Voce nao usou o cinto de segurança.");
	}
	else if (carta == 35) {
		set_valor(-300);
		set_texto("Ver a cara de surpresa da sua filha com o seu presente nao tem preço! Que bom que voce tem um MasterCard!");
	}
}