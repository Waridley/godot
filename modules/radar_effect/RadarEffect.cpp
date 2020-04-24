#include "RadarEffect.h"

Ref<AudioEffectInstance> AudioEffectRadar::instance() {
    Ref<AudioEffectRadarInstance> ins;
    ins.instance();
    return ins;
}
