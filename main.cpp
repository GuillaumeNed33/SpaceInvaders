#include "View.h"
#include "Model.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(){
  srand(time(NULL));

  Model model(SCREEN_WIDTH, SCREEN_HEIGHT);
  View view(SCREEN_WIDTH, SCREEN_HEIGHT);
  view.setModel(&model);

  while(view.treatEvents()){
        if(view.game && !view.pause)
            model.nextStep();
    view.draw();
    view.synchronize();
  }

  return EXIT_SUCCESS;
}
