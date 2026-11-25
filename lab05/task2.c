#include <stdio.h>
#include <stdint.h>

#define SET_BIT_POS    7U
#define CLEAR_BIT_POS  3U
#define TOGGLE_BIT_POS 19U
#define STATUS_BIT_POS 2U

static void print_bin32(uint32_t val) {
    for (int b = 31; b >= 0; --b) {
        putchar(((val >> b) & 1U) ? '1' : '0');
        if (b % 8 == 0 && b != 0) {
            putchar('_');
        }
    }
}

void configure_register(uint32_t *reg) {
    if (reg == NULL) {
        return;
    }
    *reg |= (1U << SET_BIT_POS);
    *reg &= ~(1U << CLEAR_BIT_POS);
    *reg ^= (1U << TOGGLE_BIT_POS);
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos) {
    if (reg == NULL || bit_pos >= 32U) {
        return 0;
    }
    return ((*reg >> bit_pos) & 1U) ? 1 : 0;
}

int main(void) {
    uint32_t ctrl_reg = 0x0000000CU;

    printf("Before: 0x%08X (", ctrl_reg);
    print_bin32(ctrl_reg);
    printf(")\n");

    configure_register(&ctrl_reg);

    printf("After:  0x%08X (", ctrl_reg);
    print_bin32(ctrl_reg);
    printf(")\n");

    int flag = check_status_flag(&ctrl_reg, STATUS_BIT_POS);
    printf("Status flag at bit %u: %d\n", STATUS_BIT_POS, flag);

    return 0;
}