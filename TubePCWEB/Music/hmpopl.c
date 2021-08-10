#ifndef NOALLOC
#include <stdlib.h>
#endif
#include <stdint.h>
#include <string.h>

#include "hmpopl.h"
//int opl_log = 0;

static int v_op[][2] = {{0, 3}, {1, 4}, {2, 5}, {8, 0xb}, {9, 0xc}, {0xa, 0xd}, {0x10, 0x13}, {0x11, 0x14}, {0x12, 0x15} };

static int velvol_vol[] = {
	0x3F, 0x3A, 0x35, 0x30, 0x2C, 0x29, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1F, 0x1E, 0x1D, 0x1C,
	0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0E, 0x0D,
	0x0D, 0x0C, 0x0C, 0x0B, 0x0B, 0x0A, 0x0A, 0x09, 0x09, 0x08, 0x08, 0x07, 0x07, 0x06, 0x06, 0x06,
	0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00};

static int notefnum[] = {
0,0,0,0,0,0,0,0,0,0,0,0,
343, 363, 385, 408, 432, 458, 485, 514, 544, 577, 611,
647, 1367, 1387, 1409, 1432, 1456, 1482, 1509, 1538,
1568, 1601, 1635, 1671, 2391, 2411, 2433, 2456, 2480,
2506, 2533, 2562, 2592, 2625, 2659, 2695, 3415, 3435,
3457, 3480, 3504, 3530, 3557, 3586, 3616, 3649, 3683,
3719, 4439, 4459, 4481, 4504, 4528, 4554, 4581, 4610,
4640, 4673, 4707, 4743, 5463, 5483, 5505, 5528, 5552,
5578, 5605, 5634, 5664, 5697, 5731, 5767, 6487, 6507,
6529, 6552, 6576, 6602, 6629, 6658, 6688, 6721, 6755,
6791, 7511, 7531, 7553, 7576, 7600, 7626, 7653, 7682,
7712, 7745, 7779, 7815, 7854, 7863, 7938, 7984, 8032,
8084
};
static int octfnum[] = { 324, 306, 289, 272, 257, 248, 229, 216, 204, 193, 182, 172 };

#pragma pack(push,1)

struct bnkins {
	uint8_t field_00;
	uint8_t field_01;
	uint8_t op0_ksl;
	uint8_t op0_fmult;
	uint8_t feedback;
	uint8_t op0_attack;
	uint8_t op0_sustain;
	uint8_t op0_envgain;
	uint8_t op0_decay;
	uint8_t op0_release;
	uint8_t op0_outlevel;
	uint8_t op0_am; 
	uint8_t op0_vib;
	uint8_t op0_ksr;
	uint8_t con;
	uint8_t op1_ksl;
	uint8_t op1_fmult;
	uint8_t field_11;
	uint8_t op1_attack;
	uint8_t op1_sustain;
	uint8_t op1_envgain;
	uint8_t op1_decay;
	uint8_t op1_release;
	uint8_t op1_outlevel;
	uint8_t op1_am;
	uint8_t op1_vib;
	uint8_t op1_ksr;
	uint8_t field_1b;
	uint8_t op0_ws;
	uint8_t op1_ws;
};
//} __attribute__((packed));

struct bnkhdr {
    uint8_t major;
    uint8_t minor;
    char sig[6];
    uint16_t num_ins;
    uint16_t num_used;
    uint32_t offset_name;
    uint32_t offset_data;
    uint8_t pad[8];
};
//} __attribute__((packed));

struct bnkdesc {
    uint16_t index;
    uint8_t flags;
    char name[9];
};
//} __attribute__((packed));

#pragma pack(pop)

enum oplri {
	oplri_connsel  = 0x04,
	oplri_new      = 0x05,
	oplri_freq     = 0x20,
	oplri_vol      = 0x40,
	oplri_attdec   = 0x60,
	oplri_sustrel  = 0x80,
	oplri_fnum     = 0xa0,
	oplri_key      = 0xb0,
	oplri_drum     = 0xbd,
	oplri_chfb     = 0xc0,
	oplri_ws       = 0xe0
};

static void parsebnk(struct oplins *ins, const struct bnkins *bnk) {
    ins->op0_freq = (bnk->op0_am << 7) | (bnk->op0_vib << 6) | (bnk->op0_envgain << 5) | (bnk->op0_ksr << 4) |
        bnk->op0_fmult;
    ins->op0_vol = (bnk->op0_ksl << 6) | bnk->op0_outlevel;
    ins->op0_attdec = (bnk->op0_attack << 4) | bnk->op0_decay;
    ins->op0_sustrel = (bnk->op0_sustain << 4) | bnk->op0_release;
    ins->chfb = bnk->con | (bnk->feedback << 1);
    ins->op1_freq = (bnk->op1_am << 7) | (bnk->op1_vib << 6) | (bnk->op1_envgain << 5) | (bnk->op1_ksr << 4) |
        bnk->op1_fmult;
    ins->op1_vol = (bnk->op1_ksl << 6) | bnk->op1_outlevel;
    ins->op1_attdec = (bnk->op1_attack << 4) | bnk->op1_decay;
    ins->op1_sustrel = (bnk->op1_sustain << 4) | bnk->op1_release;
    ins->op0_ws = bnk->op0_ws;
    ins->op1_ws = bnk->op1_ws;
}

//extern int printf(const char *format, ...);
static int loadbnk(struct oplins *ins, const void *data, int size) {
    const struct bnkhdr *bnkhdr = data;
    const struct bnkdesc *bnkdesc;
    const struct bnkins *bnkins;
    int num, i;
    if (size < sizeof(bnkhdr))
        return -1;
    if (memcmp(bnkhdr->sig, "ADLIB-", 6) &&
        memcmp(bnkhdr->sig, "AMLIB-", 6) &&
        memcmp(bnkhdr->sig, "ANLIB-", 6))
        return -1;
    num = bnkhdr->num_ins;
    if (memcmp(bnkhdr->sig, "AMLIB-", 6) && num == 128 && size == 5404)
        num--;
    if (size < bnkhdr->offset_name + num * sizeof(bnkdesc) || size < bnkhdr->offset_data)
        return -1;
    bnkdesc = (const struct bnkdesc *)((const uint8_t *)data + bnkhdr->offset_name);
    bnkins = (const struct bnkins *)((const uint8_t *)data + bnkhdr->offset_data);
    for (i = 0; i < num; i++) {
        int idx = bnkdesc[i].index;
        if (bnkhdr->offset_data + (idx + 1) * sizeof(bnkins) > size)
            return -1;
        parsebnk(&ins[i], &bnkins[idx]);
        ins[i].flags = bnkdesc[i].flags;
    }
    /*
    printf("loaded %d ins\n", num);
    printf("0{f=%02x v=%02x ad=%02x sr=%02x cf=%02x} 1{f=%02x 
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
                                                    
    */
    return 0;
}        

#ifndef opl_write
static void opl_write(hmpopl *h, int idx, int reg, int val) {
    //if (opl_log)
    //    //printf("%d.%02x = %02x\n", idx, reg, val);
    h->write(/*h->write_data,*/ idx, reg, val);
}
#endif

static void opl_write_both(hmpopl *h, int reg, int val) {
    opl_write(h, 0, reg, val);
    opl_write(h, 1, reg, val);
}

static void opl_write_both_rev(hmpopl *h, int reg, int val) {
	opl_write(h, 1, reg, val);
	opl_write(h, 0, reg, val);
}

static void opl_init(hmpopl *h) {
    opl_write(h, 1, oplri_new, 1);
    opl_write(h, 1, oplri_connsel, 0);
}

static void opl_clear(hmpopl *h) {
    int v;
	for (v = 0; v < 9; v++) {
		h->oplreg_key[v] = 0;
		opl_write_both(h, oplri_key + v, h->oplreg_key[v]);
	}
	opl_write(h, 0, oplri_drum, 0);
}

static void v_noteoff(hmpopl *h, int v) {
	if (!h->v_note[v])
		return;
	h->oplreg_key[v] &= ~0x20;
	opl_write_both(h, oplri_key + v, h->oplreg_key[v]);
    h->v_note[v] = 0;
	return;
}

static void v_noteoffon(hmpopl *h, int v, int fnum) {
    h->oplreg_fnum[v] = fnum & 0xff;
    if (v <= 5) // reproduce array overflow bug
        h->op_sustrel[v + 0x10] = h->oplreg_fnum[v];
    h->oplreg_key[v] = (fnum >> 8) | 0x20;
    opl_write_both(h, oplri_fnum + v, h->oplreg_fnum[v]);
    opl_write_both(h, oplri_key + v, h->oplreg_key[v] & ~0x20);
    opl_write_both(h, oplri_key + v, h->oplreg_key[v]);
}

static void v_noteon(hmpopl *h, int v, int fnum) {
    h->oplreg_fnum[v] = fnum & 0xff;
    if (v <= 5) // reproduce array overflow bug
        h->op_sustrel[v + 0x10] = h->oplreg_fnum[v];
    h->oplreg_key[v] = (fnum >> 8) | 0x20;
    opl_write_both(h, oplri_fnum + v, h->oplreg_fnum[v]);
    opl_write_both(h, oplri_key + v, h->oplreg_key[v]);
}

static void v_alloff(hmpopl *h) {
    int v;
	opl_write(h, 0, 0xbd, 0);
	for (v = 0; v < 9; v++)
		opl_write_both(h, oplri_key + v, h->oplreg_key[v] & 0xdf);
	for (v = 0; v < 9; v++)
		opl_write_both(h, oplri_vol + v_op[v][1], 0xff);
}

static void opl_done(hmpopl *h) {
    opl_write(h, 1, oplri_new, 0);
}

static int calcvol(hmpopl *h, int op, int velvol) {
	int volreg = h->op_basevol[op] & 0x3f;
	int nvol = (64 - velvol_vol[velvol >> 1]) << 1;
	nvol = (64 - volreg) * nvol;
	nvol = (8192 - nvol) >> 7;
	return (h->op_basevol[op] & 0xc0) | nvol;
}

static int v_get_velvol(hmpopl *h, int v) {
    int vol = h->ch_vol[h->v_ch[v]];    
	return (((vol << 7) / 127) * h->v_velo[v]) >> 7;
}

static void v_setvelvol(hmpopl *h, int v, int subop, int velvol, int nopan, int revpan) {
    int op = v_op[v][subop];
    int volreg = calcvol(h, op, velvol);
	if (nopan) {
		opl_write_both(h, 0x40 + op, volreg);
	} else if ((h->ch_pan[h->v_ch[v]] < 64) ^ revpan)
		opl_write(h, 0, 0x40 + op, volreg);
	else
		opl_write(h, 1, 0x40 + op, volreg);
}

static void v_setins(hmpopl *h, int v, struct oplins *ins) {
	int op = v_op[v][0];
	int op1 = v_op[v][1];
	h->op_sustrel[op] = ins->op0_sustrel;
	h->op_sustrel[op1] = ins->op1_sustrel;
	h->op_basevol[op] = ins->op0_vol;
	h->op_basevol[op1] = ins->op1_vol;
	
	//opl_log = 1;
	opl_write_both(h, oplri_freq + op, ins->op0_freq);
	opl_write_both(h, oplri_vol + op, ins->op0_vol);
	opl_write_both(h, oplri_attdec + op, ins->op0_attdec);
	opl_write_both(h, oplri_sustrel + op, ins->op0_sustrel);
	
	opl_write(h, 0, oplri_chfb + v, (ins->chfb & 0x1f) | 0x20);
	opl_write(h, 1, oplri_chfb + v, (ins->chfb & 0x1f) | 0x10);
	
	opl_write_both(h, oplri_ws + op, ins->op0_ws);
	
	opl_write_both(h, oplri_freq + op1, ins->op1_freq);
	opl_write_both(h, oplri_attdec + op1, ins->op1_attdec);
	opl_write_both(h, oplri_sustrel + op1, ins->op1_sustrel);
	opl_write_both(h, oplri_ws + op1, ins->op1_ws);
	//opl_log = 0;
}


static void ch_setpan(hmpopl *h, int ch, int pan) {
    int v;
	h->ch_pan[ch] = pan;
	int abspan = pan;
	if (abspan >= 64)
		abspan = 127 - abspan;
	abspan *= 2;
	for (v = 0; v < 9; v++) {
		if (!h->v_note[v] || h->v_ch[v] != ch)
			continue;
		int velvol = (v_get_velvol(h, v) * abspan) >> 7;
       	v_setvelvol(h, v, 1, velvol, 0, 1);
		if (h->melodic[h->ch_prog[ch]].chfb & 1)
			v_setvelvol(h, v, 0, velvol, 0, 1);
	}
}

static void v_setvol(hmpopl *h, int v) {
	int velvol = v_get_velvol(h, v);
	if (h->melodic[h->ch_prog[h->v_ch[v]]].chfb & 1)
		v_setvelvol(h, v, 0, velvol, 0, 0);
	v_setvelvol(h, v, 1, velvol, 0, 0);
}

static void ch_setvol(hmpopl *h, int ch, int vol) {
    int v;
	if (ch >= 16)
		return;
	h->ch_vol[ch] = vol;
	for (v = 0; v < 9; v++)
		if (h->v_note[v] && h->v_ch[v] == ch)
    		v_setvol(h, v);

	ch_setpan(h, ch, h->ch_pan[ch]);
}

static void ch_noteoff(hmpopl *h, int ch, int note, int velo) {
    int v;
    if (h->ch_sust[ch] && h->ch_sust_idx[ch] < 32) {
        h->ch_sustnotes[ch][h->ch_sust_idx[ch]++] = note;
        return;
    }
    for (v = 0; v < 9; v++)
        if (h->v_note[v] == note && h->v_ch[v] == ch)
            v_noteoff(h, v);
}

static int pitchnote_to_fnum(int pitch, int note, int rng) {
	int noteinoct = note % 12;
	int fnumbl = notefnum[note];
	int fbl = fnumbl & 0x1c00;
	int fnum = fnumbl & 0x3ff;
	if (pitch < 64) {
		int pitchofs = ((63 - pitch) * 1000) >> 6;
		int fnumrng = fnumbl - notefnum[note - rng];
		if (fnumrng > 719)
		    fnumrng = (fnum - octfnum[rng - 1]) & 0x3ff;
		return fnumbl - (fnumrng * pitchofs) / 1000;
	} else {
		int pitchofs = ((pitch - 64) * 1000) >> 6;
		int fnumrng = notefnum[note + rng] - fnumbl;
		if (fnumrng > 719) {
		    fbl += 0x400;
		    fnum = octfnum[11 - noteinoct];
		    fnumbl = fnum | fbl;
		    fnumrng = notefnum[note + rng] - fnumbl;
        }
		return fnumbl + (fnumrng * pitchofs) / 1000;
	}
}

static void v_noteon_setvol(hmpopl *h, int v) {
	int op0 = v_op[v][0], op1 = v_op[v][1];
	if (h->melodic[h->ch_prog[h->v_ch[v]]].chfb & 1)
    	opl_write_both_rev(h, oplri_vol + op0, calcvol(h, op0, v_get_velvol(h, v)));
   	opl_write_both_rev(h, oplri_vol + op1, calcvol(h, op1, v_get_velvol(h, v)));
}

static int findvoice(hmpopl *h, int orgch) {
    int v, ch;
	for (v = 0; v < 9; v++)
		if (!h->v_note[v])
			return v;

	for (ch = 0; ch < 16; ch++)
		if (!h->ch_pitched[ch])
			for (v = 0; v < 9; v++)
				if (h->v_ch[v] == ch)
					return v;

	return orgch >= 9 ? orgch - 9 : orgch;
}

static void ch_noteondrum(hmpopl *h, int ch, int note, int velo) {
	int v = findvoice(h, ch);
	int i;
	v_noteoff(h, v);
	h->v_ch[v] = ch;
	for (i = 0; i < 5; i++) {
		opl_write_both(h, oplri_sustrel + v_op[v][1], h->op_sustrel[v_op[v][1]] | 0x0f);
		opl_write_both(h, oplri_sustrel + v_op[v][0], h->op_sustrel[v_op[v][0]] | 0x0f);
	}
	v_setins(h, v, &h->drum[note]);
	h->v_velo[v] = velo;
	v_noteon_setvol(h, v);
	h->v_note[v] = note;
	ch_setpan(h, ch, h->ch_pan[ch]);
	v_noteoffon(h, v, notefnum[h->drum[note].flags]);
}

static void ch_noteon(hmpopl *h, int ch, int note, int velo) {
    int i;
	if (!velo) {
		ch_noteoff(h, ch, note, 0);
		return;
	}
	if (ch == 9) {
		ch_noteondrum(h, ch, note, velo);
		return;
	}
	int v = findvoice(h, ch);
	v_noteoff(h, v);
	h->v_ch[v] = ch;
	for (i = 0; i < 5; i++) {
		opl_write_both(h, oplri_sustrel + v_op[v][1], h->op_sustrel[v_op[v][1]] | 0x0f);
		opl_write_both(h, oplri_sustrel + v_op[v][0], h->op_sustrel[v_op[v][0]] | 0x0f);
	}
 	v_setins(h, v, &h->melodic[h->ch_prog[ch]]);
	h->v_velo[v] = velo;
	v_noteon_setvol(h, v);
	
	h->v_note[v] = note;
	ch_setpan(h, ch, h->ch_pan[ch]);
	v_noteoffon(h, v, notefnum[note]);
	if (h->ch_pitched[ch])
		v_noteon(h, v, pitchnote_to_fnum(h->ch_pitch[ch], note, h->ch_pitchrng[ch]));
}

static void ch_reset(hmpopl *h, int ch) {
	h->ch_vol[ch] = 127;
	h->ch_sust[ch] = 0;
	h->ch_pitch[ch] = 64;
	h->ch_pitchrng[ch] = 2;
}

static void initdata(hmpopl *h) {
    int v, ch;
    for (v = 0; v < 9; v++) {
        h->v_note[v] = 0;
        h->v_ch[v] = 0;
        h->v_velo[v] = 127;
        //h->oplreg_key[v] = 0;
        //h->oplreg_fnum[v] = 0;
    }
    for (ch = 0; ch < 16; ch++) {
        h->ch_pitch[ch] = 64;
        h->ch_prog[ch] = 0;
        h->ch_pitched[ch] = 0;
        h->ch_vol[ch] = 127;
        h->ch_pan[ch] = 64;
        //ch_volset[ch] = 0;
        //ch_panset[ch] = 0;
        h->ch_sust_idx[ch] = 0;
        h->ch_pitchrng[ch] = 2;
        //h->ch_sust[ch] = 0;
    }
    //memset(h->op_basevol, 0, sizeof(h->op_basevol));
    //memset(h->op_sustrel, 0, sizeof(h->op_sustrel));
    //memset(h->ch_sustnotes, 0, sizeof(h->ch_sustnotes));
}

static void ch_setprog(hmpopl *h, int ch, int prog) {
	h->ch_prog[ch] = prog;
}

static void ch_setsust(hmpopl *h, int ch, int sust) {
	h->ch_sust[ch] = sust;
	if (!sust)
		while (h->ch_sust_idx[ch])
			ch_noteoff(h, ch, h->ch_sustnotes[ch][--h->ch_sust_idx[ch]], 0);
}

static void ch_setpitch(hmpopl *h, int ch, int pitch) {
    int v;
	if (ch == 9)
		return;
	h->ch_pitch[ch] = pitch;
	h->ch_pitched[ch] = 1;
	for (v = 0; v < 9; v++)
		if (h->v_note[v] && h->v_ch[v] == ch)
			v_noteon(h, v, pitchnote_to_fnum(pitch, h->v_note[v], h->ch_pitchrng[ch]));
}

static void ch_cntr(hmpopl *h, int ch, int cntr, int param) {
	switch (cntr) {
		case 0x40:
			ch_setsust(h, ch, param);
			break;
		case 0x79:
			ch_reset(h, ch);
			break;
		case 0x7b:
			v_alloff(h);
			break;
		case 0x66:
			h->ch_pitchrng[ch] = param;
			break;
		case 0x7:
			ch_setvol(h, ch, param);
			break;
		case 0x0a:
			ch_setpan(h, ch, param);
			break;
	}
}

void hmpopl_play_midi(hmpopl *h, int event, int ch, int param1, int param2) {
	if (ch < 0 || ch >= 16)
		return;
	switch (event) {
		case 8:
			ch_noteoff(h, ch, param1, param2);
			break;
		case 9:
		    ch_noteon(h, ch, param1, param2);
		    break;
        case 0xb:
            ch_cntr(h, ch, param1, param2);
            break;
        case 0xc:
            ch_setprog(h, ch, param1);
            break;
        case 0xe:
            ch_setpitch(h, ch, param2);
            break;
	}
}


#ifndef NOALLOC
hmpopl *hmpopl_new(void) {
	return calloc(1, sizeof(hmpopl));
}

void hmpopl_done(hmpopl *h) {
	#ifndef opl_write
	if (h->write)
	#endif
		opl_done(h);
	free(h);
}
#endif

int hmpopl_set_bank(hmpopl *h, const void *data, int size, int isdrum) {
    return loadbnk(isdrum ? h->drum : h->melodic, data, size);
}

//void hmpopl_set_song(hmpopl *h, const void *data, int size, int dofree) {
//}

void hmpopl_set_write_callback(hmpopl *h, hmpopl_write_callback c/*, void *data*/) {
    h->write = c;
//    h->write_data = data;
}

void hmpopl_start(hmpopl *h) {
	opl_init(h);
	opl_clear(h);
	opl_clear(h);
	initdata(h);
}

void hmpopl_reset(hmpopl *h) {
	opl_clear(h);
	initdata(h);
}
