# jvinding — sofle_choc_rgb_trackpad keymap

## Quick references

- **`GAME.md`** — ASCII diagrams of the GAME and GAME_FN layers (readable inline or printed).
- **`game-layers.svg`** — rendered SVG of the same layers. Open in any browser.

## Regenerating the SVG

After editing the keymap, update `keymap-drawer.yaml` to match, then re-run:

```sh
# one-time install
pipx install keymap-drawer

# regenerate (run from repo root)
keymap draw keyboards/keyboardhoarders/sofle_choc_rgb_trackpad/keymaps/jvinding/keymap-drawer.yaml \
  -j keyboards/keyboardhoarders/sofle_choc_rgb_trackpad/keyboard.json \
  -o keyboards/keyboardhoarders/sofle_choc_rgb_trackpad/keymaps/jvinding/game-layers.svg
```

## Flashing

```sh
qmk compile -kb keyboardhoarders/sofle_choc_rgb_trackpad -km jvinding
qmk flash   -kb keyboardhoarders/sofle_choc_rgb_trackpad -km jvinding
```
