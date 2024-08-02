#ifndef _HW_TYPES_H_
#define _HW_TYPES_H_

//*****************************************************************************
//
// Define a boolean type, and values for true and false.
// Defina um tipo booleano e valores para verdadeiro e falso.
//
//*****************************************************************************
typedef unsigned char tBoolean;

typedef enum{
   true = 1,
   false = 0
}bool;

#ifndef NULL
#define NULL ((void*) 0)
#endif

//*****************************************************************************
//
// Macros for hardware access, both direct and via the bit-band region.
// Macros para acesso de hardware, tanto direto quanto via região bit-band.
//
//*****************************************************************************
#define HWREG(x)                                                              \
        (*((volatile unsigned int *)(x)))
#define HWREGH(x)                                                             \
        (*((volatile unsigned short *)(x)))
#define HWREGB(x)                                                             \
        (*((volatile unsigned char *)(x)))
#define HWREGBITW(x, b)                                                       \
        HWREG(((unsigned int)(x) & 0xF0000000) | 0x02000000 |                \
              (((unsigned int)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITH(x, b)                                                       \
        HWREGH(((unsigned int)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned int)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITB(x, b)                                                       \
        HWREGB(((unsigned int)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned int)(x) & 0x000FFFFF) << 5) | ((b) << 2))

#define TRUE    1
#define FALSE   0

// HWREG(x) ; Essa macro é usada para acessar um registrador de 32 bits no endereço especificado por x. Ela converte o endereço para um ponteiro para um inteiro não assinado volátil e, em seguida, usa o operador de desreferência * para acessar o valor do registrador.
//HWREGH(X): acessa registradores de 16 bits..
//HWREGB(x): acessa registradores de 8 bits...
//HWREGBITW(x, b): Essa macro é usada para acessar um bit específico em um registrador de 32 bits no endereço x. Ela combina o endereço do registrador com o número do bit (b) para formar o endereço do bit específico e, em seguida, usa a macro 
// HWREGBITH(x, b): Essa macro é semelhante à HWREGBITW(x, b), mas é usada para acessar um bit em um registrador de 16 bits.
//HWREGBITB(x, b): Essa macro é semelhante às anteriores, mas é usada para acessar um bit em um registrador de 8 bits.


#endif // __HW_TYPES_H__
