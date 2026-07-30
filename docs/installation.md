# Installation

> **There is nothing to install.** This repository is a source dump, not a
> package. It contains no controller functions for the custom dialogs — every
> one of them calls `life_fnc_*` handlers that live in a full Altis Life 5.0
> mission, not here. Copying a dialog gets you the layout; you supply the logic.

The whole repository is a single VR mission, `src/Dialog.VR/`. You open it, look
at a dialog, and take what you want.

---

## Opening the mission

1. Copy the folder `src/Dialog.VR` into your Arma 3 Profile `missions` folder:

   ```
   Documents\Arma 3\missions\Dialog.VR\
   ```

   or, if you use a named profile:

   ```
   Documents\Arma 3 - Other Profiles\<YourProfile>\missions\Dialog.VR\
   ```

   > **Keep the `.VR` suffix.** In Arma 3 the part of the folder name after the
   > dot is the terrain the mission binds to. `mission.sqm` does not name a
   > terrain itself — rename the folder to `Dialog.Altis` and the editor will
   > look for objects on the wrong world.

2. Open it in the Eden editor: **Editor → VR → Dialog**.

3. Preview the mission, then open any dialog from the debug console:

   ```sqf
   createDialog "playerSettings";
   ```

   The root class name for every file is in the header comment at the top of
   that file, on the `Opened by` line, and in
   [dialog-reference.md](dialog-reference.md). Two of the resources are **not**
   dialogs and will not respond to `createDialog`:

   ```sqf
   "playerHUD" cutRsc ["playerHUD","PLAIN"];    // hud_stats.hpp
   "progressBar" cutRsc ["life_progress","PLAIN"];  // progress.hpp
   ```

   Everything you see this way is the layout only. Lists are empty, buttons do
   nothing, and any control the missing `life_fnc_*` handler would have filled
   stays blank. That is expected — see
   [known-issues.md](known-issues.md#7--no-controller-functions-are-shipped).

## Taking one dialog into your own mission

Working from `clothing.hpp` as the example:

1. **Copy the dialog.** `src/Dialog.VR/dialog/clothing.hpp` into your mission's
   `dialog\` folder.

2. **Copy `MrFrost_defines.hpp` — once.** `src/Dialog.VR/dialog/MrFrost_defines.hpp`
   into the same folder. Every dialog in this pack depends on it: it supplies
   `MrFrost_POSITION(X,Y,W,H)`, which rewrites 1920x1080 pixel values into
   safezone coordinates at preprocess time, and the `MrFrost_Rsc*` base classes
   the controls inherit from. If your mission already has it from another one of
   these scripts, do not add it a second time.

3. **Add the include.** In your `dialog\MasterHandler.hpp`, after
   `#include "common.hpp"`:

   ```cpp
   #include "MrFrost_defines.hpp"
   #include "clothing.hpp"
   ```

   `MrFrost_defines.hpp` must come before any dialog that uses it. This is the
   order `src/Dialog.VR/dialog/MasterHandler.hpp` already uses.

4. **Copy the textures.** Search the dialog for `pictures\GUI\` and copy every
   file it names out of `src/Dialog.VR/pictures/GUI/` into the matching path in
   your mission. Across the pack: `PreviewBackground.jpg` is referenced ten
   times, `Logo_Mammut.paa` five, `Money_Bank.paa`, `Money_Cash.paa` and
   `Spawn_Background.paa` twice each, and the ten `ico_*.paa` files belong to
   `player_inv.hpp`.

   > **Match the capitalisation exactly.** These paths are compared literally.
   > A Windows client will not care; a Linux server will fail to find the file.

5. **Write the controller function.** Nothing in this repository does this for
   you. `dialog/function/` holds only the 24 stock Altis Life functions — none
   of them were written for these layouts.

### About the IDCs

The IDCs have to match whatever your handler expects. That constraint is why
these dialogs were built the way they were: the stock Altis Life handlers
address their controls by the stock IDC numbers, and most of these dialogs
deliberately reuse those same numbers so a stock handler keeps working against a
new layout. `player_inv.hpp` goes further and `#include`s the stock
`player_sys.sqf`, using its plain `#define` list directly.

So there are two workable directions:

- **Keep the IDCs, adapt nothing.** Point a stock handler at the new layout and
  it should find its controls.
- **Change the IDCs, adapt the handler.** Then every `displayCtrl` number in
  your function has to move with them.

What does not work is changing one and not the other.

## Check for IDD collisions

Before you include anything, look up its IDD in
[dialog-reference.md](dialog-reference.md) and check it against what your
mission already defines. Two dialogs sharing an IDD is legal in Arma as long as
they are never open at the same time, but `findDisplay` cannot tell them apart
if they are. The full list of overlaps inside this pack is in
[known-issues.md](known-issues.md#5--duplicate-idds-across-dialogs).

Two of them need a decision from you rather than just awareness:

- **IDD 2300 — the vehicle-shop trio.** `vehicleShop3D.hpp` (this pack), plus
  the stock `veh_shop.hpp` and `vehicleShop.hpp`, all claim 2300. All three are
  alternative vehicle shops. **Pick exactly one** and do not include the other
  two.
- **IDD 2900 — settings and admin menu.** `settings.hpp` (this pack) and the
  stock `admin_menu.hpp` both use 2900. If you want both in one mission, one of
  them has to be renumbered — and its handler updated to match.

## The logo

`src/Dialog.VR/pictures/GUI/Logo_Mammut.paa` is **not** the original artwork. It
is a generated 1024x1024 DXT5 texture that is fully transparent: it loads
without error and draws nothing. The original was the Mammut-Roleplay.de logo,
which was never the author's to redistribute, so it was replaced rather than
removed — every path and every dialog stays exactly as released.

Five dialogs reference it: `cell_phone.hpp:111`, `key_chain.hpp:114`,
`player_inv.hpp:204`, `settings.hpp:164`, `spawnSelection.hpp:109`.

To drop in your own, overwrite the placeholder with a 1024x1024 DXT5 `.paa` and
change nothing else. The full spec, including the box size each dialog draws it
into, is in
[`src/Dialog.VR/pictures/GUI/README.md`](../src/Dialog.VR/pictures/GUI/README.md).

## What you will need to supply yourself

- **A controller function for every dialog you take.** This is the large one.
  None are shipped.
- **A working Altis Life 5.0 mission** to host them. The dialogs call
  `life_fnc_*` handlers, `life_*` variables and stock IDC numbers throughout.
- **Your own logo**, or acceptance that the logo control draws nothing.
- **An IDD renumbering plan**, if you want more than one of the colliding
  dialogs listed above.
- **Testing.** Nothing in this repository has been run since 2021. No claim is
  made that any of it still works.
