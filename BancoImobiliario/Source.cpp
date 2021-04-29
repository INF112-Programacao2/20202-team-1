//Devemos dar o Include de todas as classes nesse arquivo
#include "Acao.h"
#include "Casa.h"
#include "CasasEspeciais.h"
#include "CasasNegociaveis.h"
#include "Imovel.h"
#include "Jogador.h"
#include "Noticias.h"
#include "Partida.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
    godot::Godot::nativescript_init(handle);
    
    //Registramos as classes AQUI!
    godot::register_class<Acao>();
    godot::register_class<Casa>();
    godot::register_class<CasasEspeciais>();
    godot::register_class<CasasNegociaveis>(); 
    godot::register_class<Jogador>();
    godot::register_class<Imovel>();
    godot::register_class<Noticias>(); 
    godot::register_class<Partida>(); 
}