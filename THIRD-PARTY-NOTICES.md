# Third-party notices and provenance

Not all of this is my own work. A large part of this mission is not. This page
says what came from someone else and what state it is in.

---

## Code by other authors, included unmodified

### Heyoxe — GUI defines

`src/Dialog.VR/dialog/MrFrost_defines.hpp` (50 KB)

Despite the filename, this is **Heyoxe's** work — the header inside says so. It
provides the `MrFrost_POSITION(X,Y,W,H)` macro that converts 1920 × 1080 pixel
coordinates into safezone-relative ones at preprocess time, plus the
`MrFrost_Rsc*` control base classes that every dialog in this pack inherits
from. Nothing here renders without it.

Untouched. No documentation header was added to it, and it is marked
`linguist-vendored` so it does not count toward this repository's language
statistics.

Profile: <https://steamcommunity.com/id/Heyoxe/>

### Bryan "Tonic" Boardwine — Altis Life RPG framework

This is a mission, not a script folder, so it carries a slice of the stock
Altis Life 5.0 framework. Those files are **Tonic's**, not mine. They are here
so the mission preprocesses and opens in the Eden editor — the custom dialogs
inherit from `common.hpp` and there is nothing to look at without them.

Every one of these is byte-identical to the framework. The source files among
them are marked `linguist-vendored` so they do not count toward this
repository's language statistics.

**Stock dialogs** — `src/Dialog.VR/dialog/`

| File | What it is |
| --- | --- |
| `admin_menu.hpp` | Admin menu, IDD 2900 |
| `common.hpp` | Stock control base classes — the whole pack depends on it |
| `compensate.hpp` | Compensation dialog, IDD 9920 |
| `emp_menu.hpp` | EMP menu, IDD 3494 |
| `gang.hpp` | Gang menu, IDD 2620 and 2520 |
| `hud_nameTags.hpp` | Name tags |
| `ticket.hpp` | Ticket dialog, IDD 2650 and 2600 |
| `veh_shop.hpp` | Vehicle shop, IDD 2300 |
| `vehicleShop.hpp` | Vehicle shop, IDD 2300 |
| `wanted_list.hpp` | Wanted list, IDD 2400 |

**Stock functions** — all 24 files in `src/Dialog.VR/dialog/function/`

```
fn_bankDeposit.sqf        fn_safeFix.sqf
fn_bankTransfer.sqf       fn_safeInventory.sqf
fn_bankWithdraw.sqf       fn_safeOpen.sqf
fn_displayHandler.sqf     fn_safeStore.sqf
fn_gangBankResponse.sqf   fn_safeTake.sqf
fn_garageLBChange.sqf     fn_sellGarage.sqf
fn_impoundMenu.sqf        fn_setMapPosition.sqf
fn_insureCar.sqf          fn_spawnConfirm.sqf
fn_progressBar.sqf        fn_spawnMenu.sqf
fn_unimpound.sqf          fn_spawnPointCfg.sqf
fn_useGangBank.sqf        fn_spawnPointSelected.sqf
fn_vehicleGarage.sqf      fn_wireTransfer.sqf
```

To be clear about what this folder is not: these are the framework's own
functions. **None of them was written for the dialogs in this pack**, and there
are no controller functions for those dialogs anywhere in this repository. See
the [README](README.md#this-is-not-a-drop-in-script).

**Other stock files**

| File | What it is |
| --- | --- |
| `src/Dialog.VR/script_macros.hpp` | Framework macros |
| `src/Dialog.VR/dialog/player_sys.sqf` | Defines `playersys_DIALOG` = 2001, the IDD `player_inv.hpp` uses |
| `src/Dialog.VR/mission.sqm` | The Eden mission file, written by the editor |
| `src/Dialog.VR/description.ext` | Mission config; includes `dialog/MasterHandler.hpp` |
| `src/Dialog.VR/init.sqf` | Empty, 0 bytes, kept as found |

---

## Artwork

### Replaced

| Path | Was | Now |
| --- | --- | --- |
| `src/Dialog.VR/pictures/GUI/Logo_Mammut.paa` | Mammut-Roleplay.de logo | 1024 × 1024 DXT5, fully transparent |

This pack was commissioned work for a project built around
**Mammut-Roleplay.de**. The logo was theirs, never mine — MrFrost said so in the
original release post and offered to swap the file if the rights holder asked.
It has now been swapped. The replacement is a generated placeholder of identical
dimensions and pixel format, so every path still resolves and every dialog still
opens; the logo control simply draws nothing.

Five dialogs reference it:

| File | Line | Control class | Box (1080p px) |
| --- | --- | --- | --- |
| `cell_phone.hpp` | 111 | `MrFrost_RscPicture` | 512 × 512 |
| `key_chain.hpp` | 114 | `MrFrost_RscPictureKeepAspect` | 462 × 462 |
| `player_inv.hpp` | 204 | `MrFrost_RscPictureKeepAspect` | 412 × 412 |
| `settings.hpp` | 164 | `MrFrost_RscPictureKeepAspect` | 412 × 412 |
| `spawnSelection.hpp` | 109 | `MrFrost_RscPictureKeepAspect` | 412 × 412 |

See [`src/Dialog.VR/pictures/GUI/README.md`](src/Dialog.VR/pictures/GUI/README.md)
for the spec if you want to drop your own logo in.

### Kept

Original to the pack and shipping exactly as they were:

| File | Resolution | Format |
| --- | --- | --- |
| `ico_*.paa` (10 files) | 64 × 64 | DXT5 |
| `Money_Bank.paa` | 256 × 256 | DXT5 |
| `Money_Cash.paa` | 256 × 256 | DXT5 |
| `ZMenu_Diagonal.paa` | 1024 × 1024 | DXT1 |
| `Spawn_Background.paa` | 1920 × 1080 | ARGB1555 |
| `PreviewBackground.jpg` | 1920 × 1080 | JPEG |

`Spawn_Background.paa` is deliberately non-power-of-two — it is a full-screen
backdrop for `spawnSelection.hpp`, authored at exactly 1080p.
`PreviewBackground.jpg` is an in-game screenshot used as a decorative panel
background by seven dialogs.

### Screenshots

`assets/*.jpg` are my own screenshots, taken in the VR test mission in 2020-2021
and re-encoded from PNG to JPEG for this repository. Nothing in them was
retouched.

Several of them show the **Mammut-Roleplay.de logo** as it appeared at the time,
because that artwork was still in the build when the screenshots were taken. The
logo file itself is not redistributed here - `Logo_Mammut.paa` is a transparent
placeholder - so a clean checkout renders those panels without it. The
screenshots are kept unaltered as a record of how the pack actually looked.

`assets/hud-stats.jpg` and `assets/hud-stats-2.jpg` are two revisions of the
same HUD, roughly three years apart.

### Referenced but not redistributed

The dialogs pull a number of stock Bohemia Interactive UI assets in by path.
These load from the game installation and none of them is included here:

| Path prefix | Used for |
| --- | --- |
| `\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa` | The close button on sixteen dialogs |
| `\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_saveas_ca.paa` | `player_inv.hpp` |
| `\A3\ui_f\data\IGUI\RscTitles\HealthTextures\` | Blood and dust overlays in `deathScreen.hpp` |
| `\A3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\icon_cross_ca.paa` | `deathScreen.hpp` |
| `\A3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa` | `progress.hpp` |
| `\A3\ui_f\data\map\mapcontrol\` | The map icon set used by `spawnSelection.hpp` |
| `\A3\ui_f\data\gui\cfg\scrollbar\`, `\slider\` | Scrollbar and slider chrome, via `MrFrost_defines.hpp` |
| `\A3\ui_f\data\GUI\RscCommon\` | Combo arrows, tree expanders, checkboxes, shortcut buttons |
| `\A3\ui_f\data\map_background2_co.paa` | Map control background |
| `\A3\ui_f\data\sound\` | Stock UI button sounds |

---

## If something here is yours

Open an issue or contact me and I will remove it. That was the standing offer in
the original release post and it still applies.
