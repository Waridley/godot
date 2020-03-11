#[macro_use]
extern crate godot_module_bindings as gd;

use gd::{godot_string, godot_rid, godot_rid_get_id, RID, gdprint_str, gdprintln};
use std::intrinsics::transmute;


#[no_mangle]
pub extern "C" fn hello() {
    let greeting = "Hello from Rust module!";
    gdprint_str(greeting)
}

#[no_mangle]
pub extern "C" fn print_rid_using_rust(rid: RID) {
    gddbg!(unsafe { &*rid._data });
    gdprintln(unsafe { godot_rid_get_id(&transmute::<RID, godot_rid>(rid) as *const _) });
}
