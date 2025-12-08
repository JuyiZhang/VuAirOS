/*int cvi_board_init(void)
{
	// Camera
	PINMUX_CONFIG(PAD_MIPI_TXM1, IIC2_SDA);    // GP10
	PINMUX_CONFIG(PAD_MIPI_TXP1, IIC2_SCL);    // GP11
	PINMUX_CONFIG(PAD_MIPI_TXP0, CAM_MCLK0);   // Sensor MCLK
	PINMUX_CONFIG(PAD_MIPI_TXP2, XGPIOC_17);   // Sensor RESET

	// UART1
	PINMUX_CONFIG(IIC0_SCL, UART1_TX);         // GP0
	PINMUX_CONFIG(IIC0_SDA, UART1_RX);         // GP1

	// PWM
	PINMUX_CONFIG(JTAG_CPU_TMS, PWM_7);        // GP2
	PINMUX_CONFIG(JTAG_CPU_TCK, PWM_6);        // GP3

	// I2C1
	PINMUX_CONFIG(SD1_D2, IIC1_SCL);           // GP4
	PINMUX_CONFIG(SD1_D1, IIC1_SDA);           // GP5

	// SPI2
	PINMUX_CONFIG(SD1_CLK, SPI2_SCK);          // GP6
	PINMUX_CONFIG(SD1_CMD, SPI2_SDO);          // GP7
	PINMUX_CONFIG(SD1_D0, SPI2_SDI);           // GP8
	PINMUX_CONFIG(SD1_D3, SPI2_CS_X);          // GP9

	// All default GPIOs
	PINMUX_CONFIG(SD0_PWR_EN, XGPIOA_14);      // GP14
	PINMUX_CONFIG(SPK_EN, XGPIOA_15);          // GP15
	//PINMUX_CONFIG(EMMC_CMD, XGPIOA_23);        // GP16
	//PINMUX_CONFIG(EMMC_DAT1, XGPIOA_24);       // GP17
	//PINMUX_CONFIG(EMMC_CLK, XGPIOA_22);        // GP18
	//PINMUX_CONFIG(EMMC_DAT0, XGPIOA_25);       // GP19
	//PINMUX_CONFIG(EMMC_DAT3, XGPIOA_27);       // GP20
	//PINMUX_CONFIG(EMMC_DAT2, XGPIOA_26);       // GP21
	PINMUX_CONFIG(PWR_SEQ2, PWR_GPIO_4);       // GP22

	// LED
	PINMUX_CONFIG(PWR_GPIO2, PWR_GPIO_2);      // GP25

	// ADC pins set to GPIO
	PINMUX_CONFIG(ADC1, XGPIOB_3);             // GP26 (ADC1)
	PINMUX_CONFIG(USB_VBUS_DET, XGPIOB_6);     // GP27 (ADC2)

	return 0;
}*/

int cvi_board_init(void)
{

	// SPI Camera
	mmio_write_32(0x0300101C, 0x2); //SD0_CLK, SPI0_SCK
	mmio_write_32(0x03001020, 0x2); //SD0_CMD, SPI0_SDO
	mmio_write_32(0x03001024, 0x2); //SD0_D0, SPI0_SDI
	mmio_write_32(0x03001030, 0x2); //SD0_D3, SPI0_CS_X
	mmio_write_32(0x03001034, 0x3); //Grounded SDIO CD, may consider reuse with SDNAND?

	// I2C1
	mmio_write_32(0x03001028, 0x1); //SD0_D1, IIC1_SCL
	mmio_write_32(0x0300102C, 0x1); //SD0_D2, IIC1_SDA
	
	// Not used PWR_EN
	mmio_write_32(0x03001038, 0x3);

	//SPK_EN, NC
	mmio_write_32(0x0300103C, 0x3);

	//UART DEBUG
	mmio_write_32(0x03001040, 0x0); //UART0_TX
	mmio_write_32(0x03001044, 0x0); //UART0_RX

	// SPI FLASH
	mmio_write_32(0x0300104C, 0x2); //SPINAND_HOLD
	mmio_write_32(0x03001050, 0x2); //SPINAND_CLK
	mmio_write_32(0x03001054, 0x2); //SPINAND_MOSI
	mmio_write_32(0x03001058, 0x2); //SPINAND_WP
	mmio_write_32(0x0300105C, 0x2); //SPINAND_MISO
	mmio_write_32(0x03001060, 0x2); //SPINAND_CS

	// JTAG
	mmio_write_32(0x03001064, 0x0); //JTAG_TMS
	mmio_write_32(0x03001068, 0x0); //JTAG_TCK
	mmio_write_32(0x03001070, 0x0); //JTAG_TDI
	mmio_write_32(0x03001074, 0x0);	//JTAG_TDO

	// IIS
	mmio_write_32(0x03001078, 0x4); //IIS1_MCLK

	// PWR CONFIG
	mmio_write_32(0x0300107C, 0x0); //PWR_VBAT_DET
	mmio_write_32(0x03001080, 0x0); //PAR_RSTN
	mmio_write_32(0x03001084, 0x3); //PWR_SEQ1, PWR_GPIO[3]
	mmio_write_32(0x03001088, 0x3); //PWR_SEQ2, PWR_GPIO[4]
	mmio_write_32(0x03001090, 0x0); //PWR_WAKEUP0 -- Consider modify in Production Board for Enhanced Func (IIC/UART)
	mmio_write_32(0x03001098, 0x0); //PWR_BTN -- Consider modify in Production Board for Enhanced Func (IIC/UART)
	
	// Crystal, do not reuse
	// mmio_write_32(0x030010A0, 0x0); 

	// PWR_GPIO
	mmio_write_32(0x030010A4, 0x0); // SCR_RESETN

	// Camera Control
	mmio_write_32(0x030010A8, 0x6); // CAMERA_I2C_SCL
	mmio_write_32(0x030010AC, 0x6); // CAMERA_I2C_SDA

	// WIFI SDIO
	mmio_write_32(0x030010D0, 0x0); // WIFI_SDIO_D3
	mmio_write_32(0x030010D4, 0x0); // WIFI_SDIO_D2
	mmio_write_32(0x030010D8, 0x0); // WIFI_SDIO_D1
	mmio_write_32(0x030010DC, 0x0); // WIFI_SDIO_D0
	mmio_write_32(0x030010E0, 0x0); // WIFI_SDIO_CMD
	mmio_write_32(0x030010E4, 0x0); // WIFI_SDIO_CLK

	// GPIO
	mmio_write_32(0x030010EC, 0x3); // Not used, consider reuse as GPIO in production
	mmio_write_32(0x030010F8, 0x3); // IMU Int Pin
	// mmio_write_32(0x03001108, 0x0); // USB_VBUS_DET choosing Host and Device, need to review in production
	mmio_write_32(0x03001124, 0x7); // IIS2_LRCK
	mmio_write_32(0x03001128, 0x7); // IIS2_BCLK
	mmio_write_32(0x0300112C, 0x7); // IIS2_DO
	mmio_write_32(0x03001130, 0x7); // IIS2_DI

	// MIPI RX and TX follow normal settings

	return 0;
}
