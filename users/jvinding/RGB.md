# RGB color rules — `users/jvinding/rgb.c`

All per-key LED logic lives in `jv_hsv_for_key_in_context()`. Rules are applied
top-to-bottom; the first match wins.

## Palette (Catppuccin Latte)

| Name       | Macro            | Description        |
|------------|------------------|--------------------|
| Lavender   | `JV_C_LAVENDER`  | Pastel blue-purple |
| Pink       | `JV_C_PINK`      |                    |
| Rosewater  | `JV_C_ROSEWATER` |                    |
| Sapphire   | `JV_C_SAPPHIRE`  |                    |
| Sky        | `JV_C_SKY`       |                    |
| Yellow     | `JV_C_YELLOW`    |                    |
| Green      | `JV_C_GREEN`     |                    |
| Blue       | `JV_C_BLUE`      |                    |
| Mauve      | `JV_C_MAUVE`     | Soft purple        |
| Teal       | `JV_C_TEAL`      |                    |
| Peach      | `JV_C_PEACH`     |                    |
| Red        | `JV_C_RED`       |                    |

## Layer colors

| Layer       | Color      |
|-------------|------------|
| BASE        | Lavender   |
| QWERTY      | Pink       |
| OSALT       | Rosewater  |
| BUTTON      | Sapphire   |
| NAV         | Sky        |
| MOUSE       | Yellow     |
| MEDIA       | Green      |
| NUM         | Blue       |
| NUMPAD      | Mauve      |
| SYM         | Teal       |
| FUN         | Peach      |
| GAME        | Mauve      |
| GAME_FN     | Lavender   |

NUMPAD and GAME intentionally share Mauve; they never coexist. Same for GAME_FN
and BASE.

## Per-key rules (priority order)

1. **`KC_NO`** → off (black).

2. **`TG(JV_GAME)` toggle key** → shows the color of its destination:
   - While on `JV_GAME` or `JV_GAME_FN`: BASE color (you're going back).
   - On any other layer: GAME color (you're going in).

3. **Layer-switching keys** (`MO`, `LT`, `TG`, `TO`, `OSL`, etc.) → the target
   layer's color.

4. **Tap-dance keys** that have a layer target → that layer's color.

5. **Directional accents on specific layers** → Red:
   - `JV_NAV`: arrow keys.
   - `JV_MOUSE`: mouse cursor keys.
   - `JV_MEDIA`: volume and track-skip keys.

6. **Mouse buttons and scroll wheels** → MOUSE color (Yellow), on any layer.

7. **Gaming layers** (`JV_GAME` and `JV_GAME_FN`):
   - Numpad keys (`KC_NUM_LOCK`…`KC_KP_DOT`, `KC_KP_EQUAL`) → NUMPAD color.
   - Function keys (`KC_F1`…`KC_F12`) → FUN color.
   - Digit row (`KC_1`…`KC_0`) → NUM color.
   - `JV_GAME` only: WASD → Red.
   - `JV_GAME_FN` only: arrow keys → Red; nav cluster (PgUp/PgDn/Home/End/Ins)
     → NAV color.

8. **Default** → the color of the highest layer that defines the key
   (i.e. `jv_hsv_for_layer_id(per_key_layer)`).

## Board overrides

`jv_rgb_matrix_indicators_keyboard()` is a weak hook called after the cache is
pushed. Override it in a board-level `.c` file to apply board-specific LED tweaks
without touching the shared rules above.

## Brightness and correction

Global brightness is `JV_RGB_BRIGHTNESS` (default 64 = full; sofle uses 16 =
quarter). Per-channel white-balance correction is `JV_RGB_CORRECT_{LEFT,RIGHT}_{R,G,B}`
(default 1024 = no correction). Define these in the board's `config.h`.
