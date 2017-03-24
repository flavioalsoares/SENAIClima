#ifndef __LIGHT_H__
#define __LIGHT_H__

typedef unsigned char uchar;
typedef unsigned short ushort;

enum _LightStatus {
	LIGHT_STATUS_OK,
	LIGHT_STATUS_HW_ERR,
};
typedef enum _LightStatus LightStatus;

//http://www.eav.eng.br/tech/fisica/Unidadesdemedidadaluz.html
enum _LightUnit {
	LIGHT_UNIT_CANDELA_CD,
	LIGHT_UNIT_LUX_LX,
	LIGHT_UNIT_LUMEN_LM,
};
typedef enum _LightUnit LightUnit;

struct _Light {
	LightStatus		(* status) 	(uchar ndev);
	void			(* set_unit)(LightUnit unit);
	LightUnit 		(* get_unit)(void);
	LightStatus		(* measure)	(ushort dev);
	float 			(* value)	(ushort dev);
	float			(* average)	(ushort dev);
	uchar			(* sensors_count)(void);
}; 
typedef struct _Light Light;

Light *LightInit(void);

#endif //__LIGHT_H__
