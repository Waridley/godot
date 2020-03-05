#[macro_use]
extern crate gdnative;

#[no_mangle]
pub extern "C" fn hello() {
    godot_print!("Hello from Rust module!")
}
