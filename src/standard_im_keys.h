/* Key Masks */

#define IME_KEY_ShiftMask        (1<<0)
#define IME_KEY_LockMask        (1<<1)
#define IME_KEY_CapsLockMask        (1<<1)
#define IME_KEY_ControlMask        (1<<2)
#define IME_KEY_Mod1Mask        (1<<3)
#define IME_KEY_AltMask            (1<<3)
#define IME_KEY_Mod2Mask        (1<<4)
#define IME_KEY_NumLockMask        (1<<4)
#define IME_KEY_Mod3Mask        (1<<5)
#define IME_KEY_Mod4Mask        (1<<6)
#define IME_KEY_Mod5Mask        (1<<7)
#define IME_KEY_ScrollLockMask        (1<<7)
#define IME_KEY_ReleaseMask        (1<<30)

/* Key Symbols */
#define IME_KEY_VoidSymbol        0xFFFFFF    /* void symbol */

/*
 * TTY Functions, cleverly chosen to map to ascii, for convenience of
 * programming, but could have been arbitrary (at the cost of lookup
 * tables in client code.
 */

#define IME_KEY_BackSpace        0xFF08    /* back space, back char */
#define IME_KEY_Tab            0xFF09
#define IME_KEY_Linefeed        0xFF0A    /* Linefeed, LF */
#define IME_KEY_Clear        0xFF0B
#define IME_KEY_Return        0xFF0D    /* Return, enter */
#define IME_KEY_Pause        0xFF13    /* Pause, hold */
#define IME_KEY_Scroll_Lock        0xFF14
#define IME_KEY_Sys_Req        0xFF15
#define IME_KEY_Escape        0xFF1B
#define IME_KEY_Delete        0xFFFF    /* Delete, rubout */



/* International & multi-key character composition */

#define IME_KEY_Multi_key        0xFF20  /* Multi-key character compose */
#define IME_KEY_Codeinput        0xFF37
#define IME_KEY_SingleCandidate    0xFF3C
#define IME_KEY_MultipleCandidate    0xFF3D
#define IME_KEY_PreviousCandidate    0xFF3E

/* Japanese keyboard support */

#define IME_KEY_Kanji        0xFF21    /* Kanji, Kanji convert */
#define IME_KEY_Muhenkan        0xFF22  /* Cancel Conversion */
#define IME_KEY_Henkan_Mode        0xFF23  /* Start/Stop Conversion */
#define IME_KEY_Henkan        0xFF23  /* Alias for Henkan_Mode */
#define IME_KEY_Romaji        0xFF24  /* to Romaji */
#define IME_KEY_Hiragana        0xFF25  /* to Hiragana */
#define IME_KEY_Katakana        0xFF26  /* to Katakana */
#define IME_KEY_Hiragana_Katakana    0xFF27  /* Hiragana/Katakana toggle */
#define IME_KEY_Zenkaku        0xFF28  /* to Zenkaku */
#define IME_KEY_Hankaku        0xFF29  /* to Hankaku */
#define IME_KEY_Zenkaku_Hankaku    0xFF2A  /* Zenkaku/Hankaku toggle */
#define IME_KEY_Touroku        0xFF2B  /* Add to Dictionary */
#define IME_KEY_Massyo        0xFF2C  /* Delete from Dictionary */
#define IME_KEY_Kana_Lock        0xFF2D  /* Kana Lock */
#define IME_KEY_Kana_Shift        0xFF2E  /* Kana Shift */
#define IME_KEY_Eisu_Shift        0xFF2F  /* Alphanumeric Shift */
#define IME_KEY_Eisu_toggle        0xFF30  /* Alphanumeric toggle */
#define IME_KEY_Kanji_Bangou        0xFF37  /* Codeinput */
#define IME_KEY_Zen_Koho        0xFF3D    /* Multiple/All Candidate(s) */
#define IME_KEY_Mae_Koho        0xFF3E    /* Previous Candidate */

/* 0xFF31 thru 0xFF3F are under IME_KEY_KOREAN */

/* Cursor control & motion */

#define IME_KEY_Home            0xFF50
#define IME_KEY_Left            0xFF51    /* Move left, left arrow */
#define IME_KEY_Up            0xFF52    /* Move up, up arrow */
#define IME_KEY_Right        0xFF53    /* Move right, right arrow */
#define IME_KEY_Down            0xFF54    /* Move down, down arrow */
#define IME_KEY_Prior        0xFF55    /* Prior, previous */
#define IME_KEY_Page_Up        0xFF55
#define IME_KEY_Next            0xFF56    /* Next */
#define IME_KEY_Page_Down        0xFF56
#define IME_KEY_End            0xFF57    /* EOL */
#define IME_KEY_Begin        0xFF58    /* BOL */


/* Misc Functions */

#define IME_KEY_Select        0xFF60    /* Select, mark */
#define IME_KEY_Print        0xFF61
#define IME_KEY_Execute        0xFF62    /* Execute, run, do */
#define IME_KEY_Insert        0xFF63    /* Insert, insert here */
#define IME_KEY_Undo            0xFF65    /* Undo, oops */
#define IME_KEY_Redo            0xFF66    /* redo, again */
#define IME_KEY_Menu            0xFF67
#define IME_KEY_Find            0xFF68    /* Find, search */
#define IME_KEY_Cancel        0xFF69    /* Cancel, stop, abort, exit */
#define IME_KEY_Help            0xFF6A    /* Help */
#define IME_KEY_Break        0xFF6B
#define IME_KEY_Mode_switch        0xFF7E    /* Character set switch */
#define IME_KEY_script_switch        0xFF7E  /* Alias for mode_switch */
#define IME_KEY_Num_Lock        0xFF7F

/* Keypad Functions, keypad numbers cleverly chosen to map to ascii */

#define IME_KEY_KP_Space        0xFF80    /* space */
#define IME_KEY_KP_Tab        0xFF89
#define IME_KEY_KP_Enter        0xFF8D    /* enter */
#define IME_KEY_KP_F1        0xFF91    /* PF1, KP_A, ... */
#define IME_KEY_KP_F2        0xFF92
#define IME_KEY_KP_F3        0xFF93
#define IME_KEY_KP_F4        0xFF94
#define IME_KEY_KP_Home        0xFF95
#define IME_KEY_KP_Left        0xFF96
#define IME_KEY_KP_Up        0xFF97
#define IME_KEY_KP_Right        0xFF98
#define IME_KEY_KP_Down        0xFF99
#define IME_KEY_KP_Prior        0xFF9A
#define IME_KEY_KP_Page_Up        0xFF9A
#define IME_KEY_KP_Next        0xFF9B
#define IME_KEY_KP_Page_Down        0xFF9B
#define IME_KEY_KP_End        0xFF9C
#define IME_KEY_KP_Begin        0xFF9D
#define IME_KEY_KP_Insert        0xFF9E
#define IME_KEY_KP_Delete        0xFF9F
#define IME_KEY_KP_Equal        0xFFBD    /* equals */
#define IME_KEY_KP_Multiply        0xFFAA
#define IME_KEY_KP_Add        0xFFAB
#define IME_KEY_KP_Separator        0xFFAC    /* separator, often comma */
#define IME_KEY_KP_Subtract        0xFFAD
#define IME_KEY_KP_Decimal        0xFFAE
#define IME_KEY_KP_Divide        0xFFAF

#define IME_KEY_KP_0            0xFFB0
#define IME_KEY_KP_1            0xFFB1
#define IME_KEY_KP_2            0xFFB2
#define IME_KEY_KP_3            0xFFB3
#define IME_KEY_KP_4            0xFFB4
#define IME_KEY_KP_5            0xFFB5
#define IME_KEY_KP_6            0xFFB6
#define IME_KEY_KP_7            0xFFB7
#define IME_KEY_KP_8            0xFFB8
#define IME_KEY_KP_9            0xFFB9



/*
 * Auxilliary Functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufactures have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

#define IME_KEY_F1            0xFFBE
#define IME_KEY_F2            0xFFBF
#define IME_KEY_F3            0xFFC0
#define IME_KEY_F4            0xFFC1
#define IME_KEY_F5            0xFFC2
#define IME_KEY_F6            0xFFC3
#define IME_KEY_F7            0xFFC4
#define IME_KEY_F8            0xFFC5
#define IME_KEY_F9            0xFFC6
#define IME_KEY_F10            0xFFC7
#define IME_KEY_F11            0xFFC8
#define IME_KEY_L1            0xFFC8
#define IME_KEY_F12            0xFFC9
#define IME_KEY_L2            0xFFC9
#define IME_KEY_F13            0xFFCA
#define IME_KEY_L3            0xFFCA
#define IME_KEY_F14            0xFFCB
#define IME_KEY_L4            0xFFCB
#define IME_KEY_F15            0xFFCC
#define IME_KEY_L5            0xFFCC
#define IME_KEY_F16            0xFFCD
#define IME_KEY_L6            0xFFCD
#define IME_KEY_F17            0xFFCE
#define IME_KEY_L7            0xFFCE
#define IME_KEY_F18            0xFFCF
#define IME_KEY_L8            0xFFCF
#define IME_KEY_F19            0xFFD0
#define IME_KEY_L9            0xFFD0
#define IME_KEY_F20            0xFFD1
#define IME_KEY_L10            0xFFD1
#define IME_KEY_F21            0xFFD2
#define IME_KEY_R1            0xFFD2
#define IME_KEY_F22            0xFFD3
#define IME_KEY_R2            0xFFD3
#define IME_KEY_F23            0xFFD4
#define IME_KEY_R3            0xFFD4
#define IME_KEY_F24            0xFFD5
#define IME_KEY_R4            0xFFD5
#define IME_KEY_F25            0xFFD6
#define IME_KEY_R5            0xFFD6
#define IME_KEY_F26            0xFFD7
#define IME_KEY_R6            0xFFD7
#define IME_KEY_F27            0xFFD8
#define IME_KEY_R7            0xFFD8
#define IME_KEY_F28            0xFFD9
#define IME_KEY_R8            0xFFD9
#define IME_KEY_F29            0xFFDA
#define IME_KEY_R9            0xFFDA
#define IME_KEY_F30            0xFFDB
#define IME_KEY_R10            0xFFDB
#define IME_KEY_F31            0xFFDC
#define IME_KEY_R11            0xFFDC
#define IME_KEY_F32            0xFFDD
#define IME_KEY_R12            0xFFDD
#define IME_KEY_F33            0xFFDE
#define IME_KEY_R13            0xFFDE
#define IME_KEY_F34            0xFFDF
#define IME_KEY_R14            0xFFDF
#define IME_KEY_F35            0xFFE0
#define IME_KEY_R15            0xFFE0

/* Modifiers */

#define IME_KEY_Shift_L        0xFFE1    /* Left shift */
#define IME_KEY_Shift_R        0xFFE2    /* Right shift */
#define IME_KEY_Control_L        0xFFE3    /* Left control */
#define IME_KEY_Control_R        0xFFE4    /* Right control */
#define IME_KEY_Caps_Lock        0xFFE5    /* Caps lock */
#define IME_KEY_Shift_Lock        0xFFE6    /* Shift lock */

#define IME_KEY_Meta_L        0xFFE7    /* Left meta */
#define IME_KEY_Meta_R        0xFFE8    /* Right meta */
#define IME_KEY_Alt_L        0xFFE9    /* Left alt */
#define IME_KEY_Alt_R        0xFFEA    /* Right alt */
#define IME_KEY_Super_L        0xFFEB    /* Left super */
#define IME_KEY_Super_R        0xFFEC    /* Right super */
#define IME_KEY_Hyper_L        0xFFED    /* Left hyper */
#define IME_KEY_Hyper_R        0xFFEE    /* Right hyper */

/*
 * ISO 9995 Function and Modifier Keys
 * Byte 3 = 0xFE
 */

#define    IME_KEY_ISO_Lock                    0xFE01
#define    IME_KEY_ISO_Level2_Latch                0xFE02
#define    IME_KEY_ISO_Level3_Shift                0xFE03
#define    IME_KEY_ISO_Level3_Latch                0xFE04
#define    IME_KEY_ISO_Level3_Lock                0xFE05
#define    IME_KEY_ISO_Group_Shift        0xFF7E    /* Alias for mode_switch */
#define    IME_KEY_ISO_Group_Latch                0xFE06
#define    IME_KEY_ISO_Group_Lock                0xFE07
#define    IME_KEY_ISO_Next_Group                0xFE08
#define    IME_KEY_ISO_Next_Group_Lock                0xFE09
#define    IME_KEY_ISO_Prev_Group                0xFE0A
#define    IME_KEY_ISO_Prev_Group_Lock                0xFE0B
#define    IME_KEY_ISO_First_Group                0xFE0C
#define    IME_KEY_ISO_First_Group_Lock                0xFE0D
#define    IME_KEY_ISO_Last_Group                0xFE0E
#define    IME_KEY_ISO_Last_Group_Lock                0xFE0F

#define    IME_KEY_ISO_Left_Tab                    0xFE20
#define    IME_KEY_ISO_Move_Line_Up                0xFE21
#define    IME_KEY_ISO_Move_Line_Down                0xFE22
#define    IME_KEY_ISO_Partial_Line_Up                0xFE23
#define    IME_KEY_ISO_Partial_Line_Down            0xFE24
#define    IME_KEY_ISO_Partial_Space_Left            0xFE25
#define    IME_KEY_ISO_Partial_Space_Right            0xFE26
#define    IME_KEY_ISO_Set_Margin_Left                0xFE27
#define    IME_KEY_ISO_Set_Margin_Right                0xFE28
#define    IME_KEY_ISO_Release_Margin_Left            0xFE29
#define    IME_KEY_ISO_Release_Margin_Right            0xFE2A
#define    IME_KEY_ISO_Release_Both_Margins            0xFE2B
#define    IME_KEY_ISO_Fast_Cursor_Left                0xFE2C
#define    IME_KEY_ISO_Fast_Cursor_Right            0xFE2D
#define    IME_KEY_ISO_Fast_Cursor_Up                0xFE2E
#define    IME_KEY_ISO_Fast_Cursor_Down                0xFE2F
#define    IME_KEY_ISO_Continuous_Underline            0xFE30
#define    IME_KEY_ISO_Discontinuous_Underline            0xFE31
#define    IME_KEY_ISO_Emphasize                0xFE32
#define    IME_KEY_ISO_Center_Object                0xFE33
#define    IME_KEY_ISO_Enter                    0xFE34

#define    IME_KEY_dead_grave                    0xFE50
#define    IME_KEY_dead_acute                    0xFE51
#define    IME_KEY_dead_circumflex                0xFE52
#define    IME_KEY_dead_tilde                    0xFE53
#define    IME_KEY_dead_macron                    0xFE54
#define    IME_KEY_dead_breve                    0xFE55
#define    IME_KEY_dead_abovedot                0xFE56
#define    IME_KEY_dead_diaeresis                0xFE57
#define    IME_KEY_dead_abovering                0xFE58
#define    IME_KEY_dead_doubleacute                0xFE59
#define    IME_KEY_dead_caron                    0xFE5A
#define    IME_KEY_dead_cedilla                    0xFE5B
#define    IME_KEY_dead_ogonek                    0xFE5C
#define    IME_KEY_dead_iota                    0xFE5D
#define    IME_KEY_dead_voiced_sound                0xFE5E
#define    IME_KEY_dead_semivoiced_sound            0xFE5F
#define    IME_KEY_dead_belowdot                0xFE60
#define IME_KEY_dead_hook                    0xFE61
#define IME_KEY_dead_horn                    0xFE62

#define    IME_KEY_First_Virtual_Screen                0xFED0
#define    IME_KEY_Prev_Virtual_Screen                0xFED1
#define    IME_KEY_Next_Virtual_Screen                0xFED2
#define    IME_KEY_Last_Virtual_Screen                0xFED4
#define    IME_KEY_Terminate_Server                0xFED5

#define    IME_KEY_AccessX_Enable                0xFE70
#define    IME_KEY_AccessX_Feedback_Enable            0xFE71
#define    IME_KEY_RepeatKeys_Enable                0xFE72
#define    IME_KEY_SlowKeys_Enable                0xFE73
#define    IME_KEY_BounceKeys_Enable                0xFE74
#define    IME_KEY_StickyKeys_Enable                0xFE75
#define    IME_KEY_MouseKeys_Enable                0xFE76
#define    IME_KEY_MouseKeys_Accel_Enable            0xFE77
#define    IME_KEY_Overlay1_Enable                0xFE78
#define    IME_KEY_Overlay2_Enable                0xFE79
#define    IME_KEY_AudibleBell_Enable                0xFE7A

#define    IME_KEY_Pointer_Left                    0xFEE0
#define    IME_KEY_Pointer_Right                0xFEE1
#define    IME_KEY_Pointer_Up                    0xFEE2
#define    IME_KEY_Pointer_Down                    0xFEE3
#define    IME_KEY_Pointer_UpLeft                0xFEE4
#define    IME_KEY_Pointer_UpRight                0xFEE5
#define    IME_KEY_Pointer_DownLeft                0xFEE6
#define    IME_KEY_Pointer_DownRight                0xFEE7
#define    IME_KEY_Pointer_Button_Dflt                0xFEE8
#define    IME_KEY_Pointer_Button1                0xFEE9
#define    IME_KEY_Pointer_Button2                0xFEEA
#define    IME_KEY_Pointer_Button3                0xFEEB
#define    IME_KEY_Pointer_Button4                0xFEEC
#define    IME_KEY_Pointer_Button5                0xFEED
#define    IME_KEY_Pointer_DblClick_Dflt            0xFEEE
#define    IME_KEY_Pointer_DblClick1                0xFEEF
#define    IME_KEY_Pointer_DblClick2                0xFEF0
#define    IME_KEY_Pointer_DblClick3                0xFEF1
#define    IME_KEY_Pointer_DblClick4                0xFEF2
#define    IME_KEY_Pointer_DblClick5                0xFEF3
#define    IME_KEY_Pointer_Drag_Dflt                0xFEF4
#define    IME_KEY_Pointer_Drag1                0xFEF5
#define    IME_KEY_Pointer_Drag2                0xFEF6
#define    IME_KEY_Pointer_Drag3                0xFEF7
#define    IME_KEY_Pointer_Drag4                0xFEF8
#define    IME_KEY_Pointer_Drag5                0xFEFD

#define    IME_KEY_Pointer_EnableKeys                0xFEF9
#define    IME_KEY_Pointer_Accelerate                0xFEFA
#define    IME_KEY_Pointer_DfltBtnNext                0xFEFB
#define    IME_KEY_Pointer_DfltBtnPrev                0xFEFC


/*
 * 3270 Terminal Keys
 * Byte 3 = 0xFD
 */

#define IME_KEY_3270_Duplicate      0xFD01
#define IME_KEY_3270_FieldMark      0xFD02
#define IME_KEY_3270_Right2         0xFD03
#define IME_KEY_3270_Left2          0xFD04
#define IME_KEY_3270_BackTab        0xFD05
#define IME_KEY_3270_EraseEOF       0xFD06
#define IME_KEY_3270_EraseInput     0xFD07
#define IME_KEY_3270_Reset          0xFD08
#define IME_KEY_3270_Quit           0xFD09
#define IME_KEY_3270_PA1            0xFD0A
#define IME_KEY_3270_PA2            0xFD0B
#define IME_KEY_3270_PA3            0xFD0C
#define IME_KEY_3270_Test           0xFD0D
#define IME_KEY_3270_Attn           0xFD0E
#define IME_KEY_3270_CursorBlink    0xFD0F
#define IME_KEY_3270_AltCursor      0xFD10
#define IME_KEY_3270_KeyClick       0xFD11
#define IME_KEY_3270_Jump           0xFD12
#define IME_KEY_3270_Ident          0xFD13
#define IME_KEY_3270_Rule           0xFD14
#define IME_KEY_3270_Copy           0xFD15
#define IME_KEY_3270_Play           0xFD16
#define IME_KEY_3270_Setup          0xFD17
#define IME_KEY_3270_Record         0xFD18
#define IME_KEY_3270_ChangeScreen   0xFD19
#define IME_KEY_3270_DeleteWord     0xFD1A
#define IME_KEY_3270_ExSelect       0xFD1B
#define IME_KEY_3270_CursorSelect   0xFD1C
#define IME_KEY_3270_PrintScreen    0xFD1D
#define IME_KEY_3270_Enter          0xFD1E

/*
 *  Latin 1
 *  Byte 3 = 0
 */
#define IME_KEY_space               0x020
#define IME_KEY_exclam              0x021
#define IME_KEY_quotedbl            0x022
#define IME_KEY_numbersign          0x023
#define IME_KEY_dollar              0x024
#define IME_KEY_percent             0x025
#define IME_KEY_ampersand           0x026
#define IME_KEY_apostrophe          0x027
#define IME_KEY_quoteright          0x027    /* deprecated */
#define IME_KEY_parenleft           0x028
#define IME_KEY_parenright          0x029
#define IME_KEY_asterisk            0x02a
#define IME_KEY_plus                0x02b
#define IME_KEY_comma               0x02c
#define IME_KEY_minus               0x02d
#define IME_KEY_period              0x02e
#define IME_KEY_slash               0x02f
#define IME_KEY_0                   0x030
#define IME_KEY_1                   0x031
#define IME_KEY_2                   0x032
#define IME_KEY_3                   0x033
#define IME_KEY_4                   0x034
#define IME_KEY_5                   0x035
#define IME_KEY_6                   0x036
#define IME_KEY_7                   0x037
#define IME_KEY_8                   0x038
#define IME_KEY_9                   0x039
#define IME_KEY_colon               0x03a
#define IME_KEY_semicolon           0x03b
#define IME_KEY_less                0x03c
#define IME_KEY_equal               0x03d
#define IME_KEY_greater             0x03e
#define IME_KEY_question            0x03f
#define IME_KEY_at                  0x040
#define IME_KEY_A                   0x041
#define IME_KEY_B                   0x042
#define IME_KEY_C                   0x043
#define IME_KEY_D                   0x044
#define IME_KEY_E                   0x045
#define IME_KEY_F                   0x046
#define IME_KEY_G                   0x047
#define IME_KEY_H                   0x048
#define IME_KEY_I                   0x049
#define IME_KEY_J                   0x04a
#define IME_KEY_K                   0x04b
#define IME_KEY_L                   0x04c
#define IME_KEY_M                   0x04d
#define IME_KEY_N                   0x04e
#define IME_KEY_O                   0x04f
#define IME_KEY_P                   0x050
#define IME_KEY_Q                   0x051
#define IME_KEY_R                   0x052
#define IME_KEY_S                   0x053
#define IME_KEY_T                   0x054
#define IME_KEY_U                   0x055
#define IME_KEY_V                   0x056
#define IME_KEY_W                   0x057
#define IME_KEY_X                   0x058
#define IME_KEY_Y                   0x059
#define IME_KEY_Z                   0x05a
#define IME_KEY_bracketleft         0x05b
#define IME_KEY_backslash           0x05c
#define IME_KEY_bracketright        0x05d
#define IME_KEY_asciicircum         0x05e
#define IME_KEY_underscore          0x05f
#define IME_KEY_grave               0x060
#define IME_KEY_quoteleft           0x060    /* deprecated */
#define IME_KEY_a                   0x061
#define IME_KEY_b                   0x062
#define IME_KEY_c                   0x063
#define IME_KEY_d                   0x064
#define IME_KEY_e                   0x065
#define IME_KEY_f                   0x066
#define IME_KEY_g                   0x067
#define IME_KEY_h                   0x068
#define IME_KEY_i                   0x069
#define IME_KEY_j                   0x06a
#define IME_KEY_k                   0x06b
#define IME_KEY_l                   0x06c
#define IME_KEY_m                   0x06d
#define IME_KEY_n                   0x06e
#define IME_KEY_o                   0x06f
#define IME_KEY_p                   0x070
#define IME_KEY_q                   0x071
#define IME_KEY_r                   0x072
#define IME_KEY_s                   0x073
#define IME_KEY_t                   0x074
#define IME_KEY_u                   0x075
#define IME_KEY_v                   0x076
#define IME_KEY_w                   0x077
#define IME_KEY_x                   0x078
#define IME_KEY_y                   0x079
#define IME_KEY_z                   0x07a
#define IME_KEY_braceleft           0x07b
#define IME_KEY_bar                 0x07c
#define IME_KEY_braceright          0x07d
#define IME_KEY_asciitilde          0x07e

#define IME_KEY_nobreakspace        0x0a0
#define IME_KEY_exclamdown          0x0a1
#define IME_KEY_cent                   0x0a2
#define IME_KEY_sterling            0x0a3
#define IME_KEY_currency            0x0a4
#define IME_KEY_yen                 0x0a5
#define IME_KEY_brokenbar           0x0a6
#define IME_KEY_section             0x0a7
#define IME_KEY_diaeresis           0x0a8
#define IME_KEY_copyright           0x0a9
#define IME_KEY_ordfeminine         0x0aa
#define IME_KEY_guillemotleft       0x0ab    /* left angle quotation mark */
#define IME_KEY_notsign             0x0ac
#define IME_KEY_hyphen              0x0ad
#define IME_KEY_registered          0x0ae
#define IME_KEY_macron              0x0af
#define IME_KEY_degree              0x0b0
#define IME_KEY_plusminus           0x0b1
#define IME_KEY_twosuperior         0x0b2
#define IME_KEY_threesuperior       0x0b3
#define IME_KEY_acute               0x0b4
#define IME_KEY_mu                  0x0b5
#define IME_KEY_paragraph           0x0b6
#define IME_KEY_periodcentered      0x0b7
#define IME_KEY_cedilla             0x0b8
#define IME_KEY_onesuperior         0x0b9
#define IME_KEY_masculine           0x0ba
#define IME_KEY_guillemotright      0x0bb    /* right angle quotation mark */
#define IME_KEY_onequarter          0x0bc
#define IME_KEY_onehalf             0x0bd
#define IME_KEY_threequarters       0x0be
#define IME_KEY_questiondown        0x0bf
#define IME_KEY_Agrave              0x0c0
#define IME_KEY_Aacute              0x0c1
#define IME_KEY_Acircumflex         0x0c2
#define IME_KEY_Atilde              0x0c3
#define IME_KEY_Adiaeresis          0x0c4
#define IME_KEY_Aring               0x0c5
#define IME_KEY_AE                  0x0c6
#define IME_KEY_Ccedilla            0x0c7
#define IME_KEY_Egrave              0x0c8
#define IME_KEY_Eacute              0x0c9
#define IME_KEY_Ecircumflex         0x0ca
#define IME_KEY_Ediaeresis          0x0cb
#define IME_KEY_Igrave              0x0cc
#define IME_KEY_Iacute              0x0cd
#define IME_KEY_Icircumflex         0x0ce
#define IME_KEY_Idiaeresis          0x0cf
#define IME_KEY_ETH                 0x0d0
#define IME_KEY_Eth                 0x0d0    /* deprecated */
#define IME_KEY_Ntilde              0x0d1
#define IME_KEY_Ograve              0x0d2
#define IME_KEY_Oacute              0x0d3
#define IME_KEY_Ocircumflex         0x0d4
#define IME_KEY_Otilde              0x0d5
#define IME_KEY_Odiaeresis          0x0d6
#define IME_KEY_multiply            0x0d7
#define IME_KEY_Ooblique            0x0d8
#define IME_KEY_Oslash              IME_KEY_Ooblique
#define IME_KEY_Ugrave              0x0d9
#define IME_KEY_Uacute              0x0da
#define IME_KEY_Ucircumflex         0x0db
#define IME_KEY_Udiaeresis          0x0dc
#define IME_KEY_Yacute              0x0dd
#define IME_KEY_THORN               0x0de
#define IME_KEY_Thorn               0x0de    /* deprecated */
#define IME_KEY_ssharp              0x0df
#define IME_KEY_agrave              0x0e0
#define IME_KEY_aacute              0x0e1
#define IME_KEY_acircumflex         0x0e2
#define IME_KEY_atilde              0x0e3
#define IME_KEY_adiaeresis          0x0e4
#define IME_KEY_aring               0x0e5
#define IME_KEY_ae                  0x0e6
#define IME_KEY_ccedilla            0x0e7
#define IME_KEY_egrave              0x0e8
#define IME_KEY_eacute              0x0e9
#define IME_KEY_ecircumflex         0x0ea
#define IME_KEY_ediaeresis          0x0eb
#define IME_KEY_igrave              0x0ec
#define IME_KEY_iacute              0x0ed
#define IME_KEY_icircumflex         0x0ee
#define IME_KEY_idiaeresis          0x0ef
#define IME_KEY_eth                 0x0f0
#define IME_KEY_ntilde              0x0f1
#define IME_KEY_ograve              0x0f2
#define IME_KEY_oacute              0x0f3
#define IME_KEY_ocircumflex         0x0f4
#define IME_KEY_otilde              0x0f5
#define IME_KEY_odiaeresis          0x0f6
#define IME_KEY_division            0x0f7
#define IME_KEY_oslash              0x0f8
#define IME_KEY_ooblique            IME_KEY_oslash
#define IME_KEY_ugrave              0x0f9
#define IME_KEY_uacute              0x0fa
#define IME_KEY_ucircumflex         0x0fb
#define IME_KEY_udiaeresis          0x0fc
#define IME_KEY_yacute              0x0fd
#define IME_KEY_thorn               0x0fe
#define IME_KEY_ydiaeresis          0x0ff

/*
 *   Latin 2
 *   Byte 3 = 1
 */

#define IME_KEY_Aogonek             0x1a1
#define IME_KEY_breve               0x1a2
#define IME_KEY_Lstroke             0x1a3
#define IME_KEY_Lcaron              0x1a5
#define IME_KEY_Sacute              0x1a6
#define IME_KEY_Scaron              0x1a9
#define IME_KEY_Scedilla            0x1aa
#define IME_KEY_Tcaron              0x1ab
#define IME_KEY_Zacute              0x1ac
#define IME_KEY_Zcaron              0x1ae
#define IME_KEY_Zabovedot           0x1af
#define IME_KEY_aogonek             0x1b1
#define IME_KEY_ogonek              0x1b2
#define IME_KEY_lstroke             0x1b3
#define IME_KEY_lcaron              0x1b5
#define IME_KEY_sacute              0x1b6
#define IME_KEY_caron               0x1b7
#define IME_KEY_scaron              0x1b9
#define IME_KEY_scedilla            0x1ba
#define IME_KEY_tcaron              0x1bb
#define IME_KEY_zacute              0x1bc
#define IME_KEY_doubleacute         0x1bd
#define IME_KEY_zcaron              0x1be
#define IME_KEY_zabovedot           0x1bf
#define IME_KEY_Racute              0x1c0
#define IME_KEY_Abreve              0x1c3
#define IME_KEY_Lacute              0x1c5
#define IME_KEY_Cacute              0x1c6
#define IME_KEY_Ccaron              0x1c8
#define IME_KEY_Eogonek             0x1ca
#define IME_KEY_Ecaron              0x1cc
#define IME_KEY_Dcaron              0x1cf
#define IME_KEY_Dstroke             0x1d0
#define IME_KEY_Nacute              0x1d1
#define IME_KEY_Ncaron              0x1d2
#define IME_KEY_Odoubleacute        0x1d5
#define IME_KEY_Rcaron              0x1d8
#define IME_KEY_Uring               0x1d9
#define IME_KEY_Udoubleacute        0x1db
#define IME_KEY_Tcedilla            0x1de
#define IME_KEY_racute              0x1e0
#define IME_KEY_abreve              0x1e3
#define IME_KEY_lacute              0x1e5
#define IME_KEY_cacute              0x1e6
#define IME_KEY_ccaron              0x1e8
#define IME_KEY_eogonek             0x1ea
#define IME_KEY_ecaron              0x1ec
#define IME_KEY_dcaron              0x1ef
#define IME_KEY_dstroke             0x1f0
#define IME_KEY_nacute              0x1f1
#define IME_KEY_ncaron              0x1f2
#define IME_KEY_odoubleacute        0x1f5
#define IME_KEY_udoubleacute        0x1fb
#define IME_KEY_rcaron              0x1f8
#define IME_KEY_uring               0x1f9
#define IME_KEY_tcedilla            0x1fe
#define IME_KEY_abovedot            0x1ff

/*
 *   Latin 3
 *   Byte 3 = 2
 */

#define IME_KEY_Hstroke             0x2a1
#define IME_KEY_Hcircumflex         0x2a6
#define IME_KEY_Iabovedot           0x2a9
#define IME_KEY_Gbreve              0x2ab
#define IME_KEY_Jcircumflex         0x2ac
#define IME_KEY_hstroke             0x2b1
#define IME_KEY_hcircumflex         0x2b6
#define IME_KEY_idotless            0x2b9
#define IME_KEY_gbreve              0x2bb
#define IME_KEY_jcircumflex         0x2bc
#define IME_KEY_Cabovedot           0x2c5
#define IME_KEY_Ccircumflex         0x2c6
#define IME_KEY_Gabovedot           0x2d5
#define IME_KEY_Gcircumflex         0x2d8
#define IME_KEY_Ubreve              0x2dd
#define IME_KEY_Scircumflex         0x2de
#define IME_KEY_cabovedot           0x2e5
#define IME_KEY_ccircumflex         0x2e6
#define IME_KEY_gabovedot           0x2f5
#define IME_KEY_gcircumflex         0x2f8
#define IME_KEY_ubreve              0x2fd
#define IME_KEY_scircumflex         0x2fe


/*
 *   Latin 4
 *   Byte 3 = 3
 */

#define IME_KEY_kra                 0x3a2
#define IME_KEY_kappa               0x3a2    /* deprecated */
#define IME_KEY_Rcedilla            0x3a3
#define IME_KEY_Itilde              0x3a5
#define IME_KEY_Lcedilla            0x3a6
#define IME_KEY_Emacron             0x3aa
#define IME_KEY_Gcedilla            0x3ab
#define IME_KEY_Tslash              0x3ac
#define IME_KEY_rcedilla            0x3b3
#define IME_KEY_itilde              0x3b5
#define IME_KEY_lcedilla            0x3b6
#define IME_KEY_emacron             0x3ba
#define IME_KEY_gcedilla            0x3bb
#define IME_KEY_tslash              0x3bc
#define IME_KEY_ENG                 0x3bd
#define IME_KEY_eng                 0x3bf
#define IME_KEY_Amacron             0x3c0
#define IME_KEY_Iogonek             0x3c7
#define IME_KEY_Eabovedot           0x3cc
#define IME_KEY_Imacron             0x3cf
#define IME_KEY_Ncedilla            0x3d1
#define IME_KEY_Omacron             0x3d2
#define IME_KEY_Kcedilla            0x3d3
#define IME_KEY_Uogonek             0x3d9
#define IME_KEY_Utilde              0x3dd
#define IME_KEY_Umacron             0x3de
#define IME_KEY_amacron             0x3e0
#define IME_KEY_iogonek             0x3e7
#define IME_KEY_eabovedot           0x3ec
#define IME_KEY_imacron             0x3ef
#define IME_KEY_ncedilla            0x3f1
#define IME_KEY_omacron             0x3f2
#define IME_KEY_kcedilla            0x3f3
#define IME_KEY_uogonek             0x3f9
#define IME_KEY_utilde              0x3fd
#define IME_KEY_umacron             0x3fe

/*
 * Latin-8
 * Byte 3 = 18
 */
#define IME_KEY_Babovedot           0x12a1
#define IME_KEY_babovedot           0x12a2
#define IME_KEY_Dabovedot           0x12a6
#define IME_KEY_Wgrave              0x12a8
#define IME_KEY_Wacute              0x12aa
#define IME_KEY_dabovedot           0x12ab
#define IME_KEY_Ygrave              0x12ac
#define IME_KEY_Fabovedot           0x12b0
#define IME_KEY_fabovedot           0x12b1
#define IME_KEY_Mabovedot           0x12b4
#define IME_KEY_mabovedot           0x12b5
#define IME_KEY_Pabovedot           0x12b7
#define IME_KEY_wgrave              0x12b8
#define IME_KEY_pabovedot           0x12b9
#define IME_KEY_wacute              0x12ba
#define IME_KEY_Sabovedot           0x12bb
#define IME_KEY_ygrave              0x12bc
#define IME_KEY_Wdiaeresis          0x12bd
#define IME_KEY_wdiaeresis          0x12be
#define IME_KEY_sabovedot           0x12bf
#define IME_KEY_Wcircumflex         0x12d0
#define IME_KEY_Tabovedot           0x12d7
#define IME_KEY_Ycircumflex         0x12de
#define IME_KEY_wcircumflex         0x12f0
#define IME_KEY_tabovedot           0x12f7
#define IME_KEY_ycircumflex         0x12fe

/*
 * Latin-9 (a.k.a. Latin-0)
 * Byte 3 = 19
 */

#define IME_KEY_OE                  0x13bc
#define IME_KEY_oe                  0x13bd
#define IME_KEY_Ydiaeresis          0x13be

/*
 * Katakana
 * Byte 3 = 4
 */

#define IME_KEY_overline                       0x47e
#define IME_KEY_kana_fullstop                               0x4a1
#define IME_KEY_kana_openingbracket                         0x4a2
#define IME_KEY_kana_closingbracket                         0x4a3
#define IME_KEY_kana_comma                                  0x4a4
#define IME_KEY_kana_conjunctive                            0x4a5
#define IME_KEY_kana_middledot                              0x4a5  /* deprecated */
#define IME_KEY_kana_WO                                     0x4a6
#define IME_KEY_kana_a                                      0x4a7
#define IME_KEY_kana_i                                      0x4a8
#define IME_KEY_kana_u                                      0x4a9
#define IME_KEY_kana_e                                      0x4aa
#define IME_KEY_kana_o                                      0x4ab
#define IME_KEY_kana_ya                                     0x4ac
#define IME_KEY_kana_yu                                     0x4ad
#define IME_KEY_kana_yo                                     0x4ae
#define IME_KEY_kana_tsu                                    0x4af
#define IME_KEY_kana_tu                                     0x4af  /* deprecated */
#define IME_KEY_prolongedsound                              0x4b0
#define IME_KEY_kana_A                                      0x4b1
#define IME_KEY_kana_I                                      0x4b2
#define IME_KEY_kana_U                                      0x4b3
#define IME_KEY_kana_E                                      0x4b4
#define IME_KEY_kana_O                                      0x4b5
#define IME_KEY_kana_KA                                     0x4b6
#define IME_KEY_kana_KI                                     0x4b7
#define IME_KEY_kana_KU                                     0x4b8
#define IME_KEY_kana_KE                                     0x4b9
#define IME_KEY_kana_KO                                     0x4ba
#define IME_KEY_kana_SA                                     0x4bb
#define IME_KEY_kana_SHI                                    0x4bc
#define IME_KEY_kana_SU                                     0x4bd
#define IME_KEY_kana_SE                                     0x4be
#define IME_KEY_kana_SO                                     0x4bf
#define IME_KEY_kana_TA                                     0x4c0
#define IME_KEY_kana_CHI                                    0x4c1
#define IME_KEY_kana_TI                                     0x4c1  /* deprecated */
#define IME_KEY_kana_TSU                                    0x4c2
#define IME_KEY_kana_TU                                     0x4c2  /* deprecated */
#define IME_KEY_kana_TE                                     0x4c3
#define IME_KEY_kana_TO                                     0x4c4
#define IME_KEY_kana_NA                                     0x4c5
#define IME_KEY_kana_NI                                     0x4c6
#define IME_KEY_kana_NU                                     0x4c7
#define IME_KEY_kana_NE                                     0x4c8
#define IME_KEY_kana_NO                                     0x4c9
#define IME_KEY_kana_HA                                     0x4ca
#define IME_KEY_kana_HI                                     0x4cb
#define IME_KEY_kana_FU                                     0x4cc
#define IME_KEY_kana_HU                                     0x4cc  /* deprecated */
#define IME_KEY_kana_HE                                     0x4cd
#define IME_KEY_kana_HO                                     0x4ce
#define IME_KEY_kana_MA                                     0x4cf
#define IME_KEY_kana_MI                                     0x4d0
#define IME_KEY_kana_MU                                     0x4d1
#define IME_KEY_kana_ME                                     0x4d2
#define IME_KEY_kana_MO                                     0x4d3
#define IME_KEY_kana_YA                                     0x4d4
#define IME_KEY_kana_YU                                     0x4d5
#define IME_KEY_kana_YO                                     0x4d6
#define IME_KEY_kana_RA                                     0x4d7
#define IME_KEY_kana_RI                                     0x4d8
#define IME_KEY_kana_RU                                     0x4d9
#define IME_KEY_kana_RE                                     0x4da
#define IME_KEY_kana_RO                                     0x4db
#define IME_KEY_kana_WA                                     0x4dc
#define IME_KEY_kana_N                                      0x4dd
#define IME_KEY_voicedsound                                 0x4de
#define IME_KEY_semivoicedsound                             0x4df
#define IME_KEY_kana_switch          0xFF7E  /* Alias for mode_switch */

/*
 *  Arabic
 *  Byte 3 = 5
 */

#define IME_KEY_Farsi_0                                     0x590
#define IME_KEY_Farsi_1                                     0x591
#define IME_KEY_Farsi_2                                     0x592
#define IME_KEY_Farsi_3                                     0x593
#define IME_KEY_Farsi_4                                     0x594
#define IME_KEY_Farsi_5                                     0x595
#define IME_KEY_Farsi_6                                     0x596
#define IME_KEY_Farsi_7                                     0x597
#define IME_KEY_Farsi_8                                     0x598
#define IME_KEY_Farsi_9                                     0x599
#define IME_KEY_Arabic_percent                              0x5a5
#define IME_KEY_Arabic_superscript_alef                     0x5a6
#define IME_KEY_Arabic_tteh                                 0x5a7
#define IME_KEY_Arabic_peh                                  0x5a8
#define IME_KEY_Arabic_tcheh                                0x5a9
#define IME_KEY_Arabic_ddal                                 0x5aa
#define IME_KEY_Arabic_rreh                                 0x5ab
#define IME_KEY_Arabic_comma                                0x5ac
#define IME_KEY_Arabic_fullstop                             0x5ae
#define IME_KEY_Arabic_0                                    0x5b0
#define IME_KEY_Arabic_1                                    0x5b1
#define IME_KEY_Arabic_2                                    0x5b2
#define IME_KEY_Arabic_3                                    0x5b3
#define IME_KEY_Arabic_4                                    0x5b4
#define IME_KEY_Arabic_5                                    0x5b5
#define IME_KEY_Arabic_6                                    0x5b6
#define IME_KEY_Arabic_7                                    0x5b7
#define IME_KEY_Arabic_8                                    0x5b8
#define IME_KEY_Arabic_9                                    0x5b9
#define IME_KEY_Arabic_semicolon                            0x5bb
#define IME_KEY_Arabic_question_mark                        0x5bf
#define IME_KEY_Arabic_hamza                                0x5c1
#define IME_KEY_Arabic_maddaonalef                          0x5c2
#define IME_KEY_Arabic_hamzaonalef                          0x5c3
#define IME_KEY_Arabic_hamzaonwaw                           0x5c4
#define IME_KEY_Arabic_hamzaunderalef                       0x5c5
#define IME_KEY_Arabic_hamzaonyeh                           0x5c6
#define IME_KEY_Arabic_alef                                 0x5c7
#define IME_KEY_Arabic_beh                                  0x5c8
#define IME_KEY_Arabic_tehmarbuta                           0x5c9
#define IME_KEY_Arabic_teh                                  0x5ca
#define IME_KEY_Arabic_theh                                 0x5cb
#define IME_KEY_Arabic_jeem                                 0x5cc
#define IME_KEY_Arabic_hah                                  0x5cd
#define IME_KEY_Arabic_khah                                 0x5ce
#define IME_KEY_Arabic_dal                                  0x5cf
#define IME_KEY_Arabic_thal                                 0x5d0
#define IME_KEY_Arabic_ra                                   0x5d1
#define IME_KEY_Arabic_zain                                 0x5d2
#define IME_KEY_Arabic_seen                                 0x5d3
#define IME_KEY_Arabic_sheen                                0x5d4
#define IME_KEY_Arabic_sad                                  0x5d5
#define IME_KEY_Arabic_dad                                  0x5d6
#define IME_KEY_Arabic_tah                                  0x5d7
#define IME_KEY_Arabic_zah                                  0x5d8
#define IME_KEY_Arabic_ain                                  0x5d9
#define IME_KEY_Arabic_ghain                                0x5da
#define IME_KEY_Arabic_tatweel                              0x5e0
#define IME_KEY_Arabic_feh                                  0x5e1
#define IME_KEY_Arabic_qaf                                  0x5e2
#define IME_KEY_Arabic_kaf                                  0x5e3
#define IME_KEY_Arabic_lam                                  0x5e4
#define IME_KEY_Arabic_meem                                 0x5e5
#define IME_KEY_Arabic_noon                                 0x5e6
#define IME_KEY_Arabic_ha                                   0x5e7
#define IME_KEY_Arabic_heh                                  0x5e7  /* deprecated */
#define IME_KEY_Arabic_waw                                  0x5e8
#define IME_KEY_Arabic_alefmaksura                          0x5e9
#define IME_KEY_Arabic_yeh                                  0x5ea
#define IME_KEY_Arabic_fathatan                             0x5eb
#define IME_KEY_Arabic_dammatan                             0x5ec
#define IME_KEY_Arabic_kasratan                             0x5ed
#define IME_KEY_Arabic_fatha                                0x5ee
#define IME_KEY_Arabic_damma                                0x5ef
#define IME_KEY_Arabic_kasra                                0x5f0
#define IME_KEY_Arabic_shadda                               0x5f1
#define IME_KEY_Arabic_sukun                                0x5f2
#define IME_KEY_Arabic_madda_above                          0x5f3
#define IME_KEY_Arabic_hamza_above                          0x5f4
#define IME_KEY_Arabic_hamza_below                          0x5f5
#define IME_KEY_Arabic_jeh                                  0x5f6
#define IME_KEY_Arabic_veh                                  0x5f7
#define IME_KEY_Arabic_keheh                                0x5f8
#define IME_KEY_Arabic_gaf                                  0x5f9
#define IME_KEY_Arabic_noon_ghunna                          0x5fa
#define IME_KEY_Arabic_heh_doachashmee                      0x5fb
#define IME_KEY_Farsi_yeh                                   0x5fc
#define IME_KEY_Arabic_farsi_yeh                     IME_KEY_Farsi_yeh
#define IME_KEY_Arabic_yeh_baree                            0x5fd
#define IME_KEY_Arabic_heh_goal                             0x5fe
#define IME_KEY_Arabic_switch        0xFF7E  /* Alias for mode_switch */

/*
 * Cyrillic
 * Byte 3 = 6
 */
#define IME_KEY_Cyrillic_GHE_bar                               0x680
#define IME_KEY_Cyrillic_ghe_bar                               0x690
#define IME_KEY_Cyrillic_ZHE_descender                       0x681
#define IME_KEY_Cyrillic_zhe_descender                       0x691
#define IME_KEY_Cyrillic_KA_descender                       0x682
#define IME_KEY_Cyrillic_ka_descender                       0x692
#define IME_KEY_Cyrillic_KA_vertstroke                       0x683
#define IME_KEY_Cyrillic_ka_vertstroke                       0x693
#define IME_KEY_Cyrillic_EN_descender                       0x684
#define IME_KEY_Cyrillic_en_descender                       0x694
#define IME_KEY_Cyrillic_U_straight                           0x685
#define IME_KEY_Cyrillic_u_straight                           0x695
#define IME_KEY_Cyrillic_U_straight_bar                       0x686
#define IME_KEY_Cyrillic_u_straight_bar                       0x696
#define IME_KEY_Cyrillic_HA_descender                       0x687
#define IME_KEY_Cyrillic_ha_descender                       0x697
#define IME_KEY_Cyrillic_CHE_descender                       0x688
#define IME_KEY_Cyrillic_che_descender                       0x698
#define IME_KEY_Cyrillic_CHE_vertstroke                       0x689
#define IME_KEY_Cyrillic_che_vertstroke                       0x699
#define IME_KEY_Cyrillic_SHHA                               0x68a
#define IME_KEY_Cyrillic_shha                               0x69a

#define IME_KEY_Cyrillic_SCHWA                               0x68c
#define IME_KEY_Cyrillic_schwa                               0x69c
#define IME_KEY_Cyrillic_I_macron                           0x68d
#define IME_KEY_Cyrillic_i_macron                           0x69d
#define IME_KEY_Cyrillic_O_bar                               0x68e
#define IME_KEY_Cyrillic_o_bar                               0x69e
#define IME_KEY_Cyrillic_U_macron                           0x68f
#define IME_KEY_Cyrillic_u_macron                           0x69f

#define IME_KEY_Serbian_dje                                 0x6a1
#define IME_KEY_Macedonia_gje                               0x6a2
#define IME_KEY_Cyrillic_io                                 0x6a3
#define IME_KEY_Ukrainian_ie                                0x6a4
#define IME_KEY_Ukranian_je                                 0x6a4  /* deprecated */
#define IME_KEY_Macedonia_dse                               0x6a5
#define IME_KEY_Ukrainian_i                                 0x6a6
#define IME_KEY_Ukranian_i                                  0x6a6  /* deprecated */
#define IME_KEY_Ukrainian_yi                                0x6a7
#define IME_KEY_Ukranian_yi                                 0x6a7  /* deprecated */
#define IME_KEY_Cyrillic_je                                 0x6a8
#define IME_KEY_Serbian_je                                  0x6a8  /* deprecated */
#define IME_KEY_Cyrillic_lje                                0x6a9
#define IME_KEY_Serbian_lje                                 0x6a9  /* deprecated */
#define IME_KEY_Cyrillic_nje                                0x6aa
#define IME_KEY_Serbian_nje                                 0x6aa  /* deprecated */
#define IME_KEY_Serbian_tshe                                0x6ab
#define IME_KEY_Macedonia_kje                               0x6ac
#define IME_KEY_Ukrainian_ghe_with_upturn                   0x6ad
#define IME_KEY_Byelorussian_shortu                         0x6ae
#define IME_KEY_Cyrillic_dzhe                               0x6af
#define IME_KEY_Serbian_dze                                 0x6af  /* deprecated */
#define IME_KEY_numerosign                                  0x6b0
#define IME_KEY_Serbian_DJE                                 0x6b1
#define IME_KEY_Macedonia_GJE                               0x6b2
#define IME_KEY_Cyrillic_IO                                 0x6b3
#define IME_KEY_Ukrainian_IE                                0x6b4
#define IME_KEY_Ukranian_JE                                 0x6b4  /* deprecated */
#define IME_KEY_Macedonia_DSE                               0x6b5
#define IME_KEY_Ukrainian_I                                 0x6b6
#define IME_KEY_Ukranian_I                                  0x6b6  /* deprecated */
#define IME_KEY_Ukrainian_YI                                0x6b7
#define IME_KEY_Ukranian_YI                                 0x6b7  /* deprecated */
#define IME_KEY_Cyrillic_JE                                 0x6b8
#define IME_KEY_Serbian_JE                                  0x6b8  /* deprecated */
#define IME_KEY_Cyrillic_LJE                                0x6b9
#define IME_KEY_Serbian_LJE                                 0x6b9  /* deprecated */
#define IME_KEY_Cyrillic_NJE                                0x6ba
#define IME_KEY_Serbian_NJE                                 0x6ba  /* deprecated */
#define IME_KEY_Serbian_TSHE                                0x6bb
#define IME_KEY_Macedonia_KJE                               0x6bc
#define IME_KEY_Ukrainian_GHE_WITH_UPTURN                   0x6bd
#define IME_KEY_Byelorussian_SHORTU                         0x6be
#define IME_KEY_Cyrillic_DZHE                               0x6bf
#define IME_KEY_Serbian_DZE                                 0x6bf  /* deprecated */
#define IME_KEY_Cyrillic_yu                                 0x6c0
#define IME_KEY_Cyrillic_a                                  0x6c1
#define IME_KEY_Cyrillic_be                                 0x6c2
#define IME_KEY_Cyrillic_tse                                0x6c3
#define IME_KEY_Cyrillic_de                                 0x6c4
#define IME_KEY_Cyrillic_ie                                 0x6c5
#define IME_KEY_Cyrillic_ef                                 0x6c6
#define IME_KEY_Cyrillic_ghe                                0x6c7
#define IME_KEY_Cyrillic_ha                                 0x6c8
#define IME_KEY_Cyrillic_i                                  0x6c9
#define IME_KEY_Cyrillic_shorti                             0x6ca
#define IME_KEY_Cyrillic_ka                                 0x6cb
#define IME_KEY_Cyrillic_el                                 0x6cc
#define IME_KEY_Cyrillic_em                                 0x6cd
#define IME_KEY_Cyrillic_en                                 0x6ce
#define IME_KEY_Cyrillic_o                                  0x6cf
#define IME_KEY_Cyrillic_pe                                 0x6d0
#define IME_KEY_Cyrillic_ya                                 0x6d1
#define IME_KEY_Cyrillic_er                                 0x6d2
#define IME_KEY_Cyrillic_es                                 0x6d3
#define IME_KEY_Cyrillic_te                                 0x6d4
#define IME_KEY_Cyrillic_u                                  0x6d5
#define IME_KEY_Cyrillic_zhe                                0x6d6
#define IME_KEY_Cyrillic_ve                                 0x6d7
#define IME_KEY_Cyrillic_softsign                           0x6d8
#define IME_KEY_Cyrillic_yeru                               0x6d9
#define IME_KEY_Cyrillic_ze                                 0x6da
#define IME_KEY_Cyrillic_sha                                0x6db
#define IME_KEY_Cyrillic_e                                  0x6dc
#define IME_KEY_Cyrillic_shcha                              0x6dd
#define IME_KEY_Cyrillic_che                                0x6de
#define IME_KEY_Cyrillic_hardsign                           0x6df
#define IME_KEY_Cyrillic_YU                                 0x6e0
#define IME_KEY_Cyrillic_A                                  0x6e1
#define IME_KEY_Cyrillic_BE                                 0x6e2
#define IME_KEY_Cyrillic_TSE                                0x6e3
#define IME_KEY_Cyrillic_DE                                 0x6e4
#define IME_KEY_Cyrillic_IE                                 0x6e5
#define IME_KEY_Cyrillic_EF                                 0x6e6
#define IME_KEY_Cyrillic_GHE                                0x6e7
#define IME_KEY_Cyrillic_HA                                 0x6e8
#define IME_KEY_Cyrillic_I                                  0x6e9
#define IME_KEY_Cyrillic_SHORTI                             0x6ea
#define IME_KEY_Cyrillic_KA                                 0x6eb
#define IME_KEY_Cyrillic_EL                                 0x6ec
#define IME_KEY_Cyrillic_EM                                 0x6ed
#define IME_KEY_Cyrillic_EN                                 0x6ee
#define IME_KEY_Cyrillic_O                                  0x6ef
#define IME_KEY_Cyrillic_PE                                 0x6f0
#define IME_KEY_Cyrillic_YA                                 0x6f1
#define IME_KEY_Cyrillic_ER                                 0x6f2
#define IME_KEY_Cyrillic_ES                                 0x6f3
#define IME_KEY_Cyrillic_TE                                 0x6f4
#define IME_KEY_Cyrillic_U                                  0x6f5
#define IME_KEY_Cyrillic_ZHE                                0x6f6
#define IME_KEY_Cyrillic_VE                                 0x6f7
#define IME_KEY_Cyrillic_SOFTSIGN                           0x6f8
#define IME_KEY_Cyrillic_YERU                               0x6f9
#define IME_KEY_Cyrillic_ZE                                 0x6fa
#define IME_KEY_Cyrillic_SHA                                0x6fb
#define IME_KEY_Cyrillic_E                                  0x6fc
#define IME_KEY_Cyrillic_SHCHA                              0x6fd
#define IME_KEY_Cyrillic_CHE                                0x6fe
#define IME_KEY_Cyrillic_HARDSIGN                           0x6ff

/*
 * Greek
 * Byte 3 = 7
 */

#define IME_KEY_Greek_ALPHAaccent                           0x7a1
#define IME_KEY_Greek_EPSILONaccent                         0x7a2
#define IME_KEY_Greek_ETAaccent                             0x7a3
#define IME_KEY_Greek_IOTAaccent                            0x7a4
#define IME_KEY_Greek_IOTAdieresis                          0x7a5
#define IME_KEY_Greek_IOTAdiaeresis         IME_KEY_Greek_IOTAdieresis /* old typo */
#define IME_KEY_Greek_OMICRONaccent                         0x7a7
#define IME_KEY_Greek_UPSILONaccent                         0x7a8
#define IME_KEY_Greek_UPSILONdieresis                       0x7a9
#define IME_KEY_Greek_OMEGAaccent                           0x7ab
#define IME_KEY_Greek_accentdieresis                        0x7ae
#define IME_KEY_Greek_horizbar                              0x7af
#define IME_KEY_Greek_alphaaccent                           0x7b1
#define IME_KEY_Greek_epsilonaccent                         0x7b2
#define IME_KEY_Greek_etaaccent                             0x7b3
#define IME_KEY_Greek_iotaaccent                            0x7b4
#define IME_KEY_Greek_iotadieresis                          0x7b5
#define IME_KEY_Greek_iotaaccentdieresis                    0x7b6
#define IME_KEY_Greek_omicronaccent                         0x7b7
#define IME_KEY_Greek_upsilonaccent                         0x7b8
#define IME_KEY_Greek_upsilondieresis                       0x7b9
#define IME_KEY_Greek_upsilonaccentdieresis                 0x7ba
#define IME_KEY_Greek_omegaaccent                           0x7bb
#define IME_KEY_Greek_ALPHA                                 0x7c1
#define IME_KEY_Greek_BETA                                  0x7c2
#define IME_KEY_Greek_GAMMA                                 0x7c3
#define IME_KEY_Greek_DELTA                                 0x7c4
#define IME_KEY_Greek_EPSILON                               0x7c5
#define IME_KEY_Greek_ZETA                                  0x7c6
#define IME_KEY_Greek_ETA                                   0x7c7
#define IME_KEY_Greek_THETA                                 0x7c8
#define IME_KEY_Greek_IOTA                                  0x7c9
#define IME_KEY_Greek_KAPPA                                 0x7ca
#define IME_KEY_Greek_LAMDA                                 0x7cb
#define IME_KEY_Greek_LAMBDA                                0x7cb
#define IME_KEY_Greek_MU                                    0x7cc
#define IME_KEY_Greek_NU                                    0x7cd
#define IME_KEY_Greek_XI                                    0x7ce
#define IME_KEY_Greek_OMICRON                               0x7cf
#define IME_KEY_Greek_PI                                    0x7d0
#define IME_KEY_Greek_RHO                                   0x7d1
#define IME_KEY_Greek_SIGMA                                 0x7d2
#define IME_KEY_Greek_TAU                                   0x7d4
#define IME_KEY_Greek_UPSILON                               0x7d5
#define IME_KEY_Greek_PHI                                   0x7d6
#define IME_KEY_Greek_CHI                                   0x7d7
#define IME_KEY_Greek_PSI                                   0x7d8
#define IME_KEY_Greek_OMEGA                                 0x7d9
#define IME_KEY_Greek_alpha                                 0x7e1
#define IME_KEY_Greek_beta                                  0x7e2
#define IME_KEY_Greek_gamma                                 0x7e3
#define IME_KEY_Greek_delta                                 0x7e4
#define IME_KEY_Greek_epsilon                               0x7e5
#define IME_KEY_Greek_zeta                                  0x7e6
#define IME_KEY_Greek_eta                                   0x7e7
#define IME_KEY_Greek_theta                                 0x7e8
#define IME_KEY_Greek_iota                                  0x7e9
#define IME_KEY_Greek_kappa                                 0x7ea
#define IME_KEY_Greek_lamda                                 0x7eb
#define IME_KEY_Greek_lambda                                0x7eb
#define IME_KEY_Greek_mu                                    0x7ec
#define IME_KEY_Greek_nu                                    0x7ed
#define IME_KEY_Greek_xi                                    0x7ee
#define IME_KEY_Greek_omicron                               0x7ef
#define IME_KEY_Greek_pi                                    0x7f0
#define IME_KEY_Greek_rho                                   0x7f1
#define IME_KEY_Greek_sigma                                 0x7f2
#define IME_KEY_Greek_finalsmallsigma                       0x7f3
#define IME_KEY_Greek_tau                                   0x7f4
#define IME_KEY_Greek_upsilon                               0x7f5
#define IME_KEY_Greek_phi                                   0x7f6
#define IME_KEY_Greek_chi                                   0x7f7
#define IME_KEY_Greek_psi                                   0x7f8
#define IME_KEY_Greek_omega                                 0x7f9
#define IME_KEY_Greek_switch         0xFF7E  /* Alias for mode_switch */

/*
 * Technical
 * Byte 3 = 8
 */

#define IME_KEY_leftradical                                 0x8a1
#define IME_KEY_topleftradical                              0x8a2
#define IME_KEY_horizconnector                              0x8a3
#define IME_KEY_topintegral                                 0x8a4
#define IME_KEY_botintegral                                 0x8a5
#define IME_KEY_vertconnector                               0x8a6
#define IME_KEY_topleftsqbracket                            0x8a7
#define IME_KEY_botleftsqbracket                            0x8a8
#define IME_KEY_toprightsqbracket                           0x8a9
#define IME_KEY_botrightsqbracket                           0x8aa
#define IME_KEY_topleftparens                               0x8ab
#define IME_KEY_botleftparens                               0x8ac
#define IME_KEY_toprightparens                              0x8ad
#define IME_KEY_botrightparens                              0x8ae
#define IME_KEY_leftmiddlecurlybrace                        0x8af
#define IME_KEY_rightmiddlecurlybrace                       0x8b0
#define IME_KEY_topleftsummation                            0x8b1
#define IME_KEY_botleftsummation                            0x8b2
#define IME_KEY_topvertsummationconnector                   0x8b3
#define IME_KEY_botvertsummationconnector                   0x8b4
#define IME_KEY_toprightsummation                           0x8b5
#define IME_KEY_botrightsummation                           0x8b6
#define IME_KEY_rightmiddlesummation                        0x8b7
#define IME_KEY_lessthanequal                               0x8bc
#define IME_KEY_notequal                                    0x8bd
#define IME_KEY_greaterthanequal                            0x8be
#define IME_KEY_integral                                    0x8bf
#define IME_KEY_therefore                                   0x8c0
#define IME_KEY_variation                                   0x8c1
#define IME_KEY_infinity                                    0x8c2
#define IME_KEY_nabla                                       0x8c5
#define IME_KEY_approximate                                 0x8c8
#define IME_KEY_similarequal                                0x8c9
#define IME_KEY_ifonlyif                                    0x8cd
#define IME_KEY_implies                                     0x8ce
#define IME_KEY_identical                                   0x8cf
#define IME_KEY_radical                                     0x8d6
#define IME_KEY_includedin                                  0x8da
#define IME_KEY_includes                                    0x8db
#define IME_KEY_intersection                                0x8dc
#define IME_KEY_union                                       0x8dd
#define IME_KEY_logicaland                                  0x8de
#define IME_KEY_logicalor                                   0x8df
#define IME_KEY_partialderivative                           0x8ef
#define IME_KEY_function                                    0x8f6
#define IME_KEY_leftarrow                                   0x8fb
#define IME_KEY_uparrow                                     0x8fc
#define IME_KEY_rightarrow                                  0x8fd
#define IME_KEY_downarrow                                   0x8fe

/*
 *  Special
 *  Byte 3 = 9
 */

#define IME_KEY_blank                                       0x9df
#define IME_KEY_soliddiamond                                0x9e0
#define IME_KEY_checkerboard                                0x9e1
#define IME_KEY_ht                                          0x9e2
#define IME_KEY_ff                                          0x9e3
#define IME_KEY_cr                                          0x9e4
#define IME_KEY_lf                                          0x9e5
#define IME_KEY_nl                                          0x9e8
#define IME_KEY_vt                                          0x9e9
#define IME_KEY_lowrightcorner                              0x9ea
#define IME_KEY_uprightcorner                               0x9eb
#define IME_KEY_upleftcorner                                0x9ec
#define IME_KEY_lowleftcorner                               0x9ed
#define IME_KEY_crossinglines                               0x9ee
#define IME_KEY_horizlinescan1                              0x9ef
#define IME_KEY_horizlinescan3                              0x9f0
#define IME_KEY_horizlinescan5                              0x9f1
#define IME_KEY_horizlinescan7                              0x9f2
#define IME_KEY_horizlinescan9                              0x9f3
#define IME_KEY_leftt                                       0x9f4
#define IME_KEY_rightt                                      0x9f5
#define IME_KEY_bott                                        0x9f6
#define IME_KEY_topt                                        0x9f7
#define IME_KEY_vertbar                                     0x9f8

/*
 *  Publishing
 *  Byte 3 = a
 */

#define IME_KEY_emspace                                     0xaa1
#define IME_KEY_enspace                                     0xaa2
#define IME_KEY_em3space                                    0xaa3
#define IME_KEY_em4space                                    0xaa4
#define IME_KEY_digitspace                                  0xaa5
#define IME_KEY_punctspace                                  0xaa6
#define IME_KEY_thinspace                                   0xaa7
#define IME_KEY_hairspace                                   0xaa8
#define IME_KEY_emdash                                      0xaa9
#define IME_KEY_endash                                      0xaaa
#define IME_KEY_signifblank                                 0xaac
#define IME_KEY_ellipsis                                    0xaae
#define IME_KEY_doubbaselinedot                             0xaaf
#define IME_KEY_onethird                                    0xab0
#define IME_KEY_twothirds                                   0xab1
#define IME_KEY_onefifth                                    0xab2
#define IME_KEY_twofifths                                   0xab3
#define IME_KEY_threefifths                                 0xab4
#define IME_KEY_fourfifths                                  0xab5
#define IME_KEY_onesixth                                    0xab6
#define IME_KEY_fivesixths                                  0xab7
#define IME_KEY_careof                                      0xab8
#define IME_KEY_figdash                                     0xabb
#define IME_KEY_leftanglebracket                            0xabc
#define IME_KEY_decimalpoint                                0xabd
#define IME_KEY_rightanglebracket                           0xabe
#define IME_KEY_marker                                      0xabf
#define IME_KEY_oneeighth                                   0xac3
#define IME_KEY_threeeighths                                0xac4
#define IME_KEY_fiveeighths                                 0xac5
#define IME_KEY_seveneighths                                0xac6
#define IME_KEY_trademark                                   0xac9
#define IME_KEY_signaturemark                               0xaca
#define IME_KEY_trademarkincircle                           0xacb
#define IME_KEY_leftopentriangle                            0xacc
#define IME_KEY_rightopentriangle                           0xacd
#define IME_KEY_emopencircle                                0xace
#define IME_KEY_emopenrectangle                             0xacf
#define IME_KEY_leftsinglequotemark                         0xad0
#define IME_KEY_rightsinglequotemark                        0xad1
#define IME_KEY_leftdoublequotemark                         0xad2
#define IME_KEY_rightdoublequotemark                        0xad3
#define IME_KEY_prescription                                0xad4
#define IME_KEY_minutes                                     0xad6
#define IME_KEY_seconds                                     0xad7
#define IME_KEY_latincross                                  0xad9
#define IME_KEY_hexagram                                    0xada
#define IME_KEY_filledrectbullet                            0xadb
#define IME_KEY_filledlefttribullet                         0xadc
#define IME_KEY_filledrighttribullet                        0xadd
#define IME_KEY_emfilledcircle                              0xade
#define IME_KEY_emfilledrect                                0xadf
#define IME_KEY_enopencircbullet                            0xae0
#define IME_KEY_enopensquarebullet                          0xae1
#define IME_KEY_openrectbullet                              0xae2
#define IME_KEY_opentribulletup                             0xae3
#define IME_KEY_opentribulletdown                           0xae4
#define IME_KEY_openstar                                    0xae5
#define IME_KEY_enfilledcircbullet                          0xae6
#define IME_KEY_enfilledsqbullet                            0xae7
#define IME_KEY_filledtribulletup                           0xae8
#define IME_KEY_filledtribulletdown                         0xae9
#define IME_KEY_leftpointer                                 0xaea
#define IME_KEY_rightpointer                                0xaeb
#define IME_KEY_club                                        0xaec
#define IME_KEY_diamond                                     0xaed
#define IME_KEY_heart                                       0xaee
#define IME_KEY_maltesecross                                0xaf0
#define IME_KEY_dagger                                      0xaf1
#define IME_KEY_doubledagger                                0xaf2
#define IME_KEY_checkmark                                   0xaf3
#define IME_KEY_ballotcross                                 0xaf4
#define IME_KEY_musicalsharp                                0xaf5
#define IME_KEY_musicalflat                                 0xaf6
#define IME_KEY_malesymbol                                  0xaf7
#define IME_KEY_femalesymbol                                0xaf8
#define IME_KEY_telephone                                   0xaf9
#define IME_KEY_telephonerecorder                           0xafa
#define IME_KEY_phonographcopyright                         0xafb
#define IME_KEY_caret                                       0xafc
#define IME_KEY_singlelowquotemark                          0xafd
#define IME_KEY_doublelowquotemark                          0xafe
#define IME_KEY_cursor                                      0xaff

/*
 *  APL
 *  Byte 3 = b
 */

#define IME_KEY_leftcaret                                   0xba3
#define IME_KEY_rightcaret                                  0xba6
#define IME_KEY_downcaret                                   0xba8
#define IME_KEY_upcaret                                     0xba9
#define IME_KEY_overbar                                     0xbc0
#define IME_KEY_downtack                                    0xbc2
#define IME_KEY_upshoe                                      0xbc3
#define IME_KEY_downstile                                   0xbc4
#define IME_KEY_underbar                                    0xbc6
#define IME_KEY_jot                                         0xbca
#define IME_KEY_quad                                        0xbcc
#define IME_KEY_uptack                                      0xbce
#define IME_KEY_circle                                      0xbcf
#define IME_KEY_upstile                                     0xbd3
#define IME_KEY_downshoe                                    0xbd6
#define IME_KEY_rightshoe                                   0xbd8
#define IME_KEY_leftshoe                                    0xbda
#define IME_KEY_lefttack                                    0xbdc
#define IME_KEY_righttack                                   0xbfc

/*
 * Hebrew
 * Byte 3 = c
 */

#define IME_KEY_hebrew_doublelowline                        0xcdf
#define IME_KEY_hebrew_aleph                                0xce0
#define IME_KEY_hebrew_bet                                  0xce1
#define IME_KEY_hebrew_beth                                 0xce1  /* deprecated */
#define IME_KEY_hebrew_gimel                                0xce2
#define IME_KEY_hebrew_gimmel                               0xce2  /* deprecated */
#define IME_KEY_hebrew_dalet                                0xce3
#define IME_KEY_hebrew_daleth                               0xce3  /* deprecated */
#define IME_KEY_hebrew_he                                   0xce4
#define IME_KEY_hebrew_waw                                  0xce5
#define IME_KEY_hebrew_zain                                 0xce6
#define IME_KEY_hebrew_zayin                                0xce6  /* deprecated */
#define IME_KEY_hebrew_chet                                 0xce7
#define IME_KEY_hebrew_het                                  0xce7  /* deprecated */
#define IME_KEY_hebrew_tet                                  0xce8
#define IME_KEY_hebrew_teth                                 0xce8  /* deprecated */
#define IME_KEY_hebrew_yod                                  0xce9
#define IME_KEY_hebrew_finalkaph                            0xcea
#define IME_KEY_hebrew_kaph                                 0xceb
#define IME_KEY_hebrew_lamed                                0xcec
#define IME_KEY_hebrew_finalmem                             0xced
#define IME_KEY_hebrew_mem                                  0xcee
#define IME_KEY_hebrew_finalnun                             0xcef
#define IME_KEY_hebrew_nun                                  0xcf0
#define IME_KEY_hebrew_samech                               0xcf1
#define IME_KEY_hebrew_samekh                               0xcf1  /* deprecated */
#define IME_KEY_hebrew_ayin                                 0xcf2
#define IME_KEY_hebrew_finalpe                              0xcf3
#define IME_KEY_hebrew_pe                                   0xcf4
#define IME_KEY_hebrew_finalzade                            0xcf5
#define IME_KEY_hebrew_finalzadi                            0xcf5  /* deprecated */
#define IME_KEY_hebrew_zade                                 0xcf6
#define IME_KEY_hebrew_zadi                                 0xcf6  /* deprecated */
#define IME_KEY_hebrew_qoph                                 0xcf7
#define IME_KEY_hebrew_kuf                                  0xcf7  /* deprecated */
#define IME_KEY_hebrew_resh                                 0xcf8
#define IME_KEY_hebrew_shin                                 0xcf9
#define IME_KEY_hebrew_taw                                  0xcfa
#define IME_KEY_hebrew_taf                                  0xcfa  /* deprecated */
#define IME_KEY_Hebrew_switch        0xFF7E  /* Alias for mode_switch */

/*
 * Thai
 * Byte 3 = d
 */

#define IME_KEY_Thai_kokai                    0xda1
#define IME_KEY_Thai_khokhai                    0xda2
#define IME_KEY_Thai_khokhuat                0xda3
#define IME_KEY_Thai_khokhwai                0xda4
#define IME_KEY_Thai_khokhon                    0xda5
#define IME_KEY_Thai_khorakhang                    0xda6  
#define IME_KEY_Thai_ngongu                    0xda7  
#define IME_KEY_Thai_chochan                    0xda8  
#define IME_KEY_Thai_choching                0xda9   
#define IME_KEY_Thai_chochang                0xdaa  
#define IME_KEY_Thai_soso                    0xdab
#define IME_KEY_Thai_chochoe                    0xdac
#define IME_KEY_Thai_yoying                    0xdad
#define IME_KEY_Thai_dochada                    0xdae
#define IME_KEY_Thai_topatak                    0xdaf
#define IME_KEY_Thai_thothan                    0xdb0
#define IME_KEY_Thai_thonangmontho                    0xdb1
#define IME_KEY_Thai_thophuthao                    0xdb2
#define IME_KEY_Thai_nonen                    0xdb3
#define IME_KEY_Thai_dodek                    0xdb4
#define IME_KEY_Thai_totao                    0xdb5
#define IME_KEY_Thai_thothung                0xdb6
#define IME_KEY_Thai_thothahan                0xdb7
#define IME_KEY_Thai_thothong                 0xdb8
#define IME_KEY_Thai_nonu                    0xdb9
#define IME_KEY_Thai_bobaimai                0xdba
#define IME_KEY_Thai_popla                    0xdbb
#define IME_KEY_Thai_phophung                0xdbc
#define IME_KEY_Thai_fofa                    0xdbd
#define IME_KEY_Thai_phophan                    0xdbe
#define IME_KEY_Thai_fofan                    0xdbf
#define IME_KEY_Thai_phosamphao                    0xdc0
#define IME_KEY_Thai_moma                    0xdc1
#define IME_KEY_Thai_yoyak                    0xdc2
#define IME_KEY_Thai_rorua                    0xdc3
#define IME_KEY_Thai_ru                    0xdc4
#define IME_KEY_Thai_loling                    0xdc5
#define IME_KEY_Thai_lu                    0xdc6
#define IME_KEY_Thai_wowaen                    0xdc7
#define IME_KEY_Thai_sosala                    0xdc8
#define IME_KEY_Thai_sorusi                    0xdc9
#define IME_KEY_Thai_sosua                    0xdca
#define IME_KEY_Thai_hohip                    0xdcb
#define IME_KEY_Thai_lochula                    0xdcc
#define IME_KEY_Thai_oang                    0xdcd
#define IME_KEY_Thai_honokhuk                0xdce
#define IME_KEY_Thai_paiyannoi                0xdcf
#define IME_KEY_Thai_saraa                    0xdd0
#define IME_KEY_Thai_maihanakat                0xdd1
#define IME_KEY_Thai_saraaa                    0xdd2
#define IME_KEY_Thai_saraam                    0xdd3
#define IME_KEY_Thai_sarai                    0xdd4   
#define IME_KEY_Thai_saraii                    0xdd5   
#define IME_KEY_Thai_saraue                    0xdd6    
#define IME_KEY_Thai_sarauee                    0xdd7    
#define IME_KEY_Thai_sarau                    0xdd8    
#define IME_KEY_Thai_sarauu                    0xdd9   
#define IME_KEY_Thai_phinthu                    0xdda
#define IME_KEY_Thai_maihanakat_maitho               0xdde
#define IME_KEY_Thai_baht                    0xddf
#define IME_KEY_Thai_sarae                    0xde0    
#define IME_KEY_Thai_saraae                    0xde1
#define IME_KEY_Thai_sarao                    0xde2
#define IME_KEY_Thai_saraaimaimuan                0xde3   
#define IME_KEY_Thai_saraaimaimalai                0xde4  
#define IME_KEY_Thai_lakkhangyao                0xde5
#define IME_KEY_Thai_maiyamok                0xde6
#define IME_KEY_Thai_maitaikhu                0xde7
#define IME_KEY_Thai_maiek                    0xde8   
#define IME_KEY_Thai_maitho                    0xde9
#define IME_KEY_Thai_maitri                    0xdea
#define IME_KEY_Thai_maichattawa                0xdeb
#define IME_KEY_Thai_thanthakhat                0xdec
#define IME_KEY_Thai_nikhahit                0xded
#define IME_KEY_Thai_leksun                    0xdf0 
#define IME_KEY_Thai_leknung                    0xdf1  
#define IME_KEY_Thai_leksong                    0xdf2 
#define IME_KEY_Thai_leksam                    0xdf3
#define IME_KEY_Thai_leksi                    0xdf4  
#define IME_KEY_Thai_lekha                    0xdf5  
#define IME_KEY_Thai_lekhok                    0xdf6  
#define IME_KEY_Thai_lekchet                    0xdf7  
#define IME_KEY_Thai_lekpaet                    0xdf8  
#define IME_KEY_Thai_lekkao                    0xdf9 

/*
 *   Korean
 *   Byte 3 = e
 */


#define IME_KEY_Hangul        0xff31    /* Hangul start/stop(toggle) */
#define IME_KEY_Hangul_Start        0xff32    /* Hangul start */
#define IME_KEY_Hangul_End        0xff33    /* Hangul end, English start */
#define IME_KEY_Hangul_Hanja        0xff34    /* Start Hangul->Hanja Conversion */
#define IME_KEY_Hangul_Jamo        0xff35    /* Hangul Jamo mode */
#define IME_KEY_Hangul_Romaja    0xff36    /* Hangul Romaja mode */
#define IME_KEY_Hangul_Codeinput    0xff37    /* Hangul code input mode */
#define IME_KEY_Hangul_Jeonja    0xff38    /* Jeonja mode */
#define IME_KEY_Hangul_Banja        0xff39    /* Banja mode */
#define IME_KEY_Hangul_PreHanja    0xff3a    /* Pre Hanja conversion */
#define IME_KEY_Hangul_PostHanja    0xff3b    /* Post Hanja conversion */
#define IME_KEY_Hangul_SingleCandidate    0xff3c    /* Single candidate */
#define IME_KEY_Hangul_MultipleCandidate    0xff3d    /* Multiple candidate */
#define IME_KEY_Hangul_PreviousCandidate    0xff3e    /* Previous candidate */
#define IME_KEY_Hangul_Special    0xff3f    /* Special symbols */
#define IME_KEY_Hangul_switch    0xFF7E    /* Alias for mode_switch */

/* Hangul Consonant Characters */
#define IME_KEY_Hangul_Kiyeog                0xea1
#define IME_KEY_Hangul_SsangKiyeog                0xea2
#define IME_KEY_Hangul_KiyeogSios                0xea3
#define IME_KEY_Hangul_Nieun                    0xea4
#define IME_KEY_Hangul_NieunJieuj                0xea5
#define IME_KEY_Hangul_NieunHieuh                0xea6
#define IME_KEY_Hangul_Dikeud                0xea7
#define IME_KEY_Hangul_SsangDikeud                0xea8
#define IME_KEY_Hangul_Rieul                    0xea9
#define IME_KEY_Hangul_RieulKiyeog                0xeaa
#define IME_KEY_Hangul_RieulMieum                0xeab
#define IME_KEY_Hangul_RieulPieub                0xeac
#define IME_KEY_Hangul_RieulSios                0xead
#define IME_KEY_Hangul_RieulTieut                0xeae
#define IME_KEY_Hangul_RieulPhieuf                0xeaf
#define IME_KEY_Hangul_RieulHieuh                0xeb0
#define IME_KEY_Hangul_Mieum                    0xeb1
#define IME_KEY_Hangul_Pieub                    0xeb2
#define IME_KEY_Hangul_SsangPieub                0xeb3
#define IME_KEY_Hangul_PieubSios                0xeb4
#define IME_KEY_Hangul_Sios                    0xeb5
#define IME_KEY_Hangul_SsangSios                0xeb6
#define IME_KEY_Hangul_Ieung                    0xeb7
#define IME_KEY_Hangul_Jieuj                    0xeb8
#define IME_KEY_Hangul_SsangJieuj                0xeb9
#define IME_KEY_Hangul_Cieuc                    0xeba
#define IME_KEY_Hangul_Khieuq                0xebb
#define IME_KEY_Hangul_Tieut                    0xebc
#define IME_KEY_Hangul_Phieuf                0xebd
#define IME_KEY_Hangul_Hieuh                    0xebe

/* Hangul Vowel Characters */
#define IME_KEY_Hangul_A                    0xebf
#define IME_KEY_Hangul_AE                    0xec0
#define IME_KEY_Hangul_YA                    0xec1
#define IME_KEY_Hangul_YAE                    0xec2
#define IME_KEY_Hangul_EO                    0xec3
#define IME_KEY_Hangul_E                    0xec4
#define IME_KEY_Hangul_YEO                    0xec5
#define IME_KEY_Hangul_YE                    0xec6
#define IME_KEY_Hangul_O                    0xec7
#define IME_KEY_Hangul_WA                    0xec8
#define IME_KEY_Hangul_WAE                    0xec9
#define IME_KEY_Hangul_OE                    0xeca
#define IME_KEY_Hangul_YO                    0xecb
#define IME_KEY_Hangul_U                    0xecc
#define IME_KEY_Hangul_WEO                    0xecd
#define IME_KEY_Hangul_WE                    0xece
#define IME_KEY_Hangul_WI                    0xecf
#define IME_KEY_Hangul_YU                    0xed0
#define IME_KEY_Hangul_EU                    0xed1
#define IME_KEY_Hangul_YI                    0xed2
#define IME_KEY_Hangul_I                    0xed3

/* Hangul syllable-final (JongSeong) Characters */
#define IME_KEY_Hangul_J_Kiyeog                0xed4
#define IME_KEY_Hangul_J_SsangKiyeog                0xed5
#define IME_KEY_Hangul_J_KiyeogSios                0xed6
#define IME_KEY_Hangul_J_Nieun                0xed7
#define IME_KEY_Hangul_J_NieunJieuj                0xed8
#define IME_KEY_Hangul_J_NieunHieuh                0xed9
#define IME_KEY_Hangul_J_Dikeud                0xeda
#define IME_KEY_Hangul_J_Rieul                0xedb
#define IME_KEY_Hangul_J_RieulKiyeog                0xedc
#define IME_KEY_Hangul_J_RieulMieum                0xedd
#define IME_KEY_Hangul_J_RieulPieub                0xede
#define IME_KEY_Hangul_J_RieulSios                0xedf
#define IME_KEY_Hangul_J_RieulTieut                0xee0
#define IME_KEY_Hangul_J_RieulPhieuf                0xee1
#define IME_KEY_Hangul_J_RieulHieuh                0xee2
#define IME_KEY_Hangul_J_Mieum                0xee3
#define IME_KEY_Hangul_J_Pieub                0xee4
#define IME_KEY_Hangul_J_PieubSios                0xee5
#define IME_KEY_Hangul_J_Sios                0xee6
#define IME_KEY_Hangul_J_SsangSios                0xee7
#define IME_KEY_Hangul_J_Ieung                0xee8
#define IME_KEY_Hangul_J_Jieuj                0xee9
#define IME_KEY_Hangul_J_Cieuc                0xeea
#define IME_KEY_Hangul_J_Khieuq                0xeeb
#define IME_KEY_Hangul_J_Tieut                0xeec
#define IME_KEY_Hangul_J_Phieuf                0xeed
#define IME_KEY_Hangul_J_Hieuh                0xeee

/* Ancient Hangul Consonant Characters */
#define IME_KEY_Hangul_RieulYeorinHieuh            0xeef
#define IME_KEY_Hangul_SunkyeongeumMieum            0xef0
#define IME_KEY_Hangul_SunkyeongeumPieub            0xef1
#define IME_KEY_Hangul_PanSios                0xef2
#define IME_KEY_Hangul_KkogjiDalrinIeung            0xef3
#define IME_KEY_Hangul_SunkyeongeumPhieuf            0xef4
#define IME_KEY_Hangul_YeorinHieuh                0xef5

/* Ancient Hangul Vowel Characters */
#define IME_KEY_Hangul_AraeA                    0xef6
#define IME_KEY_Hangul_AraeAE                0xef7

/* Ancient Hangul syllable-final (JongSeong) Characters */
#define IME_KEY_Hangul_J_PanSios                0xef8
#define IME_KEY_Hangul_J_KkogjiDalrinIeung            0xef9
#define IME_KEY_Hangul_J_YeorinHieuh                0xefa

/* Korean currency symbol */
#define IME_KEY_Korean_Won                    0xeff


/*
 *   Armenian
 *   Byte 3 = 0x14
 */

#define IME_KEY_Armenian_eternity                0x14a1
#define IME_KEY_Armenian_ligature_ew                0x14a2
#define IME_KEY_Armenian_full_stop                0x14a3
#define IME_KEY_Armenian_verjaket                0x14a3
#define IME_KEY_Armenian_parenright                0x14a4
#define IME_KEY_Armenian_parenleft                0x14a5
#define IME_KEY_Armenian_guillemotright            0x14a6
#define IME_KEY_Armenian_guillemotleft            0x14a7
#define IME_KEY_Armenian_em_dash                0x14a8
#define IME_KEY_Armenian_dot                    0x14a9
#define IME_KEY_Armenian_mijaket                0x14a9
#define IME_KEY_Armenian_separation_mark            0x14aa
#define IME_KEY_Armenian_but                    0x14aa
#define IME_KEY_Armenian_comma                0x14ab
#define IME_KEY_Armenian_en_dash                0x14ac
#define IME_KEY_Armenian_hyphen                0x14ad
#define IME_KEY_Armenian_yentamna                0x14ad
#define IME_KEY_Armenian_ellipsis                0x14ae
#define IME_KEY_Armenian_exclam                0x14af
#define IME_KEY_Armenian_amanak                0x14af
#define IME_KEY_Armenian_accent                0x14b0
#define IME_KEY_Armenian_shesht                0x14b0
#define IME_KEY_Armenian_question                0x14b1
#define IME_KEY_Armenian_paruyk                0x14b1
#define IME_KEY_Armenian_AYB                    0x14b2
#define IME_KEY_Armenian_ayb                    0x14b3
#define IME_KEY_Armenian_BEN                    0x14b4
#define IME_KEY_Armenian_ben                    0x14b5
#define IME_KEY_Armenian_GIM                    0x14b6
#define IME_KEY_Armenian_gim                    0x14b7
#define IME_KEY_Armenian_DA                    0x14b8
#define IME_KEY_Armenian_da                    0x14b9
#define IME_KEY_Armenian_YECH                0x14ba
#define IME_KEY_Armenian_yech                0x14bb
#define IME_KEY_Armenian_ZA                    0x14bc
#define IME_KEY_Armenian_za                    0x14bd
#define IME_KEY_Armenian_E                    0x14be
#define IME_KEY_Armenian_e                    0x14bf
#define IME_KEY_Armenian_AT                    0x14c0
#define IME_KEY_Armenian_at                    0x14c1
#define IME_KEY_Armenian_TO                    0x14c2
#define IME_KEY_Armenian_to                    0x14c3
#define IME_KEY_Armenian_ZHE                    0x14c4
#define IME_KEY_Armenian_zhe                    0x14c5
#define IME_KEY_Armenian_INI                    0x14c6
#define IME_KEY_Armenian_ini                    0x14c7
#define IME_KEY_Armenian_LYUN                0x14c8
#define IME_KEY_Armenian_lyun                0x14c9
#define IME_KEY_Armenian_KHE                    0x14ca
#define IME_KEY_Armenian_khe                    0x14cb
#define IME_KEY_Armenian_TSA                    0x14cc
#define IME_KEY_Armenian_tsa                    0x14cd
#define IME_KEY_Armenian_KEN                    0x14ce
#define IME_KEY_Armenian_ken                    0x14cf
#define IME_KEY_Armenian_HO                    0x14d0
#define IME_KEY_Armenian_ho                    0x14d1
#define IME_KEY_Armenian_DZA                    0x14d2
#define IME_KEY_Armenian_dza                    0x14d3
#define IME_KEY_Armenian_GHAT                0x14d4
#define IME_KEY_Armenian_ghat                0x14d5
#define IME_KEY_Armenian_TCHE                0x14d6
#define IME_KEY_Armenian_tche                0x14d7
#define IME_KEY_Armenian_MEN                    0x14d8
#define IME_KEY_Armenian_men                    0x14d9
#define IME_KEY_Armenian_HI                    0x14da
#define IME_KEY_Armenian_hi                    0x14db
#define IME_KEY_Armenian_NU                    0x14dc
#define IME_KEY_Armenian_nu                    0x14dd
#define IME_KEY_Armenian_SHA                    0x14de
#define IME_KEY_Armenian_sha                    0x14df
#define IME_KEY_Armenian_VO                    0x14e0
#define IME_KEY_Armenian_vo                    0x14e1
#define IME_KEY_Armenian_CHA                    0x14e2
#define IME_KEY_Armenian_cha                    0x14e3
#define IME_KEY_Armenian_PE                    0x14e4
#define IME_KEY_Armenian_pe                    0x14e5
#define IME_KEY_Armenian_JE                    0x14e6
#define IME_KEY_Armenian_je                    0x14e7
#define IME_KEY_Armenian_RA                    0x14e8
#define IME_KEY_Armenian_ra                    0x14e9
#define IME_KEY_Armenian_SE                    0x14ea
#define IME_KEY_Armenian_se                    0x14eb
#define IME_KEY_Armenian_VEV                    0x14ec
#define IME_KEY_Armenian_vev                    0x14ed
#define IME_KEY_Armenian_TYUN                0x14ee
#define IME_KEY_Armenian_tyun                0x14ef
#define IME_KEY_Armenian_RE                    0x14f0
#define IME_KEY_Armenian_re                    0x14f1
#define IME_KEY_Armenian_TSO                    0x14f2
#define IME_KEY_Armenian_tso                    0x14f3
#define IME_KEY_Armenian_VYUN                0x14f4
#define IME_KEY_Armenian_vyun                0x14f5
#define IME_KEY_Armenian_PYUR                0x14f6
#define IME_KEY_Armenian_pyur                0x14f7
#define IME_KEY_Armenian_KE                    0x14f8
#define IME_KEY_Armenian_ke                    0x14f9
#define IME_KEY_Armenian_O                    0x14fa
#define IME_KEY_Armenian_o                    0x14fb
#define IME_KEY_Armenian_FE                    0x14fc
#define IME_KEY_Armenian_fe                    0x14fd
#define IME_KEY_Armenian_apostrophe                0x14fe
#define IME_KEY_Armenian_section_sign            0x14ff

/*
 *   Georgian
 *   Byte 3 = 0x15
 */

#define IME_KEY_Georgian_an                    0x15d0
#define IME_KEY_Georgian_ban                    0x15d1
#define IME_KEY_Georgian_gan                    0x15d2
#define IME_KEY_Georgian_don                    0x15d3
#define IME_KEY_Georgian_en                    0x15d4
#define IME_KEY_Georgian_vin                    0x15d5
#define IME_KEY_Georgian_zen                    0x15d6
#define IME_KEY_Georgian_tan                    0x15d7
#define IME_KEY_Georgian_in                    0x15d8
#define IME_KEY_Georgian_kan                    0x15d9
#define IME_KEY_Georgian_las                    0x15da
#define IME_KEY_Georgian_man                    0x15db
#define IME_KEY_Georgian_nar                    0x15dc
#define IME_KEY_Georgian_on                    0x15dd
#define IME_KEY_Georgian_par                    0x15de
#define IME_KEY_Georgian_zhar                0x15df
#define IME_KEY_Georgian_rae                    0x15e0
#define IME_KEY_Georgian_san                    0x15e1
#define IME_KEY_Georgian_tar                    0x15e2
#define IME_KEY_Georgian_un                    0x15e3
#define IME_KEY_Georgian_phar                0x15e4
#define IME_KEY_Georgian_khar                0x15e5
#define IME_KEY_Georgian_ghan                0x15e6
#define IME_KEY_Georgian_qar                    0x15e7
#define IME_KEY_Georgian_shin                0x15e8
#define IME_KEY_Georgian_chin                0x15e9
#define IME_KEY_Georgian_can                    0x15ea
#define IME_KEY_Georgian_jil                    0x15eb
#define IME_KEY_Georgian_cil                    0x15ec
#define IME_KEY_Georgian_char                0x15ed
#define IME_KEY_Georgian_xan                    0x15ee
#define IME_KEY_Georgian_jhan                0x15ef
#define IME_KEY_Georgian_hae                    0x15f0
#define IME_KEY_Georgian_he                    0x15f1
#define IME_KEY_Georgian_hie                    0x15f2
#define IME_KEY_Georgian_we                    0x15f3
#define IME_KEY_Georgian_har                    0x15f4
#define IME_KEY_Georgian_hoe                    0x15f5
#define IME_KEY_Georgian_fi                    0x15f6

/*
 * Azeri (and other Turkic or Caucasian languages of ex-USSR)
 * Byte 3 = 0x16
 */

/* latin */
#define IME_KEY_Ccedillaabovedot    0x16a2
#define IME_KEY_Xabovedot        0x16a3
#define IME_KEY_Qabovedot        0x16a5
#define    IME_KEY_Ibreve        0x16a6
#define IME_KEY_IE            0x16a7
#define IME_KEY_UO            0x16a8
#define IME_KEY_Zstroke        0x16a9
#define    IME_KEY_Gcaron        0x16aa
#define    IME_KEY_Obarred        0x16af
#define IME_KEY_ccedillaabovedot    0x16b2
#define IME_KEY_xabovedot        0x16b3
#define    IME_KEY_Ocaron        0x16b4
#define IME_KEY_qabovedot        0x16b5
#define    IME_KEY_ibreve        0x16b6
#define IME_KEY_ie            0x16b7
#define IME_KEY_uo            0x16b8
#define IME_KEY_zstroke        0x16b9
#define    IME_KEY_gcaron        0x16ba
#define    IME_KEY_ocaron        0x16bd
#define    IME_KEY_obarred        0x16bf
#define IME_KEY_SCHWA        0x16c6
#define IME_KEY_schwa        0x16f6
/* those are not really Caucasus, but I put them here for now */
/* For Inupiak */
#define IME_KEY_Lbelowdot        0x16d1
#define IME_KEY_Lstrokebelowdot    0x16d2
#define IME_KEY_lbelowdot        0x16e1
#define IME_KEY_lstrokebelowdot    0x16e2
/* For Guarani */
#define IME_KEY_Gtilde        0x16d3
#define IME_KEY_gtilde        0x16e3

/*
 *   Vietnamese
 *   Byte 3 = 0x1e
 */
 
#define IME_KEY_Abelowdot                    0x1ea0
#define IME_KEY_abelowdot                    0x1ea1
#define IME_KEY_Ahook                    0x1ea2
#define IME_KEY_ahook                    0x1ea3
#define IME_KEY_Acircumflexacute                0x1ea4
#define IME_KEY_acircumflexacute                0x1ea5
#define IME_KEY_Acircumflexgrave                0x1ea6
#define IME_KEY_acircumflexgrave                0x1ea7
#define IME_KEY_Acircumflexhook                0x1ea8
#define IME_KEY_acircumflexhook                0x1ea9
#define IME_KEY_Acircumflextilde                0x1eaa
#define IME_KEY_acircumflextilde                0x1eab
#define IME_KEY_Acircumflexbelowdot                0x1eac
#define IME_KEY_acircumflexbelowdot                0x1ead
#define IME_KEY_Abreveacute                    0x1eae
#define IME_KEY_abreveacute                    0x1eaf
#define IME_KEY_Abrevegrave                    0x1eb0
#define IME_KEY_abrevegrave                    0x1eb1
#define IME_KEY_Abrevehook                    0x1eb2
#define IME_KEY_abrevehook                    0x1eb3
#define IME_KEY_Abrevetilde                    0x1eb4
#define IME_KEY_abrevetilde                    0x1eb5
#define IME_KEY_Abrevebelowdot                0x1eb6
#define IME_KEY_abrevebelowdot                0x1eb7
#define IME_KEY_Ebelowdot                    0x1eb8
#define IME_KEY_ebelowdot                    0x1eb9
#define IME_KEY_Ehook                    0x1eba
#define IME_KEY_ehook                    0x1ebb
#define IME_KEY_Etilde                    0x1ebc
#define IME_KEY_etilde                    0x1ebd
#define IME_KEY_Ecircumflexacute                0x1ebe
#define IME_KEY_ecircumflexacute                0x1ebf
#define IME_KEY_Ecircumflexgrave                0x1ec0
#define IME_KEY_ecircumflexgrave                0x1ec1
#define IME_KEY_Ecircumflexhook                0x1ec2
#define IME_KEY_ecircumflexhook                0x1ec3
#define IME_KEY_Ecircumflextilde                0x1ec4
#define IME_KEY_ecircumflextilde                0x1ec5
#define IME_KEY_Ecircumflexbelowdot                0x1ec6
#define IME_KEY_ecircumflexbelowdot                0x1ec7
#define IME_KEY_Ihook                    0x1ec8
#define IME_KEY_ihook                    0x1ec9
#define IME_KEY_Ibelowdot                    0x1eca
#define IME_KEY_ibelowdot                    0x1ecb
#define IME_KEY_Obelowdot                    0x1ecc
#define IME_KEY_obelowdot                    0x1ecd
#define IME_KEY_Ohook                    0x1ece
#define IME_KEY_ohook                    0x1ecf
#define IME_KEY_Ocircumflexacute                0x1ed0
#define IME_KEY_ocircumflexacute                0x1ed1
#define IME_KEY_Ocircumflexgrave                0x1ed2
#define IME_KEY_ocircumflexgrave                0x1ed3
#define IME_KEY_Ocircumflexhook                0x1ed4
#define IME_KEY_ocircumflexhook                0x1ed5
#define IME_KEY_Ocircumflextilde                0x1ed6
#define IME_KEY_ocircumflextilde                0x1ed7
#define IME_KEY_Ocircumflexbelowdot                0x1ed8
#define IME_KEY_ocircumflexbelowdot                0x1ed9
#define IME_KEY_Ohornacute                    0x1eda
#define IME_KEY_ohornacute                    0x1edb
#define IME_KEY_Ohorngrave                    0x1edc
#define IME_KEY_ohorngrave                    0x1edd
#define IME_KEY_Ohornhook                    0x1ede
#define IME_KEY_ohornhook                    0x1edf
#define IME_KEY_Ohorntilde                    0x1ee0
#define IME_KEY_ohorntilde                    0x1ee1
#define IME_KEY_Ohornbelowdot                0x1ee2
#define IME_KEY_ohornbelowdot                0x1ee3
#define IME_KEY_Ubelowdot                    0x1ee4
#define IME_KEY_ubelowdot                    0x1ee5
#define IME_KEY_Uhook                    0x1ee6
#define IME_KEY_uhook                    0x1ee7
#define IME_KEY_Uhornacute                    0x1ee8
#define IME_KEY_uhornacute                    0x1ee9
#define IME_KEY_Uhorngrave                    0x1eea
#define IME_KEY_uhorngrave                    0x1eeb
#define IME_KEY_Uhornhook                    0x1eec
#define IME_KEY_uhornhook                    0x1eed
#define IME_KEY_Uhorntilde                    0x1eee
#define IME_KEY_uhorntilde                    0x1eef
#define IME_KEY_Uhornbelowdot                0x1ef0
#define IME_KEY_uhornbelowdot                0x1ef1
#define IME_KEY_Ybelowdot                    0x1ef4
#define IME_KEY_ybelowdot                    0x1ef5
#define IME_KEY_Yhook                    0x1ef6
#define IME_KEY_yhook                    0x1ef7
#define IME_KEY_Ytilde                    0x1ef8
#define IME_KEY_ytilde                    0x1ef9
#define IME_KEY_Ohorn                    0x1efa /* U+01a0 */
#define IME_KEY_ohorn                    0x1efb /* U+01a1 */
#define IME_KEY_Uhorn                    0x1efc /* U+01af */
#define IME_KEY_uhorn                    0x1efd /* U+01b0 */

#define IME_KEY_combining_tilde                0x1e9f /* U+0303 */
#define IME_KEY_combining_grave                0x1ef2 /* U+0300 */
#define IME_KEY_combining_acute                0x1ef3 /* U+0301 */
#define IME_KEY_combining_hook                0x1efe /* U+0309 */
#define IME_KEY_combining_belowdot                0x1eff /* U+0323 */

#define IME_KEY_EcuSign                    0x20a0
#define IME_KEY_ColonSign                    0x20a1
#define IME_KEY_CruzeiroSign                    0x20a2
#define IME_KEY_FFrancSign                    0x20a3
#define IME_KEY_LiraSign                    0x20a4
#define IME_KEY_MillSign                    0x20a5
#define IME_KEY_NairaSign                    0x20a6
#define IME_KEY_PesetaSign                    0x20a7
#define IME_KEY_RupeeSign                    0x20a8
#define IME_KEY_WonSign                    0x20a9
#define IME_KEY_NewSheqelSign                0x20aa
#define IME_KEY_DongSign                    0x20ab
#define IME_KEY_EuroSign                    0x20ac
