//
// Created by mario on 3/4/2020.
//

#include "register_types.h"

#include "core/class_db.h"
#include "RustCaller.h"

void register_hello_rust_module_types() {
    ClassDB::register_class<RustCaller>();
}

void unregister_hello_rust_module_types() {

}