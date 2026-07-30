/*
 * Dialog by MrFrost
 * Macros by Heyoxe
 *
 * Hereby I forbid the publication under a different name, as original or modified, without my explicit permission.
 * This script was developed explicitly for all "Mammut-Roleplay.de Servers".
 * It is not allowed to use, publish or sell it on other platforms without my explicit permission.
 * It is not allowed to remove this header.
 */

/* --------------------------------------------------------------------------
 * bank.hpp - ATM / bank management
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_atm_management
 * IDD        : MrFrost_IDD_ATM = 2700
 * Opened by  : createDialog "Life_atm_management";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Deposit/withdraw/transfer are wired to the stock Altis Life
 *              functions life_fnc_bankDeposit / bankWithdraw / bankTransfer.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_ATM 2700
//Main Background
#define MrFrost_IDC_ATM_MainBackground -1
#define MrFrost_IDC_ATM_Bar_Bottom -1
#define MrFrost_IDC_ATM_Bar_Top -1
#define MrFrost_IDC_ATM_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_ATM_Background_Money -1
#define MrFrost_IDC_ATM_Background_Transfer -1
#define MrFrost_IDC_ATM_Background_Gang -1
#define MrFrost_IDC_ATM_Background_Input -1
#define MrFrost_IDC_ATM_Bar_Money -1
#define MrFrost_IDC_ATM_Bar_Input -1
#define MrFrost_IDC_ATM_Bar_Transfer -1
#define MrFrost_IDC_ATM_Bar_Gang -1
//Titles
#define MrFrost_IDC_ATM_Money_Title -1
//Elements Background
#define MrFrost_IDC_ATM_Background_Money_Bank -1
#define MrFrost_IDC_ATM_Background_Money_Cash -1
#define MrFrost_IDC_ATM_Background_Money_Value -1
#define MrFrost_IDC_ATM_Background_Money_Person -1
//Icons
#define MrFrost_IDC_ATM_Money_Bank_Icon -1
#define MrFrost_IDC_ATM_Money_Cash_Icon -1
//Elements
#define MrFrost_IDC_ATM_Money_Bank 50003 //2701
#define MrFrost_IDC_ATM_Money_Cash 50004 //2701
#define MrFrost_IDC_ATM_Money_Value 2702
#define MrFrost_IDC_ATM_Money_Person 2703
//Buttons
#define MrFrost_IDC_ATM_Button_Deposit -1
#define MrFrost_IDC_ATM_Button_Withdraw -1
#define MrFrost_IDC_ATM_Button_Deposit_All -1
#define MrFrost_IDC_ATM_Button_Withdraw_All -1
#define MrFrost_IDC_ATM_Button_Transfer -1
#define MrFrost_IDC_ATM_Button_Gang_Withdraw 2705
#define MrFrost_IDC_ATM_Button_Gang_Deposit 2706
//Main Buttons
#define MrFrost_IDC_ATM_Button_Close -1

/* Positions Macros
#define MrFrost_POSITION(X,Y,W,H) \
	x = #((((X * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX); \
	y = #((((Y * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY); \
	w = #((((W * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	h = #((((H * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));

#define MrFrost_POSITION_CT(X,Y,W,H) \
	x = #((((X * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	y = #((((Y * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1)); \
	w = #((((W * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	h = #((((H * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
*/

/* Dialog */
class Life_atm_management {
    idd = MrFrost_IDD_ATM;
    name= "life_atm_menu";
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        class ATM_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_MainBackground;
			MrFrost_POSITION(765,260,364,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class ATM_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Bottom;
			MrFrost_POSITION(765,842,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class ATM_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Top;
			MrFrost_POSITION(765,253,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Background_Money : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Money;
			MrFrost_POSITION(802,319,290,169)
			colorBackground[] = {0,0,0,0.31};
		};

        class ATM_Background_Input : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Input;
			MrFrost_POSITION(802,509,290,58)
			colorBackground[] = {0,0,0,0.31};
		};

        class ATM_Background_Transfer : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Transfer;
			MrFrost_POSITION(802,573,290,187)
			colorBackground[] = {0,0,0,0.31};
		};

        class ATM_Background_Gang : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Gang;
			MrFrost_POSITION(802,766,290,58)
			colorBackground[] = {0,0,0,0.31};
		};

        class ATM_Bar_Money : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Money;
			MrFrost_POSITION(802,313,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ATM_Bar_Input : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Input;
			MrFrost_POSITION(802,503,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ATM_Bar_Transfer : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Transfer;
			MrFrost_POSITION(802,567,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ATM_Bar_Gang : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Bar_Gang;
			MrFrost_POSITION(802,760,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Money_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Money_Title;
			MrFrost_POSITION(802,275,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "ATM";
            //text = "$STR_ATM_Title";
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Background_Money_Bank : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Money_Bank;
			MrFrost_POSITION(817,333,260,62)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ATM_Background_Money_Cash : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Money_Cash;
			MrFrost_POSITION(817,410,260,62)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ATM_Background_Money_Value : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Money_Value;
			MrFrost_POSITION(817,524,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ATM_Background_Money_Person : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Background_Money_Person;
			MrFrost_POSITION(817,674,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Money_Bank_Icon : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ATM_Money_Bank_Icon;
			MrFrost_POSITION(820,333,62,62)
			colorBackground[] = {0,0,0,0};
            text = "pictures\GUI\Money_Bank.paa";
		};

        class ATM_Money_Cash_Icon : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ATM_Money_Cash_Icon;
			MrFrost_POSITION(820,410,62,62)
			colorBackground[] = {0,0,0,0};
            text = "pictures\GUI\Money_Cash.paa";
		};

        class ATM_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ATM_Button_Close_Image;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Money_Bank : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Money_Bank;
			MrFrost_POSITION(890,333,187,62)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x01;
            sizeex = 0.07;
            text= "12.345.678$";
		};

        class ATM_Money_Cash : MrFrost_RscText {
			idc = MrFrost_IDC_ATM_Money_Cash;
			MrFrost_POSITION(890,411,187,62)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x01;
            sizeex = 0.07;
            text= "12.345$";
		};

        class ATM_Money_Person : MrFrost_RscCombo {
			idc = MrFrost_IDC_ATM_Money_Person;
			MrFrost_POSITION(817,674,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
		};

        class ATM_Money_Value : MrFrost_RscEdit {
			idc = MrFrost_IDC_ATM_Money_Value;
			MrFrost_POSITION(817,524,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Button_Deposit : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Deposit;
			MrFrost_POSITION(817,588,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_Deposit";
            text= "Deposit";
		};

        class ATM_Button_Deposit_All : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Deposit_All;
			MrFrost_POSITION(817,631,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_DepositAll";
            text= "Deposit All";
		};

        class ATM_Button_Withdraw : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Withdraw;
			MrFrost_POSITION(955,588,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_Withdraw";
            text= "Withdraw";
		};

        class ATM_Button_Withdraw_All : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Withdraw_All;
			MrFrost_POSITION(955,631,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_WithdrawAll";
            text= "Withdraw All";
		};

        class ATM_Button_Transfer : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Transfer;
			MrFrost_POSITION(817,717,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_Transfer";
            text= "Transfer";
            onButtonClick = "[] call life_fnc_bankTransfer";
		};

        class ATM_Button_Gang_Deposit : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Gang_Button_Deposit;
			MrFrost_POSITION(817,781,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_DepositGang";
            text= "On Gang";
            onButtonClick = "[true] call life_fnc_useGangBank";
		};

        class ATM_Button_Gang_Withdraw : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Gang_Button_Withdraw;
			MrFrost_POSITION(955,781,122,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_ATM_WithdrawGang";
            text= "From Gang";
            onButtonClick = "[false] call life_fnc_useGangBank";
		};

        class ATM_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_ATM_Button_Close;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "";
            onButtonClick = "closeDialog 0;";
        };
    };
};
