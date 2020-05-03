#include "RustCaller.h"
#include "bindings.gen.h"

void RustCaller::hello_rust() {
    hello();
}

void RustCaller::print_rid(RID rid) {
    print_rid_using_rust(rid);
}

void RustCaller::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hello_rust"), &RustCaller::hello_rust);
    ClassDB::bind_method(D_METHOD("print_rid"), &RustCaller::print_rid);
}

RustCaller::RustCaller() {

}

void AudioEffectMinus20dbInstance::process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) {
    minus_20db(p_src_frames, p_dst_frames, p_frame_count);
}

bool AudioEffectMinus20dbInstance::process_silence() const {
    return AudioEffectInstance::process_silence();
}

Ref<AudioEffectInstance> AudioEffectMinus20db::instance() {
    Ref<AudioEffectMinus20dbInstance> ins;
    ins.instance();
    return ins;
}