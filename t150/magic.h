const size_t magic_packet_length = 24;
uint8_t magic_buffer[36][128];

const uint8_t magic_packet[][8] = {
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x28, 0x00},
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00},
	{0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x29, 0x00},
	{0x00, 0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00},
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00},
	{0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x29, 0x00},
	{0x00, 0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00},
	{0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0xff, 0x00},
	{0x80, 0x06, 0x00, 0x03, 0x00, 0x00, 0xff, 0x00},
	{0x80, 0x06, 0x02, 0x03, 0x09, 0x04, 0xff, 0x00},
	{0x80, 0x06, 0x00, 0x06, 0x00, 0x00, 0x0a, 0x00},
	{0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00},
	{0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00},
	{0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x29, 0x00},
	{0xc1, 0x56, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0x81, 0x06, 0x00, 0x22, 0x00, 0x00, 0x82, 0x00},
	{0xc1, 0x42, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00},
	{0xc1, 0x4e, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00},
	{0xc1, 0x56, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00}, // halt here first, send init_win up to 
	{0x41, 0x48, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00}, // send before init_win at 5
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	/*{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00},
	{0}*/
};

static const size_t init_win_len = 5;

/** Packet that the Windows's driver sends to the wheel. I do not understant
 why, yet */
static const uint8_t init_win[][15] = {
	{0x42, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x90, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x12, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};

/** Send this when you want to use the wheel ffb motor to simulate a spring **/
static uint8_t return_wheel_mode[] = {0x40, 0x04, 0x01, 0x00};

static uint8_t magic[] = {0x43, 0x60};
static uint8_t range900[] = {0x40, 0x11, 0x55, 0xd5};

static const size_t magic_apply_len = 3;
static const uint8_t magic_apply[][15] = {
	{0x0a, 0x04, 0x12, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0a, 0x04, 0x90, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

static const uint8_t driver_settings_start[] = {0xc1, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00};