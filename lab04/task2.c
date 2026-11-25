#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t reg, uint8_t bit);
uint32_t clear_bit(uint32_t reg, uint8_t bit);
uint32_t toggle_bit(uint32_t reg, uint8_t bit);
uint8_t  check_bit(uint32_t reg, uint8_t bit);
void     print_binary(uint32_t reg);

int main(void) {
    uint32_t reg = (1U << 8) | (1U << 2);

    printf("\n=== Робота з 32-б╕тним рег╕стром (Вар╕ант 3) ===\n");
    printf("Початковий стан:       "); print_binary(reg);
    reg = set_bit(reg, 4);
    printf("П╕сля set_bit(4):      "); print_binary(reg);
    reg = clear_bit(reg, 8);
    printf("П╕сля clear_bit(8):    "); print_binary(reg);
    reg = toggle_bit(reg, 14);
    printf("П╕сля toggle_bit(14):  "); print_binary(reg);
    printf("Стан б╕та 2 (check_bit): %u\n", check_bit(reg, 2));
    return 0;
}

uint32_t set_bit(uint32_t reg, uint8_t bit)    { return reg | (1U << bit); }
uint32_t clear_bit(uint32_t reg, uint8_t bit)  { return reg & ~(1U << bit); }
uint32_t toggle_bit(uint32_t reg, uint8_t bit) { return reg ^ (1U << bit); }
uint8_t  check_bit(uint32_t reg, uint8_t bit)  { return (reg >> bit) & 1U; }

void print_binary(uint32_t reg) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (reg >> i) & 1U);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf(" (0x%08X)\n", reg);
}
