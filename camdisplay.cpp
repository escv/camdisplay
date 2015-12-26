#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "raspicam_still.h"
#include "tft.h"
#include "RAIO8870.h"

using namespace std;

int main( int argc, char **argv )
{	
	raspicam::RaspiCam_Still Camera; //Cmaera object
    
    int width = 320;
    int height = 240;

    Camera.setEncoding ( raspicam::RASPICAM_ENCODING_RGB );

    Camera.setWidth(width);
    Camera.setISO(400);
    Camera.setHeight(height);

    //Open camera
    cout<<"Opening Camera..."<<endl;
    
    if ( !Camera.open()) {
        cerr<<"Error opening camera"<<endl;
        return -1;
    }

    //wait a while until camera stabilizes
    sleep(1);
    
    unsigned int length = Camera.getImageBufferSize();
    unsigned char *data=new unsigned char[ length ];

	Camera.grab_retrieve ( data , length);

	if (!bcm2835_init())
		return 1;

	uint16_t* pic = new uint16_t[length/3];
	uint16_t color;
	uint8_t red, green, blue;
	int z = 0;

	for (int i=0; i<length; i=i+3) {
		red = data[i];
		green = data[i+1];
		blue = data[i+2];

		color = (red >> 3);
		color = color << 6;
		color = color | (green >> 2);
		color = color << 5;
		color = color | (blue >> 3);	

		pic[z++] = color;
	}

	TFT_init_board();
	TFT_hard_reset();
	RAIO_init();
	RAIO_clear_screen();
	RAIO_Write_Picture ( pic, PICTURE_PIXELS );

	sleep(2);

	bcm2835_close();

	return 0;
}
