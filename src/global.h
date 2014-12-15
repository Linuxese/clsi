const int MAX = 500;

/////////////DATA STRUCT/////////////////////
typedef struct _IME_HELPER_DATA {
    int command;
    IME_KeyEvent key;
    char data[MAX];
}IME_HELPER_DATA;

//////////////COMMAND//////////////////
const int IME_HELPER_FOCUS_IN = 1;
const int IME_HELPER_FOCUS_OUT = 2;
const int IME_HELPER_PROCESS_KEY_EVENT = 3;
const int IME_HELPER_COMMIT_STRING = 4;
const int IME_HELPER_HELPER_START = 5;

/////////////CONST///////////////////////////
const int MAX_UUID_LEN = 40;
