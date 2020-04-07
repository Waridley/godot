#include "RadarEffect.h"
#include "bindings.gen.h"

bool AudioEffectRadarInstance::process_silence() const {
    return AudioEffectInstance::process_silence();
}

void AudioEffectRadarInstance::process(const AudioFrame *p_src_frames, AudioFrame *p_dst_frames, int p_frame_count) {
    radar_process(p_src_frames, p_dst_frames, p_frame_count);
}

Ref<AudioEffectInstance> AudioEffectRadar::instance() {
    Ref<AudioEffectRadarInstance> ins;
    ins.instance();
    return ins;
}