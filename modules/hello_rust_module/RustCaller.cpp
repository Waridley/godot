#include "RustCaller.h"
#include "modules/hello_rust_module/include/hello_rust_module.h"

int32_t RustCaller::hello_rust() {
    return hello();
}

void RustCaller::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hello_rust"), &RustCaller::hello_rust);
}

RustCaller::RustCaller() {

}