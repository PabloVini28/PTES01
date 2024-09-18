# Embbeded Systems I Final Project - 

## Developers 👥

  - ### Pablo Vinícios da S.Araújo [![github](https://img.shields.io/badge/GitHub-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/PabloVini28)
  - ### David Silva Fernandes de Oliveira [![github](https://img.shields.io/badge/GitHub-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/sfoDavid)

## Setup Components 💡
For our final project, we developed a mini-game called "Jogo da Marmota" as a bare-metal application. We used various electronic components, such as LEDs, buttons, protoboard, one active buzzer and jumpers. The embedded system was implemented on a BeagleBone Black board, and the project was enclosed in a small pressed wood box.

## Setup Configurations ⚙️

- Ensure the circuit setup, TFTP environment, the correct cross-compiler, and the connections for the serial cable, Ethernet cable, and power cable are all in place.
- Navigate to the project directory and run the command make. If you encounter issues, check your ARM cross-compiler setup.
 - Open a serial tool like Minicom, access the board's U-Boot, and follow the instructions in the file 'roteiro tftp.odt' found in the repository.
  - Once the binary file is transferred, run the command go 0x80000000 in the terminal

## Playing 🕹️

  - Press the start button to begin the game.
- During gameplay, four random sequences will cause the LEDs to blink. If you press the correct button in sequence, the buzzer will sound for one second.

## Rules 📋

   - If you press more than one button at a time, you will lose one point.
   - The maximum score is 16 points.
   - The minimum score is 0 points.
   - You can reset the game at any time.

## Note 📌

  - GPIO input interrupts are disabled in real-time during the game.
    
## Components 🔋
| Item               | Quantity  | Unit Price | Total Price |
|--------------------|-----------|------------|-------------|
| LEDs               | 4 units   | R$ 1.00    | R$ 4.00     |
| Buttons            | 6 units   | R$ 4.50    | R$ 27.00    |
| Buzzer             | 1 unit    | R$ 5.00    | R$ 5.00     |
| Protoboard         | 1 unit    | R$ 16.00   | R$ 16.00    |
| Prototype Box      | 1 unit    | R$ 9.30    | R$ 9.30     |
| Jumpers            |           |            |             |

## Board used during the project :🧑‍💻

[![BEAGLEBONEBLACK](https://img.shields.io/badge/BEAGLEBONEBLACK-black?style=for-the-badge&logoColor=orange)](https://www.beagleboard.org/boards/beaglebone-black)
