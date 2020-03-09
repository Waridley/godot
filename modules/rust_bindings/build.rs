extern crate bindgen;

use std::path::PathBuf;

fn main() {
    // use std::env;
    // let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    let out_path = PathBuf::from("src");

    let out_file = out_path.join("bindings.rs");

    println!("cargo:rerun-if-changed=headers.h");

    let bindings = bindgen::Builder::default()
        .clang_arg("-x").clang_arg("c++")
        .clang_arg("-I../../")
        .clang_arg("-I../gdnative/include/")
        .clang_arg("-I../../platform/windows/")
        .header("headers.h")
        .whitelist_type("godot.*")
        .whitelist_function("godot.*")
        .whitelist_var("godot.*")
        .whitelist_type("GDNATIVE.*")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Failed to generate bindings");

    let out_file_str = out_file.to_str().unwrap().to_owned();
    bindings.write_to_file(out_file)
        .expect(format!("Coudln't write bindings to {}", out_file_str).as_str());
}