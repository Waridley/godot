#include "RustCaller.h"
#include "bindings.h"

void RustCaller::hello_rust() {
    hello();
}

void RustCaller::print_rid(RID rid) {
    print_rid_using_rust(rid);
}

void RustCaller::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hello_rust"), &RustCaller::hello_rust);
    ClassDB::bind_method(D_METHOD("print_rid"), &RustCaller::print_rid);
}

RustCaller::RustCaller() {

}