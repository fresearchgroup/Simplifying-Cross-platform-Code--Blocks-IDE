#ifndef _SPRITE_INCLUDED_
#define _SPRITE_INCLUDED_

//#define DEBUG
#include <common_def.h>
#include <vector>

using namespace std;

class Sprite
{
 public:
  static int max_z_index;
  vector<Sprite *> parts;
};
#endif
