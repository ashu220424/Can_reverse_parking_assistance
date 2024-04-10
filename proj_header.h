typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef signed char s8;

extern void delay_sec(unsigned int, unsigned int);
extern void delay_ms(unsigned int, unsigned int);

extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern void uart0_tx_string(s8 *);
extern u8 uart0_rx(void);
extern void uart0_ascii(u8);
extern void uart0_hex(u8);
extern void uart0_tx_int(s32);
extern void uart0_tx_float(float);
extern void uart0_rx_string(s8 *, s32);

extern void us_init(void);
void send_pulse(void);
unsigned int get_range(void);

extern void can2_init(void);
typedef struct CAN2_MSG
{
    u32 id;
    u32 dlc;
    u32 rtr;
    u32 byteB;
    u32 byteA;
} CAN2;
extern void can2_tx(CAN2);
extern void can2_rx(CAN2 *ptr);
extern void uart0_can_hex(s32 num);

extern void en_CAN_intr(void);
extern void config_vic(void);
