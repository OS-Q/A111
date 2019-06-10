
#ifndef __DHT11_H
#define __DHT11_H


#include "common.h"

//#define DHT11_DATA              P2_0

#define DHT11_ERR_CHECKSUM      1
#define DHT11_ERR_TIMEOUT       2


unsigned char dht11_read(unsigned char *out);


#endif /* __DHT11_H */
