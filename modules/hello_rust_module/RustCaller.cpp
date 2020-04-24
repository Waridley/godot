#include "RustCaller.h"

void RustCaller::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hello_rust"), &RustCaller::hello_rust);
    ClassDB::bind_method(D_METHOD("print_rid"), &RustCaller::print_rid);
}
