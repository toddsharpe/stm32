#pragma once

#include "Graphics/Color.h"
#include "Graphics/Types.h"
#include "Graphics/Font.h"

#include <string>

using namespace Graphics;

template<size_t Width, size_t Height>
class GraphicsBuffer
{
public:
	GraphicsBuffer(): m_font(), m_backing()
	{

	}

	void FillScreen(const Color color)
	{
		this->DrawRectangle(color, {0, 0, Width, Height});
	}

	void DrawRectangle(const Color color, const Rectangle& region)
	{
		for (size_t y = 0; y < region.Height; y++)
		{
			if (y + region.Y >= Height)
				break;

			//Write row
			Color* dst = (Color*)m_backing + (region.Y + y) * Width + region.X;
			const size_t count = std::min(region.Width, Width - region.X);
			SetPixels(dst, color, count);
		}
	}

	void DrawPrintf(Point2D position, const Color color, const char* format, ...)
	{
		char buffer[255];

		va_list args;
		va_start(args, format);
		int retval = vsprintf(buffer, format, args);
		buffer[retval] = '\0';
		va_end(args);

		this->DrawText(position, std::string(buffer), color);
	}

	void DrawText(const Point2D position, const std::string& text, const Color color)
	{
		Point2D pos = position;
		for (const char c : text)
		{
			if (c == '\n')
			{
				pos.Y += PixelScale;
				pos.X = position.X;
			}
			else if (c != '\r')
			{
				DrawCharacter(pos, c, color);
				pos.X += PixelScale;
			}
		}
	}

	Color GetPixel(const Point2D& position) const
	{
		Assert(position.X < Width);
		Assert(position.Y < Height);

		return m_backing[position.Y][position.X];
	}

	void* GetAddress()
	{
		return m_backing;
	}

	size_t Size() const
	{
		return sizeof(m_backing);
	}

private:
	static constexpr size_t PixelScale = 10;
	static constexpr size_t FontScale = 1;

	static void SetPixels(Color* _Dst, const Color _Val, const size_t _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			*_Dst = (Color)_Val;
			_Dst++;
		}
	}

	void DrawCharacter(const Point2D position, const char c, const Color color)
	{
		const char* map = m_font.GetCharacterMap(c);
		uint8_t size = 8; // TODO: get from font

		for (size_t y = 0; y < size; y++)
		{
			//Line is reversed
			char line = map[y];

			size_t x = 0;
			unsigned char mask = 0x80;
			while (mask > 0)
			{
				if ((line & mask) != 0)
				{
					Rectangle rect;
					rect.X = (position.X + (8 - x - 1)) * FontScale;
					rect.Y = (position.Y + y) * FontScale;
					rect.Width = FontScale;
					rect.Height = FontScale;
					DrawRectangle(color, rect);
				}

				mask = mask >> 1;
				x++;
			}
		}
	}

	const Font m_font;

	Color m_backing[Width][Height];
};