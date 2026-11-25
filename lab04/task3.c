#include <stdio.h>
#include <stdint.h>

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power);
void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power);

int main(void) {
    uint8_t p = 11, f = 185, e = 2, pw = 1;

    printf("\n=== Пакування та розпакування телеметр╕╖ (Вар╕ант 3) ===\n");
    printf("Початков╕ дан╕: Пр╕оритет=%u, Вентилятор=%u, Помилка=%u, Живлення=%u\n", p, f, e, pw);

    uint16_t packed = pack_telemetry(p, f, e, pw);
    printf("Запакований пакет: HEX: 0x%04X (DEC: %u)\n", packed, packed);

    uint8_t dp, df, de, dpw;
    unpack_telemetry(packed, &dp, &df, &de, &dpw);
    printf("В╕дновлен╕ дан╕: Пр╕оритет=%u, Вентилятор=%u, Помилка=%u, Живлення=%u\n", dp, df, de, dpw);
    return 0;
}

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power) {
    uint16_t packet = 0;
    packet |= (uint16_t)(priority   & 0x0F) << 0;
    packet |= (uint16_t)(fan_speed  & 0xFF) << 4;
    packet |= (uint16_t)(error_code & 0x03) << 12;
    packet |= (uint16_t)(power      & 0x01) << 14;
    return packet;
}

void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power) {
    *priority   = (packet >> 0)  & 0x0F;
    *fan_speed  = (packet >> 4)  & 0xFF;
    *error_code = (packet >> 12) & 0x03;
    *power      = (packet >> 14) & 0x01;
}
