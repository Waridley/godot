extern crate godot_module_bindings as gd;

use gd::{godot_string_chars_to_utf8_with_len, godot_print, godot_rid, godot_rid_get_id, RID};
use std::intrinsics::transmute;

#[no_mangle]
pub extern "C" fn hello() {
    let greeting = "Hello from Rust module!";

    gprint(greeting)
}

#[no_mangle]
pub extern "C" fn print_rid_using_rust(rid: RID) {
    gprint(format!("{:?}", unsafe { godot_rid_get_id(&transmute::<RID, godot_rid>(rid) as *const _) }).as_str());
}

fn gprint(rust_str: &str) {
    unsafe {
        let line = godot_string_chars_to_utf8_with_len(rust_str.as_ptr() as *const _, rust_str.len() as _);
        godot_print(&line as *const _);
    }
}