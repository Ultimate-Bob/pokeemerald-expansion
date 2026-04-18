#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "constants/regions.h"

extern const u8 gText_RegionNone[];
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
extern const enum Region gMapsecToRegion[];

enum KantoSubRegion GetKantoSubregion(u32 mapSecId);

static inline enum Region GetRegionForSectionId(u32 sectionId)
{
    if (sectionId >= KANTO_MAPSEC_START && sectionId < KANTO_MAPSEC_END)
        return REGION_KANTO;
    return gMapsecToRegion[gMapHeader.regionMapSectionId]; // feature/multi-region
}

static inline enum Region GetCurrentRegion(void)
{
    return GetRegionForSectionId(gMapHeader.regionMapSectionId);
}

#endif // GUARD_REGIONS_H
