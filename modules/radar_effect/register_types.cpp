#include <core/engine.h>
#include <core/class_db.h>
#include "register_types.h"
#include "RadarEffect.h"

void register_radar_effect_types() {
    ClassDB::register_class<AudioEffectRadar>();
}

void unregister_radar_effect_types() { }