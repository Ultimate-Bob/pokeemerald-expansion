#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "constants/regions.h"

extern const u8 gText_RegionKanto[];
extern const u8 gText_RegionSevii[];
extern const u8 gText_RegionJohto[];
extern const u8 gText_RegionHoenn[];
extern const u8 gText_RegionSinnoh[];
extern const u8 gText_RegionUnova[];
extern const u8 gText_RegionKalos[];
extern const u8 gText_RegionAlola[];
extern const u8 gText_RegionGalar[];
extern const u8 gText_RegionHisui[];
extern const u8 gText_RegionPaldea[];

extern const u8 *const gRegionNames[];
extern const u8 gMapsecToRegion[];

static inline u32 GetCurrentRegion(void)
{
    // TODO: Since there's no current multi-region support, we have this constant for the purposes of regional form comparisons.
    //return REGION_HOENN;

    return gMapHeader.region;
}


#endif // GUARD_REGIONS_H
