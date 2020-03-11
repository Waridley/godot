#ifndef GODOT_RUSTCALLER_H
#define GODOT_RUSTCALLER_H

#include "core/reference.h"

class RustCaller : public Reference {
    GDCLASS(RustCaller, Reference);

protected:
    static void _bind_methods();

public:
    void hello_rust();
    void print_rid(RID rid);

    RustCaller();
};


#endif //GODOT_RUSTCALLER_H
