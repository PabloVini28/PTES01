# PROGRAMMING TECHNIQUES FOR EMBEDDED SYSTEMS I - 🖥️
## Blinking The On Board Leds Practice 💡

  - First of all, we need to take the names of On board leds in the PTSE01/Documents/BEAGLEBONEBLK_C - BBB_SCH.pdf path, his names are USR0 until USR3, if you want, go to the page 3.
  - Next to the led names, there is the name of GPIO group and your value. eg.GPIO1_21,GPIO1_22 ...
  - So, we knows about the on board leds belongs to the GPIO1, after that we need to do the function configuration.
  - We need to define the macros for apply at the BareMetal application, I took the macros in the user manual, it is in the PTSE01/Documents/ User_Manual path.
  - For this practice, we need, majoritarity, the GPIO1 macros about the Base Address, Clock And Module Enable. After, we need to find the name of GPIO1_21,22,23 and 24 pin, to do that, take the gpio1_21 and search on the PTES01/Documents/DatasheetAM335x.pdf, you will find the name of pin, in this case is CM_conf_gpmc_a5, next to there is his offset.
  - Finally, we need to find the Address offset about the GPIO Output controls, search on the User Manual the GPIO_OE, GPIO_CLEARDATAOUT and GPIO_SETDATAOUT.
  - Conclusion, do the bitwise code using this practice as an example, you will blink the 4 on board leds in the binary sequence like 0 until 15.
  
