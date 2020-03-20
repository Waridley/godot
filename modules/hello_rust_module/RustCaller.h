#ifndef GODOT_RUSTCALLER_H
#define GODOT_RUSTCALLER_H

#include <servers/audio/audio_effect.h>
#include <core/reference.h>

class RustCaller : public Reference {
    GDCLASS(RustCaller, Reference);

protected:
    static void _bind_methods();

public:
    void hello_rust();
    void print_rid(RID rid);

    RustCaller();
};

class AudioEffectMinus20dbInstance : public AudioEffectInstance {
    GDCLASS(AudioEffectMinus20dbInstance, AudioEffectInstance);
    friend class AudioEffectMinus20db;

public:
    void process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) override;
    bool process_silence() const override;
};

class AudioEffectMinus20db : public AudioEffect {
    GDCLASS(AudioEffectMinus20db, AudioEffect);
    friend class AudioEffectMinus20dbInstance;

public:
    Ref<AudioEffectInstance> instance() override;
};

#endif //GODOT_RUSTCALLER_H
