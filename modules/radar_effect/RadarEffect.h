#ifndef OSOG_RADAREFFECT_H
#define OSOG_RADAREFFECT_H

#include <core/reference.h>
#include <servers/audio/audio_effect.h>
#include "bindings.gen.h"

class AudioEffectRadarInstance : public AudioEffectInstance {
    GDCLASS(AudioEffectRadarInstance, AudioEffectInstance);
    friend class AudioEffectRadar;

public:
    _FORCE_INLINE_ void process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) override { radar_process(p_src_frames, p_dst_frames, p_frame_count); };
    bool process_silence() const override { return false; };
};

class AudioEffectRadar : public AudioEffect {
    GDCLASS(AudioEffectRadar, AudioEffect);
    friend class AudioEffectRadarInstance;

public:
    Ref<AudioEffectInstance> instance() override;
};




#endif //OSOG_RADAREFFECT_H
