#include <ILI9341.h>

#if defined(__PIC32__)

void ILI9341::command(uint8_t cmd) {
    _rs_port->lat.clr = _rs_mask;
    _cs_port->lat.clr = _cs_mask;

    if (cmd & 0x01) _d0_port->lat.set = _d0_mask; else _d0_port->lat.clr = _d0_mask;
    if (cmd & 0x02) _d1_port->lat.set = _d1_mask; else _d1_port->lat.clr = _d1_mask;
    if (cmd & 0x04) _d2_port->lat.set = _d2_mask; else _d2_port->lat.clr = _d2_mask;
    if (cmd & 0x08) _d3_port->lat.set = _d3_mask; else _d3_port->lat.clr = _d3_mask;
    if (cmd & 0x10) _d4_port->lat.set = _d4_mask; else _d4_port->lat.clr = _d4_mask;
    if (cmd & 0x20) _d5_port->lat.set = _d5_mask; else _d5_port->lat.clr = _d5_mask;
    if (cmd & 0x40) _d6_port->lat.set = _d6_mask; else _d6_port->lat.clr = _d6_mask;
    if (cmd & 0x80) _d7_port->lat.set = _d7_mask; else _d7_port->lat.clr = _d7_mask;

    _wr_port->lat.clr = _wr_mask;
    _wr_port->lat.set = _wr_mask;

    _cs_port->lat.set = _cs_mask;
}

void ILI9341::data(uint8_t dat) {
    _rs_port->lat.set = _rs_mask;
    _cs_port->lat.clr = _cs_mask;

    if (dat & 0x01) _d0_port->lat.set = _d0_mask; else _d0_port->lat.clr = _d0_mask;
    if (dat & 0x02) _d1_port->lat.set = _d1_mask; else _d1_port->lat.clr = _d1_mask;
    if (dat & 0x04) _d2_port->lat.set = _d2_mask; else _d2_port->lat.clr = _d2_mask;
    if (dat & 0x08) _d3_port->lat.set = _d3_mask; else _d3_port->lat.clr = _d3_mask;
    if (dat & 0x10) _d4_port->lat.set = _d4_mask; else _d4_port->lat.clr = _d4_mask;
    if (dat & 0x20) _d5_port->lat.set = _d5_mask; else _d5_port->lat.clr = _d5_mask;
    if (dat & 0x40) _d6_port->lat.set = _d6_mask; else _d6_port->lat.clr = _d6_mask;
    if (dat & 0x80) _d7_port->lat.set = _d7_mask; else _d7_port->lat.clr = _d7_mask;

    _wr_port->lat.clr = _wr_mask;
    _wr_port->lat.set = _wr_mask;

    _cs_port->lat.set = _cs_mask;
}

#elif defined(__STM32F1__)
void ILI9341::command(uint8_t cmd) {
    _rs_info->gpio_device->regs->BSRR = (1U << _rs_info->gpio_bit) << ((!LOW) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!LOW) << 4);

    _d0_info->gpio_device->regs->BSRR = (1U << _d0_info->gpio_bit) << ((!(cmd & 0x01)) << 4);
    _d1_info->gpio_device->regs->BSRR = (1U << _d1_info->gpio_bit) << ((!(cmd & 0x02)) << 4);
    _d2_info->gpio_device->regs->BSRR = (1U << _d2_info->gpio_bit) << ((!(cmd & 0x04)) << 4);
    _d3_info->gpio_device->regs->BSRR = (1U << _d3_info->gpio_bit) << ((!(cmd & 0x08)) << 4);
    _d4_info->gpio_device->regs->BSRR = (1U << _d4_info->gpio_bit) << ((!(cmd & 0x10)) << 4);
    _d5_info->gpio_device->regs->BSRR = (1U << _d5_info->gpio_bit) << ((!(cmd & 0x20)) << 4);
    _d6_info->gpio_device->regs->BSRR = (1U << _d6_info->gpio_bit) << ((!(cmd & 0x40)) << 4);
    _d7_info->gpio_device->regs->BSRR = (1U << _d7_info->gpio_bit) << ((!(cmd & 0x80)) << 4);

    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!LOW) << 4);
    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!HIGH) << 4);
}

void ILI9341::data(uint8_t cmd) {
    _rs_info->gpio_device->regs->BSRR = (1U << _rs_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!LOW) << 4);

    _d0_info->gpio_device->regs->BSRR = (1U << _d0_info->gpio_bit) << ((!(cmd & 0x01)) << 4);
    _d1_info->gpio_device->regs->BSRR = (1U << _d1_info->gpio_bit) << ((!(cmd & 0x02)) << 4);
    _d2_info->gpio_device->regs->BSRR = (1U << _d2_info->gpio_bit) << ((!(cmd & 0x04)) << 4);
    _d3_info->gpio_device->regs->BSRR = (1U << _d3_info->gpio_bit) << ((!(cmd & 0x08)) << 4);
    _d4_info->gpio_device->regs->BSRR = (1U << _d4_info->gpio_bit) << ((!(cmd & 0x10)) << 4);
    _d5_info->gpio_device->regs->BSRR = (1U << _d5_info->gpio_bit) << ((!(cmd & 0x20)) << 4);
    _d6_info->gpio_device->regs->BSRR = (1U << _d6_info->gpio_bit) << ((!(cmd & 0x40)) << 4);
    _d7_info->gpio_device->regs->BSRR = (1U << _d7_info->gpio_bit) << ((!(cmd & 0x80)) << 4);

    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!LOW) << 4);
    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!HIGH) << 4);
}

#else
void ILI9341::command(uint8_t cmd) {
    digitalWrite(_rs_pin, LOW);
    digitalWrite(_cs_pin, LOW);

    digitalWrite(_d0_pin, (cmd & 0x01) ? 1 : 0);
    digitalWrite(_d1_pin, (cmd & 0x02) ? 1 : 0);
    digitalWrite(_d2_pin, (cmd & 0x04) ? 1 : 0);
    digitalWrite(_d3_pin, (cmd & 0x08) ? 1 : 0);
    digitalWrite(_d4_pin, (cmd & 0x10) ? 1 : 0);
    digitalWrite(_d5_pin, (cmd & 0x20) ? 1 : 0);
    digitalWrite(_d6_pin, (cmd & 0x40) ? 1 : 0);
    digitalWrite(_d7_pin, (cmd & 0x80) ? 1 : 0);

    digitalWrite(_wr_pin, LOW);
    digitalWrite(_wr_pin, HIGH);

    digitalWrite(_cs_pin, HIGH);
}

void ILI9341::data(uint8_t cmd) {
    digitalWrite(_rs_pin, HIGH);
    digitalWrite(_cs_pin, LOW);

    digitalWrite(_d0_pin, (cmd & 0x01) ? 1 : 0);
    digitalWrite(_d1_pin, (cmd & 0x02) ? 1 : 0);
    digitalWrite(_d2_pin, (cmd & 0x04) ? 1 : 0);
    digitalWrite(_d3_pin, (cmd & 0x08) ? 1 : 0);
    digitalWrite(_d4_pin, (cmd & 0x10) ? 1 : 0);
    digitalWrite(_d5_pin, (cmd & 0x20) ? 1 : 0);
    digitalWrite(_d6_pin, (cmd & 0x40) ? 1 : 0);
    digitalWrite(_d7_pin, (cmd & 0x80) ? 1 : 0);

    digitalWrite(_wr_pin, LOW);
    digitalWrite(_wr_pin, HIGH);

    digitalWrite(_cs_pin, HIGH);
}
#endif

void ILI9341::initializeDevice() {
#if defined(__PIC32__)
    if (_cs_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_rs_pin >= NUM_DIGITAL_PINS_EXTENDED) return; 
    if (_wr_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_rd_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_reset_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d0_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d1_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d2_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d3_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d4_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d5_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d6_pin >= NUM_DIGITAL_PINS_EXTENDED) return;
    if (_d7_pin >= NUM_DIGITAL_PINS_EXTENDED) return;

    _cs_port = getPortInformation(_cs_pin, &_cs_mask);
    _rs_port = getPortInformation(_rs_pin, &_rs_mask);
    _wr_port = getPortInformation(_wr_pin, &_wr_mask);
    _rd_port = getPortInformation(_rd_pin, &_rd_mask);
    _d0_port = getPortInformation(_d0_pin, &_d0_mask);
    _d1_port = getPortInformation(_d1_pin, &_d1_mask);
    _d2_port = getPortInformation(_d2_pin, &_d2_mask);
    _d3_port = getPortInformation(_d3_pin, &_d3_mask);
    _d4_port = getPortInformation(_d4_pin, &_d4_mask);
    _d5_port = getPortInformation(_d5_pin, &_d5_mask);
    _d6_port = getPortInformation(_d6_pin, &_d6_mask);
    _d7_port = getPortInformation(_d7_pin, &_d7_mask);

#elif defined(__STM32F1__)
    if (_cs_pin >= BOARD_NR_GPIO_PINS) return;
    if (_rs_pin >= BOARD_NR_GPIO_PINS) return;
    if (_wr_pin >= BOARD_NR_GPIO_PINS) return;
    if (_rd_pin >= BOARD_NR_GPIO_PINS) return;
    if (_reset_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d0_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d1_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d2_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d3_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d4_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d5_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d6_pin >= BOARD_NR_GPIO_PINS) return;
    if (_d7_pin >= BOARD_NR_GPIO_PINS) return;

    _wr_info = &PIN_MAP[_wr_pin];
    _rd_info = &PIN_MAP[_rd_pin];
    _rs_info = &PIN_MAP[_rs_pin];
    _cs_info = &PIN_MAP[_cs_pin];

    _d0_info = &PIN_MAP[_d0_pin];
    _d1_info = &PIN_MAP[_d1_pin];
    _d2_info = &PIN_MAP[_d2_pin];
    _d3_info = &PIN_MAP[_d3_pin];
    _d4_info = &PIN_MAP[_d4_pin];
    _d5_info = &PIN_MAP[_d5_pin];
    _d6_info = &PIN_MAP[_d6_pin];
    _d7_info = &PIN_MAP[_d7_pin];

#endif

    pinMode(_cs_pin, OUTPUT);
    pinMode(_rs_pin, OUTPUT);
    pinMode(_wr_pin, OUTPUT);
    pinMode(_rd_pin, OUTPUT);
    pinMode(_reset_pin, OUTPUT);
    pinMode(_d0_pin, OUTPUT);
    pinMode(_d1_pin, OUTPUT);
    pinMode(_d2_pin, OUTPUT);
    pinMode(_d3_pin, OUTPUT);
    pinMode(_d4_pin, OUTPUT);
    pinMode(_d5_pin, OUTPUT);
    pinMode(_d6_pin, OUTPUT);
    pinMode(_d7_pin, OUTPUT);

    _width  = ILI9341::Width;
    _height = ILI9341::Height;

    digitalWrite(_cs_pin, HIGH);
    digitalWrite(_rs_pin, HIGH);
    digitalWrite(_wr_pin, HIGH);
    digitalWrite(_rd_pin, HIGH);

    digitalWrite(_reset_pin, HIGH);
    delay(100);
    digitalWrite(_reset_pin, LOW);
    delay(100);
    digitalWrite(_reset_pin, HIGH);
    delay(100);
    initChip();
}

void ILI9341::initChip() {
    command(ILI9341_SOFTRESET);
    delay(50);
    command(ILI9341_DISPLAYOFF);
    command(ILI9341_POWERCONTROL1); data(0x23);
    command(ILI9341_POWERCONTROL2); data(0x10);
    command(ILI9341_VCOMCONTROL1); data(0x2B); data(0x2B);
    command(ILI9341_VCOMCONTROL2); data(0xC0);
    command(ILI9341_MEMCONTROL); data(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
    command(ILI9341_PIXELFORMAT); data(0x55);
    command(ILI9341_FRAMECONTROL); data(0x00); data(0x1B);
    command(ILI9341_ENTRYMODE); data(0x07);

    command(ILI9341_SLEEPOUT);
    delay(150);
    command(ILI9341_DISPLAYON);
    delay(500);
}

void ILI9341::setAddrWindow(int x0, int y0, int x1, int y1) {
	command(ILI9341_COLADDRSET); // Column addr set
    data(x0 >> 8);
    data(x0 & 0xFF);
    data(x1 >> 8);
    data(x1 & 0xFF);

	command(ILI9341_PAGEADDRSET); // Row addr set
	data(y0 >> 8);
	data(y0 & 0xFF);     // YSTART
	data(y1 >> 8);
	data(y1 & 0xFF);     // YEND

	command(ILI9341_MEMORYWRITE); // write to RAM
}

void ILI9341::setPixel(int x, int y, color_t color) {
	if((x < 0) ||(x >= _width) || (y < 0) || (y >= _height)) 
		return;
	setAddrWindow(x,y,x+1,y+1);
    data(color >> 8);
    data(color & 0xFF);
}

void ILI9341::fillScreen(color_t color) {
	fillRectangle(0, 0,  _width, _height, color);
}

void ILI9341::fillRectangle(int x, int y, int w, int h, color_t color) {
	if((x >= _width) || (y >= _height)) 
		return;
	if((x + w - 1) >= _width)  
		w = _width  - x;
	if((y + h - 1) >= _height) 
		h = _height - y;
	setAddrWindow(x, y, x+w-1, y+h-1);

	for(y=h; y>0; y--) {
		for(x=w; x>0; x--) {
            data(color >> 8);
            data(color & 0xFF);
		}
	}
}

void ILI9341::drawHorizontalLine(int x, int y, int w, color_t color) {
	// Rudimentary clipping
	if((x >= _width) || (y >= _height)) 
		return;
	if((x+w-1) >= _width)  
		w = _width-x;
	setAddrWindow(x, y, x+w-1, y);

	while (w--) {
        data(color >> 8);
        data(color & 0xFF);
	}
}

void ILI9341::drawVerticalLine(int x, int y, int h, color_t color) {
	if((x >= _width) || (y >= _height)) 
		return;
	if((y+h-1) >= _height) 
		h = _height-y;
	setAddrWindow(x, y, x, y+h-1);

	while (h--) {
        data(color >> 8);
        data(color & 0xFF);
	}
}

void ILI9341::setRotation(int m) {
	command(ILI9341_MADCTL);
	rotation = m % 4; // can't be higher than 3
	switch (rotation) {
		case 0:
			data(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
			_width  = ILI9341::Width;
			_height = ILI9341::Height;
			break;
		case 1:
		    data(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
			_width  = ILI9341::Height;
			_height = ILI9341::Width;
			break;
		case 2:
			data(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
			_width  = ILI9341::Width;
			_height = ILI9341::Height;
			break;
		case 3:
			data(ILI9341_MADCTL_MV | ILI9341_MADCTL_MY | ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
			_width  = ILI9341::Height;
			_height = ILI9341::Width;
			break;
	}
}

void ILI9341::invertDisplay(bool i) {
	command(i ? ILI9341_INVERTON : ILI9341_INVERTOFF);
}

void ILI9341::openWindow(int x0, int y0, int x1, int y1) {
	setAddrWindow(x0, y0, x0 + x1 - 1, y0 + y1 - 1);
}

void ILI9341::windowData(color_t c) {
    data(c >> 8);
    data(c & 0xFF);
}

void ILI9341::windowData(color_t *c, int len) {
    for (int i = 0; i < len; i++) {
        data(c[i] >> 8);
        data(c[i] & 0xFF);
    }
}

void ILI9341::closeWindow() {
}

void ILI9341::setBacklight(int b) {
    command(0x53);
    data(0b00101100);
    command(0x51);
    data(b);
}

#if defined(__PIC32__)

void ILI9341_DSPI::initializeDevice() {
    pinMode(_cs_pin, OUTPUT);
    pinMode(_rs_pin, OUTPUT);
    digitalWrite(_cs_pin, HIGH);
    digitalWrite(_rs_pin, LOW);

    _width  = ILI9341::Width;
    _height = ILI9341::Height;

    _cs_port = getPortInformation(_cs_pin, &_cs_mask);
    _rs_port = getPortInformation(_rs_pin, &_rs_mask);

    _spi->begin();
    initChip();
}

void ILI9341_DSPI::command(uint8_t c) {
    _spi->setSpeed(20000000UL);
    _rs_port->lat.clr = _rs_mask;
    _cs_port->lat.clr = _cs_mask;
    _spi->transfer(c);
    _cs_port->lat.set = _cs_mask;

}

void ILI9341_DSPI::data(uint8_t d) {
    _spi->setSpeed(20000000UL);
    _rs_port->lat.set = _rs_mask;
    _cs_port->lat.clr = _cs_mask;
    _spi->transfer(d);
    _cs_port->lat.set = _cs_mask;
}

#endif

#if defined(__STM32F1__)

void ILI9341_PORTB::command(uint8_t cmd) {
    _rs_info->gpio_device->regs->BSRR = (1U << _rs_info->gpio_bit) << ((!LOW) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!LOW) << 4);

    gpiob.regs->ODR &= 0xFF00;
    gpiob.regs->ODR |= cmd;

    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!LOW) << 4);
    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!HIGH) << 4);
}

void ILI9341_PORTB::data(uint8_t cmd) {
    _rs_info->gpio_device->regs->BSRR = (1U << _rs_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!LOW) << 4);

    gpiob.regs->ODR &= 0xFF00;
    gpiob.regs->ODR |= cmd;

    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!LOW) << 4);
    _wr_info->gpio_device->regs->BSRR = (1U << _wr_info->gpio_bit) << ((!HIGH) << 4);
    _cs_info->gpio_device->regs->BSRR = (1U << _cs_info->gpio_bit) << ((!HIGH) << 4);
}

void ILI9341_PORTB::initializeDevice() {
    if (_cs_pin >= BOARD_NR_GPIO_PINS) return;
    if (_rs_pin >= BOARD_NR_GPIO_PINS) return;
    if (_wr_pin >= BOARD_NR_GPIO_PINS) return;
    if (_rd_pin >= BOARD_NR_GPIO_PINS) return;
    if (_reset_pin >= BOARD_NR_GPIO_PINS) return;

    _wr_info = &PIN_MAP[_wr_pin];
    _rd_info = &PIN_MAP[_rd_pin];
    _rs_info = &PIN_MAP[_rs_pin];
    _cs_info = &PIN_MAP[_cs_pin];

    pinMode(_cs_pin, OUTPUT);
    pinMode(_rs_pin, OUTPUT);
    pinMode(_wr_pin, OUTPUT);
    pinMode(_rd_pin, OUTPUT);
    pinMode(_reset_pin, OUTPUT);

    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(20, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);

//    gpiob.regs->CRL = 0x33333333;

    _width  = ILI9341::Width;
    _height = ILI9341::Height;

    digitalWrite(_cs_pin, HIGH);
    digitalWrite(_rs_pin, HIGH);
    digitalWrite(_wr_pin, HIGH);
    digitalWrite(_rd_pin, HIGH);

    digitalWrite(_reset_pin, HIGH);
    delay(100);
    digitalWrite(_reset_pin, LOW);
    delay(100);
    digitalWrite(_reset_pin, HIGH);
    delay(100);
    initChip();
}


#endif
