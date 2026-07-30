# Known issues

Everything below was found while archiving this in 2026. **None of it has been
fixed** — this repository preserves the 2021 code as released, because I can no
longer test a change. Each entry says what a fix would look like so you can make
it yourself.

One thing to keep in mind while reading: this pack ships **layouts, not a
working feature set**. Issue 7 is the reason none of the rest can be confirmed
in-game.

---

## 1 — `MrFrost_IDD_Interaction` is never defined

**Severity: high. This is the first thing to fix.**

`src/Dialog.VR/dialog/pInteraction.hpp` lines 128–129:

```cpp
class pInteraction_Menu {
    idd = MrFrost_IDD_Interaction;
```

That macro does not exist. Nowhere in the project is `MrFrost_IDD_Interaction`
defined. The two macros that *are* defined in the same file are:

```cpp
#define MrFrost_IDD_pInteraction 37400   // line 35
#define MrFrost_IDD_vInteraction 37400   // line 74
```

Note the lowercase `p` and `v` prefixes. The Arma preprocessor passes an unknown
identifier through literally rather than erroring, so the config ends up with a
non-numeric `idd` on the player interaction menu. The vehicle menu on line 471
is fine — it uses `MrFrost_IDD_vInteraction`.

### The same mistake in ten more places

The interaction menu is the headline because it breaks a whole dialog, but it is
one instance of a pattern. Eleven `MrFrost_ID*` names are referenced by a dialog
or a control and defined nowhere in the project:

| File | Undefined name referenced | Line | Almost certainly meant |
| --- | --- | --- | --- |
| `pInteraction.hpp` | `MrFrost_IDD_Interaction` | 129 | `MrFrost_IDD_pInteraction` (37400, line 35) |
| `pInteraction.hpp` | `MrFrost_IDC_vInteraction_Button_Close` | 791 | nothing matches; the p-side has `MrFrost_IDC_pInteraction_Button_Close` (-1, line 71), the v-side has no equivalent |
| `hud_stats.hpp` | `MrFrost_IDC_PlayerHUD_Life` | 125 | `MrFrost_IDC_PlayerHUD_Life_Bar` (2201, line 43) |
| `hud_stats.hpp` | `MrFrost_IDC_PlayerHUD_Food` | 132 | `MrFrost_IDC_PlayerHUD_Food_Bar` (2200, line 44) |
| `hud_stats.hpp` | `MrFrost_IDC_PlayerHUD_Water` | 139 | `MrFrost_IDC_PlayerHUD_Water_Bar` (2202, line 45) |
| `bank.hpp` | `MrFrost_IDC_ATM_Gang_Button_Deposit` | 368 | `MrFrost_IDC_ATM_Button_Gang_Deposit` (2706, line 70) |
| `bank.hpp` | `MrFrost_IDC_ATM_Gang_Button_Withdraw` | 387 | `MrFrost_IDC_ATM_Button_Gang_Withdraw` (2705, line 69) |
| `shops.hpp` | `MrFrost_IDC_ItemShop_Button_Elements_Buy` | 225 | `MrFrost_IDC_ItemShop_Button_Elements_BuySell` (38405, line 52) |
| `shops.hpp` | `MrFrost_IDC_ItemShop_Background_Button_Close` | 99 | nothing matches; the file has no `*_Button_Close_Image` define, only `MrFrost_IDC_ItemShop_Button_Close` (-1, line 54) for the button itself |
| `key_chain.hpp` | `MrFrost_IDC_Keys_Background_Keys_Combo` | 163 | nothing matches; its sibling backgrounds are `MrFrost_IDC_Keys_Background_Keys_List` / `_Buttons` / `_Value`, all -1 |
| `settings.hpp` | `MrFrost_IDC_Edit_Settings_ViewDistance_Air_Edit` | 320 | `MrFrost_IDC_Background_Settings_ViewDistance_Air_Edit` (-1, line 59), matching the Foot and Car siblings on lines 308 and 314 |

Four of those eleven — the two close buttons, the key-chain combo background and
the settings background — were headed for `-1` anyway, so nothing visible
changes at runtime. They are still malformed config values.

**The three HUD bars are the worst case.** `PlayerHUD_Life`, `PlayerHUD_Food`
and `PlayerHUD_Water` are the only `MrFrost_RscProgress` controls in the pack,
and none of them gets its number:

```cpp
    class PlayerHUD_Life : MrFrost_RscProgress {
        idc = MrFrost_IDC_PlayerHUD_Life;      // line 125
```

2200, 2201 and 2202 are defined and reach no control, so `displayCtrl 2201`
finds nothing and the health bar can never be driven from script. 2705, 2706 and
38405 are orphaned the same way — the gang deposit and withdraw buttons and the
item shop's buy/sell button are all unaddressable.

**Fix:** change line 129 to the correct macro, then work down the table.

```cpp
    idd = MrFrost_IDD_pInteraction;
```

Each row is a one-token edit. For the four rows with no matching define, add the
missing `#define ... -1` next to its siblings rather than inventing a number.

## 2 — One IDC given to two controls in the same dialog

Two files do this.

`src/Dialog.VR/dialog/player_inv.hpp` gives the number 2014 to two different
controls, both inside the single `playerSettings` dialog that starts at line
160:

```cpp
#define MrFrost_IDC_ZMenu_Licenses_List_Text 2014   // line 63
#define MrFrost_IDC_ZMenu_Button_Cellphone   2014   // line 114
```

Both are used — the structured text control at line 606, the button at line 750:

```cpp
                    idc = MrFrost_IDC_ZMenu_Licenses_List_Text;   // line 606
			idc = MrFrost_IDC_ZMenu_Button_Cellphone;             // line 750
```

`src/Dialog.VR/dialog/FuelStat.hpp` does the same with 20901, inside
`Life_FuelStat`. The slider and the panel drawn behind it carry one number:

```cpp
        class Fuel_Background_Slider : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Slider;   // line 233

        class Fuel_Slider : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_Fuel_Slider;   // line 240
```

The background was meant to use its own macro, which is defined and then
referenced by nothing:

```cpp
#define MrFrost_IDC_Fuel_Background_Slider -1   // line 55
#define MrFrost_IDC_Fuel_Slider 20901           // line 56
```

In both cases `displayCtrl` on the shared number is ambiguous and one of the two
controls is unreachable from script. The fuel slider still responds to its own
`onSliderPosChanged` on line 245, because that handler is passed the control
directly, but anything that looks 20901 up by number may get the `RscText`.

Unlike issue 5, these are genuine collisions: in each case the two controls live
in the same display and are on screen at the same time.

**Fix:** for `FuelStat.hpp`, change line 233 to
`MrFrost_IDC_Fuel_Background_Slider`. That is a one-token edit with no script
side — the macro is already defined as -1 and the panel needs no id.

For `player_inv.hpp`, give one of the two a free number and update whichever
handler addresses it. 2014 sits in the stock Altis Life `player_sys.sqf` range,
so check what the stock inventory handler expects before deciding which of the
two to move.

## 3 — `progress.hpp` never reaches the config

`dialog/MasterHandler.hpp` has 29 `#include` lines, and `progress.hpp` is not
one of them. It is the only one of the 20 MrFrost dialog files left out. The
tail of the include list:

```cpp
#include "FuelStat.hpp"      // line 30
#include "newsStation.hpp"   // line 31
#include "emp_menu.hpp"      // line 32
```

`description.ext` pulls in nothing else:

```cpp
#include "dialog\MasterHandler.hpp"   // line 2
```

So `life_progress` (progress.hpp line 58) and `life_timer` (line 107) are never
seen by the mission at all. There is also no `class RscTitles { }` anywhere in
the mission, which is where both belong — they are `cutRsc` resources, not
dialogs.

The stock functions shipped in `dialog/function/` do call them.
`fn_progressBar.sqf` line 10, and `fn_safeFix.sqf` lines 18 and 36:

```sqf
"progressBar" cutRsc ["life_progress","PLAIN"];
```

With the resource absent from config that line does nothing, the
`uiNamespace getVariable "life_progress"` on the following line returns `nil`,
and every `progressSetPosition` after it fails.

Worth noting in passing: `life_timer` is the one class in the pack that skips
the macro convention entirely — a literal `idd = 38300` on line 109 and a
literal `idc = 38301` on line 129, where every other file goes through a
`MrFrost_ID*` define.

**Fix:** add `#include "progress.hpp"` to `MasterHandler.hpp`, and declare both
resources under `RscTitles` rather than at config root:

```cpp
class RscTitles {
    class life_progress { /* ... */ };
    class life_timer { /* ... */ };
};
```

`hud_stats.hpp` needs the same treatment. It *is* included, on line 14, but its
`playerHUD` class (line 65) is another `cutRsc` resource sitting at config root
with no `RscTitles` around it.

## 4 — `newsStation.hpp` redefines `MrFrost_IDD_Trunk`

Two files define the same macro name with different values:

```cpp
#define MrFrost_IDD_Trunk 3500      // trunk.hpp line 33
#define MrFrost_IDD_Trunk 100100    // newsStation.hpp line 34
```

`dialog/MasterHandler.hpp` includes `trunk.hpp` on line 20 and
`newsStation.hpp` on line 31. Because preprocessing is single-pass and
top-to-bottom, `TrunkMenu` is resolved to 3500 before the redefinition happens
and `life_news_broadcast` then gets 100100 — so both dialogs do end up with the
number they were meant to have.

What it costs you is a macro-redefinition warning in the RPT, and a trap: reorder
those two `#include` lines, or include `newsStation.hpp` without `trunk.hpp`, and
the numbers move.

**Fix:** rename the macro in `newsStation.hpp` to something that describes the
dialog, e.g. `MrFrost_IDD_NewsStation`, and update its `idd =` on line 78. See
also issue 9.

## 5 — Duplicate IDDs across dialogs

This is a caveat, not a crash. Two dialogs may share an IDD in Arma as long as
they are never open simultaneously; `findDisplay` becomes ambiguous only if they
are. Included here because you have to know about it before you combine these
files with a stock mission.

| IDD | Dialogs |
| --- | --- |
| 2300 | `vehicleShop3D.hpp` + stock `veh_shop.hpp` + stock `vehicleShop.hpp` |
| 2400 | `shop_items.hpp` + stock `wanted_list.hpp` |
| 2700 | `bank.hpp` + `key_chain.hpp` |
| 2900 | `settings.hpp` + stock `admin_menu.hpp` |
| 3500 | `trunk.hpp` + `federalReserve.hpp` |

The 2300 row is the one that needs a decision rather than just awareness: all
three are alternative vehicle shops, so **pick exactly one** and drop the other
two from your `MasterHandler.hpp`.

> **Not a bug:** `pInteraction.hpp` repeats the IDCs 37401, 37450–37457 and
> 50020–50022. That is deliberate. `pInteraction_Menu` and `vInteraction_Menu`
> are two separate displays sharing one layout, so the same control numbers
> appear twice by design.

**Fix:** renumber whichever side you control, and move the matching
`displayCtrl` numbers in its handler at the same time.

## 6 — Copy/paste `onLoad` leftovers

Two dialogs carry an `onLoad` that belongs to a different dialog.

`src/Dialog.VR/dialog/FuelStat.hpp` line 83 — active:

```cpp
    onLoad = "ctrlShow [2330,false];";
```

2330 is a control id in the stock vehicle shop. `Life_FuelStat` has no control
2330 of its own, so the statement acts on whatever is holding that number when
the fuel dialog opens.

`src/Dialog.VR/dialog/clothing.hpp` line 87 — commented out in the shipped file:

```cpp
    //onLoad = "[] execVM 'core\client\keychain\init.sqf'";
```

A clothing shop starting the key chain's init script. It is disabled as
released, so it does nothing today, but it is clearly a leftover from the key
chain dialog rather than something written for `Life_Clothing`.

**Fix:** delete both lines. Neither does anything the dialog needs.

## 7 — No controller functions are shipped

**This is the defining limitation of the repository, not a defect in any one
file.**

The custom dialogs reference roughly 47 distinct `life_fnc_*` handlers —
`life_fnc_buyClothes`, `life_fnc_weaponShopBuySell`, `life_fnc_spawnConfirm`,
`life_fnc_keyMenu`, and so on. **None of them are in this repository.**
`src/Dialog.VR/dialog/function/` contains only the 24 stock Altis Life
functions, and none of those were written for these layouts.

What that means in practice: open any of these dialogs in the VR mission and you
get the visual layout with empty lists and inert buttons. Nothing is broken —
there is simply nothing behind it.

**Fix:** there is no fix; this is what the pack is. To use a dialog you write
the handler yourself or adapt the stock Altis Life one, keeping the IDCs aligned
either way. See [installation.md](installation.md#taking-one-dialog-into-your-own-mission).

## 8 — Texture reference with the wrong capitalisation

`player_inv.hpp` line 768 asks for a lowercase filename:

```cpp
class ZMenu_Button_Adminmenu : MrFrost_MammutRP_RscButtonMenu {
    textureNoShortcut = "pictures\GUI\ico_admin.paa";
```

The file on disk is `ico_Admin.paa`, with a capital A. Windows does not care,
because its filesystem is case-insensitive. **On a Linux server it silently
fails** and the admin-menu button in the Z-menu renders without its icon.

This is the same class of bug that affected the Info Menu logo, and it is the
only remaining one of its kind — the other 22 texture references in this pack
resolve exactly.

**Fix:** either rename `src/Dialog.VR/pictures/GUI/ico_Admin.paa` to
`ico_admin.paa`, or change the one reference to match the file. Renaming the
asset is the smaller change and needs no code edit. Neither was done here,
because this archive leaves original files as it found them.

## 9 — Cosmetic

- **`newsStation.hpp`** — its IDD macro is named `MrFrost_IDD_Trunk`. The root
  class is `life_news_broadcast`; it has nothing to do with a trunk. Harmless in
  itself, but it is what causes issue 4.
- **`src/Dialog.VR/test.sqf`** — an unfinished scratch file. It defines a
  `MrFrost_Esc_POSITION` macro, then grabs four controls from display 49 (the
  Esc menu) — `_abortButton`, `_respawnButton`, `_fieldManual`, `_saveButton` —
  and stops. It does nothing and nothing references it. Preserved as found.
- **`src/Dialog.VR/init.sqf`** — empty, 0 bytes. Preserved as found.

---

## Summary

| # | Issue | Severity | Affects |
| --- | --- | --- | --- |
| 1 | 11 `MrFrost_ID*` macros referenced but never defined | **High** — non-numeric `idd`, 6 orphaned IDCs | `pInteraction.hpp`, `hud_stats.hpp`, `bank.hpp`, `shops.hpp`, `key_chain.hpp`, `settings.hpp` |
| 2 | One IDC given to two controls in one dialog | Medium — one control unreachable | `player_inv.hpp` (2014), `FuelStat.hpp` (20901) |
| 3 | `progress.hpp` never reaches the config | Medium — `life_progress` / `life_timer` missing | `MasterHandler.hpp`, `progress.hpp` |
| 4 | `MrFrost_IDD_Trunk` redefined | Low — warning, breaks if reordered | `trunk.hpp` / `newsStation.hpp` |
| 5 | Duplicate IDDs across dialogs | Caveat — only if both are open | 5 IDDs, 11 dialogs |
| 6 | Copy/paste `onLoad` leftovers | Low | `FuelStat.hpp`, `clothing.hpp` |
| 7 | No controller functions shipped | By design — layouts only | Whole pack |
| 8 | `ico_admin.paa` vs `ico_Admin.paa` | Low — breaks on Linux only | `player_inv.hpp` |
| 9 | Cosmetic | — | — |
