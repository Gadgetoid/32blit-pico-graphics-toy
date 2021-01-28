#include "game.hpp"
#include "pico_graphics.hpp"

using namespace blit;

constexpr Size bounds(320, 240);

uint16_t _pico_buffer[bounds.w * bounds.h];
pimoroni::PicoGraphics picographics(bounds.w, bounds.h, _pico_buffer);


void init() {
    set_screen_mode(ScreenMode::hires);
}

void render(uint32_t time) {
    picographics.pen = picographics.create_pen(255, 0, 0);
    picographics.circle(pimoroni::Point(160, 120), 30);

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