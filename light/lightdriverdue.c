#include "lightdriver.h"

static LightDriverStatus DriverDueInit(void *initdata);
static LightDriverStatus DriverDueFinalize(void *enddata);
static LightDriverStatus DriverDueMeasure(void);
static float DriverDueValue(void);
static float DriverDueAverage(void);

static LightDriver LightDriverDue = {
										.init 		= DriverDueInit,
										.finalize 	= DriverDueFinalize,
										.measure 	= DriverDueMeasure,
										.value 		= DriverDueValue,
										.average 	= DriverDueAverage,
									};
static short driverID = -1;

LightDriver *
GetLightDriverDue(void)
{
	return &LightDriverDue;
}

static LightDriverStatus
DriverDueInit(void *initdata)
{
	if(initdata) {
		driverID = *(short *)initdata;
	}	
}

static LightDriverStatus
DriverDueFinalize(void *enddata)
{
	
}

static LightDriverStatus
DriverDueMeasure(void)
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
DriverDueValue(void)
{
	return 0.0;
}

static float
DriverDueAverage(void)
{
	return 0.0;
}

