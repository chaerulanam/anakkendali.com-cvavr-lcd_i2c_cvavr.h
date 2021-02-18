/*ditulis oleh kang chaerul anam
*kunjungi web nya di www.anakkendali.com
* November 2018
*/



#ifndef _LCD_I2C_CVAVR_INCLUDED_
#define _LCD_I2C_CVAVR_INCLUDED_

#define SETBUSS 0x10

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define En 0b00000100  // Enable bit
#define Rw 0b00000010  // Read/Write bit
#define Rs 0b00000001  // Register select bit

#include <stdint.h>



#pragma used+

void i2c_begin (void);
unsigned char i2c_send_start (void);
void i2c_send_stop (void);

unsigned char i2c_send_add_rw (unsigned char address, unsigned char rw);
unsigned char i2c_send_byte (unsigned char byte);
unsigned char i2c_read_byte (void);
unsigned char i2c_get_inputs (unsigned char address);
void i2c_set_outputs (unsigned char address, unsigned char byte);

void lcd_begin(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

	 /**
	  * Remove all the characters currently shown. Next print/write operation will start
	  * from the first position on LCD display.
	  */
void lcd_clear();

	/**
	 * Next print/write operation will will start from the first position on the LCD display.
	 */
void lcd_home();

	 /**
	  * Do not show any characters on the LCD display. Backlight state will remain unchanged.
	  * Also all characters written on the display will return, when the display in enabled again.
	  */
void lcd_noDisplay();

	/**
	 * Show the characters on the LCD display, this is the normal behaviour. This method should
	 * only be used after noDisplay() has been used.
	 */
void lcd_display();

	/**
	 * Do not blink the cursor indicator.
	 */
void lcd_noBlink();

	/**
	 * Start blinking the cursor indicator.
	 */
void lcd_blink();

	/**
	 * Do not show a cursor indicator.
	 */
void lcd_noCursor();

	/**
 	 * Show a cursor indicator, cursor can blink on not blink. Use the
	 * methods blink() and noBlink() for changing cursor blink.
	 */
void lcd_cursor();

void lcd_scrollDisplayLeft();
void lcd_scrollDisplayRight();
void lcd_leftToRight();
void lcd_rightToLeft();
void lcd_autoscroll();
void lcd_noAutoscroll();
void lcd_gotoxy(uint8_t, uint8_t);
unsigned char lcd_write(uint8_t);
void lcd_print(char *str);
void lcd_command(uint8_t);

	// private:
void send(uint8_t, uint8_t);
void write4bits(uint8_t);
void expanderWrite(uint8_t);
void pulseEnable(uint8_t);

#pragma used-

#pragma library lcd_i2c_cvavr.lib

#endif