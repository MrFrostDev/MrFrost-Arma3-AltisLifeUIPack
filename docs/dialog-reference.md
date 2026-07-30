# Dialog reference

This is the IDD/IDC map for the 20 MrFrost-authored dialog files in
`src/Dialog.VR/dialog/`. Every number below was read out of the `.hpp` files
themselves, with `#define` macros resolved in the include order used by
`MasterHandler.hpp`. Positions in these files are authored against a 1920x1080
reference canvas and converted to safezone-relative coordinates at preprocess
time by `MrFrost_POSITION(X,Y,W,H)`, so the pixel numbers in the sources can be
read directly as 1080p pixels. Controls with `idc = -1` are decoration -- frames,
bars, backgrounds, title strips -- and are omitted here; only constants that a
script could actually address are listed.

Known defects are recorded separately in [known-issues.md](known-issues.md).
Nothing in this repository fixes them; this document only tells you what is
there.

---

## Summary

Sorted by resolved IDD, ascending.

| File | Root class | IDD | Named IDCs | What it is |
| --- | --- | --- | --- | --- |
| `hud_stats.hpp` | `playerHUD` | **-1** (resource) | 6 | Player HUD: health, food, water |
| `player_inv.hpp` | `playerSettings` | 2001 | 13 | Player inventory / Z-menu |
| `vehicleShop3D.hpp` | `Life_Vehicle_Shop_v2_3D` | 2300 | 5 | Vehicle shop with 3D preview |
| `shop_items.hpp` | `shops_menu` | 2400 | 6 | Virtual item shop |
| `bank.hpp` | `Life_atm_management` | 2700 | 6 | ATM / bank management |
| `key_chain.hpp` | `Life_key_management` | 2700 | 3 | Vehicle key chain |
| `impound.hpp` | `Life_impound_menu` | 2800 | 5 | Garage / impound |
| `settings.hpp` | `SettingsMenu` | 2900 | 9 | Settings menu |
| `cell_phone.hpp` | `Life_cell_phone` | 3000 | 12 | Cell phone |
| `clothing.hpp` | `Life_Clothing` | 3100 | 6 | Clothing store |
| `federalReserve.hpp` | `Federal_Safe` | 3500 | 4 | Federal reserve safe |
| `trunk.hpp` | `TrunkMenu` | 3500 | 7 | Vehicle trunk |
| `deathScreen.hpp` | `DeathScreen` | 7300 | 4 | Death screen overlay |
| `FuelStat.hpp` | `Life_FuelStat` | 20300 | 9 | Fuel station |
| `pInteraction.hpp` | `pInteraction_Menu` / `vInteraction_Menu` | **broken** / 37400 | 24 | Player and vehicle interaction menus |
| `progress.hpp` | `life_progress` / `life_timer` | 38200 / 38300 (resources) | 2 | Progress bar and timer |
| `shops.hpp` | `life_weapon_shop` | 38400 | 7 | Weapon shop |
| `spawnSelection.hpp` | `life_spawn_selection` | 38500 | 3 | Spawn point selection |
| `chop_shop.hpp` | `Chop_Shop` | 39400 | 2 | Chop shop |
| `newsStation.hpp` | `life_news_broadcast` | 100100 | 5 | News station broadcast |

Legend:

- **resource** -- `hud_stats.hpp` and `progress.hpp` declare RscTitles resources,
  not dialogs. They are shown with `cutRsc`, never with `createDialog`. Every
  other file in the table is opened with `createDialog "<root class>";`.
- **broken** -- `pInteraction_Menu` sets `idd = MrFrost_IDD_Interaction;`, a macro
  that is defined nowhere in the project, so its `idd` never resolves to a
  number. See [known-issues.md](known-issues.md).
- 138 named IDCs in total across the 20 files.

---

## IDD collisions

Two dialogs sharing an IDD is legal in Arma as long as they are never open at the
same time -- `createDialog` and `closeDialog` work on the class name, not the
number. It only becomes a problem for `findDisplay <idd>`, which returns whichever
matching display is currently open and is ambiguous if both are. Treat the list
below as a caveat when you lift files out of this pack into a running mission,
not as a crash.

Stock Altis Life dialogs shipped alongside these files are included, because they
are the collisions you are most likely to hit in practice.

| IDD | Declared by |
| --- | --- |
| 2300 | `vehicleShop3D.hpp` (`Life_Vehicle_Shop_v2_3D`), stock `veh_shop.hpp` (`Life_vehicle_shop`), stock `vehicleShop.hpp` (`Life_Vehicle_Shop_v2`) |
| 2400 | `shop_items.hpp` (`shops_menu`), stock `wanted_list.hpp` (`life_wanted_menu`) |
| 2700 | `bank.hpp` (`Life_atm_management`), `key_chain.hpp` (`Life_key_management`) |
| 2900 | `settings.hpp` (`SettingsMenu`), stock `admin_menu.hpp` (`life_admin_menu`) |
| 3500 | `trunk.hpp` (`TrunkMenu`), `federalReserve.hpp` (`Federal_Safe`) |

Notes on the individual cases:

- **2300** -- all three are alternative vehicle shops. Pick exactly one and remove
  the other two; they are not meant to coexist.
- **3500** -- `trunk.hpp` and `federalReserve.hpp` also reuse the same IDC numbers
  (3502, 3504, 3505) for their equivalent list, weight title and quantity field.
  They are structurally the same dialog with different labels.
- **100100** -- `newsStation.hpp` is unique at this value, but it gets there by
  redefining the macro name `MrFrost_IDD_Trunk`, which `trunk.hpp` already defined
  as 3500. Both dialogs still receive their intended number because preprocessing
  is single-pass and `MasterHandler.hpp` includes `trunk.hpp` (line 20) before
  `newsStation.hpp` (line 31), but the redefinition emits a warning and breaks if
  anyone reorders those includes. See [known-issues.md](known-issues.md).

The repeated IDCs in `pInteraction.hpp` (37401, 37450-37457, 50020-50022) are
**not** a collision. That file declares two separate displays,
`pInteraction_Menu` and `vInteraction_Menu`, which deliberately share one layout
and one numbering scheme so the same handler code can drive either. Each number
appears exactly once per display.

There is one genuine within-dialog IDC collision, in `player_inv.hpp`, and one
more in `FuelStat.hpp`. Both are noted in their sections below.

---

## `hud_stats.hpp`

Player HUD: health, food and water bars in the bottom-right corner. Root class
`playerHUD`, `idd = MrFrost_IDD_PlayerHUD` -> **-1**. This is an RscTitles
resource, not a dialog: it is shown with `cutRsc` and reached from script through
`uiNamespace getVariable "playerHUD"`, which is why the `-1` is intentional.

| IDC | Constant | Control |
| --- | --- | --- |
| 1200 | `MrFrost_IDC_PlayerHUD_Food_Text` | Food label |
| 1201 | `MrFrost_IDC_PlayerHUD_Life_Text` | Health label |
| 1202 | `MrFrost_IDC_PlayerHUD_Water_Text` | Water label |
| 2200 | `MrFrost_IDC_PlayerHUD_Food_Bar` | Food bar -- constant unused, see below |
| 2201 | `MrFrost_IDC_PlayerHUD_Life_Bar` | Health bar -- constant unused, see below |
| 2202 | `MrFrost_IDC_PlayerHUD_Water_Bar` | Water bar -- constant unused, see below |

> The three `MrFrost_RscProgress` bars (`PlayerHUD_Life`, `PlayerHUD_Food`,
> `PlayerHUD_Water`) set `idc = MrFrost_IDC_PlayerHUD_Life` / `_Food` / `_Water`
> -- without the `_Bar` suffix. Those three names are never defined. The `_Bar`
> constants listed above exist but are referenced by nothing, so 2200/2201/2202
> do not currently reach any control. See [known-issues.md](known-issues.md).

---

## `player_inv.hpp`

Player inventory and the main "Z menu". Root class `playerSettings`,
`idd = playersys_DIALOG` -> **2001**. That macro is not a `MrFrost_*` one: it
comes from `dialog/player_sys.sqf`, which the file includes at the top. Opened
with `createDialog "playerSettings";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2001 | `MrFrost_IDC_ZMenu_Money_Button_Give` | Give money button |
| 2002 | `MrFrost_IDC_ZMenu_Inventory_Button_Give` | Give item button |
| 2011 | `MrFrost_IDC_ZMenu_Button_Gang` | Gang menu button |
| 2012 | `MrFrost_IDC_ZMenu_Button_Wanted` | Wanted list button |
| 2013 | `MrFrost_IDC_ZMenu_Button_Keys` | Key chain button |
| 2014 | `MrFrost_IDC_ZMenu_Licenses_List_Text` | Licence list, structured text |
| 2014 | `MrFrost_IDC_ZMenu_Button_Cellphone` | Cell phone button |
| 2018 | `MrFrost_IDC_ZMenu_Money_Value` | Amount edit field |
| 2021 | `MrFrost_IDC_ZMenu_Button_Adminmenu` | Admin menu button |
| 2022 | `MrFrost_IDC_ZMenu_Money_Person` | Money recipient combo |
| 2023 | `MrFrost_IDC_ZMenu_Inventory_Person` | Item recipient combo |
| 50001 | `MrFrost_IDC_ZMenu_Money_Bank` | Bank balance |
| 50002 | `MrFrost_IDC_ZMenu_Money_Cash` | Cash on hand |

> **2014 is defined twice in the same dialog.** The licence text lives inside the
> `ZMenu_Licenses_List` controls group; the cell phone button is a top-level
> control. `displayCtrl 2014` therefore reaches only one of them. This is a real
> collision, not a shared layout -- see [known-issues.md](known-issues.md).

The dialog's IDD (2001) and the first IDC (2001) are the same number. That is
harmless: displays and controls live in separate namespaces.

---

## `vehicleShop3D.hpp`

Vehicle shop with a 3D preview of the selected car. Root class
`Life_Vehicle_Shop_v2_3D`, `idd = MrFrost_IDD_Life_Vehicle_Shop_v2_3D` -> **2300**.
Opened with `createDialog "Life_Vehicle_Shop_v2_3D";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2301 | `MrFrost_IDC_VehicleShop_Title_Shop` | Shop title |
| 2302 | `MrFrost_IDC_VehicleShop_List_Shop` | Vehicle list |
| 2303 | `MrFrost_IDC_VehicleShop_Text_Info` | Vehicle specs, structured text |
| 2304 | `MrFrost_IDC_VehicleShop_Combo_Elements_Color` | Colour combo |
| 2309 | `MrFrost_IDC_VehicleShop_Button_Elements_Buy` | Buy button |

> This is a drop-in replacement for the stock `veh_shop.hpp` / `vehicleShop.hpp`.
> All three declare IDD 2300 -- use exactly one.

---

## `shop_items.hpp`

Virtual item shop: buy on the left, sell from your inventory on the right. Root
class `shops_menu`, `idd = MrFrost_IDD_VShop` -> **2400**. Opened with
`createDialog "shops_menu";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2401 | `MrFrost_IDC_VShop_Shop_List` | Shop list |
| 2402 | `MrFrost_IDC_VShop_Inventory_List` | Inventory list |
| 2403 | `MrFrost_IDC_VShop_Title_Shop_List` | Shop list title |
| 2404 | `MrFrost_IDC_VShop_Shop_Value` | Shop quantity edit field |
| 2405 | `MrFrost_IDC_VShop_Inventory_Value` | Inventory quantity edit field |
| 50010 | `MrFrost_IDC_VShop_Title_Inventory_Weight` | Inventory weight readout |

---

## `bank.hpp`

ATM and bank management, including the gang bank. Root class
`Life_atm_management`, `idd = MrFrost_IDD_ATM` -> **2700**. Opened with
`createDialog "Life_atm_management";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2702 | `MrFrost_IDC_ATM_Money_Value` | Amount edit field |
| 2703 | `MrFrost_IDC_ATM_Money_Person` | Transfer recipient combo |
| 2705 | `MrFrost_IDC_ATM_Button_Gang_Withdraw` | Gang withdraw button -- constant unused, see below |
| 2706 | `MrFrost_IDC_ATM_Button_Gang_Deposit` | Gang deposit button -- constant unused, see below |
| 50003 | `MrFrost_IDC_ATM_Money_Bank` | Bank balance |
| 50004 | `MrFrost_IDC_ATM_Money_Cash` | Cash on hand |

> The two gang buttons set `idc = MrFrost_IDC_ATM_Gang_Button_Deposit` and
> `MrFrost_IDC_ATM_Gang_Button_Withdraw` -- `Gang_Button` instead of
> `Button_Gang`. Neither name is defined, so 2705 and 2706 reach no control.
> The definitions for 50003 and 50004 carry a trailing `//2701` comment, an
> earlier value that was replaced. See [known-issues.md](known-issues.md).

---

## `key_chain.hpp`

Vehicle key chain: list your keys, hand one to another player. Root class
`Life_key_management`, `idd = MrFrost_IDD_Keys` -> **2700**. Opened with
`createDialog "Life_key_management";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2701 | `MrFrost_IDC_Keys_List` | Key list |
| 2702 | `MrFrost_IDC_Keys_Combo` | Recipient combo |
| 2703 | `MrFrost_IDC_Keys_Button_Give_Key` | Give key button |

> The decorative panel behind the combo (`Keys_Background_Keys_Combo`) sets
> `idc = MrFrost_IDC_Keys_Background_Keys_Combo`, which is never defined. It was
> presumably meant to be `-1` like its neighbours.

---

## `impound.hpp`

Garage and impound lot. Root class `Life_impound_menu`,
`idd = MrFrost_IDD_Garage` -> **2800**. Opened with
`createDialog "Life_impound_menu";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2801 | `MrFrost_IDC_Garage_Title_Garage_List` | Vehicle list title |
| 2802 | `MrFrost_IDC_Garage_Garage_List` | Vehicle list |
| 2803 | `MrFrost_IDC_Garage_Text_Info` | Vehicle specs panel (a list box despite the name) |
| 2804 | `MrFrost_IDC_Garage_Button_Insurance` | Insure button |
| 2830 | `MrFrost_IDC_Garage_Title_Info` | Specs panel title |

---

## `settings.hpp`

Client settings: three view-distance sliders with matching edit fields, and three
toggles. Root class `SettingsMenu`, `idd = MrFrost_IDD_Settings` -> **2900**.
Opened with `createDialog "SettingsMenu";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2901 | `MrFrost_IDC_Slider_Settings_ViewDistance_Foot` | View distance on foot, slider |
| 2902 | `MrFrost_IDC_Edit_Settings_ViewDistance_Foot` | View distance on foot, edit field |
| 2911 | `MrFrost_IDC_Slider_Settings_ViewDistance_Car` | View distance in a car, slider |
| 2912 | `MrFrost_IDC_Edit_Settings_ViewDistance_Car` | View distance in a car, edit field |
| 2921 | `MrFrost_IDC_Slider_Settings_ViewDistance_Air` | View distance in an aircraft, slider |
| 2922 | `MrFrost_IDC_Edit_Settings_ViewDistance_Air` | View distance in an aircraft, edit field |
| 2971 | `MrFrost_IDC_Button_Settings_Buttons_SideChat` | Side chat checkbox |
| 2972 | `MrFrost_IDC_Button_Settings_Buttons_NearObjects` | Nearby objects checkbox |
| 2973 | `MrFrost_IDC_Button_Settings_Buttons_Broadcast` | Broadcast checkbox |

> The backing panel for the air edit field
> (`Background_Settings_ViewDistance_Air_Edit`) sets
> `idc = MrFrost_IDC_Edit_Settings_ViewDistance_Air_Edit`, which is undefined.
> Its foot and car counterparts correctly use
> `MrFrost_IDC_Background_Settings_ViewDistance_*_Edit`, all `-1`.

---

## `cell_phone.hpp`

Cell phone: pick a recipient, type a message, send it to a player or a faction.
Root class `Life_cell_phone`, `idd = MrFrost_IDD_Life_cell_phone` -> **3000**.
Opened with `createDialog "Life_cell_phone";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 3001 | `MrFrost_IDC_CellPhone_Title_Main` | Dialog title |
| 3002 | `MrFrost_IDC_CellPhone_Title_Message` | Message panel title |
| 3003 | `MrFrost_IDC_CellPhone_Edit_Message` | Message edit field |
| 3004 | `MrFrost_IDC_CellPhone_Combo_Player` | Recipient combo |
| 3015 | `MrFrost_IDC_CellPhone_Button_Button_SendMessage` | Send message button |
| 3016 | `MrFrost_IDC_CellPhone_Button_Button_SendCop` | Send to police button |
| 3017 | `MrFrost_IDC_CellPhone_Button_Button_SendToAdmin` | Send to admin button |
| 3020 | `MrFrost_IDC_CellPhone_Button_Button_SendAsAdmin` | Send as admin button |
| 3021 | `MrFrost_IDC_CellPhone_Button_Button_SendAsAdminAll` | Send to all as admin button |
| 3022 | `MrFrost_IDC_CellPhone_Button_Button_SendEMS` | Send to EMS button |
| 3023 | `MrFrost_IDC_CellPhone_Button_Button_SendCopAll` | Send to all as police button |
| 3024 | `MrFrost_IDC_CellPhone_Button_Button_SendAsMercenary` | Send as mercenary button |

---

## `clothing.hpp`

Clothing store with a filtered item list and a camera slider. Root class
`Life_Clothing`, `idd = MrFrost_IDD_Life_Clothing` -> **3100**. Opened with
`createDialog "Life_Clothing";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 3101 | `MrFrost_IDC_ClothingShop_List_Shop` | Item list |
| 3102 | `MrFrost_IDC_ClothingShop_Text_Price` | Item price, structured text |
| 3103 | `MrFrost_IDC_ClothingShop_Title_Shop` | Shop title |
| 3105 | `MrFrost_IDC_ClothingShop_Combo_Elements_Filter` | Category filter combo |
| 3106 | `MrFrost_IDC_ClothingShop_Text_Price_Total` | Total price, structured text |
| 3107 | `MrFrost_IDC_ClothingShop_Slider_View` | Camera view slider |

> The `onLoad` on the root class is commented out. It would have run
> `core\client\keychain\init.sqf`, a copy/paste leftover from the key chain
> dialog. See [known-issues.md](known-issues.md).

---

## `federalReserve.hpp`

Federal reserve safe: take gold bars out of the vault. Root class `Federal_Safe`,
`idd = MrFrost_IDD_Federal` -> **3500**. Opened with
`createDialog "Federal_Safe";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2403 | `MrFrost_IDC_Federal_Title_Safe_Federal_List` | Safe contents title |
| 3502 | `MrFrost_IDC_Federal_Safe_Federal_List` | Safe contents list |
| 3504 | `MrFrost_IDC_Federal_Title_Safe_Weight` | Weight readout |
| 3505 | `MrFrost_IDC_Federal_Safe_Federal_Value` | Quantity edit field |

> Shares IDD 3500 and IDCs 3502/3504/3505 with `trunk.hpp`, which is the layout
> this one was derived from.

---

## `trunk.hpp`

Vehicle trunk: move items between the trunk and your inventory. Root class
`TrunkMenu`, `idd = MrFrost_IDD_Trunk` -> **3500**. Opened with
`createDialog "TrunkMenu";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 2403 | `MrFrost_IDC_Trunk_Title_Vehicle_Trunk_List` | Trunk list title |
| 3502 | `MrFrost_IDC_Trunk_Vehicle_Trunk_List` | Trunk list |
| 3503 | `MrFrost_IDC_Trunk_Inventory_List` | Player inventory list |
| 3504 | `MrFrost_IDC_Trunk_Title_Vehicle_Weight` | Trunk weight readout |
| 3505 | `MrFrost_IDC_Trunk_Vehicle_Trunk_Value` | Trunk quantity edit field |
| 3506 | `MrFrost_IDC_Trunk_Inventory_Value` | Inventory quantity edit field |
| 50011 | `MrFrost_IDC_Trunk_Title_Inventory_Weight` | Inventory weight readout |

> The macro name `MrFrost_IDD_Trunk` is defined here as 3500 and defined again by
> `newsStation.hpp` as 100100. See [known-issues.md](known-issues.md).

---

## `deathScreen.hpp`

Death screen overlay with a respawn countdown. Root class `DeathScreen`,
`idd = MrFrost_IDD_DeathScreen` -> **7300**. Opened with
`createDialog "DeathScreen";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 7301 | `MrFrost_IDC_DeathScreen_Title_DeathCount` | Respawn countdown |
| 7302 | `MrFrost_IDC_DeathScreen_Button_Respawn` | Give up button |
| 7303 | `MrFrost_IDC_DeathScreen_Button_Help` | Call medic button |
| 7304 | `MrFrost_IDC_DeathScreen_Background_Medics_Online` | Medics-online panel |

---

## `FuelStat.hpp`

Fuel station: pick a vehicle, set an amount, pay. Root class `Life_FuelStat`,
`idd = MrFrost_IDD_Fuel` -> **20300**. Opened with
`createDialog "Life_FuelStat";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 20301 | `MrFrost_IDC_Fuel_Title_Vehicle_List` | Vehicle list title |
| 20302 | `MrFrost_IDC_Fuel_Vehicle_List` | Vehicle list |
| 20303 | `MrFrost_IDC_Fuel_Text_Info` | Vehicle specs, structured text |
| 20309 | `MrFrost_IDC_Fuel_Button_Refuel` | Refuel button |
| 20322 | `MrFrost_IDC_Fuel_Text_Price` | Price per litre |
| 20323 | `MrFrost_IDC_Fuel_Text_Total` | Total price |
| 20324 | `MrFrost_IDC_Fuel_Text_Fuel` | Litres selected |
| 20330 | `MrFrost_IDC_Fuel_Title_Info` | Specs panel title |
| 20901 | `MrFrost_IDC_Fuel_Slider` | Amount slider -- and its backing panel, see below |

> Two controls in this dialog carry IDC 20901: the `MrFrost_RscXSliderH`
> (`Fuel_Slider`) and the plain text panel behind it (`Fuel_Background_Slider`),
> which should have used `MrFrost_IDC_Fuel_Background_Slider` (`-1`) -- that
> constant is defined but never referenced. `displayCtrl 20901` is therefore
> ambiguous, the same problem as IDC 2014 in `player_inv.hpp`.
>
> This dialog's `onLoad` is `ctrlShow [2330,false];`, an IDC belonging to the
> stock vehicle shop. See [known-issues.md](known-issues.md).

---

## `pInteraction.hpp`

Two interaction menus in one file: `pInteraction_Menu` for players and
`vInteraction_Menu` for vehicles. They share a layout and a numbering scheme so
one set of handlers can drive either. Opened with
`createDialog "pInteraction_Menu";` and `createDialog "vInteraction_Menu";`.

- `pInteraction_Menu` -- `idd = MrFrost_IDD_Interaction;`. **That macro is never
  defined.** The file defines `MrFrost_IDD_pInteraction` (37400) and
  `MrFrost_IDD_vInteraction` (37400) and uses neither for this class, so the
  preprocessor passes the unknown identifier through literally and the config
  ends up with a non-numeric `idd`. Fixing it is a one-token change. See
  [known-issues.md](known-issues.md).
- `vInteraction_Menu` -- `idd = MrFrost_IDD_vInteraction` -> **37400**.

| IDC | Constant | Control |
| --- | --- | --- |
| 37401 | `MrFrost_IDC_pInteraction_Title_Interaction` | Player menu title |
| 37401 | `MrFrost_IDC_vInteraction_Title_Interaction` | Vehicle menu title |
| 37450 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_1` | Player action button 1 |
| 37450 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_1` | Vehicle action button 1 |
| 37451 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_2` | Player action button 2 |
| 37451 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_2` | Vehicle action button 2 |
| 37452 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_3` | Player action button 3 |
| 37452 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_3` | Vehicle action button 3 |
| 37453 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_4` | Player action button 4 |
| 37453 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_4` | Vehicle action button 4 |
| 37454 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_5` | Player action button 5 |
| 37454 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_5` | Vehicle action button 5 |
| 37455 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_6` | Player action button 6 |
| 37455 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_6` | Vehicle action button 6 |
| 37456 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_7` | Player action button 7 |
| 37456 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_7` | Vehicle action button 7 |
| 37457 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_8` | Player action button 8 |
| 37457 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_8` | Vehicle action button 8 |
| 50020 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_9` | Player action button 9 |
| 50020 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_9` | Vehicle action button 9 |
| 50021 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_10` | Player action button 10 |
| 50021 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_10` | Vehicle action button 10 |
| 50022 | `MrFrost_IDC_pInteraction_Button_Interaction_Button_11` | Player action button 11 |
| 50022 | `MrFrost_IDC_vInteraction_Button_Interaction_Button_11` | Vehicle action button 11 |

> Each number appears once per display, so this is not a collision. The vehicle
> menu's close button sets `idc = MrFrost_IDC_vInteraction_Button_Close`, which is
> undefined -- only `MrFrost_IDC_vInteraction_Button_Close_Image` exists.
> `MrFrost_IDC_pInteraction_Button_Close` is defined twice, both times as `-1`,
> which is harmless.

---

## `progress.hpp`

Two RscTitles resources rather than dialogs, shown with `cutRsc` -- for example
`"progressBar" cutRsc ["life_progress","PLAIN"];`.

- `life_progress` -- `idd = MrFrost_IDD_life_progress` -> **38200**. The progress
  bar the stock `life_fnc_progressBar` drives.
- `life_timer` -- `idd = 38300`, written as a literal rather than a macro.

| IDC | Constant | Control |
| --- | --- | --- |
| 38201 | `MrFrost_IDC_Progress_ProgressBar` | Progress bar |
| 38202 | `MrFrost_IDC_Progress_ProgressText` | Progress label |

> `life_timer` uses no `MrFrost_IDC_*` constants at all. Its text control carries
> a hardcoded `idc = 38301`, and its icon is `-1`.
>
> `progress.hpp` is the only one of the 20 files that `MasterHandler.hpp` does
> not `#include`, and `description.ext` includes nothing but `MasterHandler.hpp`.
> The file therefore never reaches the config in this mission -- add the include
> yourself if you want it. Note also that this mission declares no
> `class RscTitles { }` block, so `life_progress`, `life_timer` and `playerHUD`
> sit at top level; in a real Altis Life mission they belong inside `RscTitles`.

---

## `shops.hpp`

Weapon shop with a category filter and magazine/accessory shortcuts. Root class
`life_weapon_shop`, `idd = MrFrost_IDD_ItemShop` -> **38400**. Opened with
`createDialog "life_weapon_shop";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 38401 | `MrFrost_IDC_ItemShop_Title_Shop` | Shop title |
| 38402 | `MrFrost_IDC_ItemShop_Combo_Elements_Filter` | Category filter combo |
| 38403 | `MrFrost_IDC_ItemShop_List_Shop` | Item list |
| 38404 | `MrFrost_IDC_ItemShop_Text_Price` | Price, structured text |
| 38405 | `MrFrost_IDC_ItemShop_Button_Elements_BuySell` | Buy/sell button -- constant unused, see below |
| 38406 | `MrFrost_IDC_ItemShop_Button_Elements_Mag` | Magazines button |
| 38407 | `MrFrost_IDC_ItemShop_Button_Elements_Acc` | Accessories button |

> The `ItemShop_Button_Elements_BuySell` class sets
> `idc = MrFrost_IDC_ItemShop_Button_Elements_Buy` -- no `Sell` -- which is
> undefined, so 38405 reaches no control. The close-button image likewise uses
> the undefined `MrFrost_IDC_ItemShop_Background_Button_Close`; the defined
> `MrFrost_IDC_ItemShop_Button_Close` (`-1`) is what it should have been.

---

## `spawnSelection.hpp`

Spawn point selection over a map control, with a full-screen backdrop
(`pictures\GUI\Spawn_Background.paa`). Root class `life_spawn_selection`,
`idd = MrFrost_IDD_SpawnMenu` -> **38500**. Opened with
`createDialog "life_spawn_selection";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 38501 | `MrFrost_IDC_SpawnMenu_Spawn_Map_Title` | Selected spawn point label |
| 38502 | `MrFrost_IDC_SpawnMenu_Spawn_Map` | Map control |
| 38510 | `MrFrost_IDC_SpawnMenu_Spawn_List` | Spawn point list |

> The logo picture in this dialog reuses `MrFrost_IDC_ZMenu_Logo` (`-1`) from
> `player_inv.hpp`, so this file only preprocesses cleanly when `player_inv.hpp`
> is included before it. `MasterHandler.hpp` does that.

---

## `chop_shop.hpp`

Chop shop: sell a stolen vehicle. Root class `Chop_Shop`,
`idd = MrFrost_IDD_ChopShop` -> **39400**. Opened with
`createDialog "Chop_Shop";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 39401 | `MrFrost_IDC_ChopShop_Text_Price` | Price, structured text |
| 39402 | `MrFrost_IDC_ChopShop_Vehicles_List` | Vehicle list |

> The close-button image reuses `MrFrost_IDC_ATM_Button_Close_Image` (`-1`) from
> `bank.hpp`, so this file depends on `bank.hpp` being included first.
> `MasterHandler.hpp` does that.

---

## `newsStation.hpp`

News station broadcast: write a headline and a body, pay to broadcast. Root class
`life_news_broadcast`, `idd = MrFrost_IDD_Trunk` -> **100100**. Opened with
`createDialog "life_news_broadcast";`.

| IDC | Constant | Control |
| --- | --- | --- |
| 100101 | `MrFrost_IDC_News_Header_Edit` | Headline edit field |
| 100102 | `MrFrost_IDC_News_Text_Edit` | Message edit field |
| 100103 | `MrFrost_IDC_News_Text_Price` | Broadcast cost |
| 100104 | `MrFrost_IDC_News_Button_Send` | Broadcast button |
| 184838 | `MrFrost_IDC_News_Text_Next` | Broadcast availability readout |

> The IDD macro is named `MrFrost_IDD_Trunk` even though the class is
> `life_news_broadcast`, which is what causes the redefinition described in the
> collisions section. See [known-issues.md](known-issues.md).

---

## Reading the macros

**`MrFrost_POSITION(X,Y,W,H)`** takes pixel coordinates on a 1920x1080 canvas and
expands, at preprocess time, into four `x` / `y` / `w` / `h` assignments in
safezone units. It adds `safeZoneX` and `safeZoneY`, so the result is an absolute
position on screen. Every positioned control in all 20 files uses this form.

**`MrFrost_POSITION_CT(X,Y,W,H)`** is the same conversion without the
`safeZoneX` / `safeZoneY` offsets, intended for controls nested inside a
`MrFrost_RscControlsGroup`, whose coordinates are relative to the group. It is
defined in `MrFrost_defines.hpp` but no dialog in this pack actually uses it --
the one controls group that exists, `ZMenu_Licenses_List` in `player_inv.hpp`,
writes raw `x` / `y` / `w` / `h` values instead.

Both macros are reproduced as a comment block near the top of every dialog file
so you can read a file without opening `MrFrost_defines.hpp`. Those copies are
inert; only the definitions in `MrFrost_defines.hpp` are live.

**`idc = -1`** means the control is never addressed from script. It renders and
that is all -- backgrounds, coloured bars, static labels, the invisible button
overlaid on the close icon. Those controls are omitted from the tables above,
which is why a file with 30 controls may list only six IDCs.

**`MrFrost_Rsc*` base classes** -- `MrFrost_RscText`, `MrFrost_RscButton`,
`MrFrost_RscListBox`, `MrFrost_RscEdit`, `MrFrost_RscCombo`,
`MrFrost_RscStructuredText`, `MrFrost_RscProgress`, `MrFrost_RscXSliderH`,
`MrFrost_RscPictureKeepAspect` and the rest -- all come from
`dialog/MrFrost_defines.hpp`, which was written by Heyoxe. A few controls inherit
from stock Altis Life classes instead (`Life_RscListBox`, `Life_Checkbox`,
`RscText`, `RscButton`), which come from `dialog/common.hpp`. Both files must be
included before any dialog that uses them; `MasterHandler.hpp` includes
`common.hpp` first and `MrFrost_defines.hpp` second.
