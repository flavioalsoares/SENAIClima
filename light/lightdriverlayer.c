#include "light/light.h"
#include "lightdriverlayer.h"
#include "lightdriver.h"
#include "lightdriveruno.h"
#include "lightdriverdue.h"

#define LIGHT_VALUES_BUFFER_SIZE 16
#define LIGHT_SENSOR_COUNT 2


struct _LightPrivate {
	LightStatus status;
	float intensidade;
	LightUnit unidade;
	unsigned short value_posit_now;
	int values[LIGHT_VALUES_BUFFER_SIZE];
	LightDriver *sensor[LIGHT_SENSOR_COUNT];	
};
typedef struct _LightPrivate LightPrivate;

//INICIALIZA A ESTRUTURA PRIVADA QUE CONTÉM OS ATRIBUTOS UTILIZADOS PELO NOSSO SISTEMA
static LightPrivate LightPrivateObject = {
											.status = LIGHT_STATUS_OK, 
											.intensidade = 0.0000000,
											.unidade = LIGHT_UNIT_CANDELA_CD,
											.value_posit_now = 0
										 };


/* FUNÇÕES/MÉTODOS */

/* ******************************************************************************************** */
/* AQUI FICAM AS FUNÇÕES COMUNS A TODAS AS PLATAFORMAS */
static LightStatus LightInitHWCommon(void)
{
	unsigned short i;
	for (i = 0; i < LIGHT_VALUES_BUFFER_SIZE; i++)
		 LightPrivateObject.values[i] = 0;
		 
	LightPrivateObject.sensor[0] = GetLightDriverUno();
	LightPrivateObject.sensor[1] = GetLightDriverDue();
	
	for (i = 0; i < LIGHT_SENSOR_COUNT; i++) {
		LightDriverStatus drvstatus;
		 /*PASSAMOS PARA CADA DRIVER A SUA IDENTIFICAÇÃO QUE É O CONTADOR DE POSIÇÃO DO ARRAY 
		 (PODERIA SER QUALQUER OUTRA INFORMAÇÃO, DESDE QUE PADRONIZADA)*/
		 drvstatus = LightPrivateObject.sensor[0]->init((void *)&i);
		 if (drvstatus != LIGHT_DRIVER_STATUS_OK) {
		 	 LightPrivateObject.status = LIGHT_STATUS_HW_ERR;
		 }
	}
		
	return LightPrivateObject.status;
}

LightStatus	GetLightStatus(uchar ndev)
{
	return LightPrivateObject.status;
}

void LightSetUnit(LightUnit unit)
{
	LightPrivateObject.unidade = unit;	
}

LightUnit LightGetUnit(void)
{
	return LightPrivateObject.unidade;
}

uchar LightSensorsCount(void)
{
	return LIGHT_SENSOR_COUNT;
}
/* ******************************************************************************************** */

LightStatus LightInitHardware(void)
{
	LightStatus init_status = LightInitHWCommon();
	
	return (LightPrivateObject.status = init_status);
}

/**
 * LightStatus LightMeasure()
 *
 * Efetivamente faz o acesso ao hardware de medida de intensidade de luz e armazena para posterior processamento
 * 
 * @return LIGHT_STATUS_OK se a leitura foi correta, outro valor em caso de falha
 **/
LightStatus LightMeasure(ushort dev)
{
	LightStatus mystatus = LIGHT_STATUS_OK;
	LightDriverStatus drvstatus;
	
	LightDriver *drv = LightPrivateObject.sensor[dev];
	if (drv)
		drvstatus = drv->measure();
	else
		mystatus = LIGHT_DRIVER_STATUS_HW_ERR;
		
	return mystatus;

}

float LightValue(ushort dev)
{
	float val = 0.0;
	LightDriver *drv = LightPrivateObject.sensor[dev];
	if (drv)
		val = drv->value();
	
	return val;
}

float LightAverage(ushort dev)
{
	float aver = 0.0;
	LightDriver *drv = LightPrivateObject.sensor[dev];
	if (drv)
		aver = drv->average();
	
	return aver;
}


