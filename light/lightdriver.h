#ifndef __LIGHT_DRIVER_H__
#define __LIGHT_DRIVER_H__

enum _LightDriverStatus {
	LIGHT_DRIVER_STATUS_OK,
	LIGHT_DRIVER_STATUS_HW_ERR,
};
typedef enum _LightDriverStatus LightDriverStatus;

struct _LightDriver {
	LightDriverStatus	(* init)	(void *initdata);
	LightDriverStatus	(* finalize)(void *enddata);
	LightDriverStatus	(* measure)	(void);
	float 				(* value)	(void);
	float				(* average)	(void);
}; 
typedef struct _LightDriver LightDriver;

#endif //__LIGHT_DRIVER_H__
