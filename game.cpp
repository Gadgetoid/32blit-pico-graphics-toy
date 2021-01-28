#include "game.hpp"
#include "pico_graphics.hpp"

using namespace blit;

constexpr Size bounds(320, 240);

uint16_t _pico_buffer[bounds.w * bounds.h];
pimoroni::PicoGraphics picographics(bounds.w, bounds.h, _pico_buffer);

enum ArrowDirection {
    up = 0,
    down = 1,
    left = 2,
    right = 3
};

void arrow(pimoroni::Point tip, ArrowDirection d) {
    switch(d) {
        case ArrowDirection::up: // Up
            picographics.line(tip, pimoroni::Point(tip.x - 3, tip.y + 3));
            picographics.line(tip, pimoroni::Point(tip.x + 3, tip.y + 3));
            break;
        case ArrowDirection::right: // Right
            picographics.line(tip, pimoroni::Point(tip.x - 3, tip.y - 3));
            picographics.line(tip, pimoroni::Point(tip.x - 3, tip.y + 3));
            break;
        case ArrowDirection::down: // Down
            picographics.line(tip, pimoroni::Point(tip.x - 3, tip.y - 3));
            picographics.line(tip, pimoroni::Point(tip.x + 3, tip.y - 3));
            break;
        case ArrowDirection::left: // Left
            picographics.line(tip, pimoroni::Point(tip.x + 3, tip.y - 3));
            picographics.line(tip, pimoroni::Point(tip.x + 3, tip.y + 3));
            break;
        default:
            break;
    }
}

void text_demo() {
    picographics.set_pen(255, 255, 255);
    picographics.text("Scale: 1x", pimoroni::Point(10, 10), 320, 1);
    picographics.text("Scale: 2x", pimoroni::Point(170, 10), 320, 1);
    picographics.text("Scale: 3x", pimoroni::Point(10, 130), 320, 1);
    picographics.text("Scale: 4x", pimoroni::Point(170, 130), 320, 1);

    picographics.set_pen(30, 30, 30);
    picographics.rectangle(pimoroni::Rect(10, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(10, 150, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 150, 140, 80));

    picographics.set_pen(255, 255, 255);
    picographics.text("Very very smol", pimoroni::Point(10 + 10, 30 + 10), 140, 1);
    picographics.text("Less smol", pimoroni::Point(170 + 10, 30 + 10), 140, 2);
    picographics.text("Kinda large", pimoroni::Point(10 + 10, 150 + 10), 140, 3);
    picographics.set_pen(255, 0, 0);
    picographics.text("AAAAAH!", pimoroni::Point(170 + 10, 150 + 10), 140, 4);
}

void circle_demo() {
    picographics.set_pen(255, 255, 255);
    picographics.text("1. Origin", pimoroni::Point(10, 10), 320, 1);
    picographics.text("2. Radius", pimoroni::Point(170, 10), 320, 1);
    picographics.text("3. Circle", pimoroni::Point(10, 130), 320, 1);
    //picographics.text("4. Eyes", pimoroni::Point(170, 130), 320, 1);

    picographics.set_pen(30, 30, 30);
    picographics.rectangle(pimoroni::Rect(10, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(10, 150, 140, 80));
    //picographics.rectangle(pimoroni::Rect(170, 150, 140, 80));

    // Origin
    picographics.set_pen(255, 0, 0);
    picographics.pixel(pimoroni::Point(80, 70));

    // Radius
    picographics.line(pimoroni::Point(160 + 80, 70), pimoroni::Point(160 + 80, 100));
    arrow(pimoroni::Point(160 + 80, 100), ArrowDirection::down);

    // Circle
    picographics.set_pen(0, 255, 0);
    picographics.circle(pimoroni::Point(80, 120 + 70), 30);

    // Eyes
    /*picographics.set_pen(255, 255, 255);
    picographics.circle(pimoroni::Point(170 + 40 + 5, 120 + 70), 30);
    picographics.circle(pimoroni::Point(170 + 100 - 5, 120 + 70), 30);
    picographics.set_pen(100, 50, 0);
    picographics.circle(pimoroni::Point(170 + 40 + 5, 120 + 70), 10);
    picographics.circle(pimoroni::Point(170 + 100 - 5, 120 + 70), 10);
    picographics.set_pen(0, 0, 0);
    picographics.circle(pimoroni::Point(170 + 40 + 5, 120 + 70), 5);
    picographics.circle(pimoroni::Point(170 + 100 - 5, 120 + 70), 5);*/

}

void rectangle_demo() {
    picographics.set_pen(255, 255, 255);
    picographics.text("1. Origin", pimoroni::Point(10, 10), 320, 1);
    picographics.text("2. Width", pimoroni::Point(170, 10), 320, 1);
    picographics.text("3. Height", pimoroni::Point(10, 130), 320, 1);
    picographics.text("4. Rectangle", pimoroni::Point(170, 130), 320, 1);

    picographics.set_pen(30, 30, 30);
    picographics.rectangle(pimoroni::Rect(10, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 30, 140, 80));
    picographics.rectangle(pimoroni::Rect(10, 150, 140, 80));
    picographics.rectangle(pimoroni::Rect(170, 150, 140, 80));

    // Origin
    picographics.set_pen(255, 0, 0);
    picographics.pixel(pimoroni::Point(20, 40));

    // Width
    picographics.line(pimoroni::Point(180, 40), pimoroni::Point(300, 40));
    arrow(pimoroni::Point(180, 40), ArrowDirection::left);
    arrow(pimoroni::Point(300, 40), ArrowDirection::right);

    // Height
    picographics.line(pimoroni::Point(20, 160), pimoroni::Point(20, 220));
    arrow(pimoroni::Point(20, 160), ArrowDirection::up);
    arrow(pimoroni::Point(20, 220), ArrowDirection::down);

    // Rectangle
    picographics.set_pen(0, 255, 0);
    picographics.rectangle(pimoroni::Rect(180, 160, 120, 60));
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

void init() {
    set_screen_mode(ScreenMode::hires);
    // Only need to draw our demo once
    circle_demo();
}

void render(uint32_t time) {
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