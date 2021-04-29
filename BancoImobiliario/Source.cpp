//Devemos dar o Include de todas as classes nesse arquivo
#include "Header/Acao.h"
#include "Header/Casa.h"
#include "Header/CasasEspeciais.h"
#include "Header/CasasNegociaveis.h"
#include "Header/Jogador.h"

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
    godot::register_class<Jogador>();f 


}