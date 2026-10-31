#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>

#include "framework/canvas.h"

// ここに、この回で書くものを足していく
//   Vec3      … 3D の位置や向き。足し算・引き算・数を掛ける・内積・長さ・正規化
//   Ray       … 光線。始点と向き
//   to_color  … 0〜1 の色（Vec3）を、0〜255 の Color に直す関数
//   mix       … 2つの色を混ぜる関数
//   sky_color … 光線の向きから、空の色を決める関数
// Add what we write in this episode here.
// Vec3 ... 3D positions and directions; addition, subtraction, scaling, dot product, length, and normalization
// Ray ... a ray with an origin and direction
// to_color ... convert a color from 0 to 1 (Vec3) to a Color from 0 to 255
// mix ... mix two colors
// sky_color ... choose the sky color from the ray direction

// (x, y) のピクセルを color にする
// Set the pixel at (x, y) to color.
void set_pixel(Canvas& canvas, int x, int y, Color color) {
    // 画面の外は何もしない。はみ出して pixels の外を書くと、プログラムが壊れるため
    // Do nothing outside the screen. Writing past pixels would break the program.
    if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height) {
        return;
    }
    canvas.pixels[y * canvas.width + x] = color;
}

int main() {
    Canvas canvas(320, 180, 4);  // 320×180 の絵を、4倍に拡大して表示する / Display a 320x180 image enlarged 4 times.

    while (canvas.update()) {
        // この回で、ここを「ピクセルごとにカメラから光線を作り、光線の向きで色を決める」処理に差し替える
        // 光線はピクセルの真ん中を通す。画面の縦横比（320 ÷ 180）と、画面の y が下向きなことに気をつける
        // In this episode, replace this with code that makes a ray from the camera for each pixel and chooses a color from its direction. Make the ray pass through the pixel center. Keep the 320 / 180 screen aspect ratio and downward screen y in mind.

        // 画面全体を塗る。赤は x に、緑は y に合わせて 0〜255 に変える
        // Fill the screen. Set red from x and green from y, each from 0 to 255.
        for (int y = 0; y < canvas.height; y++) {
            for (int x = 0; x < canvas.width; x++) {
                const uint8_t r = static_cast<uint8_t>(x * 255 / (canvas.width - 1));
                const uint8_t g = static_cast<uint8_t>(y * 255 / (canvas.height - 1));
                set_pixel(canvas, x, y, Color{r, g, 0});
            }
        }

        canvas.present();
    }
}
