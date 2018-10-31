////////////////////////////////////
// ForserX to X-Ray Oxygen Project
#include "common.h"

#define PIXEL_SIZE screen_res.zw
#include "../toolbox/dlaa.h"

float4 main(p_screen I) : SV_Target
{
	return DLAAPixelShader(I.tc0);
}