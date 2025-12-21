#ifndef _MIPI_TX_PARAM_SY049_1080P_H_
#define _MIPI_TX_PARAM_SY049_1080P_H_

#include <cvi_mipi.h>

#define PANEL_NAME "SY049_1080P"

#define SY049_VACT	1080
#define SY049_VSA		2
#define SY049_VBP		14
#define SY049_VFP		16

#define SY049_HACT		1920
#define SY049_HSA		32
#define SY049_HBP		32
#define SY049_HFP		64

#define PIXEL_CLK(x) ((x##_VACT + x##_VSA + x##_VBP + x##_VFP) \
	* (x##_HACT + x##_HSA + x##_HBP + x##_HFP) * 60 / 1000)

const struct combo_dev_cfg_s dev_cfg_sy049_1080p = {
	.devno = 0,
	.lane_id = {MIPI_TX_LANE_1, MIPI_TX_LANE_0, MIPI_TX_LANE_CLK, -1, -1},
	.lane_pn_swap = {false, false, false, false, false},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,
	.video_mode = BURST_MODE,
	.output_format = OUT_FORMAT_RGB_24_BIT,
	.sync_info = {
		.vid_hsa_pixels = SY049_HSA,
		.vid_hbp_pixels = SY049_HBP,
		.vid_hfp_pixels = SY049_HFP,
		.vid_hline_pixels = SY049_HACT,
		.vid_vsa_lines = SY049_VSA,
		.vid_vbp_lines = SY049_VBP,
		.vid_vfp_lines = SY049_VFP,
		.vid_active_lines = SY049_VACT,
		.vid_vsa_pos_polarity = true,
		.vid_hsa_pos_polarity = false,
	},
	.pixel_clk = PIXEL_CLK(SY049),
};

const struct hs_settle_s hs_timing_cfg_sy049_1080p = { .prepare = 6, .zero = 32, .trail = 1 };

static u8 data_sy049_0[] = { 0x53, 0x29 };
static u8 data_sy049_1[] = { 0x51, 0xff, 0x01 };
static u8 data_sy049_2[] = { 0x03, 0x00 };
static u8 data_sy049_3[] = { 0x80, 0x01, 0xe0, 0xe0, 0x0e, 0x00, 0x31 };
static u8 data_sy049_4[] = { 0x81, 0x03, 0x04, 0x00, 0x10, 0x00, 0x10, 0x00 };
static u8 data_sy049_5[] = { 0x82, 0x03, 0x04, 0x00, 0x10, 0x00, 0x10, 0x00 };
static u8 data_sy049_6[] = { 0x35, 0x00 };
static u8 data_sy049_7[] = { 0x26, 0x20 };
static u8 data_sy049_8[] = { 0xf0, 0xaa, 0x11 };
static u8 data_sy049_9[] = { 0xc2, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x82 };
static u8 data_sy049_10[] = { 0xf0, 0xaa, 0x12 };
static u8 data_sy049_11[] = { 0xbf, 0x37, 0xa9 };
static u8 data_sy049_12[] = { 0xff, 0x5a, 0x80 };
static u8 data_sy049_13[] = { 0x65, 0x2f };
static u8 data_sy049_14[] = { 0xf2, 0x01 };
static u8 data_sy049_15[] = { 0xff, 0x5a, 0x81 };
static u8 data_sy049_16[] = { 0x65, 0x05 };
static u8 data_sy049_17[] = { 0xf2, 0x22 };
static u8 data_sy049_18[] = { 0x65, 0x0a };
static u8 data_sy049_19[] = { 0xf2, 0x00 };
static u8 data_sy049_20[] = { 0x65, 0x17 };
static u8 data_sy049_21[] = { 0xf9, 0x5e, 0x62, 0x66, 0x6a, 0x6f, 0x73, 0x77, 0x7b, 0x7f, 0x84, 0x88, 0x8c, 0x90 };
static u8 data_sy049_22[] = { 0x11 };
static u8 data_sy049_23[] = { 0x29 };
static u8 data_sy049_24[] = { 0xf0, 0xaa, 0x11 };
static u8 data_sy049_25[] = { 0xc0, 0xff };

const struct dsc_instr dsi_init_cmds_sy049_1080p[] = {
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_0 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_1 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_2 },
	{.delay = 0, .data_type = 0x39, .size = 7, .data = data_sy049_3 },
	{.delay = 0, .data_type = 0x39, .size = 8, .data = data_sy049_4 },
	{.delay = 0, .data_type = 0x39, .size = 8, .data = data_sy049_5 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_6 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_7 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_8 },
	{.delay = 0, .data_type = 0x39, .size = 10, .data = data_sy049_9 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_10 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_11 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_12 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_13 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_14 },
	{.delay = 0, .data_type = 0x39, .size = 3, .data = data_sy049_15 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_16 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_17 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_18 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_19 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_20 },
	{.delay = 0, .data_type = 0x39, .size = 14, .data = data_sy049_21 },
	{.delay = 20, .data_type = 0x05, .size = 1, .data = data_sy049_22 },
	{.delay = 100, .data_type = 0x05, .size = 1, .data = data_sy049_23 },
	{.delay = 20, .data_type = 0x39, .size = 3, .data = data_sy049_24 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_sy049_25 }
};
#else
#error "_MIPI_TX_PARAM_SY049_1080P_H_ multi-delcaration!!"
#endif // _MIPI_TX_PARAM_SY049_1080P_H_