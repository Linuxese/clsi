/**
 * @file API definition of the Standard Input Method interface.
 *
 * Abbreviation:
 * IME   Input Method Engine
 * IMM   Input Method Manager
 */

#ifndef __SIMP_IM_ENGINE_H
#define __SIMP_IM_ENGINE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum _IME_Bool {
    IME_FALSE = 0,
    IME_TRUE  = 1
} IME_Bool;

/**
 * @brief Struct to hold input method information.
 *
 * This struct includes:
 *   - uuid
 *     An unique string to identify this input method.
 *     You should use uuidgen to generate it.
 *
 *   - encoding
 *     The character encoding used in this input method.
 *     The strings send to Input Method Manager via any methods
 *     should use this encoding.
 *     UTF-8 encoding is prefered here, though other local encodings
 *     should also be acceptable.
 *
 *   - name
 *     The name of this input method, should be encoded in the encoding
 *     specified by the previous encoding parameter.
 *
 *   - icon
 *     Local path of the icon file for this input method.
 *
 *   - languages
 *     All languages supported by this input method.
 *     Multiple languages should be separated by comma.
 *     The language name is same as the glibc locale name standard (without encoding info).
 *     For example: zh_CN,zh_TW,ja_JP,ko_KR
 *
 *   - help
 *     A brief help text of this input method, should be encoded in the
 *     given encoding.
 *
 *   - copyright
 *     Copyright information of this input method, should be encoded in the
 *     given encoding.
 *
 *   - version
 *     Version string of this input method, should be encoded in the
 *     given encoding.
 *
 * All of this strings should be held by IME module, and should not be freed
 * until the module is finalized. In other word, they should be static string.
 */
typedef struct _IME_InputMethod {
    const char *uuid;
    const char *encoding;
    const char *name;
    const char *icon;
    const char *languages;
    const char *help;
    const char *copyright;
    const char *version;
} IME_InputMethod;

/**
 * @brief Struct to hold the information of one Input Context.
 *
 * This struct includes;
 *   - id
 *     An integer id of this Input Context,
 *     allocated by Input Method Manager. IME module must not change
 *     this id.
 *
 *   - uuid
 *     The uuid of the corresponding input method. This may just a pointer
 *     to the corresponding field in the previous structure.
 *     IME should use this uuid to distinguish which input method should be
 *     used for this input context.
 *
 *   - charset
 *     The charset supported by the client.
 *     The client can not accept the characters outside this charset.
 *     Input method should filter the input result
 *     according to this information.
 *
 *   - private_data
 *     Input method module can store any data related to the IC here.
 *     The memory should be freed when destroying the IC.
 */
typedef struct _IME_InputContext {
    int         id;
    const char *uuid;
    const char *charset;
    void       *private_data;
} IME_InputContext;

/**
 * @brief Struct to hold a key event.
 *
 * The members are:
 *   - code
 *     Key code of this event, will be defined in another header file.
 *   - unicode
 *     Unicode (UCS-4) code of this event, if have.
 *   - mask
 *     Key mask of this event, including Modifiers state and Key Release mask.
 */
typedef struct _IME_KeyEvent {
    int code;
    int unicode;
    int mask;
} IME_KeyEvent;

/**
 * @brief Valid string attribute types.
 *
 *   - IME_ATTR_NONE
 *     No attribute.
 *
 *   - IME_ATTR_DECORATION
 *     Simple decoration attribute, like underline, reverse, highlight etc.
 *
 *   - IME_ATTR_FOREGROUND_RGB
 *     Attribute to change the foreground color of a string.
 *
 *   - IME_ATTR_BACKGROUND_RGB
 *     Attribute to change the background color of a string.
 */
typedef enum _IME_AttributeType {
    IME_ATTR_NONE,
    IME_ATTR_DECORATION,
    IME_ATTR_FOREGROUND_RGB,
    IME_ATTR_BACKGROUND_RGB
} IME_AttributeType;

#define IME_DECORATION_NONE        0
#define IME_DECORATION_UNDERLINE   1
#define IME_DECORATION_HIGHLIGHT   2
#define IME_DECORATION_REVERSE     4

#define IME_RGB_COLOR(RED,GREEN,BLUE)  ((int)(((RED)<<16) + ((GREEN)<<8) + (BLUE)))
#define IME_RGB_COLOR_RED(COLOR)       ((int)(COLOR>>16))
#define IME_RGB_COLOR_GREEN(COLOR)     ((int)((COLOR>>8)&0x00ff))
#define IME_RGB_COLOR_BLUE(COLOR)      ((int)(COLOR&0x0000ff))

/**
 * @brief Struct to hold an attribute.
 *
 * The members are:
 *   - type
 *     The type of this attribute.
 *   - value
 *     The value of this attribute. For decoration attribute,
 *     it can be IME_DECORATION_NONE, IME_DECORATION_HIGHLIGHT, etc.
 *     For foreground and background attribute, it's a color value generated with IME_RGB_COLOR macro.
 *   - start
 *     The start position of this attribute in the string, should be counted in unicode characters.
 *   - length
 *     The length of this attribute, should be counted in unicode characters.
 */ 
typedef struct _IME_Attribute {
    IME_AttributeType type;
    int           value;
    int           start;
    int           length;
} IME_Attribute;

/**
 * @brief Struct to hold a string with its attributes.
 * 
 * The members are:
 *   - string
 *     The string in specific encoding.
 *   - nr_attributes
 *     The number of attributes.
 *   - attributes
 *     The attributes of this string.
 */
typedef struct _IME_String {
    const char    *string;
    int            nr_attributes;
    IME_Attribute *attributes;
} IME_String;

/**
 * @brief Struct to hold a candidate string.
 *
 * The members are:
 *   - label
 *     A label string of this candidate, for example "1", "2" etc.
 *   - content
 *     The content string of this candidate.
 */
typedef struct _IME_Candidate {
    const char   *label;
    IME_String    content;
} IME_Candidate;

#define IME_FIRST_PAGE   1
#define IME_LAST_PAGE    2

/**
 * @brief Struct to hold a set of candidates
 *
 * The members are:
 *   - focused_candidate
 *     The index of focused candidate, -1 means no focused candidate.
 *   - page_state
 *     IME_FIRST_PAGE is set if it's the first page
 *     IME_LAST_PAGE is set if it's the last page
 *   - nr_candidates
 *     The number of candidates in this list.
 *   - candidates
 *     Array to hold the candidates.
 *   - title
 *     The title of this CandidatesList.
 */
typedef struct _IME_CandidatesList {
    int            focused_candidate;
    int            page_state;
    int            nr_candidates;
    const char    *title;
    IME_Candidate *candidates;
} IME_CandidatesList;

#define IME_PROPERTY_ACTIVE   1
#define IME_PROPERTY_VISIBLE  2

/**
 * @brief Struct to hold an input method property.
 *
 * For example, a Chinese input method may have properties
 * to indicate the full/half input mode of punctuations and letters.
 *
 * The members are:
 *   - key
 *     An unique key string to identify this property.
 *     Multiple properties can be organized as a tree,
 *     by using file path like key string. For example:
 *     /PropertyRoot
 *     /PropertyRoot/PropOne
 *     /PropertyRoot/PropTwo
 *     /PropertyRoot/PropThree
 *     /PropertyRoot/PropThree/PropFour
 *     /PropertyRoot/PropThree/PropFive
 *
 *     In this example, there are six properties, which are organized 
 *     into a two level tree. The root of this tree is the property "/PropertyRoot".
 *     The property "/PropertyRoot/PropThree" is a subroot which contains two
 *     sub properties.
 *
 *     This properties tree can be shown as a multilevel menu in GUI.
 *
 *   - label
 *     The label string of this property shown by GUI.
 *
 *   - icon
 *     The path of the icon file of this property.
 *
 *   - tip
 *     The tip (simple help) of this property.
 *
 *   - state
 *     The state mask of this property, can be combined by following mask:
 *     IME_PROPERTY_ACTIVE  1
 *     IME_PROPERTY_VISIBLE 2
 *     If IME_PROPERTY_ACTIVE is set then this property is active and can be triggered by user.
 *     If IME_PROPERTY_VISIBLE is set then this property is visible to user.
 */
typedef struct _IME_Property {
    const char *key;
    const char *label;
    const char *icon;
    const char *tip;
    int         state;
} IME_Property;

/**
 * @brief Struct to hold a set of properties.
 * 
 * The members are:
 *   - nr_properties
 *     The number of properties in this list.
 *   - properties
 *     Array to hold the properties.
 */
typedef struct _IME_PropertiesList {
    int           nr_properties;
    IME_Property *properties;
} IME_PropertiesList;


/**
 * @brief Struct to hold the function pointers exported from IM Engine to IM Manager.
 */ 
typedef struct _IME_Functions {
    void     (*initialize)                  (void);

    void     (*finalize)                    (void);

    int      (*get_number_of_input_methods) (void);

    IME_Bool (*get_input_method_info)       (int                       index,
                                             IME_InputMethod          *info);

    IME_Bool (*create_input_context)        (IME_InputContext         *ic);

    void     (*destroy_input_context)       (IME_InputContext         *ic);

    IME_Bool (*process_key_event)           (const IME_InputContext   *ic,
                                             const IME_KeyEvent       *key);

    void     (*process_helper_event)        (const IME_InputContext   *ic,
                                             const char               *helper_uuid,
                                             const void               *buf,
                                             size_t                    bufsize);

    void     (*focus_in)                    (const IME_InputContext   *ic);

    void     (*focus_out)                   (const IME_InputContext   *ic);

    void     (*reset)                       (const IME_InputContext   *ic);

    void     (*move_preedit_caret)          (const IME_InputContext   *ic,
                                             int                       position);
 
    void     (*select_candidate)            (const IME_InputContext   *ic,
                                             int                       index);

    void     (*previous_candidates_page)    (const IME_InputContext   *ic);

    void     (*next_candidates_page)        (const IME_InputContext   *ic);

    void     (*update_candidates_page_size) (const IME_InputContext   *ic,
                                             int                       size);

    void     (*trigger_property)            (const IME_InputContext   *ic,
                                             const char               *property);

//    void     (*reload_config)               (void);

} IME_Functions;

/**
 * @brief Struct to hold the function pointers exported from IM Manager to IM Engine.
 */
typedef struct _IMM_Functions {
    void (*show_preedit_string)             (const IME_InputContext   *ic);

    void (*hide_preedit_string)             (const IME_InputContext   *ic);

    void (*update_preedit_string)           (const IME_InputContext   *ic,
                                             const IME_String         *string);

    void (*update_preedit_caret)            (const IME_InputContext   *ic,
                                             int                       caret);

    void (*show_aux_string)                 (const IME_InputContext   *ic);

    void (*hide_aux_string)                 (const IME_InputContext   *ic);

    void (*update_aux_string)               (const IME_InputContext   *ic,
                                             const IME_String         *string);

    void (*show_candidates_list)            (const IME_InputContext   *ic);

    void (*hide_candidates_list)            (const IME_InputContext   *ic);

    void (*update_candidates_list)          (const IME_InputContext   *ic,
                                             const IME_CandidatesList *candidates);

    void (*set_focused_candidate)           (const IME_InputContext   *ic,
                                             int                       index);

    void (*commit_string)                   (const IME_InputContext   *ic,
                                             const char               *string);

    void (*register_properties)             (const IME_InputContext   *ic,
                                             const IME_PropertiesList *properties);

    void (*update_property)                 (const IME_InputContext   *ic,
                                             const IME_Property       *property);

/*    void (*read_config)                     (const char               *key,
                                             char                     *buf,
                                             size_t                    buf_size);

    void (*write_config)                    (const char               *key,
                                             const char               *value);
*/
    /**
     * @brief Load a block of user data from user specific storage.
     *
     * @param key The identify key of this block of data. It can not contain path delimiter '/'.
     * @param buf The pointer holder to store the newly allocated buffer which contains the data.
     * @param bufsize The size of this block of data will be stored here.
     */
/*    void (*load_user_data)                  (const char               *key,
                                             void                     **buf,
                                             size_t                   *bufsize);
*/
    /**
     * @brief Free a data buffer which was allocated by load_user_data () function.
     *
     * @param buf The buffer pointer to be freed.
     */
//    void (*free_user_data)                  (void                     *buf);

    /**
     * @brief Save a block of user data to user specific storage.
     *
     * @param key The identify key of this block of data.
     * @param buf The pointer to the buffer which contains the data to be saved.
     * @param bufsize The size of the buffer.
     */
/*    void (*save_user_data)                  (const char               *key,
                                             const void               *buf,
                                             size_t                    bufsize);
*/
    /**
     * @brief Start a helper object by its uuid.
     */
    void (*start_helper)                    (const IME_InputContext   *ic,
                                             const char               *helper_uuid);

    /**
     * @brief Stop a runnig helper object by its uuid
     */
    void (*stop_helper)                     (const IME_InputContext   *ic,
                                             const char               *helper_uuid);

    /**
     * @brief Send event to a running helper object.
     *
     * @param helper_uuid UUID of the helper object
     * @param buf The event buffer
     * @param bufsize The size of the event buffer
     */
    void (*send_helper_event)               (const IME_InputContext   *ic,
                                             const char               *helper_uuid,
                                             const void               *buf,
                                             size_t                    bufsize);

    void (*beep)                            (const IME_InputContext   *ic);

} IMM_Functions;

/**
 * @brief The only one symbol need be exported by each IM Engine module.
 *
 * This function is used to register this IME into the IMM.
 */
IME_Bool ime_register_module                (const IMM_Functions      *imm,
                                             IME_Functions            *ime);


/** The helper has no corresponding IME **/
#define IME_HELPER_STAND_ALONE  1

/** Start the helper automatically when IME need it, or when IMM starts (for stand alone helper). **/
#define IME_HELPER_AUTO_START   2

/** Restart the helper automatically when it dies. **/
#define IME_HELPER_AUTO_RESTART 4

typedef struct _IME_Helper_Info {
    /**
     * @brief The UUID of this helper object.
     */
    const char *uuid;

    /**
     * @brief The encoding used by this helper object.
     * All strings sent by this object will be converted according to this encondig.
     */
    const char *encoding;

    /**
     * @brief The name of this helper object.
     */
    const char *name;

    /**
     * @brief The brief description of this helper object.
     */
    const char *description;

    /**
     * @brief The icon file of this helper object.
     */
    const char *icon;

    /**
     * @brief Options of this helper, can be any combination of
     * IME_HELPER_STAND_ALONE, IME_HELPER_AUTO_START, IME_HELPER_AUTO_RESTART.
     */
    int         options;
} IME_Helper_Info;

/**
 * @brief Struct to hold the function pointers exported from IME Helper shared object to IMM Helper Manager.
 *
 * A Helper shared object can be a Auxiliary GUI helper, but not limited to this.
 * 
 * @param ic       -- The id of current focused Input Context.
 * @param ic_uuid  -- The uuid string of current focused Input Context (The uuid of the input method).
 */ 
typedef struct _IME_Helper_Functions {
    /**
     * @brief Finalize (exit) this object.
     */
    void     (*finalize)                    (void);

    /**
     * @brief Run this object.
     *
     * This function won't return until finalize () is called.
     */
    void     (*run)                         (const char *display);

    /**
      * @brief Attach an input context to this helper.
      *
      * This function will be called if an input context requst to start this helper.
      */
    void     (*attach_input_context)        (int         ic,
                                             const char *ic_uuid);

    /**
      * @brief Detach an input context to this helper.
      *
      * This function will be called if  an input context requst to stop this helper.
      */      
    void     (*detach_input_context)        (int         ic,
                                             const char *ic_uuid);

    /**
     * @brief Update the current screen.
     *
     * This function will be called if the current screen is changed.
     *
     * @param screen The name of new screen.
     */
    void     (*update_screen)                (int         ic, 
                                              const char *ic_uuid,
                                              const char *screen);
 
    /**
     * @brief Update the location of current input cursor.
     * 
     * This function will be called if the location of input cursor is changed.
     */
    void     (*update_spot_location)        (int         ic,
                                             const char *ic_uuid,
                                             int         x,
                                             int         y);

    /**
     * @brief Trigger a property.
     *
     * This function will be called if a registered property is triggered by user.
     */
    void     (*trigger_property)            (int         ic,
                                             const char *ic_uuid,
                                             const char *property);

    /**
     * @brief Process the event sent from coressponding IMEngine.
     *
     * This function will be called if a event sent from coressponding IMEngine is available.
     */
    void     (*process_ime_event)           (int         ic,
                                             const char *ic_uuid,
                                             const void *buf,
                                             size_t      len);

} IME_Helper_Functions;


/**
 * @brief Struct to hold the function pointers exported from IMM Helper Manager to IME Helper object.
 */
typedef struct _IMM_Helper_Functions {
    /**
     * @brief Open the connection to IM Manager.
     *
     * The return value is the connection number, such as socket fd number,
     * or pipe fd number etc. Can be used with select () or poll () system function
     * to determine if any data are available for reading.
     *
     * If there are some data available, then filter_event () should be called to
     * process the data.
     *
     * @return the connection number (maybe socket fd number). -1 means failed.
     */
//    int      (*open_connection)             (void);

    /**
     * @brief Close the connection.
     */
//    void     (*close_connection)            (void);

    /**
     * @brief Get the connection number previously returned by open_connection ();
     */
    int      (*get_connection_number)       (void);

    /**
     * @brief Check if there is any pending event.
     *
     * @return True if any pending event is available.
     */
//    IME_Bool (*has_pending_event)           (void);

    /**
     * @brief Call this function if any pending event is available, to process the event.
     *
     * This function will call back the respective functions
     * registered in IME_Helper_Functions structure,
     * eg. update_display (), update_screen (), trigger_property (), process_im_event () etc.
     */
    void     (*filter_event)                (void);

    /**
     * @brief Register some properties into IMM.
     *
     * These properties will be shown in input method toolbar.
     */
    void     (*register_properties)         (const IME_PropertiesList *properties);

    /**
     * @brief Update a property.
     */
    void     (*update_property)             (const IME_Property       *property);

    /**
     * @brief Send an event ot coressponding IMEngine.
     *
     * @param ime_uuid The uuid of the IMEngine to be sent to.
     * @param buf The event buffer.
     * @param bufsize The size of the buffer.
     */
    void     (*send_ime_event)              (int                       ic,
                                             const char               *ic_uuid,
                                             const void               *buf,
                                             size_t                    bufsize);

    /**
     * @brief Send a key event to coressponding IMEngine.
     * if ime_uuid is null, then Helper Manager doesn't check the ime's uuid.
     */
    void     (*send_key_event)              (int                       ic,
                                             const char               *ic_uuid,
                                             const IME_KeyEvent       *key);

    /**
     * @brief Commit a string to current focused client.
     */
    void     (*commit_string)               (int                       ic,
                                             const char               *ic_uuid,
                                             const char               *string);

    /**
     * @brief Forward a key event to current focused client.
     */
    void     (*forward_key_event)           (int                       ic,
                                             const char               *ic_uuid,
                                             const IME_KeyEvent       *key);

    /**
     * @brief Read a configuration.
     */
/*    void     (*read_config)                 (const char               *key,
                                             char                     *buf,
                                             size_t                    buf_size);
*/
    /**
     * @brief Write a configuration.
     */
/*    void     (*write_config)                (const char               *key,
                                             const char               *value);
*/
    /**
     * @brief Load a block of user specific data.
     */
/*    void     (*load_user_data)              (const char               *key,
                                             void                     **buf,
                                             size_t                   *bufsize);
*/
    /**
     * @brief Free the data loaded by load_user_data ();
     */
//    void     (*free_user_data)              (void                     *buf);

    /**
     * @brief Save a block of user specific data.
     */
/*    void     (*save_user_data)              (const char               *key,
                                             const void               *buf,
                                             size_t                    bufsize);
*/
} IMM_Helper_Functions;

/**
 * @brief Register the Helper module.
 *
 * This function should fill in ime_helper and info data structure.
 */
IME_Bool ime_helper_register_module         (const IMM_Helper_Functions      *imm_helper,
                                             IME_Helper_Functions            *ime_helper,
                                             IME_Helper_Info                 *helper_info);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SIMP_IM_ENGINE_H */

/*
vi:ts=4:nowrap:ai:expandtab
*/

