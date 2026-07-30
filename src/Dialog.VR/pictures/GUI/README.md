# Textures

## `Logo_Mammut.paa` — generated placeholder

The file in this folder is a **generated placeholder**: a valid 1024 × 1024 DXT5
texture that is fully transparent. It loads without error and draws nothing.

The original was the **Mammut-Roleplay.de** logo. This UI pack was commissioned
work for that project and the artwork was never mine, so it was replaced rather
than removed — every path and every dialog stays exactly as released.

Five dialogs reference it:

| File                 | Line | Control class                  | Box (1080p px) |
| -------------------- | ---- | ------------------------------ | -------------- |
| `cell_phone.hpp`     | 111  | `MrFrost_RscPicture`           | 512 × 512      |
| `key_chain.hpp`      | 114  | `MrFrost_RscPictureKeepAspect` | 462 × 462      |
| `player_inv.hpp`     | 204  | `MrFrost_RscPictureKeepAspect` | 412 × 412      |
| `settings.hpp`       | 164  | `MrFrost_RscPictureKeepAspect` | 412 × 412      |
| `spawnSelection.hpp` | 109  | `MrFrost_RscPictureKeepAspect` | 412 × 412      |

### Dropping in your own

| Property   | Value                                               |
| ---------- | --------------------------------------------------- |
| Path       | `pictures\GUI\Logo_Mammut.paa`                       |
| Resolution | 1024 × 1024 (power of two, square)                   |
| Format     | DXT5, 8-bit alpha                                    |
| Scaling    | square box in every dialog, so no distortion either way |

Convert a PNG with **TexView 2** or `ImageToPAA.exe` from the
[Arma 3 Tools](https://store.steampowered.com/app/233800/Arma_3_Tools/), then
overwrite the placeholder. Renaming it instead means editing the five `text = `
lines above — the only code change this archive would ever need.

## Original assets

These are original to the pack and ship exactly as they were in 2021:

| File                     | Resolution  | Format    |
| ------------------------ | ----------- | --------- |
| `ico_*.paa` (10 files)   | 64 × 64     | DXT5      |
| `Money_Bank.paa`         | 256 × 256   | DXT5      |
| `Money_Cash.paa`         | 256 × 256   | DXT5      |
| `ZMenu_Diagonal.paa`     | 1024 × 1024 | DXT1      |
| `Spawn_Background.paa`   | 1920 × 1080 | ARGB1555  |
| `PreviewBackground.jpg`  | 1920 × 1080 | JPEG      |

`Spawn_Background.paa` is deliberately non-power-of-two — it is a full-screen
backdrop for `spawnSelection.hpp`, authored at exactly 1080p.
`PreviewBackground.jpg` is an in-game screenshot used as a decorative panel
background by seven dialogs.
