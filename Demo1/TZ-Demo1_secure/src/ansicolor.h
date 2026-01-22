#ifndef _ANSICOLOR_H    // Guard against multiple inclusion
#define _ANSICOLOR_H

// Provide C++ Compatibility
#ifdef __cplusplus
extern "C" {
#endif

#define ANSI_ESCAPE "\x1b"

#define ANSI_BLACK ANSI_ESCAPE"[30m"    
#define ANSI_RED ANSI_ESCAPE"[31m"    
#define ANSI_GREEN ANSI_ESCAPE"[32m"    
#define ANSI_YELLOW ANSI_ESCAPE"[33m"    
#define ANSI_BLUE ANSI_ESCAPE"[34m"    
#define ANSI_MAGENTA ANSI_ESCAPE"[35m"    
#define ANSI_CYAN ANSI_ESCAPE"[36m"    
#define ANSI_WHITE ANSI_ESCAPE"[37m"    

#define ANSI_BK_BLACK ANSI_ESCAPE"[40m"    
#define ANSI_BK_RED ANSI_ESCAPE"[41m"    
#define ANSI_BK_GREEN ANSI_ESCAPE"[42m"    
#define ANSI_BK_YELLOW ANSI_ESCAPE"[43m"    
#define ANSI_BK_BLUE ANSI_ESCAPE"[44m"    
#define ANSI_BK_MAGENTA ANSI_ESCAPE"[45m"    
#define ANSI_BK_CYAN ANSI_ESCAPE"[46m"    
#define ANSI_BK_WHITE ANSI_ESCAPE"[47m"    
  
// Provide C++ Compatibility
#ifdef __cplusplus
}
#endif

#endif // _ANSICOLOR_H 
