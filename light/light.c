#include "light/light.h"
#include "lightdriverlayer.h"

//INICIALIZA A ESTRUTURA QUE CONTÉM OS MÉTODOS UTILIZADOS
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
 * Função para inicializar o módulo de medida de intensidade de luz
 * Aqui inicializamos os objetos (variáveis) necessários para o nosso sub-sistema de leitura de intensidade de luz
 */
Light *LightInit(void)
{	
	LightInitHardware();
		 
	return &light;
}


