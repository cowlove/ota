#BOARD=esp32doit-devkit-v1
#BOARD=heltec_wifi_kit_32
#BOARD=nodemcu-32s
#VERBOSE=1

CHIP=esp8266
BOARD=sonoff

OTA_ADDR=192.168.43.222
IGNORE_STATE=1

include ${HOME}/Arduino/makeEspArduino/makeEspArduino.mk

fixtty:
	stty -F ${UPLOAD_PORT} -hupcl -crtscts -echo raw 115200 

cat:	fixtty
	cat ${UPLOAD_PORT}


setap1:
	wget 'http://192.168.4.1/wifisave?s=Flora_2GEXT&p=maynards'




