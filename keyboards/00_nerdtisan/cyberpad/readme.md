# CyberPad by Nerdtisan

![nerdtisan](https://www.nerdtisan.com))

A compact 11-key macropad featuring 2 rotary encoders, RGB matrix lighting, and an OLED display with an animated asteroid screensaver. Designed for productivity, creative workflows, and customization.

* Keyboard Maintainer: [Adrian](https://github.com/Aiddy81)
* Hardware Supported: RP2040
* Hardware Availability: [Nerdtisan](https://www.nerdtisan.com)

## Features

- **11 Keys**: 9 programmable keys in a 3x3 grid + 2 encoder buttons
- **2 Rotary Encoders**: Fully programmable rotation and click actions
- **RGB Matrix Lighting**: Per-key RGB LEDs with multiple effects
- **128x64 OLED Display**: Shows current layer, key mappings, and animated screensaver
- **4 Programmable Layers**: Easily switch between different key configurations
- **VIA Compatible**: Real-time remapping without reflashing firmware
- **Space Invaders Screensaver**: Classic arcade game animation after 10 seconds of inactivity

## Layout

```
┌─────────┬─────────┬─────────┐
│ Encoder1│ Encoder2│         │
│  (Click)│  (Click)│         │
├─────────┼─────────┼─────────┤
│   Key   │   Key   │   Key   │
│    1    │    2    │    3    │
├─────────┼─────────┼─────────┤
│   Key   │   Key   │   Key   │
│    4    │    5    │    6    │
├─────────┼─────────┼─────────┤
│   Key   │   Key   │   Key   │
│    7    │    8    │    9    │
└─────────┴─────────┴─────────┘
```

## Default Layers

### Layer 0 (Base)
- **Encoder 1 Click**: Layer cycle
- **Encoder 1 Rotate**: Volume Up/Down
- **Encoder 2 Click**: Media Play/Pause
- **Encoder 2 Rotate**: Next/Previous Track
- **Keys 1-9**: Number keys 1-9

### Layer 1 (Function 1)
- **Encoder 1 Click**: Layer cycle
- **Encoder 1 Rotate**: RGB Brightness Up/Down
- **Encoder 2 Click**: RGB Mode Next
- **Encoder 2 Rotate**: RGB Hue Up/Down
- **Keys 1-9**: Function keys F13-F21

### Layers 2 & 3
- Transparent (pass through to Layer 0)
- Ready for your custom mappings via VIA

## OLED Display Features

### Active Mode
Displays real-time information:
- Current active layer (0-3)
- Encoder button assignments
- Encoder rotation functions (CW/CCW)
- 3x3 key grid with current mappings
- Dynamic updates when remapping via VIA

### Screensaver Mode
After 10 seconds of inactivity:
- Classic Space Invaders game animation
- 12 invaders in 3 rows (W, M, V characters) marching back and forth
- Auto-firing ship (A) at the bottom tracking and shooting invaders
- Bullets (|) automatically fire and destroy invaders on contact
- Invaders drop down when hitting edges (classic arcade behavior)
- Game resets when all invaders destroyed or they reach the bottom
- Any key press, encoder rotation, or button click exits screensaver

## Building the Firmware

### Prerequisites
Set up your QMK build environment following the [QMK documentation](https://docs.qmk.fm/#/getting_started_build_tools).

### Compile
```bash
make 00_nerdtisan/cyberpad/rev1:via
```

### Flash
```bash
make 00_nerdtisan/cyberpad/rev1:via:flash
```

## Bootloader

Enter the bootloader in 3 ways:

1. **Bootmagic reset**: Hold down the top-left key (Encoder 1) and plug in the keyboard
2. **Physical reset button**: Press the reset button on the back of the PCB
3. **Keycode in layout**: Press the key mapped to `QK_BOOT` if configured

## VIA Configuration

This keyboard is VIA-compatible! You can remap keys in real-time using [VIA](https://www.caniusevia.com/):

1. Download and install VIA
2. Connect your CyberPad
3. VIA should automatically detect it
4. Remap keys, encoders, and configure settings without reflashing

**Note**: The OLED display will automatically update to show your new key mappings!

## Customization

### Adding Custom Keycodes

The firmware includes a custom `KC_CLAY` keycode for layer cycling. You can add more custom keycodes by:

1. Adding to the `enum keycodes` section
2. Implementing behavior in `process_record_user()`
3. Adding display names in `get_key_name()` for OLED support

**Note**: Custom keycodes must be defined in `keymap.c` to appear on the OLED.
**Note 2**: In VIA to assign custom keycode KC_CLAY, use `CUSTOM(64)`.

### Modifying the Screensaver

The Space Invaders game can be customized in `keymap.c`:

- `IDLE_TIMEOUT`: Time before screensaver starts (default: 10000ms)
- `GAME_UPDATE_INTERVAL`: Invader movement speed (default: 200ms)
- `BULLET_UPDATE_INTERVAL`: Bullet speed (default: 30ms)
- `FIRE_INTERVAL`: Auto-fire rate (default: 800ms)
- `NUM_INVADERS`: Number of invaders (default: 12)
- Invader formations, speeds, and starting positions
- Ship AI behavior and tracking algorithm

### RGB Effects

Access RGB controls via Layer 1:
- **Encoder 1**: Brightness control
- **Encoder 2**: Hue control
- Press Encoder 1: Toggle RGB on/off
- Press Encoder 2: Cycle through RGB modes

## Troubleshooting

### OLED not displaying correctly
- Check `oled_rotation_t` in `oled_init_user()` - try different rotations (0, 90, 180, 270)
- Verify OLED is enabled in `rules.mk`: `OLED_ENABLE = yes`

### Encoders not working
- Ensure `ENCODER_ENABLE = yes` and `ENCODER_MAP_ENABLE = yes` in `rules.mk`
- Check encoder pin definitions in `config.h`

### VIA not detecting keyboard
- Confirm `VIA_ENABLE = yes` in `rules.mk`
- Update VIA to the latest version
- Try a different USB cable/port

### Layer cycling not working
- Ensure `KC_CLAY` (or `KC_TRNS`) is set on the encoder button for all layers
- Check that `LAYER_CYCLE_END` matches your total layers minus 1

## Resources

- [QMK Documentation](https://docs.qmk.fm/)
- [VIA Documentation](https://www.caniusevia.com/docs/specification)
- [Nerdtisan Website](https://www.nerdtisan.com)
- [QMK Discord](https://discord.gg/qmk)
- [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) 
- [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) 
- [Complete Newbs Guide](https://docs.qmk.fm/#/newbs)


## License

This project follows QMK's GPL-2.0-or-later license.

---

**Made with ❤️ by the mechanical keyboard community**




