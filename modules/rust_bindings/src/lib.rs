
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use std::fmt::{Display, Debug};
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));


#[macro_export]
macro_rules! gdprintln {
    ($($args:tt)*) => ({
        let msg = format!($($args)*);

        #[allow(unused_unsafe)]
        unsafe {
            let msg = godot_string::from(msg.as_str());
            $crate::godot_print(&msg as *const _);
        }
    });
}

#[macro_export]
macro_rules! gddbg {
    () => {
        $crate::gdprintln!("[{}:{}]", ::std::file!(), ::std::line!());
    };
    ($val:expr) => {
        // Use of `match` here is intentional because it affects the lifetimes
        // of temporaries - https://stackoverflow.com/a/48732525/1063961
        match $val {
            tmp => {
                $crate::gdprintln!("[{}:{}] {} = {:#?}",
                    ::std::file!(), ::std::line!(), ::std::stringify!($val), &tmp);
                tmp
            }
        }
    };
    // Trailing comma with single argument is ignored
    ($val:expr,) => { $crate::gddbg
   !($val) };
    ($($val:expr),+ $(,)?) => {
        ($($crate::gddbg
       !($val)),+,)
    };
}

#[macro_export]
macro_rules! gdwarn {
    ($($args:tt)*) => ({
        let msg = format!($($args)*);
        let line = line!();
        let file = file!();
        #[allow(unused_unsafe)]
        unsafe {
            let msg = ::std::ffi::CString::new(msg).unwrap();
            let file = ::std::ffi::CString::new(file).unwrap();
            let func = b"<native>\0";
            ($crate::godot_print_warning)(
                msg.as_ptr() as *const _,
                func.as_ptr() as *const _,
                file.as_ptr() as *const _,
                line as _,
            );
        }
    })
}

#[macro_export]
macro_rules! gderr {
    ($($args:tt)*) => ({
        let msg = format!($($args)*);
        let line = line!();
        let file = file!();
        #[allow(unused_unsafe)]
        unsafe {
            let msg = ::std::ffi::CString::new(msg).unwrap();
            let file = ::std::ffi::CString::new(file).unwrap();
            let func = b"<native>\0";
            ($crate::godot_print_error)(
                msg.as_ptr() as *const _,
                func.as_ptr() as *const _,
                file.as_ptr() as *const _,
                line as _,
            );
        }
    })
}


pub fn gdprint_str(rust_str: &str) {
    unsafe {
        let line = godot_string::from(rust_str);
        godot_print(&line as *const _);
    }
}

#[inline]
pub fn gdprintln(displayable: impl Display) {
    gdprint_str(format!("{}", displayable).as_str())
}

#[inline]
pub fn gdpretty_print(debuggable: impl Debug) {
    gdprint_str(format!("{:#?}", debuggable).as_str())
}

#[inline]
pub fn gddbg(debuggable: impl Debug) {
    gdprint_str(format!("{:?}", dbg!(debuggable)).as_str())
}


impl From<&str> for godot_string {
    fn from(rust_str: &str) -> godot_string {
        unsafe {
            godot_string_chars_to_utf8_with_len(rust_str.as_ptr() as *const _, rust_str.len() as _)
        }
    }
}

