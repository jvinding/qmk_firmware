# GAME / GAME_FN — sofle_choc_rgb_trackpad

Quick reference for the gaming layers. Source: `keymap.c` `[JV_GAME]` and `[JV_GAME_FN]`.

## Activation

- **Toggle GAME on/off** — outer right thumb (`TG(JV_GAME)`) on any normal layer (also bottom-right of GAME itself).
- **Hold GAME_FN** — leftmost outer thumb *or* right inner thumb (`MO(JV_GAME_FN)`) while GAME is active.

## GAME

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  5  │                 │  6  │  7  │  8  │  9  │  0  │  -  │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │                 │  Y  │  U  │  I  │  O  │  P  │  \  │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│LSFT │  A  │  S  │  D  │  F  │  G  │                 │  H  │  J  │  K  │  L  │  ;  │  '  │
├─────┼─────┼─────┼─────┼─────┼─────┤ ┌─────┐ ┌─────┐ ├─────┼─────┼─────┼─────┼─────┼─────┤
│LCTL │  Z  │  X  │  C  │  V  │  B  │ │ F12 │ │BTN1 │ │  N  │  M  │  ,  │  .  │  /  │ KP+ │
└─────┴─────┴─────┴─────┴─────┴─────┘ └─────┘ └─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
          ┌─────┬─────┬─────┬─────┬─────┐ ┌─────┬─────┬─────┬─────┬─────┐
          │ FN  │LSFT │ SPC │LCTL │LALT │ │ FN  │ ENT │LALT │RSFT │ TG  │
          └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

**Encoders**
- Left: press = `F12`; rotate CCW/CW = `VolDn` / `VolUp`
- Right: press = `MS_BTN1`; rotate = passes through to layer beneath GAME

## GAME_FN  (held)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │ KP1 │ KP2 │ KP3 │ KP4 │ KP5 │                 │ F1  │ F2  │ F3  │ F4  │ F5  │  =  │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│ KP- │PgUp │Home │  ↑  │ End │PrtSc│                 │NUMLK│ KP. │ KP* │ KP/ │ KP= │KPENT│
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│BkSp │PgDn │  ←  │  ↓  │  →  │ Ins │                 │ Del │LCTL │LSFT │LALT │ F11 │ F12 │
├─────┼─────┼─────┼─────┼─────┼─────┤ ┌─────┐ ┌─────┐ ├─────┼─────┼─────┼─────┼─────┼─────┤
│ KP+ │ KP6 │ KP7 │ KP8 │ KP9 │ KP0 │ │  ▽  │ │  ▽  │ │ F6  │ F7  │ F8  │ F9  │ F10 │  ✗  │
└─────┴─────┴─────┴─────┴─────┴─────┘ └─────┘ └─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
          ┌─────┬─────┬─────┬─────┬─────┐ ┌─────┬─────┬─────┬─────┬─────┐
          │  ▽  │  ▽  │  ▽  │  ▽  │  ▽  │ │  ▽  │  ▽  │  ▽  │  ▽  │  ▽  │
          └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

## Legend

| Symbol | Meaning |
|---|---|
| `FN` | `MO(JV_GAME_FN)` — hold to access GAME_FN |
| `TG` | `TG(JV_GAME)` — toggle GAME off |
| `BTN1` | `MS_BTN1` — left mouse click |
| `KP+` `KP-` `KP*` `KP/` `KP=` | numpad operators |
| `KP0`–`KP9` | numpad digits |
| `KPENT` | numpad enter |
| `NUMLK` | num lock |
| `▽` | `KC_TRNS` — transparent (falls through to GAME) |
| `✗` | `KC_NO` — blocked, no action |
