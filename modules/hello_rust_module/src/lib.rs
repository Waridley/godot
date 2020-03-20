#[macro_use]
extern crate godot_module_bindings as gd;

use gd::{RID, godot_string, godot_rid, godot_rid_get_id, gdprint_str, gdprintln, AudioFrame};
use std::intrinsics::transmute;
use std::slice;


#[no_mangle]
pub extern "C" fn hello() {
    let greeting = "Hello from Rust module!";
    gdprint_str(greeting);
}

#[no_mangle]
pub extern "C" fn print_rid_using_rust(rid: RID) {
    gddbg!(unsafe { &*rid._data });
    gdprintln(unsafe { godot_rid_get_id(&transmute::<RID, godot_rid>(rid) as *const _) });
}

#[no_mangle]
pub extern "C" fn minus_20db(first_src_frame: &AudioFrame, first_dst_frame: &mut AudioFrame, frame_count: i32) {
    unsafe {
        let src_frames = slice::from_raw_parts(first_src_frame, frame_count as usize);
        let dst_frames = slice::from_raw_parts_mut(first_dst_frame, frame_count as usize);
        for (idx, frame) in src_frames.iter().enumerate() {
            dst_frames[idx] = AudioFrame { l: frame.l * 0.1, r: frame.r * 0.1 }
        }
    }
}