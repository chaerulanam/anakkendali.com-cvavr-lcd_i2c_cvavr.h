#ifndef _WIRE_INCLUDED_
#define _WIRE_INCLUDED_

#define SETBUSS 0x10

#pragma used+

void wire_begin (void);
unsigned char wire_send_start (void);
void wire_send_stop (void);

unsigned char wire_send_add_rw (unsigned char address, unsigned char rw);
unsigned char wire_send_byte (unsigned char byte);
unsigned char wire_read_byte (void);
unsigned char wire_get_inputs (unsigned char address);
void wire_set_outputs (unsigned char address, unsigned char byte);

#pragma used-

#pragma library wire.lib

#endif