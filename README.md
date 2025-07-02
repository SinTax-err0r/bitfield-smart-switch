# Bitfield-Based Appliance Controller in C

This is a simple C project that simulates controlling multiple home appliances using an 8-bit register. Each bit in the register represents the ON/OFF state of an appliance or the master control.

## 🛠 Features

- Controls 7 appliances:  
  `Refrigerator`, `Washing Machine`, `Microwave Oven`, `Dishwasher`, `Air Conditioner`, `Heater`, and `Desktop`
- 8th bit is a `Master Switch` to cut power view (or optionally control all)
- View current register value in **binary**
- User-friendly console with numbered toggle options
- Uses **bitwise operations** to simulate register-level hardware control

## 🧠 Concepts Used

- Bitwise operators (`&`, `|`, `^`, `~`, `<<`)
- Bit masking
- Bit toggling and checking
- Console interaction in C
- Registers and low-level hardware simulation

## 📸 Sample Output
Current Register Value: 00000101
Appliance Status:
[0] Refrigerator : ON
[1] Washing Machine : OFF
[2] Microwave Oven : ON
...
Master Control: OFF

Enter number to toggle: [0–6] Appliance, [7] Master Switch, [-1] Exit:
