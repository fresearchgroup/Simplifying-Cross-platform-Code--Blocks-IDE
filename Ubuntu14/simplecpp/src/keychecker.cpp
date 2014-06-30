#include <graphicsim.h>

using namespace std;

int main(){

  // Always call initCanvas() after main function
  // initCanvas() initialises all data structures and opens a window
  // Key Checker Program - Title of the window. You can change that.
  initCanvas("Key Checker Program");

  char *keyname; // Pointer to string
			
  XEvent event;  // This is event structure

  // You can ignore XPoint
  XPoint p = {10, 10};   // XPoint is simple structure

  // Print messege on screen
  drawText(p, "Press key to get its code", COLOR("blue"));
  p.y += 15;
  drawText(p, "Click to exit", COLOR("blue"));

  // Event loop
  while(1){

    // nextEvent() - It pauses your program till someone presses a key or mouse button
    nextEvent(&event);

    // --> You came here because some key was pressed or mouse click occured

    // Now check what has happend?

    // If event.type has code ButtonPress
    // Then mouse click has occured. Just exit program by breaking loop
    if(event.type == ButtonPress)
      break;
 
    // If event.type has code KeyPress
    // Then keyboard key has been pressed.
    if(event.type == KeyPress){

      // Now lets try to determine what is KeyCode
      // keyname points to relevent string.
      switch(KeyCode(event)){
      case KeyCode_ESC: keyname = (char*) "KeyCode_ESC"; break;
      case KeyCode_F1: keyname = (char*) "KeyCode_F1"; break;
      case KeyCode_F2: keyname = (char*) "KeyCode_F2"; break;
      case KeyCode_F3: keyname = (char*) "KeyCode_F3"; break;
      case KeyCode_F4: keyname = (char*) "KeyCode_F4"; break;
      case KeyCode_F5: keyname = (char*) "KeyCode_F5"; break;
      case KeyCode_F6: keyname = (char*) "KeyCode_F6"; break;
      case KeyCode_F7: keyname = (char*) "KeyCode_F7"; break;
      case KeyCode_F8: keyname = (char*) "KeyCode_F8"; break;
      case KeyCode_F9: keyname = (char*) "KeyCode_F9"; break;
      case KeyCode_F10: keyname = (char*) "KeyCode_F10"; break;
      case KeyCode_F11: keyname = (char*) "KeyCode_F11"; break;
      case KeyCode_F12: keyname = (char*) "KeyCode_F12"; break;
      case KeyCode_ACUTE: keyname = (char*) "KeyCode_ACUTE"; break;
      case KeyCode_0: keyname = (char*) "KeyCode_0"; break;
      case KeyCode_1: keyname = (char*) "KeyCode_1"; break;
      case KeyCode_2: keyname = (char*) "KeyCode_2"; break;
      case KeyCode_3: keyname = (char*) "KeyCode_3"; break;
      case KeyCode_4: keyname = (char*) "KeyCode_4"; break;
      case KeyCode_5: keyname = (char*) "KeyCode_5"; break;
      case KeyCode_6: keyname = (char*) "KeyCode_6"; break;
      case KeyCode_7: keyname = (char*) "KeyCode_7"; break;
      case KeyCode_8: keyname = (char*) "KeyCode_8"; break;
      case KeyCode_9: keyname = (char*) "KeyCode_9"; break;
      case KeyCode_A: keyname = (char*) "KeyCode_A"; break;
      case KeyCode_B: keyname = (char*) "KeyCode_B"; break;
      case KeyCode_C: keyname = (char*) "KeyCode_C"; break;
      case KeyCode_D: keyname = (char*) "KeyCode_D"; break;
      case KeyCode_E: keyname = (char*) "KeyCode_E"; break;
      case KeyCode_F: keyname = (char*) "KeyCode_F"; break;
      case KeyCode_G: keyname = (char*) "KeyCode_G"; break;
      case KeyCode_H: keyname = (char*) "KeyCode_H"; break;
      case KeyCode_I: keyname = (char*) "KeyCode_I"; break;
      case KeyCode_J: keyname = (char*) "KeyCode_J"; break;
      case KeyCode_K: keyname = (char*) "KeyCode_K"; break;
      case KeyCode_L: keyname = (char*) "KeyCode_L"; break;
      case KeyCode_M: keyname = (char*) "KeyCode_M"; break;
      case KeyCode_N: keyname = (char*) "KeyCode_N"; break;
      case KeyCode_O: keyname = (char*) "KeyCode_O"; break;
      case KeyCode_P: keyname = (char*) "KeyCode_P"; break;
      case KeyCode_Q: keyname = (char*) "KeyCode_Q"; break;
      case KeyCode_R: keyname = (char*) "KeyCode_R"; break;
      case KeyCode_S: keyname = (char*) "KeyCode_S"; break;
      case KeyCode_T: keyname = (char*) "KeyCode_T"; break;
      case KeyCode_U: keyname = (char*) "KeyCode_U"; break;
      case KeyCode_V: keyname = (char*) "KeyCode_V"; break;
      case KeyCode_W: keyname = (char*) "KeyCode_W"; break;
      case KeyCode_X: keyname = (char*) "KeyCode_X"; break;
      case KeyCode_Y: keyname = (char*) "KeyCode_Y"; break;
      case KeyCode_Z: keyname = (char*) "KeyCode_Z"; break;
      case KeyCode_SUBTRACT: keyname = (char*) "KeyCode_SUBTRACT"; break;
      case KeyCode_EQUAL: keyname = (char*) "KeyCode_EQUAL"; break;
      case KeyCode_BACKSPACE: keyname = (char*) "KeyCode_BACKSPACE"; break;
      case KeyCode_TAB: keyname = (char*) "KeyCode_TAB"; break;
      case KeyCode_CAPS_LOCK: keyname = (char*) "KeyCode_CAPS_LOCK"; break;
      case KeyCode_LSHIFT: keyname = (char*) "KeyCode_LSHIFT"; break;
      case KeyCode_RSHIFT: keyname = (char*) "KeyCode_RSHIFT"; break;
      case KeyCode_LALT: keyname = (char*) "KeyCode_LALT"; break;
      case KeyCode_RALT: keyname = (char*) "KeyCode_RALT"; break;
      case KeyCode_LCTRL: keyname = (char*) "KeyCode_LCTRL"; break;
      case KeyCode_RCTRL: keyname = (char*) "KeyCode_RCTRL"; break;
      case KeyCode_SPACEBAR: keyname = (char*) "KeyCode_SPACEBAR"; break;
      case KeyCode_ENTER: keyname = (char*) "KeyCode_ENTER"; break;
      case KeyCode_LBRACKET: keyname = (char*) "KeyCode_LBRACKET"; break;
      case KeyCode_RBRACKET: keyname = (char*) "KeyCode_RBRACKET"; break;
      case KeyCode_BACKSLASH: keyname = (char*) "KeyCode_BACKSLASH"; break;
      case KeyCode_SEMICOLON: keyname = (char*) "KeyCode_SEMICOLON"; break;
      case KeyCode_QUOTE: keyname = (char*) "KeyCode_QUOTE"; break;
      case KeyCode_COMMA: keyname = (char*) "KeyCode_COMMA"; break;
      case KeyCode_FULLSTOP: keyname = (char*) "KeyCode_FULLSTOP"; break;
      case KeyCode_FORWARDSLASH: keyname = (char*) "KeyCode_FORWARDSLASH"; break;
      case KeyCode_HOME: keyname = (char*) "KeyCode_HOME"; break;
      case KeyCode_PAGEUP: keyname = (char*) "KeyCode_PAGEUP"; break;
      case KeyCode_PAGEDOWN: keyname = (char*) "KeyCode_PAGEDOWN"; break;
      case KeyCode_END: keyname = (char*) "KeyCode_END"; break;
      case KeyCode_ARROWUP: keyname = (char*) "KeyCode_ARROWUP"; break;
      case KeyCode_ARROWDOWN: keyname = (char*) "KeyCode_ARROWDOWN"; break;
      case KeyCode_ARROWLEFT: keyname = (char*) "KeyCode_ARROWLEFT"; break;
      case KeyCode_ARROWRIGHT: keyname = (char*) "KeyCode_ARROWRIGHT"; break;
      case KeyCode_SCROLL: keyname = (char*) "KeyCode_SCROLL"; break;
      case KeyCode_PAUSE: keyname = (char*) "KeyCode_PAUSE"; break;
      case KeyCode_INSERT: keyname = (char*) "KeyCode_INSERT"; break;
      case KeyCode_DELETE: keyname = (char*) "KeyCode_DELETE"; break;
      case KeyCode_NUMLOCK: keyname = (char*) "KeyCode_NUMLOCK"; break;
      case KeyCode_NUMPADDIVIDE: keyname = (char*) "KeyCode_NUMPADDIVIDE"; break;
      case KeyCode_NUMPADMULTIPLY: keyname = (char*) "KeyCode_NUMPADMULTIPLY"; break;
      case KeyCode_NUMPADSUBTRACT: keyname = (char*) "KeyCode_NUMPADSUBTRACT"; break;
      case KeyCode_NUMPADPLUS: keyname = (char*) "KeyCode_NUMPADPLUS"; break;
      case KeyCode_NUMPADENTER: keyname = (char*) "KeyCode_NUMPADENTER"; break;
      case KeyCode_NUMPAD0: keyname = (char*) "KeyCode_NUMPAD0"; break;
      case KeyCode_NUMPAD1: keyname = (char*) "KeyCode_NUMPAD1"; break;
      case KeyCode_NUMPAD2: keyname = (char*) "KeyCode_NUMPAD2"; break;
      case KeyCode_NUMPAD3: keyname = (char*) "KeyCode_NUMPAD3"; break;
      case KeyCode_NUMPAD4: keyname = (char*) "KeyCode_NUMPAD4"; break;
      case KeyCode_NUMPAD5: keyname = (char*) "KeyCode_NUMPAD5"; break;
      case KeyCode_NUMPAD6: keyname = (char*) "KeyCode_NUMPAD6"; break;
      case KeyCode_NUMPAD7: keyname = (char*) "KeyCode_NUMPAD7"; break;
      case KeyCode_NUMPAD8: keyname = (char*) "KeyCode_NUMPAD8"; break;
      case KeyCode_NUMPAD9: keyname = (char*) "KeyCode_NUMPAD9"; break;
      case KeyCode_NUMPADFULLSTOP: keyname = (char*) "KeyCode_NUMPADFULLSTOP"; break;
 
	// For Unknown key codes, print on cout stream
      default: keyname = (char*)"KeyCode_UNKNOWN"; cout<<KeyCode(event)<<endl; break;
      }    
      // Now keyname has valid code string
      
      // This is screen manipulation logic - IGNORE
      p.y += 15;     // Ignore
      if(p.y > 600){ // Ignore
	p.y = 20;    // Ignore
	p.x += 130;  // Ignore
      }              // Ignore
     
      // Now draw that string on screen
      // p is point having X co-ordinate p.x
      //              and  Y co-ordinate p.y

      drawText(p, keyname, COLOR("red"));      
    }
  }

  // Always close window with this call
  closeCanvas();

  return 0;
}
