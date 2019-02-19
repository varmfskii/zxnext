/* range */
#define XMAX 255
#define XMIN 0
#define YMAX 191
#define YMIN 0
/* drawing modes */
#define UNSET 1
#define XSET 3
#define SET 2
#define DMODE (SET|UNSET)
#define FG 4
#define BG 8
#define INK (SET|FG)
#define PAPER (UNSET|BG)
/* colors */
#define BLACK 0
#define RED 2
#define GREEN 4
#define BLUE 1
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define YELLOW (RED|GREEN)
#define WHITE (RED|GREEN|BLUE)
#define BRIGHT 8
#define FLASH 16
/* screen modes */
#define ULA 0
#define ALT 1
#define HICOL 2
#define HIRES 6
#define SM_MASK 7
#define ULAPAL 0x40
#define GRAY 0x80
#define LAYER2 7
/* base addresses */
#define B_PIXEL 0x4000
#define B_COLOR 0x5800
#define B_ALTP 0x6000
#define B_ALTC 0x7800
#define B_L2 0x0000
/* ports */
__sfr __at 0xFE P_ULA;
__sfr __at 0xFF P_TIMEXULA;
__sfr __at 0xF5 P_T_REGSEL;
__sfr __at 0xF6 P_T_REGIO;
__sfr __banked __at 0xBF3B P_P_REGSEL;
__sfr __banked __at 0xFF3B P_P_REGIO;
__sfr __banked __at 0x243B P_N_REGSEL;
__sfr __banked __at 0x253B P_N_REGIO;

typedef unsigned char UCHAR;

/* permit us to modify the bytes in an address */
typedef union address {
  UCHAR *a;
  struct hl {
    UCHAR l, h;
  } hl;
} address;

extern UCHAR ula_color, screen_mode, pixel_base, color_base;

void _hline(UCHAR x0, UCHAR x1, UCHAR y, UCHAR f);
void _line(UCHAR x0, UCHAR y0, UCHAR x1, UCHAR y1, UCHAR f);
void _set(UCHAR *a, UCHAR f, UCHAR m);
void _setbyte(UCHAR *a, UCHAR f);
void _setcolor(UCHAR x, UCHAR y, UCHAR m);
void _vline(UCHAR x, UCHAR y0, UCHAR y1, UCHAR f);
void background(UCHAR x, UCHAR y);
void circle(UCHAR xc, UCHAR yc, UCHAR r, UCHAR f);
void cls(void);
void disc(UCHAR xc, UCHAR yc, UCHAR r, UCHAR f);
void foreground(UCHAR x, UCHAR y);
void ink(UCHAR c);
void line(short x0, short y0, short x1, short y1, UCHAR f);
void paper(UCHAR c);
void set(UCHAR x, UCHAR y, UCHAR f);
void setmode(UCHAR m);
