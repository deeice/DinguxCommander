#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "window.h"

#define NB_KEY_SETS 5

class CKeyboard : public CWindow
{
    public:

    // Constructor
    CKeyboard(const std::string &p_inputText);

    // Destructor
    virtual ~CKeyboard(void);

    // Get input text
    const std::string &getInputText(void) const;

    private:

    // Forbidden
    CKeyboard(void);
    CKeyboard(const CKeyboard &p_source);
    const CKeyboard &operator =(const CKeyboard &p_source);

    // Key press management
    virtual const bool keyPress(const SDL_Event &p_event);

    // Key hold management
    virtual const bool keyHold(void);

    // Draw
    virtual void render(const bool p_focus) const;

#if defined(PLATFORM_ZIPIT)
    /* Remove virtual kbd */
#else    
    // Move cursor
    const bool moveCursorUp(const bool p_loop);
    const bool moveCursorDown(const bool p_loop);
    const bool moveCursorLeft(const bool p_loop);
    const bool moveCursorRight(const bool p_loop);
#endif
    
    // Type a letter
    const bool type(const std::string &p_text = "");

    // Remove last letter
    const bool backspace(void);

    // UTF8 character or not
    const bool utf8Code(const unsigned char p_c) const;

#if defined(PLATFORM_ZIPIT)
    /* Remove virtual kbd */
#else    
    // The image representing the keyboard
    SDL_Surface *m_imageKeyboard;
#endif
    
    // The image representing the input text field
    SDL_Surface *m_textField;

    // The input text
    std::string m_inputText;

#if defined(PLATFORM_ZIPIT)
    /* Remove virtual kbd */
#else    
    // The cursor index
    unsigned char m_selected;
#endif    

    // The footer
    SDL_Surface *m_footer;

#if defined(PLATFORM_ZIPIT)
    /* Remove virtual kbd */
#else    
    // Key sets
    std::string m_keySets[NB_KEY_SETS];
    unsigned char m_keySet;
#endif
    
    // Pointers to resources
    TTF_Font *m_font;
};

#endif
