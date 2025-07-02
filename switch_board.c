#include <stdlib.h>
#include <stdio.h>  
#include <stdint.h>

#define APPLIANCE_COUNT 7
#define master_bit 7

const char* Appliance_Names[] = {
    "Refrigerator",
    "Washing Machine",
    "Microwave Oven",
    "Dishwasher",
    "Air Conditioner",
    "Heater",
    "Desktop"
};

const int appliance_bits[] = {
    0, // Refrigerator
    1, // Washing Machine
    2, // Microwave Oven
    3, // Dishwasher
    4, // Air Conditioner
    5, // Heater
    6  // Desktop
};

int is_bit_on(uint8_t reg, int bit) {
    return (reg >> bit) & 1;
}

void print_binary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void print_appliance_status(uint8_t reg) {
    printf("\nAppliance Status:\n");

    int master_on = is_bit_on(reg, master_bit);

    for (int i = 0; i < APPLIANCE_COUNT; i++) {
    if (master_on) {
        printf("[%d] %-17s: %s\n", i, Appliance_Names[i],
               is_bit_on(reg, appliance_bits[i]) ? "ON" : "OFF");
    } else {
        printf("[%d] %-17s: OFF (Master OFF)\n", i, Appliance_Names[i]);
    }
}


    printf("Master Control: %s\n", master_on ? "ON" : "OFF");
    printf("Register (Binary): ");
    print_binary(reg);
    printf("\n");
}

int main() {
    uint8_t reg = 0;
    int choice;

    while (1) {
        print_appliance_status(reg);

        printf("Enter appliance number to toggle (0 to 6), 7 for Master Switch, or -1 to exit: ");
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        } else if (choice >= 0 && choice < APPLIANCE_COUNT) {
            reg ^= (1 << appliance_bits[choice]);  // Toggle appliance
        } else if (choice == master_bit) {
            reg ^= (1 << master_bit);              // Toggle master
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


