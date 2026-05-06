# jvinding user space

Shared layout, OLED, and hooks live under this directory.  
Per-keyboard `rules.mk` at `keyboards/.../keymaps/jvinding/` is what the build system actually includes—keep feature flags and `SRC` there (or in that keyboard’s `config.h`).

## Build and flash (from the QMK repo root)

1. `cd` to the QMK root (this repo’s top level).
2. **Compile** with `qmk compile -kb <keyboard> -km jvinding`.
3. The firmware binary is under `.build/` (e.g. `.uf2` for RP2040).
4. **Flash**: put the board in bootloader mode, then either copy the `.uf2` to the mount that appears (often `RPI-RP2` on RP2040) or use `qmk flash -kb <keyboard> -km jvinding` if your environment is set up for it.

### Holykeebs Corne (crkbd) — `rev1_hk`

- **Board path:** `crkbd/rev1_hk`
- **Compile**
  - `qmk compile -kb crkbd/rev1_hk -km jvinding`
- **Output**
  - `.build/crkbd_rev1_hk_jvinding.uf2`
- **Flash**
  - Unplug, hold **reset** (or the boot combo for your half), plug in USB, release when the drive mounts; copy the `.uf2` to that drive.  
  - **Split:** flash the same `.uf2` to **both** halves (or follow Holykeebs’ left/right build if you ever use side-specific images).

### Holykeebs Span — `holykeebs/spankbd`

- **Board path:** `holykeebs/spankbd`
- **Compile**
  - `qmk compile -kb holykeebs/spankbd -km jvinding`
- **Output**
  - `.build/holykeebs_spankbd_jvinding.uf2`
- **Flash**
  - Unplug, hold **reset** (or double-tap the reset button) to enter bootloader, plug in USB; copy the `.uf2` to the drive that mounts.
  - **Split:** flash the same `.uf2` to **both** halves.

### ControllerWorks Mini42 — `controllerworks/mini42`

- **Board path:** `controllerworks/mini42`
- **Compile**
  - `qmk compile -kb controllerworks/mini42 -km jvinding`
- **Output**
  - `.build/controllerworks_mini42_jvinding.uf2`
- **Flash**
  - Unplug, hold **reset** (or tap `JV_TD_BOOT` on the FUN layer) to enter bootloader, plug in USB; copy the `.uf2` to the drive that mounts.
  - **Split:** flash the same `.uf2` to **both** halves.
- **Notes**
  - Master = **right** half (USB-connected side).
  - Outer pinky columns are not used; those positions are `KC_NO` on every layer.
  - Right OLED: layer name + Caps Lock + Caps Word indicator.
  - Left OLED: live status board — layer, modifiers, WPM, uptime.
  - RGB brightness cap starts at `120`; lower `RGB_MATRIX_MAXIMUM_BRIGHTNESS` in `config.h` if the board browns out.

### ControllerWorks City42 — `controllerworks/city42`

- **Board path:** `controllerworks/city42`
- **Compile**
  - `qmk compile -kb controllerworks/city42 -km jvinding`
- **Output**
  - `.build/controllerworks_city42_jvinding.uf2`
- **Flash**
  - Hold upper-left key while plugging in USB (bootmagic), or double-tap the RST button; copy the `.uf2` to the `RPI-RP2` drive that mounts.
  - **Unibody:** single MCU — only one half to flash.
- **Notes**
  - Unibody (single RP2040, no split).
  - 40 mm Cirque trackpad (SPI, relative mode): cursor + tap-to-click + two-finger right-click work out of the box with no keymap code.
  - Outer pinky columns carry `MS_BTN1/2` and scroll wheel keys (same as crkbd).
  - No OLED.
  - RGB brightness cap starts at `120`; all 42 LEDs are per-key (no underglow).

---

Add a new **”### Name — path”** subsection for each future keyboard so the list stays a single place to look.
