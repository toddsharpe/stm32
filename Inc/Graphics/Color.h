#pragma once

#include <cstdint>

namespace Graphics
{
	struct RGB565
	{
		union
		{
			struct
			{
				uint16_t Red : 5;
				uint16_t Green : 6;
				uint16_t Blue : 5;
			};
			uint16_t AsUint16;
		};
	};
	static_assert(sizeof(RGB565) == sizeof(uint16_t), "Invalid color struct");
	typedef RGB565 Color;

	namespace Colors
	{
		//To support 16bit transfers, colors were converted to little endian, bytes reversed.
		static constexpr RGB565 White = {.AsUint16 = 0xFFFF };
		static constexpr RGB565 Black = {.AsUint16 = 0x0000 };
		static constexpr RGB565 Blue = {.AsUint16 = 0x1F00 };
		static constexpr RGB565 Red = {.AsUint16 = 0x00F8 };
		static constexpr RGB565 Magenta = {.AsUint16 = 0x1FF8 };
		static constexpr RGB565 Green = {.AsUint16 = 0xE007 };
		static constexpr RGB565 Cyan = {.AsUint16 = 0xFF7F };
	}
}
