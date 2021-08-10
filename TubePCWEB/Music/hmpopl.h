#ifndef HMPOPL_H_
#define HMPOPL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
typedef void (*hmpopl_write_callback)(/*void *data,*/ int index, int reg, int val);

struct oplins {
	uint8_t op0_freq;
	uint8_t op0_vol;
	uint8_t op0_attdec;
	uint8_t op0_sustrel;
	uint8_t chfb;
	uint8_t op1_freq;
	uint8_t op1_vol;
	uint8_t op1_attdec;
	uint8_t op1_sustrel;
	uint8_t flags;
	uint8_t op0_ws;
	uint8_t op1_ws;
};

struct hmpopl {
	hmpopl_write_callback write;
//	void *write_data;
	struct oplins melodic[128];
	struct oplins drum[128];

    int v_velo[9];
    int v_ch[9];
    int v_note[9];

    int op_basevol[32];
    int op_sustrel[32];

    int ch_pan[16];
    int ch_vol[16];
    int ch_prog[16];
    int ch_sust[16];
    int ch_pitch[16];
    int ch_pitched[16];
    int ch_pitchrng[16];
    int ch_sust_idx[16];

    uint8_t ch_sustnotes[16][32];

    uint8_t oplreg_key[9];
    uint8_t oplreg_fnum[9];
};

typedef struct hmpopl hmpopl;
hmpopl *hmpopl_new();
void hmpopl_done(hmpopl *h);
int hmpopl_set_bank(hmpopl *h, const void *data, int size, int isdrum);
//void hmpopl_set_song(hmpopl *h, const void *data, int size);
void hmpopl_set_write_callback(hmpopl *h, hmpopl_write_callback c/*, void *data*/);
void hmpopl_play_midi(hmpopl *h, int event, int ch, int param1, int param2);
void hmpopl_start(hmpopl *h);
void hmpopl_reset(hmpopl *h);

#ifdef __cplusplus
}
#endif

#endif
