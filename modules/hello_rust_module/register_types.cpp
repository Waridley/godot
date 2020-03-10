#include <core/engine.h>
#include <core/class_db.h>
#include "register_types.h"
#include "RustCaller.h"

void register_hello_rust_module_types() {
    static RustCaller * rust_caller = memnew(RustCaller);
    Engine::get_singleton()->add_singleton(Engine::Singleton("RustCaller", rust_caller));
    ClassDB::register_class<RustCaller>();
}

void unregister_hello_rust_module_types() {

}