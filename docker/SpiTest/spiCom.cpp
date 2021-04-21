// spiCom.cpp
//
// Configures Raspberry Pi as an SPI master and
// demonstrates bi-directional communication with
// an STM32 slave
//
// Source: http://robotics.hobbizine.com/raspiduino.html
//
// Run this program as root!

#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

using namespace std;

//----- Global variables -----//
int fd;
uint8_t sndStr[] = {'H', 'i', ' ', 'f', 'r', 'o', 'm', ' ', 'C', 'M', '4'};
uint8_t result;

//----- Function declaration -----//
uint8_t spiTxRx(uint8_t txData);

int main (void) {
	fd = open("/dev/spidev0.0", O_RDWR);

	uint32_t speed = 1000000;
	ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

	for (int i = 0; i < sizeof(sndStr); i++) {
		result = spiTxRx(sndStr[i]);
		cout << result;
	}
	
	return 0;
}

uint8_t spiTxRx(uint8_t txData) {
	uint8_t rxData;
	
	struct spi_ioc_transfer spi;

	memset(&spi, 0, sizeof(spi));

	spi.tx_buf = (unsigned long long)&txData;
	spi.rx_buf = (unsigned long long)&rxData;
	spi.len = 1;

	ioctl(fd, SPI_IOC_MESSAGE(1), &spi);

	return rxData;
}
