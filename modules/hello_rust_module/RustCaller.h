#ifndef GODOT_RUSTCALLER_H
#define GODOT_RUSTCALLER_H

#include "core/reference.h"

class RustCaller : public Reference {
    GDCLASS(RustCaller, Reference);

protected:
    static void _bind_methods();

public:
    int32_t hello_rust();

    RustCaller();
};


#endif //GODOT_RUSTCALLER_H
