extern crate godot_module_bindings as gd;

use gd::{godot_string_chars_to_utf8_with_len, godot_print};

#[no_mangle]
pub extern "C" fn hello() {
    let greeting = "Hello from Rust module!";

    unsafe {
        let line = godot_string_chars_to_utf8_with_len(greeting.as_ptr() as *const _, greeting.len() as _);
        godot_print(&line as *const _);
    }
}