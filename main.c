#include "lightlog.h"
#include "light/light.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define __LIGHT_PC_SIMULATION__

int main(void) {
	
	Light *weatherLighting = LightInit();
	
	if (weatherLighting && weatherLighting->status(1) == LIGHT_STATUS_OK)
		printf("DISPOSITIVO DE MEDIDA DE ILUMINACAO INICIALIZADO CORRETAMENTE.\n");
	
	unsigned char sensor = 0;
	for(;;) {
		if((weatherLighting->measure(0) != LIGHT_STATUS_OK) || (weatherLighting->measure(1) != LIGHT_STATUS_OK))
			printf("ERRO DURANTE A LEITURA !\n");
						
		printf("VALOR SENSOR [%d] [%f] MEDIA[%f]\n", sensor, weatherLighting->value(sensor), weatherLighting->average(sensor));
	
		#ifdef __LIGHT_PC_SIMULATION__
		sleep(1);
		#endif
		
		sensor++;
		(sensor == 2) ? sensor = 0 : 0;
	}
	
	return 0;
}
