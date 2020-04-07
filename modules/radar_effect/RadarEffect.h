#ifndef OSOG_RADAREFFECT_H
#define OSOG_RADAREFFECT_H

#include <servers/audio/audio_effect.h>
#include <core/reference.h>

class AudioEffectRadarInstance : public AudioEffectInstance {
    GDCLASS(AudioEffectRadarInstance, AudioEffectInstance);
    friend class AudioEffectRadar;

public:
    void process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) override;
    bool process_silence() const override;
};

class AudioEffectRadar : public AudioEffect {
    GDCLASS(AudioEffectRadar, AudioEffect);
    friend class AudioEffectRadarInstance;

public:
    Ref<AudioEffectInstance> instance() override;
};




#endif //OSOG_RADAREFFECT_H
