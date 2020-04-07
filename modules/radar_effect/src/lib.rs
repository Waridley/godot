#[macro_use]
extern crate godot_module_bindings as gd;

use gd::{AudioFrame,};
use std::slice;

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}

#[no_mangle]
pub extern "C" fn radar_process(first_src_frame: &AudioFrame, first_dst_frame: &mut AudioFrame, frame_count: i32) {
    unsafe {
        let src_frames = slice::from_raw_parts(first_src_frame, frame_count as usize);
        let dst_frames = slice::from_raw_parts_mut(first_dst_frame, frame_count as usize);
        for (idx, frame) in src_frames.iter().enumerate() {
            dst_frames[idx] = *frame
        }
    }
}