#include "lightdriveruno.h"

static LightDriverStatus DriverUnoInit(void *initdata);
static LightDriverStatus DriverUnoFinalize(void *enddata);
static LightDriverStatus DriverUnoMeasure(void);
static float DriverUnoValue(void);
static float DriverUnoAverage(void);

static LightDriver LightDriverUno = {
										.init 		= DriverUnoInit,
										.finalize 	= DriverUnoFinalize,
										.measure 	= DriverUnoMeasure,
										.value 		= DriverUnoValue,
										.average 	= DriverUnoAverage,
									};
static short driverID = -1;

LightDriver *
GetLightDriverUno(void)
{
	return &LightDriverUno;
}

static LightDriverStatus
DriverUnoInit(void *initdata)
{
	if(initdata) {
		driverID = *(short *)initdata;
	}
}

static LightDriverStatus
DriverUnoFinalize(void *enddata)
{
	
}

static LightDriverStatus
DriverUnoMeasure(void)
{
	//TODO
	///* FAZ TER O COMPORTAMENTO DE BUFFER CIRCULAR */
	//LightPrivateObject.value_posit_now++;
	//if (LightPrivateObject.value_posit_now >= LIGHT_VALUES_BUFFER_SIZE)
	//	LightPrivateObject.value_posit_now = 0;
	//
	///*POR ENQUANTO NESTA SIMULAÇÃO A ILUMINAÇÃO FICA CONSTANTEMENTE NO MEIO DA ESCALA DE 16 BITS,
	//  DEPOIS PODEMOS PENSAR EM ALGO MAIS INTERESSANTE*/	
	//LightPrivateObject.values[LightPrivateObject.value_posit_now] = 0x8000; 
	//	
	///* NO NOSSO CASO SIMULADO NUNCA OCORRERÁ ERRO E A LEITURA SERÁ SEMPRE RESULTARÁ EM LIGHT_STATUS_OK */
	//return (LightPrivateObject.status = LIGHT_STATUS_OK);	
	
	return LIGHT_DRIVER_STATUS_OK;
}

static float
DriverUnoValue(void)
{
	return 0.0;
}

static float
DriverUnoAverage(void)
{
	return 0.0;
}

