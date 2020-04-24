#ifndef GODOT_RUSTCALLER_H
#define GODOT_RUSTCALLER_H

#include "bindings.gen.h"
#include <core/func_ref.h>
#include <core/reference.h>
#include <servers/audio/audio_effect.h>

class RustCaller : public Reference {
    GDCLASS(RustCaller, Reference);

protected:
    static void _bind_methods();

public:
    _FORCE_INLINE_ void hello_rust() { hello(); };
    _FORCE_INLINE_ void print_rid(RID rid) { print_rid_using_rust(rid); };

    RustCaller() { }
};




class AudioEffectMinus20dbInstance : public AudioEffectInstance {
    GDCLASS(AudioEffectMinus20dbInstance, AudioEffectInstance);
    friend class AudioEffectMinus20db;

public:
    _FORCE_INLINE_ void process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) override {
		minus_20db(p_src_frames, p_dst_frames, p_frame_count);
	};

    _FORCE_INLINE_ bool process_silence() const override { return false; };
};


class AudioEffectMinus20db : public AudioEffect {
    GDCLASS(AudioEffectMinus20db, AudioEffect);
    friend class AudioEffectMinus20dbInstance;

public:
	_FORCE_INLINE_ Ref<AudioEffectInstance> instance() {
		Ref<AudioEffectMinus20dbInstance> ins;
		ins.instance();
		return ins;
	}

};




class AudioEffectSendInstance : public AudioEffectInstance {
	GDCLASS(AudioEffectSendInstance, AudioEffectInstance)
	friend class AudioEffectSend;

	StringName func_name;
	bool can_process_silence;

public:
	_FORCE_INLINE_ void process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) override {

		call(func_name, p_src_frames, p_dst_frames, p_frame_count);
	}

	bool process_silence() const override {
		return can_process_silence;
	}

};


class AudioEffectSend : public AudioEffect {
	GDCLASS(AudioEffectSend, AudioEffect)
	friend class AudioEffectSendInstance;

	StringName func_name;
	bool can_process_silence;

public:
	Ref<AudioEffectInstance> instance() override {
		Ref<AudioEffectSendInstance> ins;
		ins.instance();
		ins->func_name = func_name;
		ins->can_process_silence = can_process_silence;
		return ins;
	};

	void set_process_silence(bool value) {
		can_process_silence = value;
	}
};

#endif //GODOT_RUSTCALLER_H
