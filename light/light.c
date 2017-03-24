#include "light/light.h"
#include "lightdriverlayer.h"

//INICIALIZA A ESTRUTURA QUE CONT�M OS M�TODOS UTILIZADOS
static Light light = {	
						.status		= GetLightStatus, 
						.set_unit	= LightSetUnit, 
						.get_unit	= LightGetUnit, 
						.measure	= LightMeasure, 
						.value		= LightValue, 
						.average	= LightAverage,
						.sensors_count = LightSensorsCount,
					 };

/**
 * LightInit(void)
 *
 * Fun��o para inicializar o m�dulo de medida de intensidade de luz
 * Aqui inicializamos os objetos (vari�veis) necess�rios para o nosso sub-sistema de leitura de intensidade de luz
 */
Light *LightInit(void)
{	
	LightInitHardware();
		 
	return &light;
}


