/*
Header file for LCD - 
*/

#ifndef LCD_H_
#define LCD_H_

// If using the nucleo F445RE then we need to include this
#include "stm32f4xx_hal.h"

#include "string.h"
#include "stdio.h"
#include "main.h"

// For 16xN LCD
#define LCD16xN

// Row start addresses
extern const uint8_t ROW_16[];

/** Command Registers - uses hex code found on datasheet of lcd**/
#define CLEAR_DISPLAY 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE_SET 0x04
#define OPT_S 0x01					  	  // Shift entire display to the right
#define OPT_INC 0x02			     	  // Cursor Increment

#define DISPLAY_ON_OFF_CONTROL 0x08		  // Display OFF and Cursor OFF
#define OPT_D 0x04						  // Turn on display
#define OPT_C 0x02						  // Turn cursor on
#define OPT_B 0x01						  // Turn on cursor blink

#define CURSOR_DISPLAY_SHIFT 0x10		  // Move and shift cursor
#define OPT_SC 0x08                       // Set cursor moving and display shift control bit
#define OPT_RL 0X04

#define FUNCTION_SET 0x20
#define OPT_DL 0x10						  // Set interface data length
#define OPT_N 0x08						  // Set Number of display lines
#define OPT_F 0X04						  // Set alternate font
#define SETCGRAM_ADDR 0x040
#define SET_DDRAM_ADDR 0x80				  // Set DDRAM address

/**Helper Macros**/
#define DELAY(X) HAL_Delay(X)

/** LCD Defines **/
#define LCD_NIB 4
#define LCD_BYTE 8
#define LCD_DATA_REG 1
#define LCD_COMMAND_REG 0

/** LCD Typedefs **/
#define Lcd_PortType GPIO_TypeDef*
#define Lcd_PinType uint16_t 

typedef enum {
    LCD_4_BIT_MODE,
    LCD_8_BIT_MODE
} Lcd_ModeTypeDef;


typedef struct {
    Lcd_PortType *data_port;
    Lcd_PinType *data_pin;

    Lcd_PortType rs_port;
    Lcd_PinType rs_pin;

    Lcd_PortType en_port;
    Lcd_PinType en_pin;

    Lcd_ModeTypeDef mode;

} Lcd_HandleTypeDef;

/** Public Functions **/
void Lcd_init(Lcd_HandleTypeDef *lcd);
void Lcd_int(Lcd_HandleTypeDef *lcd, int number);
void Lcd_float(Lcd_HandleTypeDef *lcd, float number);
void Lcd_string(Lcd_HandleTypeDef *lcd, char *string);
void Lcd_cursor(Lcd_HandleTypeDef *lcd, uint8_t row, uint8_t col);

Lcd_HandleTypeDef Lcd_create(
    Lcd_PortType port[], Lcd_PinType pin[],
    Lcd_PortType rs_port, Lcd_PinType rs_pin,
    Lcd_PortType en_port, Lcd_PinType en_pin, Lcd_ModeTypeDef mode);

void Lcd_define_char(Lcd_HandleTypeDef *lcd, uint8_t code, uint8_t bitmap[]);
void Lcd_clear(Lcd_HandleTypeDef *lcd);

#endif

/*
 * 4 bit mode sends data nibble by nibble, first the upper nibble and then the lower nibble
 * A nibble is a group of 4 bits - lower four bits (D0-D3) and the upper bits (D4-D7)
 *
 * 8 bit mode can send data directly in one stroke since we used all 8 data lines
 *
 * Yes, 8 bit mode is much faster and reliable than 4 bit but exhaust too many pins
 * thus we commonly use the 4 bit more often*/