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

int g_lba2idechs(tLBA lba_geometry, tIDECHS* idechs_geometry) {
    tIDECHS best = {0, 0, 255};
    for (uint16_t i = 0; i < 256; ++i) {
        for (uint32_t j = 0; j < UINT16_MAX; ++j) {
            int64_t dif = (int64_t)(lba_geometry)-255 * i * j;
            int64_t b_dif
                    = (int64_t)(lba_geometry)-255 * best.cylinder * best.head;
            if (dif >= 0 && dif <= b_dif) {
                best.head = (uint8_t)i;
                best.cylinder = (uint16_t)j;
            }
        }
    }
    idechs_geometry->cylinder = best.cylinder;
    idechs_geometry->head = best.head;
    idechs_geometry->sector = 255;

    return 0;
}

int g_chs2large(tCHS chs_geometry, tLARGE* large_geometry) {
    uint32_t pow = 2;
    large_geometry->cylinder = (uint16_t)(chs_geometry.cylinder / pow);
    large_geometry->head = (uint8_t)(chs_geometry.head * pow);
    large_geometry->sector = chs_geometry.sector;
    return 0;
}

