#ifndef __LIGHT_DRIVER_LAYER_H__
#define __LIGHT_DRIVER_LAYER_H__

#include "light/light.h"

#ifndef __LIGHT_PC_SIMULATION__
#define __LIGHT_PC_SIMULATION__
#endif

/* FUNÇÕES/MÉTODOS */

LightStatus	GetLightStatus(uchar ndev);
void LightSetUnit(LightUnit unit);
uchar LightSensorsCount(void);
LightUnit LightGetUnit(void);
LightStatus LightMeasure(ushort dev);
float LightValue(ushort dev);
float LightAverage(ushort dev);

#endif //__LIGHT_DRIVER_LAYER_H__
