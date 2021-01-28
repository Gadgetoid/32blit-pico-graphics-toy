#include "game.hpp"
#include "pico_graphics.hpp"

#ifdef WIN32
#include <stdlib.h>
#define __builtin_bswap16 _byteswap_ushort
#endif

using namespace blit;

constexpr Size bounds(320, 240);

uint16_t _pico_buffer[bounds.w * bounds.h];
pimoroni::PicoGraphics picographics(bounds.w, bounds.h, _pico_buffer);


void init() {
    set_screen_mode(ScreenMode::hires);
}

void clip_demo() {
    picographics.set_pen(255, 255, 255);
    picographics.text("1. The screen", pimoroni::Point(10, 10), 320, 1);
    picographics.text("2. Add a clip", pimoroni::Point(170, 10), 320, 1);
    picographics.text("3. Draw a circle", pimoroni::Point(10, 130), 320, 1);
    picographics.text("4. What actually gets drawn", pimoroni::Point(170, 130), 320, 1);

    picographics.set_pen(30, 30, 30);
    picographics.rectangle(pimoroni::Rect(10, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(10, 150, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 150, 140, 80));

    // Add a clip
    picographics.set_pen(255, 0, 0);
    pimoroni::Rect clip = pimoroni::Rect(170, 30, 70, 40);
    picographics.pen = picographics.create_pen(255, 0, 0);
    picographics.rectangle(clip);

    // Draw a circle
    picographics.set_pen(0, 255, 0);
    picographics.circle(pimoroni::Point(10 + 70, 150 + 40), 30);

    // What actually gets drawn
    clip.y = 150;
    picographics.set_clip(clip);
    picographics.circle(pimoroni::Point(170 + 70, 150 + 40), 30);
}

void render(uint32_t time) {

    clip_demo();

    for(auto y = 0u; y < bounds.h; y++) {
        for(auto x = 0u; x < bounds.w; x++) {
            uint16_t p = __builtin_bswap16(_pico_buffer[y * bounds.w + x]);
            uint8_t r = ((p >> 11) & 0b11111) << 3;
            uint8_t g = ((p >> 5) & 0b111111) << 2;
            uint8_t b = (p & 0b11111) << 3;

            screen.pen = Pen(r, g, b);
            screen.pixel(Point(x, y));
        }
    }
}

void update(uint32_t time) {
}