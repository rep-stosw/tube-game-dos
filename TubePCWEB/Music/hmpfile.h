#ifndef _HMPFILE_H
#define _HMPFILE_H

#ifdef __cplusplus
extern "C" {
#endif

#define HMP_TRACKS 32
#define HMP_BUFFERS 4
#define HMP_BUFSIZE 1024

typedef struct hmp_event {
	unsigned int delta;
	unsigned char msg[3];
	const unsigned char *data;
	unsigned int datalen;
	int trk;
} hmp_event;

typedef struct hmp_track {
	const unsigned char *data;
	unsigned int len;
	const unsigned char *cur;
	unsigned int left;
	unsigned int cur_time;
	int prio;
} hmp_track;

typedef struct hmp_file {
	int num_trks;
	hmp_track trks[HMP_TRACKS];
	unsigned int cur_time;
	int tempo;
	int loop;
} hmp_file;


#define HMP_INVALID_FILE -1
#define HMP_OUT_OF_MEM -2
#define HMP_MM_ERR -3
#define HMP_EOF 1

hmp_file *hmp_open(const void *data, int size, int dev, int loop);
int hmp_init(hmp_file *hmp, const void *data, int size, int dev, int loop);
int hmp_play(hmp_file *hmp);
void hmp_close(hmp_file *hmp);
void hmp_reset_tracks(struct hmp_file *hmp);
int hmp_get_event(hmp_file *hmp, hmp_event *ev);

#ifdef __cplusplus
}
#endif

#endif
