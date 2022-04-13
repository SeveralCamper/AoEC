#include "MBR.h"

int g_lba2chs(tLBA lba_geometry, tCHS* chs_geometry) {
    tCHS best = {0, 0, 63};
    for (uint16_t i = 0; i < 256; ++i) {
        for (uint16_t j = 0; j < 1024; ++j) {
            int64_t dif = (int64_t)(lba_geometry)-63 * i * j;
            int64_t b_dif
                    = (int64_t)(lba_geometry)-63 * best.cylinder * best.head;
            if (dif >= 0 && dif <= b_dif) {
                best.head = (uint8_t)i;
                best.cylinder = j;
            }
        }
    }
    chs_geometry->cylinder = best.cylinder;
    chs_geometry->head = best.head;
    chs_geometry->sector = 63;

    return 0;
}

int g_lba2large(tLBA lba_geometry, tLARGE* large_geometry) {
    tCHS chs_geometry;
    g_lba2chs(lba_geometry, &chs_geometry);
    g_chs2large(chs_geometry, large_geometry);
    
    return 0;
}

